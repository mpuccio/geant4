//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4SimplePPReporter.cc,v 1.2 2006/06/29 19:28:00 gunter Exp $
// GEANT4 tag $Name: geant4-08-02 $
//
// 
// ---------------------------------------------------------------
#include "G4SimplePPReporter.hh"
#include "G4ios.hh"
#include "globals.hh"

//////////////////////////////
G4SimplePPReporter::G4SimplePPReporter():G4VParticlePropertyReporter()
{ 
}

////////////////////////////
G4SimplePPReporter::~G4SimplePPReporter()
{
}    

/////////////////////
void G4SimplePPReporter::Print(const G4String& )
{
  for (size_t i=0; i<pList.size(); i++){
    G4ParticlePropertyData*    ptr = (pList)[i];
    ptr->Print();  
    G4cout << G4endl;
  }
}    