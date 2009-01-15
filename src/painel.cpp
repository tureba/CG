
#include "painel.h"

#include <GL/glut.h>


/*
 * Mostra o painel com a contagem de rolhas
 */
void Painel::desenha()
{
	glPushMatrix();
		glLoadIdentity();

		glColor3f(1,1,1);
		glTranslatef(0.50f,-0.37f,-1.0f);
		glScalef(0.1f,0.1f,1.0f);

		//escolhe a textura que mostra a contagem certa de rolhas
		switch(tiros) {

		case 0:
			glBindTexture(GL_TEXTURE_2D, tex_1);
			break;

		case 1:
			glBindTexture(GL_TEXTURE_2D, tex_2);
			break;

		case 2:
			glBindTexture(GL_TEXTURE_2D, tex_3);
			break;

		case 3:
			glBindTexture(GL_TEXTURE_2D, tex_4);
			break;

		default:
			break;
		}
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.25f,-0.25f,0.0f);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.25f,-0.25f,0.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.25f,0.25f,0.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.25f,0.25f,0.0f);
		glEnd();
		
	glPopMatrix();
}


/*
 * Diminui a contagem de rolhas
 */
void Painel::atualiza()
{
	if(tiros > 0) tiros--;
}


/*
 * Reinicia o estado original do jogo,
 * ou seja, 3 tiros
 */
void Painel::reinicia()
{
	tiros = 3;
}

