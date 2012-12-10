/**
 * This module is part of the "Terrains" series.
 * Module No.: 056
 *
 * Wireframe/solid model & effect of the scaling parameters.
 * Lights.
 */
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include "camera.h"
#include "map.h"
#include "alg.h"
#include <stdio.h>




/*
 * Definitions
 */
#ifndef max
#define max(x,y)	((x>y)?x:y)
#endif

/* 
 * Menu options
 */
enum 
{
	MENU_AMBIENT_LIGHT = 1,
	MENU_DIFFUSE_LIGHT,
	MENU_EXIT,
	MENU_WIREFRAME,
	MENU_SOLID,
	MENU_FPF,
	MENU_ALTITUDE
};

/*
 * "Constants"
 */
const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;
const GLfloat BASIC_ANGLE = 5.0f;

/*
 * Global variables
 */

/* Scaling factors */
int DISTANCE_FACTOR = 90;
int HEIGHT_FACTOR = 5;

/* Aspect ratio of the window */
GLdouble aspectRatio;

/* Basic dimension */
int BASIC_DIMENSION;

/* The world size */
int WORLD_SIZE;

/* The map */
unsigned char **mapData;
int mapWidth;
int mapHeight;

/* The actual model */
GLfloat **X, **Y, **Z;		/* Vertices */
GLfloat **Nx, **Ny, **Nz;	/* Normals */

/* The camera */
Camera theCamera;


/* Lighting values */  
M3DVector4f lightAmbient;
M3DVector4f lightDiffuse;
M3DVector4f	lightPos;

GLuint   texture[3];

/* Flight Flags  */
int speed, firstPerson = 1;
int altView = 0;

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

void setPerspectiveProjection(GLdouble aspectRatio);
void resetCamera(Camera *camera);
void calcModelCoordinates();

void addNormal(M3DVector3f n, int r, int c);
GLfloat** createMatrix(int m, int n);
void destroyMatrix(GLfloat **A, int m);
void drawText(GLint x, GLint y, char* s, GLfloat r, GLfloat g, GLfloat b);
void LoadGLTextures();
void crashTest();
void outOfBoundsTest();
void firstPersonMode();
void altitudeMode();
void displayImage(int texture);

/*
 * Function definitions
 */
 
/**
 * Creates a m by n matrix.
 * @pre Number of rows is positive (m>0).
 * @pre Number of columns is positive (n>0).
 * @param m Number of rows in the matrix.
 * @param n Number of columns in the matrix.
 * @return Reference to the matrix.
 */
GLfloat** createMatrix(int m, int n)
{
    GLfloat **A;
    int i;

        /* Allocate the memory for the matrix */
    A = (GLfloat**)calloc(m, sizeof(GLfloat*));
    for (i=0; i<m; i++) {
        A[i] = (GLfloat*)calloc(n, sizeof(GLfloat));
    }

    return A;
}

/**
 * Destroys a matrix. Note: It's not necessary to reset the original
 * pointer to NULL.
 * @pre Valid matrix (non-null).
 * @param m Number of rows in the matrix.
 * @param A Reference to the matrix.
 */
void destroyMatrix(GLfloat **A, int m)
{
    int i;

    /* Deallocate the memory of the matrix */
    for (i=0; i<m; i++) {
        free(A[i]);
    }
    free(A);
}

/*
 * Initialize the app.
 */
