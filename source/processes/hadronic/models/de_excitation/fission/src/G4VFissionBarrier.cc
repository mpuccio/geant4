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
//
// $Id: G4VFissionBarrier.cc,v 1.4 2006/06/29 20:13:43 gunter Exp $
// GEANT4 tag $Name: geant4-08-02 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Oct 1998)


#include "G4VFissionBarrier.hh"

G4VFissionBarrier::G4VFissionBarrier(const G4VFissionBarrier & )
{
  throw G4HadronicException(__FILE__, __LINE__, "G4VFissionBarrier::copy_constructor meant to not be accessable.");
}


const G4VFissionBarrier & G4VFissionBarrier::operator=(const G4VFissionBarrier & )
{
 throw G4HadronicException(__FILE__, __LINE__, "G4VFissionBarrier::operator= meant to not be accessable.");
 return *this;
}

G4bool G4VFissionBarrier::operator==(const G4VFissionBarrier & ) const 
{
 return false;
}

G4bool G4VFissionBarrier::operator!=(const G4VFissionBarrier & ) const 
{
 return true;
}
