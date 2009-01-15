
#include "premio.h"

#include <GL/glut.h>

/*
 * Desenha os prêmios e o painel de prêmios
 */
void Premio::desenha()
{
	glPushMatrix();
		glColor3f(1,1,1);
		//desenha os prêmios nas posições certas
		switch(nro_premios){
			case 3:
				glPushMatrix();
					glTranslatef(100,115,-380);
					glBindTexture(GL_TEXTURE_2D, premio);
					glBegin(GL_QUADS);
						glTexCoord2f(1.0f, 1.0f);	glVertex3f(15,0,0);
						glTexCoord2f(0.0f, 1.0f);	glVertex3f(-15,0,0);
						glTexCoord2f(0.0f, 0.0f);	glVertex3f(-15,60,0);
						glTexCoord2f(1.0f, 0.0f);	glVertex3f(15,60,0);
					glEnd();
				glPopMatrix();

			case 2:
				glPushMatrix();
					glTranslatef(0,115,-380);
					glBindTexture(GL_TEXTURE_2D, premio);
					glBegin(GL_QUADS);
						glTexCoord2f(1.0f, 1.0f);	glVertex3f(15,0,0);
						glTexCoord2f(0.0f, 1.0f);	glVertex3f(-15,0,0);
						glTexCoord2f(0.0f, 0.0f);	glVertex3f(-15,60,0);
						glTexCoord2f(1.0f, 0.0f);	glVertex3f(15,60,0);
					glEnd();
				glPopMatrix();

			case 1:
				glPushMatrix();
					glTranslatef(-100,115,-380);
					glBindTexture(GL_TEXTURE_2D, premio);
					glBegin(GL_QUADS);
						glTexCoord2f(1.0f, 1.0f);	glVertex3f(15,0,0);
						glTexCoord2f(0.0f, 1.0f);	glVertex3f(-15,0,0);
						glTexCoord2f(0.0f, 0.0f);	glVertex3f(-15,60,0);
						glTexCoord2f(1.0f, 0.0f);	glVertex3f(15,60,0);
					glEnd();
				glPopMatrix();

			default:
				break;
		}
		//textura do painel de prêmios
		switch(nro_premios){
				case 0:
					glBindTexture(GL_TEXTURE_2D, painel_3);
					break;

				case 1:
					glBindTexture(GL_TEXTURE_2D, painel_2);
					break;

				case 2:
					glBindTexture(GL_TEXTURE_2D, painel_1);
					break;

				case 3:
					glBindTexture(GL_TEXTURE_2D, painel_0);
					break;

				default:
					break;
		}
		//aplica a textura sobre um painel
		glPushMatrix();
			glLoadIdentity();
			glTranslatef(-2.4f,-1.96f,-5.0f);
			glScalef(0.01f,0.01f,1.0f);
			glBegin(GL_QUADS);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(25,0,0);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-25,0,0);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-25,25,0);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(25,25,0);
			glEnd();
		glPopMatrix();
	glPopMatrix();
}


/*
 * Retira um prêmio da prateleira e coloca na contagem do usuário
 */
void Premio::retira()
{
	if(nro_premios > 0) nro_premios--;
}


/*
 * Reinicia a contagem de prêmios
 */
void Premio::reinicia()
{
	nro_premios = 3;
}

