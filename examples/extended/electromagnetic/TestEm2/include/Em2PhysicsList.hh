// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em2PhysicsList.hh,v 1.1.4.1 1999/12/07 20:46:56 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em2PhysicsList_h
#define Em2PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em2PhysicsList: public G4VUserPhysicsList
{
  public:
    Em2PhysicsList();
   ~Em2PhysicsList();

  protected:
    // Construct particles
    void ConstructParticle();
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBarions(); 
     
  public:
    void SetCuts();
        
  protected:
    // Construct processes and register them
    void ConstructProcess();  
    void ConstructGeneral();
    void ConstructEM();
};

#endif
