// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// -------------------------------------------------------------------
//      GEANT 4 class file 
//
//      For information related to this code contact:
//      CERN, IT Division, ASD group
//      CERN, Geneva, Switzerland
//
//      File name:     G4VGammaDeexcitation
//
//      Author:        Maria Grazia Pia (pia@genova.infn.it)
// 
//      Creation date: 23 October 1998
//
//      Modifications: 
//      
//        15 April 1999, Alessandro Brunengo (Alessandro.Brunengo@ge.infn.it)
//              Added creation time evaluation for products of evaporation
//
//
// -------------------------------------------------------------------

#include "G4VGammaDeexcitation.hh"

#include "globals.hh"
#include "Randomize.hh"
#include "G4Gamma.hh"
#include "G4LorentzVector.hh"
#include "G4VGammaTransition.hh"
#include "G4Fragment.hh"
#include "G4FragmentVector.hh"

#include "G4ParticleTable.hh"
#include "G4IonTable.hh"

G4VGammaDeexcitation::G4VGammaDeexcitation(): _verbose(0), _transition(0)
{ }


G4VGammaDeexcitation::~G4VGammaDeexcitation()
{ 
  //  if (_transition != 0) delete _transition;
}


G4FragmentVector* G4VGammaDeexcitation::DoTransition()
{
  // Template method

 Initialize();
 G4FragmentVector* products = new G4FragmentVector;
  
  if (CanDoTransition())
    {
     G4Fragment* gamma = GenerateGamma();
     if (gamma != 0)
       {
	 products->append(gamma);
	 UpdateNucleus(gamma);
	 Update();
       }
    }

  if (_verbose > 1)
    G4cout << "G4VGammaDeexcitation::DoTransition - Transition deleted " << endl;

  if (_transition != 0) delete _transition;

  return products;
}

G4FragmentVector* G4VGammaDeexcitation::DoChain()
{
  Initialize();
  G4FragmentVector* products = new G4FragmentVector;

  while (CanDoTransition())
    {
      if (_verbose > 5) G4cout << "G4VGammaDeexcitation::DoChain -  Looping" << endl;

      G4Fragment* gamma = GenerateGamma();
      if (gamma != 0) 
	{
	  products->append(gamma);
	  UpdateNucleus(gamma);
	}
     Update();
    } 

  if (_verbose > 1)
      G4cout << "G4VGammaDeexcitation::DoChain - Transition deleted, end of chain " << endl;

  if (_transition != 0) delete _transition;
  
  return products;
}


const G4Fragment& G4VGammaDeexcitation::GetNucleus() const
{
  return _nucleus; 
}


void G4VGammaDeexcitation::SetNucleus(const G4Fragment& nucleus)
{
  _nucleus = G4Fragment(nucleus);
}


G4Fragment* G4VGammaDeexcitation::GenerateGamma()
{
  G4double eGamma = 0.;

  if (_transition != 0)
  {
    _transition->SelectGamma();
    eGamma = _transition->GetGammaEnergy();
  }

  if (_verbose > 1 && _transition != 0) 
  {
    G4cout << "G4VGammaDeexcitation::GenerateGamma - Gamma energy " << eGamma 
	   << " ** New excitation " << _nucleus.GetExcitationEnergy() - eGamma
	   << endl;
  }

  // Photon momentum isotropically generated 
 
  if (eGamma > 0.) 
  {
    G4double cosTheta = 1. - 2. * G4UniformRand();
    G4double sinTheta = sqrt(1. - cosTheta * cosTheta);
    G4double phi = twopi * G4UniformRand();
	
    G4ThreeVector pGamma( eGamma * sinTheta * cos(phi),
			  eGamma * sinTheta * sin(phi),
			  eGamma * cosTheta );

    G4LorentzVector gamma(pGamma, eGamma);
    //	gamma.boost(_nucleus.GetMomentum().boostVector() );
    G4Fragment* gammaFragment = new
      G4Fragment(gamma,G4Gamma::GammaDefinition());

    G4double gammaTime = _transition->GetGammaCreationTime();
    gammaTime += _nucleus.GetCreationTime();
    gammaFragment->SetCreationTime(gammaTime);

    if (_verbose > 1)
      G4cout << "G4VGammaDeexcitation::GenerateGamma -  Gamma fragment generated " << endl;

    return gammaFragment;
  }
  else
  {
    return 0;
  }
}


void G4VGammaDeexcitation::UpdateNucleus(const G4Fragment*  gamma)
{
  G4LorentzVector p4Gamma = gamma->GetMomentum();
  G4ThreeVector pGamma(p4Gamma);
  G4double eGamma = gamma->GetMomentum().e();
  
  G4LorentzVector p4Nucleus(_nucleus.GetMomentum() );
  //  p4Nucleus.boost(-_nucleus.GetMomentum().boostVector() );
  
//  G4LorentzVector p4Residual(p4Nucleus - pGamma, p4Nucleus.e() - eGamma);

//
// Due to a rounding error calculation in G4Fragment excitation energy,
// we must correct p4Residual.e() when we are near to 0.
//

// New tetravector calculation:

  G4double Mass = G4ParticleTable::GetParticleTable()->GetIonTable()->GetIonMass(_nucleus.GetZ(),_nucleus.GetA());
  G4double newExcitation = p4Nucleus.mag() - Mass - eGamma;
  if(newExcitation < 0)
    newExcitation = 0;

  G4ThreeVector p3Residual(p4Nucleus - pGamma);
  G4double newEnergy = sqrt(p3Residual * p3Residual +
			    (Mass + newExcitation) * (Mass + newExcitation));
  G4LorentzVector p4Residual(p3Residual, newEnergy);

  //  G4LorentzVector p4Residual(-pGamma, p4Nucleus.e() - eGamma);
  //  p4Residual.boost( _nucleus.GetMomentum().boostVector() );
  
  // Update excited nucleus parameters

  _nucleus.SetMomentum(p4Residual);
  _nucleus.SetCreationTime(gamma->GetCreationTime());

//  if (_transition != 0) 
//  {
//    G4double excitation =_transition->GetEnergyTo();
//    if (excitation < 0.) excitation = 0.0;
//    _nucleus.SetExcitationEnergy(excitation);
//  }

  return;
}


void G4VGammaDeexcitation::Update()
{
  if (_transition !=  0) 
    { 
      delete _transition;
      _transition = 0;
      if (_verbose > 1)
	G4cout << "G4VGammaDeexcitation::Update - Transition deleted " << endl;
    }

  _transition = CreateTransition();
  if (_transition != 0) 
    {
      _transition->SetEnergyFrom(_nucleus.GetExcitationEnergy());
    }

  return;
}


void G4VGammaDeexcitation::Initialize()
{
  _transition = CreateTransition();
  if (_transition != 0) _transition->SetEnergyFrom(_nucleus.GetExcitationEnergy());
  return;
}


void G4VGammaDeexcitation::SetVerboseLevel(G4int verbose)
{
  _verbose = verbose;
  return;
}







