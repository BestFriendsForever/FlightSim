/**
 * This module is part of the "Terrains" series.
 * Module No.: 051
 *
 * Wireframe/solid model.
 */
#include <stdlib.h>
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

#include "camera.h"
#include "map.h"
#include <stdio.h>

/*
 * Definitions
 */

/* 
 * Menu options
 */
enum 
{
	MENU_WIREFRAME = 1,
	MENU_SOLID,
	MENU_EXIT
};

/*
 * "Constants"
 */
#define DISTANCE_FACTOR		10
#define HEIGHT_FACTOR		5

const int BASIC_DIMENSION = 10;
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const GLfloat BASIC_ANGLE = 5.0f;

/*
 * Global variables
 */

/* The world size */
int WORLD_SIZE;

/* The map */
unsigned char **mapData;
int mapWidth;
int mapHeight;

/* The camera */
Camera theCamera;

/*
 * Protoypes
 */
void RenderScene();
void SetupRC();
void ChangeSize(GLsizei w, GLsizei h);
void KeyPressedStd(unsigned char key, int x, int y);
int BuildPopupMenu();
void SelectFromMenu(int id);

void paintModel();
void initialize();
void finalize();

void resetCamera(Camera *camera);

/*
 * Function definitions
 */

/*
 * Initialize the app.
 */
void initialize()
{
	float pos;
	
	/* Create the map */
	mapData = mapCreate("3dtech.tga", &mapWidth, &mapHeight);
	
	/* Print report */
	printf("\n\nTerrain Modeling\n");
	printf("================\n");	
	printf("Width: %d\n", mapWidth);	
	printf("Height: %d\n", mapHeight);	
	printf("No. of triangles: %d\n", ((mapWidth - 1)*(mapHeight - 1)*2));	
	printf("No. of vertices: %d\n", (mapWidth*mapHeight));		
		
	/* Calculate basic dimensions */
	WORLD_SIZE = mapWidth*DISTANCE_FACTOR;
	pos = WORLD_SIZE/2.0f;
 	
    /* Initialize the camera */
    resetCamera(&theCamera);
	
}

/*
 * "Finalize" the app.
 */
void finalize()
{
	/* Destroy the map */
	mapDestroy(mapData, mapHeight);
}

/*
 * Resets the camera.
 */
void resetCamera(Camera *camera)
{
	M3DVector4f k = { 0.0f, 0.0f, -1.0f, 0.0f };
	
    /* Initialize the camera */
    m3dLoadVector3f(camera->position, 0.0f, 0.0f, 2*WORLD_SIZE);
    m3dLoadVector3f(camera->target, 0.0f, 0.0f, -WORLD_SIZE);

    m3dLoadIdentity44f(camera->basis);
	m3dSetMatrixColumn44f(camera->basis, k, 2);

	cmrMove(camera, X_GLOBAL_AXIS, WORLD_SIZE / 2.0f);	
	cmrMove(camera, Y_GLOBAL_AXIS, WORLD_SIZE);	
	cmrTurn(camera, X_LOCAL_AXIS, -25.0f);	
}

/*
 * Paints the model.
 */
void paintModel()
{
	int i, j;
	
    /* Taking care of the viewing/camera transformation */
    glPushMatrix();

	/* Draw the terrain */
	glColor3f(0.6f, 0.6f, 0.6f);
	for (i=0; i<mapHeight - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);	
		for (j=0; j<mapWidth; j++) {
			glVertex3f(j*DISTANCE_FACTOR, mapData[i][j]*HEIGHT_FACTOR, i*DISTANCE_FACTOR);
			glVertex3f(j*DISTANCE_FACTOR, mapData[i+1][j]*HEIGHT_FACTOR, (i + 1)*DISTANCE_FACTOR);			
		}
		glEnd();
	}
	
    glPopMatrix();
}

/*
 * Renders the model/scene.
 */