void initialize()
{
	float pos;
	
	/* Create the map */
	mapData = mapCreate("earthgs.tga", &mapWidth, &mapHeight);
	
	/* Print report */
	printf("\n\nTerrain Modeling\n");
	printf("================\n");	
	printf("Width: %d\n", mapWidth);	
	printf("Height: %d\n", mapHeight);	
	printf("No. of triangles: %d\n", ((mapWidth - 1)*(mapHeight - 1)*2));	
	printf("No. of vertices: %d\n", (mapWidth*mapHeight));		
		
	/* Calculate basic dimensions */
	WORLD_SIZE = mapWidth * DISTANCE_FACTOR;
	BASIC_DIMENSION = WORLD_SIZE / 100;
	pos = WORLD_SIZE/2.0f;
	
	/* Initialize light values */
	m3dLoadVector4f(lightAmbient, 0.3f, 0.3f, 0.3f, 1.0f); 
	m3dLoadVector4f(lightDiffuse, 0.7f, 0.7f, 0.7f, 1.0f); 	
	m3dLoadVector4f(lightPos, pos, WORLD_SIZE, pos, 1.0f);	
	
	/* Initialize aspect ratio */
	aspectRatio = 1.0;
 	
    	/* Initialize the camera */
    	resetCamera(&theCamera);
	
	/* Create the model */
	X = createMatrix(mapHeight, mapWidth);
	Y = createMatrix(mapHeight, mapWidth);	
	Z = createMatrix(mapHeight, mapWidth);	
	Nx = createMatrix(mapHeight, mapWidth);
	Ny = createMatrix(mapHeight, mapWidth);	
	Nz = createMatrix(mapHeight, mapWidth);	
	
	/* Calculate the model coordinates */
	calcModelCoordinates();

	/* Read in and create texture */
		
	
	
	
	
	
}

void LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
    
 
 


}
 


/*
 * "Finalize" the app.
 */
void finalize()
{
	/* Destroy the map */
	mapDestroy(mapData, mapHeight);
	
	/* Destroy the model */
	destroyMatrix(X, mapHeight);
	destroyMatrix(Y, mapHeight);	
	destroyMatrix(Z, mapHeight);	
	destroyMatrix(Nx, mapHeight);
	destroyMatrix(Ny, mapHeight);	
	destroyMatrix(Nz, mapHeight);	
}


/*
 * Resets the camera.
 */
void resetCamera(Camera *camera)
{
	M3DVector4f k = { 0.0f, 0.0f, -1.0f, 0.0f };
	
    /* Initialize the camera */
    m3dLoadVector3f(camera->position, 402, 3200.0f, 5263);
    m3dLoadVector3f(camera->target, 0.0f, 3000.0f, 0);

    m3dLoadIdentity44f(camera->basis);
	m3dSetMatrixColumn44f(camera->basis, k, 2);
}



/*
 * Add the contribution to the normal vector.
 */
void addNormal(M3DVector3f n, int r, int c)
{
	M3DVector3f nc, nr;
	
	m3dLoadVector3f(nc, Nx[r][c], Ny[r][c], Nz[r][c]);
	m3dAddVectors3f(nr, nc, n);
	m3dNormalizeVector3f(nr); 
	Nx[r][c] = m3dGetVectorX(nr);
	Ny[r][c] = m3dGetVectorY(nr);
	Nz[r][c] = m3dGetVectorZ(nr);
}

/*
 * Calculates the model coordinates 
 */
void calcModelCoordinates()
{
	M3DVector3f v1, v2, v3, v4, n;
	GLfloat dx = -(mapWidth * DISTANCE_FACTOR)/2.0f;
	GLfloat dz = -(mapHeight * DISTANCE_FACTOR)/2.0f;	
	int i, j;
	
	/* Vertices */
	for (i=0; i<mapHeight; i++) {
		for (j=0; j<mapWidth; j++) {
			X[i][j] = j*DISTANCE_FACTOR + dx;
			Y[i][j] = mapData[i][j]*HEIGHT_FACTOR;
			Z[i][j] = i*DISTANCE_FACTOR + dz;
			
			Nx[i][j] = Ny[i][j] = Nz[i][j] = 0.0f;
		}
	}
	
	/* Normals */
	for (i=0; i<mapHeight - 1; i++) {
		for (j=0; j<mapWidth - 1; j++) {		
			m3dLoadVector3f(v1, X[i][j], Y[i][j], Z[i][j]);
			m3dLoadVector3f(v2, X[i+1][j], Y[i+1][j], Z[i+1][j]);
			m3dLoadVector3f(v3, X[i][j+1], Y[i][j+1], Z[i][j+1]);		
			m3dLoadVector3f(v4, X[i+1][j+1], Y[i+1][j+1], Z[i+1][j+1]);					

			/* First triangle */
			m3dFindNormal3f(n, v1, v2, v3);
			addNormal(n, i, j); 		
			addNormal(n, i + 1, j); 					
			addNormal(n, i, j + 1); 			

			/* Second triangle */
			m3dFindNormal3f(n, v3, v2, v4);
			addNormal(n, i, j + 1); 		
			addNormal(n, i + 1, j); 					
			addNormal(n, i + 1, j + 1); 			
		}
	}	
}

