// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4LEAlphaInelastic.hh,v 1.1.10.1 1999/12/07 20:52:16 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
 // Hadronic Process: Low Energy Alpha Inelastic Process
 // J.L. Chuma, TRIUMF, 21-Feb-1997
 // Last modified: 27-Mar-1997
 
#ifndef G4LEAlphaInelastic_h
#define G4LEAlphaInelastic_h 1
 
#include "G4InelasticInteraction.hh"
 
 class G4LEAlphaInelastic : public G4InelasticInteraction
 {
 public:
    
    G4LEAlphaInelastic() : G4InelasticInteraction()
    {
      SetMinEnergy( 0.0 );
      // SetMaxEnergy( 100.*MeV );  // NUCREC only worked for energies < 100MeV
      // Work around to avoid exception in G4EnergyRangeManager
      SetMaxEnergy( 10.*TeV );  // NUCREC only worked for energies < 100MeV
    }
    
    ~G4LEAlphaInelastic() { }
    
    G4VParticleChange *ApplyYourself( const G4Track &aTrack,
                                      G4Nucleus &targetNucleus );
 };
 
#endif
 