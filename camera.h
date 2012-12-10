/**
 * This module implements a simple camera entity for OpenGL apps.
 * In this version, all the transformations are based on the local
 * coordinate system (camera/eye coordinate system).
 */
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "math3d.h"

/*
 * Definitions
 */
#define X_LOCAL_AXIS		0
#define Y_LOCAL_AXIS		1
#define Z_LOCAL_AXIS		2
#define X_GLOBAL_AXIS		3
#define Y_GLOBAL_AXIS		4
#define Z_GLOBAL_AXIS		5

#define MOVE_UP_KEY			'm'
#define MOVE_DOWN_KEY		'n'
#define MOVE_LEFT_KEY		'q'
#define MOVE_RIGHT_KEY		'e'
#define MOVE_FORWARD_KEY	'w'
#define MOVE_BACKWARD_KEY	's'

#define TURN_UP_KEY			'z'
#define TURN_DOWN_KEY		'c'
#define TURN_LEFT_KEY		'a'
#define TURN_RIGHT_KEY		'd'
#define TURN_CCW_KEY		'v'
#define TURN_CW_KEY			'b'

#define TURN_AROUNDX_KEY	'X'
#define TURN_AROUNDY_KEY	'Y'
#define TURN_AROUNDZ_KEY	'Z'

/*
 * Camera
 */
typedef struct
{
    M3DVector3f position;
    M3DVector3f target;
    M3DMatrix44f basis;	
} Camera;

/*
 * Protoypes
 */
int cmrIsCtrlKey(unsigned char key);
int cmrIsMoveCtrlKey(unsigned char key);
int cmrIsTurnCtrlKey(unsigned char key);
void cmrProcessCtrlKey(Camera *camera, unsigned char key, float value);

void cmrLookAt(Camera *camera);
void cmrMove(Camera *camera, int axis, float distance);
void cmrTurn(Camera *camera, int axis, float angle);
void cmrTurnAround(Camera *camera, int axis, float angle);

/* End of file -------------------------------------------------------------- */
#endif