/*
 * Paints the model.
 */
void paintModel()
{
	int i, j;
	
    /* Taking care of the viewing/camera transformation */
    glPushMatrix();

	/* Bring the light! */
	glPushMatrix(); 
	glTranslatef(lightPos[0], lightPos[1], lightPos[2]); 
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glPopMatrix();
	
	/* Draw the terrain */
	glColor3f(0.8f, 0.6f, 0.6f);
	for (i=0; i<mapHeight - 1; i++) {
		glBegin(GL_TRIANGLE_STRIP);	
		for (j=0; j<mapWidth; j++) {
			
			glNormal3f(Nx[i][j], Ny[i][j], Nz[i][j]);
			glVertex3f(X[i][j], Y[i][j], Z[i][j]);
			
			glNormal3f(Nx[i][j], Ny[i+1][j], Nz[i+1][j]);			
			glVertex3f(X[i][j], Y[i+1][j], Z[i+1][j]);			
		}
		glEnd();
	}
	
    glPopMatrix();

}




//handles the collision detection of our plane and the terrain
void crashTest(){

	int i, j, crashed;
        crashed = 0;
	for (i=0; i<mapHeight; i++) {
	    for (j=0; j<mapWidth; j++) {
		   if(Y[i][j] >= theCamera.position[1]){
			crashed = 1;
		   }
			
	     }
	}
	if(crashed == 1){
		displayImage(0);
	}
	
	glutPostRedisplay();
}




//displays the out of bounds image if we've traveled past the world edge
void outOfBoundsTest(){
	
   /*********************************************************************************/

	if(theCamera.position[0] <=   X[0][0] || theCamera.position[0] >=  X[mapHeight-1][mapWidth-1] || theCamera.position[1] <=   Y[0][0] || theCamera.position[1] >=  Y[mapHeight-1][mapWidth-1] || theCamera.position[2] <=   Z[0][0] || theCamera.position[2] >=  Z[mapHeight-1][mapWidth-1] ){
		displayImage(1);
	}
	
	glutPostRedisplay();
}	




//display the given texture in the entire window
void displayImage(int tex){

	speed = 0;
	firstPerson = 0;

	glBindTexture(GL_TEXTURE_2D, texture[tex]);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	theCamera.position[0] = 4000.0f;
	theCamera.position[1] = -12000.f;
	theCamera.position[2] = 17200.f;
	theCamera.target[0] = 4000.0f;
	theCamera.target[1] = -12000.0f;
	theCamera.target[2] = 10000.0f;
	glBegin (GL_QUADS);
		glTexCoord2f (0.0, 0.0);
		glVertex3f (0.0, -16000.0, 10000.0);
		glTexCoord2f (1.0, 0.0);
		glVertex3f (8000.0, -16000.0, 10000.0);
		glTexCoord2f (1.0, 1.0);
		glVertex3f (8000.0, -8000.0, 10000.0);
		glTexCoord2f (0.0, 1.0);
		glVertex3f (0.0, -8000.0, 10000.0);
	glEnd (); 

}

