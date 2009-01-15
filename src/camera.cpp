
#include "camera.h"

#include <GL/glut.h>

/*
 * Desenha a câmera na cena
 * Como a câmera não é algo realmente visual na cena,
 * tudo o que ela faz é refazer a matrix ModelView
 * de forma que os outros objetos da cena se comportem adequadamente.
 */
void Camera::desenha ()
{

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam_pos[0],cam_pos[1],cam_pos[2],
		cam_olha[0],cam_olha[1],cam_olha[2],
		cam_orient[0],cam_orient[1],cam_orient[2]);

}

/*
 * Coloca a câmera na posição x,y.
 * Esse método é chamado quando o mouse se move
 * para que a câmera acompanhe o movimento do mouse.
 */
void Camera::moveCamera (GLint x, GLint y)
{

	cam_olha[0] = x;
	cam_olha[1] = y;

	//coloca a câmera na nova posição correta
	this->desenha();

}

/*
 * Coloca a câmera no eixo X para uma visão lateral.
 * (apenas para teste)
 */
void Camera::x()
{

	cam_pos[0] = 550; cam_pos[1] = 0; cam_pos[2] = 0;
	cam_orient[0] = 0; cam_orient[1] = 1; cam_orient[2] = 0;
	this->desenha();

}

/*
 * Coloca a câmera no eixo Y para uma visão lateral.
 * (apenas para teste)
 */
void Camera::y()
{

	cam_pos[0] = 0; cam_pos[1] = 550; cam_pos[2] = 0;
	cam_orient[0] = 0; cam_orient[1] = 0; cam_orient[2] = -1;
	this->desenha();

}

/*
 * Coloca a câmera no eixo Z para uma visão lateral.
 * (apenas para teste)
 */
void Camera::z()
{

	cam_pos[0] = 0; cam_pos[1] = 0; cam_pos[2] = 550;
	cam_orient[0] = 0; cam_orient[1] = 1; cam_orient[2] = 0;
	this->desenha();

}

