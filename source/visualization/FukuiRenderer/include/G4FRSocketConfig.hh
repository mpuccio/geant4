// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4FRSocketConfig.hh,v 1.2.8.1 1999/12/07 20:53:09 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
////////////////////////////////
///// G4FRSocketConfig.h   /////
////////////////////////////////

//=================//
#ifdef G4VIS_BUILD_DAWN_DRIVER
//=================//


#if !defined SOCKET_CONFIG_H
#define SOCKET_CONFIG_H

//----------------------------------//
// Select one from the List below ////
//----------------------------------//

#if defined SOCKET_IRIX_SOLARIS
 #define     FR_SOCKET_IRIX_SOLARIS
#else 
 #define     FR_SOCKET_DEFAULT
#endif


///// NOT IMPLEMENTED //////////
//#define     SOCKET_NT       
                      


#endif
#endif // G4VIS_BUILD_DAWN_DRIVER