//set the world to be explored in first person
void firstPersonMode(){
	firstPerson = 1;
	altView = 0;
	resetCamera(&theCamera);
	glutPostRedisplay();
}


//sets the window to display a rotating view of the whole map
void altitudeMode(){
	firstPerson = 0;
	altView = 1;
    	theCamera.position[0] = WORLD_SIZE / 2.0f;
	theCamera.position[1] = WORLD_SIZE;
	theCamera.position[2] = 2*WORLD_SIZE;

    	theCamera.target[0] = 0.0f;
	theCamera.target[1] = 0.0f;
	theCamera.target[2] = 0.0f;
	
	cmrTurn(&theCamera, X_LOCAL_AXIS, -25.0f);	
	glutPostRedisplay();
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

    /* Perform collision and out of bounds testing if in First Person Mode*/
    if(firstPerson == 1){

    	crashTest();
	//outOfBoundsTest();
     }	

    /* Rotate our terrain if in Altitude mode */
    if(altView == 1){
	
    }


    /* Display text info */
    char displayInfo[80] = "Current Position - X: ";
    char distance[6];
    snprintf(distance, sizeof distance, "%f", theCamera.position[0]);
    strcat(displayInfo, distance);
    strcat(displayInfo, " Y: ");
    snprintf(distance, sizeof distance, "%f", theCamera.position[1]);
    strcat(displayInfo, distance);
    strcat(displayInfo, " Z: ");
    snprintf(distance, sizeof distance, "%f", theCamera.position[2]);
    strcat(displayInfo, distance);
    drawText(10, glutGet(GLUT_WINDOW_HEIGHT) - 20, displayInfo, 1.0f, 1.0f, 1.0f);

    char factorInfo[30] = "Height Factor: ";  
    snprintf(distance, sizeof distance, "%d", HEIGHT_FACTOR);
    strcat(factorInfo, distance);
    strcat(factorInfo, "     Width Factor: ");
    snprintf(distance, sizeof distance, "%d", DISTANCE_FACTOR);
    strcat(factorInfo, distance);
    drawText(10, glutGet(GLUT_WINDOW_HEIGHT) - 40, factorInfo, 1.0f, 1.0f, 1.0f);
	
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

	/* Enable lighting */ 
	glEnable(GL_LIGHTING); 

	/* Set properties for light */
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse); 	

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos); 
	glEnable(GL_LIGHT0);
	
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);			

	/* Rescale normals to unit length */
	glEnable(GL_NORMALIZE); 
}

/*
 * Resizes the window.
 * @param w Width of the window.
 * @param h Height of the window.
 */
void ChangeSize(GLsizei w, GLsizei h)
{
    /* Prevent a divide by zero, when window is too short you cant make a
     * window of zero width)
     */
    if (h == 0)
    	h = 1;
	
    /* Set the viewport to be the entire window */
    glViewport(0, 0, w, h);
	
    /* Calculate the aspect ratio of the window */
    aspectRatio = (GLfloat)w / (GLfloat)h;
	
    /* Set the projection */
	setPerspectiveProjection(aspectRatio);
	
    /* Look at... */
    cmrLookAt(&theCamera);
}

/*
 * Sets the perspective projection.
 * @param aspectRatio Aspect ratio of the window.
 */
