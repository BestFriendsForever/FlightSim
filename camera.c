/**
 * This module implements a simple camera entity for OpenGL apps.
 * In this version, all the transformations are based on the local
 * coordinate system (camera/eye coordinate system).
 */
#define _CAMERA_C_

#include <stdlib.h>
#include <ctype.h>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

#include "camera.h"

/*
 * Function definitions
 */

/*
 * Checks whether the given key is a camera control key or not. 
 * The "reserved" keys used for the camera manipulation are:
 * MOVE_UP_KEY			'm'
 * MOVE_DOWN_KEY		'n'
 * MOVE_LEFT_KEY		'q'
 * MOVE_RIGHT_KEY		'e'
 * MOVE_FORWARD_KEY		'w'
 * MOVE_BACKWARD_KEY	's'
 * TURN_UP_KEY			'z'
 * TURN_DOWN_KEY		'c'
 * TURN_LEFT_KEY		'a'
 * TURN_RIGHT_KEY		'd'
 * TURN_CCW_KEY			'v'
 * TURN_CW_KEY			'b'
 * TURN_AROUNDX_KEY		'X' 
 * TURN_AROUNDY_KEY		'Y
 * TURN_AROUNDZ_KEY		'Z' 
 * @param key The control key.
 * @return 1 if the key is a camera control key, otherwise 0.
 */
int cmrIsCtrlKey(unsigned char key)
{
	unsigned char lkey = tolower(key);

	/* Pre-check */
	if (key == TURN_AROUNDX_KEY || key == TURN_AROUNDY_KEY || key == TURN_AROUNDZ_KEY)
		return 1;
		
	/* Check the key */
	switch (lkey) {
		case MOVE_UP_KEY:
		case MOVE_DOWN_KEY:
		case MOVE_LEFT_KEY:
		case MOVE_RIGHT_KEY:
		case MOVE_FORWARD_KEY:
		case MOVE_BACKWARD_KEY:
		case TURN_UP_KEY:
		case TURN_DOWN_KEY:
		case TURN_LEFT_KEY:
		case TURN_RIGHT_KEY:
		case TURN_CCW_KEY:
		case TURN_CW_KEY:
			return 1;
	}
	return 0;
}

/*
 * Checks whether the given key is a camera "move" control key or not. 
 * The "reserved" keys used for the camera manipulation are:
 * MOVE_UP_KEY			'm'
 * MOVE_DOWN_KEY		'n'
 * MOVE_LEFT_KEY		'q'
 * MOVE_RIGHT_KEY		'e'
 * MOVE_FORWARD_KEY		'w'
 * MOVE_BACKWARD_KEY	's'
 * @param key The control key.
 * @return 1 if the key is a camera "move" control key, otherwise 0.
 */
int cmrIsMoveCtrlKey(unsigned char key)
{
	unsigned char lkey = tolower(key);

	/* Check the key */
	switch (lkey) {
		case MOVE_UP_KEY:
		case MOVE_DOWN_KEY:
		case MOVE_LEFT_KEY:
		case MOVE_RIGHT_KEY:
		case MOVE_FORWARD_KEY:
		case MOVE_BACKWARD_KEY:
			return 1;
	}
	return 0;
}

/*
 * Checks whether the given key is a camera "turn" control key or not. 
 * The "reserved" keys used for the camera manipulation are:
 * TURN_UP_KEY			'z'
 * TURN_DOWN_KEY		'c'
 * TURN_LEFT_KEY		'a'
 * TURN_RIGHT_KEY		'd'
 * TURN_CCW_KEY			'v'
 * TURN_CW_KEY			'b'
 * TURN_AROUNDX_KEY		'X' 
 * TURN_AROUNDY_KEY		'Y'
 * TURN_AROUNDZ_KEY		'Z' 
 * @param key The control key.
 * @return 1 if the key is a camera "turn" control key, otherwise 0.
 */
