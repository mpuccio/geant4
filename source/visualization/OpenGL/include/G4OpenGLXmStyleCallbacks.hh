// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmStyleCallbacks.hh,v 1.2.8.1 1999/12/07 20:53:21 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
//

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#ifndef G4OPENGLXMSTYLECALLBACKS_HH
#define G4OPENGLXMSTYLECALLBACKS_HH

#include "G4OpenGLXmViewer.hh"

void drawing_style_callback (Widget w, 
			     XtPointer clientData, 
			     XtPointer callData);

void rep_style_callback (Widget w, 
			 XtPointer clientData, 
			 XtPointer callData);

void background_color_callback (Widget w, 
				XtPointer clientData, 
				XtPointer callData);

void projection_callback (Widget w, 
			  XtPointer clientData, 
			  XtPointer callData);

#endif

#endif