void setPerspectiveProjection(GLdouble aspectRatio)
{
    GLdouble zNear = 1.0;
    GLdouble zFar = 5*WORLD_SIZE;
    GLdouble angle = 45.0;

    /* Select the projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
    /* Set the projection */
    gluPerspective(angle, aspectRatio, zNear, zFar);
	
    /* Select the modelview matrix */
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
	if (key >= '1' && key <= '9') {
		BASIC_DIMENSION = (key - '0')*(WORLD_SIZE / 100);
	}
    else if (key == 'r') {
        /* Reset visualization parameters */
		firstPersonMode();
		altView = 0;
				
    }
	else if (cmrIsCtrlKey(key)) {
		/* Process camera ctrl key */
		if(firstPerson == 1){
			cmrProcessCtrlKey(&theCamera, key, 
			cmrIsMoveCtrlKey(key) ? BASIC_DIMENSION : BASIC_ANGLE);
		}
	}
	else if (key == '+') {
		HEIGHT_FACTOR++;
		WORLD_SIZE = max(mapWidth*DISTANCE_FACTOR, 255*HEIGHT_FACTOR);
		BASIC_DIMENSION = WORLD_SIZE / 100;
		calcModelCoordinates();
		setPerspectiveProjection(aspectRatio);
	}
	else if (key == '-') {
		HEIGHT_FACTOR--;
		if (HEIGHT_FACTOR <= 1)
			HEIGHT_FACTOR = 1;
		WORLD_SIZE = max(mapWidth*DISTANCE_FACTOR, 255*HEIGHT_FACTOR);			
		BASIC_DIMENSION = WORLD_SIZE / 100;
		calcModelCoordinates();
		setPerspectiveProjection(aspectRatio);		
	}
	else if (key == '>') {
		DISTANCE_FACTOR++;
		WORLD_SIZE = max(mapWidth*DISTANCE_FACTOR, 255*HEIGHT_FACTOR);		
		BASIC_DIMENSION = WORLD_SIZE / 100;
		calcModelCoordinates();
		setPerspectiveProjection(aspectRatio);		
	}
	else if (key == '<') {
		DISTANCE_FACTOR--;
		if (DISTANCE_FACTOR <= 10)
			DISTANCE_FACTOR = 10;
		WORLD_SIZE = max(mapWidth*DISTANCE_FACTOR, 255*HEIGHT_FACTOR);			
		BASIC_DIMENSION = WORLD_SIZE / 100;
		calcModelCoordinates();
		setPerspectiveProjection(aspectRatio);		
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
		case MENU_FPF:
			firstPersonMode();
			break;
		case MENU_ALTITUDE:
			altitudeMode();
			break;
		case MENU_AMBIENT_LIGHT:
			glColorMaterial(GL_FRONT, GL_AMBIENT);
			glEnable(GL_COLOR_MATERIAL);	
			break;
		case MENU_DIFFUSE_LIGHT:
			glColorMaterial(GL_FRONT, GL_DIFFUSE);
			glEnable(GL_COLOR_MATERIAL);		
			break;
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
	glutAddMenuEntry("First Person Mode", MENU_FPF);
	glutAddMenuEntry("Altitude Mode", MENU_ALTITUDE);
	glutAddMenuEntry("Wireframe", MENU_WIREFRAME);
	glutAddMenuEntry("Solid", MENU_SOLID);
	glutAddMenuEntry("Ambient Lighting", MENU_AMBIENT_LIGHT);
	glutAddMenuEntry("Diffuse Lighting", MENU_DIFFUSE_LIGHT);
	glutAddMenuEntry("Exit", MENU_EXIT);
		
	return menu;
}

/* Draws the given string at the given window x,y coordinaties with the given RGB color */
void drawText(GLint x, GLint y, char* s, GLfloat r, GLfloat g, GLfloat b)
{
    int lines;
    char* p;

    glMatrixMode(GL_PROJECTION);
     glPushMatrix();
     glLoadIdentity();
     glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 
	    0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
     glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glLoadIdentity();
      glColor3f(r,g,b);
      glRasterPos2i(x, y);
      for(p = s, lines = 0; *p; p++) {
	  if (*p == '\n') {
	      lines++;
	      glRasterPos2i(x, y-(lines*18));
	  }
	  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
      }
      glPopMatrix();
     glMatrixMode(GL_PROJECTION);
     glPopMatrix();
     glMatrixMode(GL_MODELVIEW);
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
    glEnable(GL_TEXTURE_2D);
    initialize();
    LoadGLTextures();
	
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