int cmrIsTurnCtrlKey(unsigned char key)
{
	unsigned char lkey = tolower(key);

	/* Pre-check */
	if (key == TURN_AROUNDX_KEY || key == TURN_AROUNDY_KEY || key == TURN_AROUNDZ_KEY)
		return 1;
		
	/* Check the key */
	switch (lkey) {
		case TURN_UP_KEY:
		case TURN_DOWN_KEY:
		case TURN_LEFT_KEY:
		case TURN_RIGHT_KEY:
		case TURN_CCW_KEY:
		case TURN_CW_KEY:
			return 1;
	}
	return 0;
}



/*
 * Processes the control key (modifies the camera configuration 
 * based on the control key). This function is used for the local
 * coordinate (camera coordinate) system.
 * @param camera The camera.
 * @param key The control key.
 * @param value Distance or angle used to modify the camera 
 * configuration.
 */
void _cmrProcessCtrlKeyLocal(Camera *camera, unsigned char key, float value)
{
    if (key == MOVE_FORWARD_KEY) {
		/* Move camera forward */ 
		cmrMove(camera, Z_LOCAL_AXIS, value);
	} 
	else if (key == MOVE_BACKWARD_KEY) {
		/* Move camera backward */ 
		cmrMove(camera, Z_LOCAL_AXIS, -value);
	} 
	else if (key == MOVE_LEFT_KEY) {
		/* Move camera left */ 
		cmrMove(camera, X_LOCAL_AXIS, -value);
	} 
	else if (key == MOVE_RIGHT_KEY) {
		/* Move camera right */ 
		cmrMove(camera, X_LOCAL_AXIS, value);
	} 
	else if (key == MOVE_UP_KEY) {
		/* Move camera up */ 
		cmrMove(camera, Y_LOCAL_AXIS, value);
	} 
	else if (key == MOVE_DOWN_KEY) {
		/* Move camera down */ 
		cmrMove(camera, Y_LOCAL_AXIS, -value);
	} 
	else if (key == TURN_LEFT_KEY) {
		/* Turn camera left */ 
		cmrTurn(camera, Y_LOCAL_AXIS, value);
	}
	else if (key == TURN_RIGHT_KEY) {
		/* Turn camera right */ 
		cmrTurn(camera, Y_LOCAL_AXIS, -value);
	} 
	else if (key == TURN_UP_KEY) {
		/* Turn camera up */ 
		cmrTurn(camera, X_LOCAL_AXIS, value);
	} 
	else if (key == TURN_DOWN_KEY) {
		/* Turn camera down */ 
		cmrTurn(camera, X_LOCAL_AXIS, -value);
	} 
	else if (key == TURN_CCW_KEY) {
		/* Turn camera CCW */ 
		cmrTurn(camera, Z_LOCAL_AXIS, -value);
	} 
	else if (key == TURN_CW_KEY) {
		/* Turn camera CW */ 
		cmrTurn(camera, Z_LOCAL_AXIS, value);
	}
}

/*
 * Processes the control key (modifies the camera configuration 
 * based on the control key). This function is used for the global
 * coordinate system.
 * @param camera The camera.
 * @param key The control key.
 * @param value Distance or angle used to modify the camera 
 * configuration.
 */