void RenderScene()
{
    /* Clear the color buffer and depth buffer */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    /* Draw the object(s) */
    paintModel();
	
    /* Update the screen */
    glutSwapBuffers();
}

/*
 * Initializes the rendering context.
 */
void SetupRC()
{
   /* Set the background color */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
    /* Set color shading model to flat */
    glShadeModel(GL_SMOOTH);
	
    /* Counter-clockwise polygons are front facing */
    glFrontFace(GL_CCW);
	
    /* Enable depth buffer test */
    glEnable(GL_DEPTH_TEST);
	
    /* Enable culling */
    glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
		
	/* Initial polygon mode */
	glPolygonMode(GL_FRONT, GL_LINE);
}

/*
 * Resizes the window.
 * @param w Width of the window.
 * @param h Height of the window.
 */
void ChangeSize(GLsizei w, GLsizei h)
{
    GLdouble zNear = 1.0;
    GLdouble zFar = 5*WORLD_SIZE;
    GLdouble angle = 45.0;
    GLdouble aspectRatio;
	
    /* Prevent a divide by zero, when window is too short you cant make a
     * window of zero width)
     */
    if (h == 0)
    	h = 1;
	
    /* Set the viewport to be the entire window */
    glViewport(0, 0, w, h);
	
    /* Select the projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
    /* Calculate the aspect ratio of the window */
    aspectRatio = (GLfloat)w / (GLfloat)h;
	
    /* Set the projection */
    gluPerspective(angle, aspectRatio, zNear, zFar);
	
    /* Select the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
    /* Look at... */
    cmrLookAt(&theCamera);
}

/*
 * Callback used for key pressed event.
 * @param key ASCII code of the key.
 * @param x X-coordinate of the mouse in the window.
 * @param y Y-coordinate of the mouse in the window.
 */
void KeyPressedStd(unsigned char key, int x, int y)
{
    /* Check the key pressed */
    if (key == 'r') {
        /* Reset visualization parameters */
		resetCamera(&theCamera);		
    }
	else if (cmrIsCtrlKey(key)) {
		/* Process camera ctrl key */
		cmrProcessCtrlKey(&theCamera, key, 
		cmrIsMoveCtrlKey(key) ? BASIC_DIMENSION : BASIC_ANGLE);
	}
    else if (key == 'x') {
		exit(0);
    }
    else {
		return;
    }
	cmrLookAt(&theCamera);	
    glutPostRedisplay();
}

/*
 * Menu callback.
 * @param id Item id.
 */
void SelectFromMenu(int id)
{
	/* Check item id */
	switch (id) {
		case MENU_WIREFRAME:
			glPolygonMode(GL_FRONT, GL_LINE);
			break;
		case MENU_SOLID:
			glPolygonMode(GL_FRONT, GL_FILL);
			break;
		case MENU_EXIT:
			exit(0);
	}
	
	/* Redisplay the model */
	glutPostRedisplay();
}

/*
 * Creates the popup menu and its items.
 * @return Id of the popup menu.
 */
int BuildPopupMenu()
{
	int menu;
	
	/* Creates the menu */
	menu = glutCreateMenu(SelectFromMenu);
	glutAddMenuEntry("Wireframe", MENU_WIREFRAME);
	glutAddMenuEntry("Solid", MENU_SOLID);
	glutAddMenuEntry("Exit", MENU_EXIT);
	
	return menu;
}

/*
 * Main function.
 * @param argc Number of arguments
 * @param argv Array of arguments
 * @return Status code.
 */
int main (int argc, char **argv)
{
    /* Initialize the app */
    initialize();
	
    /* Initialization process */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Terrain Modeling");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutKeyboardFunc(KeyPressedStd);
	BuildPopupMenu(); 
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
    SetupRC();
	
    /* "Main" loop */
    glutMainLoop();
	
	/* Finalize the app */
	finalize();
	
    return EXIT_SUCCESS;
}
/* End of file -------------------------------------------------------------- */