void _cmrProcessCtrlKeyGlobal(Camera *camera, unsigned char key, float value)
{
	if (key == TURN_AROUNDX_KEY) {
		/* Turn camera around (x) */ 
		cmrTurnAround(camera, X_GLOBAL_AXIS, value);
		return;
	}
	else if (key == TURN_AROUNDY_KEY) {
		/* Turn camera around (y) */ 
		cmrTurnAround(camera, Y_GLOBAL_AXIS, value);
		return;		
	}
	else if (key == TURN_AROUNDZ_KEY) {
		/* Turn camera around (z) */ 
		cmrTurnAround(camera, Z_GLOBAL_AXIS, value);
		return;		
	}
	
	/* Lowercase... */
	key = tolower(key);

    if (key == MOVE_FORWARD_KEY) {
		/* Move camera forward */ 
		cmrMove(camera, Z_GLOBAL_AXIS, value);
	} 
	else if (key == MOVE_BACKWARD_KEY) {
		/* Move camera backward */ 
		cmrMove(camera, Z_GLOBAL_AXIS, -value);
	} 
	else if (key == MOVE_LEFT_KEY) {
		/* Move camera left */ 
		cmrMove(camera, X_GLOBAL_AXIS, -value);
	} 
	else if (key == MOVE_RIGHT_KEY) {
		/* Move camera right */ 
		cmrMove(camera, X_GLOBAL_AXIS, value);
	} 
	else if (key == MOVE_UP_KEY) {
		/* Move camera up */ 
		cmrMove(camera, Y_GLOBAL_AXIS, value);
	} 
	else if (key == MOVE_DOWN_KEY) {
		/* Move camera down */ 
		cmrMove(camera, Y_GLOBAL_AXIS, -value);
	} 
	else if (key == TURN_LEFT_KEY) {
		/* Turn camera left */ 
		cmrTurn(camera, Y_GLOBAL_AXIS, value);
	}
	else if (key == TURN_RIGHT_KEY) {
		/* Turn camera right */ 
		cmrTurn(camera, Y_GLOBAL_AXIS, -value);
	} 
	else if (key == TURN_UP_KEY) {
		/* Turn camera up */ 
		cmrTurn(camera, X_GLOBAL_AXIS, value);
	} 
	else if (key == TURN_DOWN_KEY) {
		/* Turn camera down */ 
		cmrTurn(camera, X_GLOBAL_AXIS, -value);
	} 
	else if (key == TURN_CCW_KEY) {
		/* Turn camera CCW */ 
		cmrTurn(camera, Z_GLOBAL_AXIS, -value);
	} 
	else if (key == TURN_CW_KEY) {
		/* Turn camera CW */ 
		cmrTurn(camera, Z_GLOBAL_AXIS, value);
	}
}
/*
 * Processes the control key (modifies the camera configuration 
 * based on the control key).
 * @param camera The camera.
 * @param key The control key.
 * @param value Distance or angle used to modify the camera 
 * configuration.
 */
void cmrProcessCtrlKey(Camera *camera, unsigned char key, float value)
{
	/* Process the control key */
	if (key >= 'a' && key <= 'z')
		_cmrProcessCtrlKeyLocal(camera, key, value);
	else
		_cmrProcessCtrlKeyGlobal(camera, key, value);
}

/*
 * Sets the OpenGL camera based on the given camera
 * structure.
 * @param camera The camera.
 */
void cmrLookAt(Camera *camera)
{
	M3DVector4f direction;
	
    /* Call glu directly... */
	m3dGetMatrixColumn44f(direction, camera->basis, 1);
    glLoadIdentity();
    gluLookAt(camera->position[0], camera->position[1], camera->position[2],
              camera->target[0], camera->target[1], camera->target[2],
              direction[0], direction[1], direction[2]);
}

/*
 * Moves the camera in the given axis (local) and with a
 * given distance.
 * @param camera The camera.
 * @param axis Axis used to translate the camera.
 * @param distance Amount used to translate the camera.
 */
void cmrMove(Camera *camera, int axis, float distance)
{
	M3DMatrix44f B;
	M3DVector4f d;	
	M3DVector3f v;

	/* Move the camera */
	if (axis <= Z_LOCAL_AXIS) {
		m3dGetMatrixColumn44f(d, camera->basis, axis);
		m3dLoadVector3f(v, m3dGetVectorX(d), m3dGetVectorY(d), m3dGetVectorZ(d));	
		m3dNormalizeVector3f(v);			
	}
	else {
		m3dLoadIdentity44f(B);
		m3dGetMatrixColumn44f(d, B, (axis - X_GLOBAL_AXIS));
		m3dLoadVector3f(v, m3dGetVectorX(d), m3dGetVectorY(d), m3dGetVectorZ(d));
	}

	/* Scale the projected vector */
	m3dScaleVector3f(v, distance);

	/* Change the camera position as well as the target */
	m3dAddVectors3f(camera->position, camera->position, v);
	m3dAddVectors3f(camera->target, camera->target, v);	
}

/*
 * Rotates the camera in the given axis (local) and with a
 * given angle.
 * @param camera The camera.
 * @param axis Axis used to rotate the camera.
 * @param angle Angle used to rotate the camera.
 */
void cmrTurn(Camera *camera, int axis, float angle)
{
	M3DMatrix44f B;
	M3DMatrix44f Ti, T, R, M, m;
	M3DVector4f d, v;
	M3DVector3f t;
	int i;

	/* Make a copy of the camera target */
	m3dCopyVector3f(t, camera->target);

	/* Get direction of rotation */
	if (axis <= Z_LOCAL_AXIS) {
		m3dGetMatrixColumn44f(d, camera->basis, axis);
	}
	else {
		m3dLoadIdentity44f(B);
		m3dGetMatrixColumn44f(d, B, (axis - X_GLOBAL_AXIS));
	}

	/* Calculate the transformation matrices */
	m3dTranslationMatrix44f(Ti, -m3dGetVectorX(camera->position), 
							    -m3dGetVectorY(camera->position), 
							    -m3dGetVectorZ(camera->position));
	m3dRotationMatrix44f(R, m3dDegToRad(angle), m3dGetVectorX(d), 
											    m3dGetVectorY(d), 
												m3dGetVectorZ(d));
	m3dTranslationMatrix44f(T, m3dGetVectorX(camera->position), 
							   m3dGetVectorY(camera->position), 
							   m3dGetVectorZ(camera->position));
	m3dMatrixMultiply44f(m, R, Ti);
	m3dMatrixMultiply44f(M, T, m);
	
	/* Change the target */
	m3dTransformVector3f(camera->target, t, M);
	
	/* Update the basis */
	for (i=0; i<3; i++) {
		if (i == axis)
			continue;
		m3dGetMatrixColumn44f(d, camera->basis, i);
		m3dTransformVector4f(v, d, M);	
		m3dSetMatrixColumn44f(camera->basis, v, i);				
	}
}

/*
 * Rotates the camera around a given axis (global) and with a
 * given angle.
 * @param camera The camera.
 * @param axis Axis used to rotate the camera.
 * @param angle Angle used to rotate the camera.
 */
void cmrTurnAround(Camera *camera, int axis, float angle)
{
	M3DMatrix44f B;
	M3DMatrix44f M;
	M3DVector4f d, v;
	M3DVector3f t, p;
	int i;

	/* Make a copy of the camera target and position */
	m3dCopyVector3f(t, camera->target);
	m3dCopyVector3f(p, camera->position);

	/* Get direction of rotation */
	m3dLoadIdentity44f(B);
	m3dGetMatrixColumn44f(d, B, (axis - X_GLOBAL_AXIS));

	/* Calculate the transformation matrices */
	m3dRotationMatrix44f(M, m3dDegToRad(angle), m3dGetVectorX(d), 
											    m3dGetVectorY(d), 
												m3dGetVectorZ(d));

	/* Change the target and position */
	m3dTransformVector3f(camera->target, t, M);
	m3dTransformVector3f(camera->position, p, M);
	
	/* Update the basis */
	for (i=0; i<3; i++) {
		m3dGetMatrixColumn44f(d, camera->basis, i);
		m3dTransformVector4f(v, d, M);	
		m3dSetMatrixColumn44f(camera->basis, v, i);				
	}
}

/* End of file -------------------------------------------------------------- */




