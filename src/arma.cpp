
#include "arma.h"
#include "rolha.h"
#include <GL/glut.h>


/*
 * Método que desenha a arma na tela. A arma é composta
 * por duas partes:
 *  - O cano de onde a rolha é atirada
 *  - A base de madeira que envolve a parte de baixo do cano
 */
void Arma::desenha()
{
		glPushMatrix();

			glTranslatef(0.0f, -15.0f, 400.0f);
			glRotatef(ang_y, 0.0f, 1.0f, 0.0f);
			glRotatef(ang_x, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, -120.0f);
			glScalef(3.0f, 3.0f, 1.0f);

			//madeira do cano da arma
			glColor3f(1,0,0);
			//base1 da madeira
			glBegin(GL_POLYGON);
			//glBegin(GL_LINE_LOOP);
				glVertex3f(0.86f, 0.0f, 120.0f);
				glVertex3f(1.16f, 0.0f, 120.0f);
				glVertex3f(1.16f, -0.8f, 120.0f);
				glVertex3f(0.0f, -1.3f, 120.0f);
				glVertex3f(-1.16f, -0.8f, 120.0f);
				glVertex3f(-1.16f, 0.0f, 120.0f);
				glVertex3f(-0.86f, 0.0f, 120.0f);
				glVertex3f(-0.86f, -0.5f, 120.0f);
				glVertex3f(0.0f, -1.0f, 120.0f);
				glVertex3f(0.86f, -0.5f, 120.0f);
			glEnd();

			//base2 da madeira
			glBegin(GL_POLYGON);
			//glBegin(GL_LINE_LOOP);
				glVertex3f(0.86f, 0.0f, 60.0f);
				glVertex3f(1.16f, 0.0f, 60.0f);
				glVertex3f(1.16f, -0.8f, 60.0f);
				glVertex3f(0.0f, -1.3f, 60.0f);
				glVertex3f(-1.16f, -0.8f, 60.0f);
				glVertex3f(-1.16f, 0.0f, 60.0f);
				glVertex3f(-0.86f, 0.0f, 60.0f);
				glVertex3f(-0.86f, -0.5f, 60.0f);
				glVertex3f(0.0f, -1.0f, 60.0f);
				glVertex3f(0.86f, -0.5f, 60.0f);
			glEnd();

			//liga as bases da madeira
			glBegin(GL_QUADS);
			//glBegin(GL_LINES);
/*
				glVertex3f(0.0f, 0.0f, -100000.0f);
				glVertex3f(0.0f, 0.0f, 500.0f);
*/
				glVertex3f(0.86f, 0.0f, 120.0f);
				glVertex3f(0.86f, 0.0f, 60.0f);
				glVertex3f(1.16f, 0.0f, 60.0f);
				glVertex3f(1.16f, 0.0f, 120.0f);

				glVertex3f(1.16f, 0.0f, 60.0f);
				glVertex3f(1.16f, 0.0f, 120.0f);
				glVertex3f(1.16f, -0.8f, 120.0f);
				glVertex3f(1.16f, -0.8f, 60.0f);

				glVertex3f(1.16f, -0.8f, 120.0f);
				glVertex3f(1.16f, -0.8f, 60.0f);
				glVertex3f(0.0f, -1.3f, 60.0f);
				glVertex3f(0.0f, -1.3f, 120.0f);

				glVertex3f(0.0f, -1.3f, 60.0f);
				glVertex3f(0.0f, -1.3f, 120.0f);
				glVertex3f(-1.16f, -0.8f, 120.0f);
				glVertex3f(-1.16f, -0.8f, 60.0f);

				glVertex3f(-1.16f, -0.8f, 60.0f);
				glVertex3f(-1.16f, -0.8f, 120.0f);
				glVertex3f(-1.16f, 0.0f, 120.0f);
				glVertex3f(-1.16f, 0.0f, 60.0f);

				glVertex3f(-1.16f, 0.0f, 120.0f);
				glVertex3f(-1.16f, 0.0f, 60.0f);
				glVertex3f(-0.86f, 0.0f, 60.0f);
				glVertex3f(-0.86f, 0.0f, 120.0f);

				glVertex3f(-0.86f, 0.0f, 60.0f);
				glVertex3f(-0.86f, 0.0f, 120.0f);
				glVertex3f(-0.86f, -0.5f, 120.0f);
				glVertex3f(-0.86f, -0.5f, 60.0f);

				glVertex3f(-0.86f, -0.5f, 120.0f);
				glVertex3f(-0.86f, -0.5f, 60.0f);
				glVertex3f(0.0f, -1.0f, 60.0f);
				glVertex3f(0.0f, -1.0f, 120.0f);

				glVertex3f(0.0f, -1.0f, 60.0f);
				glVertex3f(0.0f, -1.0f, 120.0f);
				glVertex3f(0.86f, -0.5f, 120.0f);
				glVertex3f(0.86f, -0.5f, 60.0f);

				glVertex3f(0.86f, -0.5f, 60.0f);
				glVertex3f(0.86f, -0.5f, 120.0f);
				glVertex3f(0.86f, 0.0f, 120.0f);
				glVertex3f(0.86f, 0.0f, 60.0f);
			glEnd();

			//cano da arma
			glColor3f(0,0,0);
			//base 1 do cano
			//glBegin(GL_POLYGON);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0f, 1.0f, 0.0f);
				glVertex3f(0.86f, 0.5f, 0.0f);
				glVertex3f(0.86f, -0.5f, 0.0f);
				glVertex3f(0.0f, -1.0f, 0.0f);
				glVertex3f(-0.86f, -0.5f, 0.0f);
				glVertex3f(-0.86f, 0.5f, 0.0f);
			glEnd();

			// base 2 do cano
			//glBegin(GL_POLYGON);
			glBegin(GL_LINE_LOOP);
				glVertex3f(0.0f, 1.0f, 120.0f);
				glVertex3f(0.86f, 0.5f, 120.0f);
				glVertex3f(0.86f, -0.5f, 120.0f);
				glVertex3f(0.0f, -1.0f, 120.0f);
				glVertex3f(-0.86f, -0.5f, 120.0f);
				glVertex3f(-0.86f, 0.5f, 120.0f);
			glEnd();

			//liga as bases do cano
			glColor3f(1,1,1);
			glBindTexture(GL_TEXTURE_2D, tex_1);
			glBegin(GL_QUADS);
			//glBegin(GL_LINES);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.86f, 0.5f, 0.0f);


				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.86f, 0.5f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.86f, -0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.86f, -0.5f, 0.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.86f, -0.5f, 120.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.86f, -0.5f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0f, -1.0f, 120.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f, -1.0f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.86f, -0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.86f, -0.5f, 0.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.86f, -0.5f, 120.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.86f, -0.5f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.86f, 0.5f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.86f, 0.5f, 120.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.86f, 0.5f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
			glEnd();

			glColor3f(0,0,0);
			glBegin(GL_LINES);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.86f, 0.5f, 0.0f);


				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.86f, 0.5f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.86f, -0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.86f, -0.5f, 0.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.86f, -0.5f, 120.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.86f, -0.5f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0f, -1.0f, 120.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0f, -1.0f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0f, -1.0f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.86f, -0.5f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.86f, -0.5f, 0.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.86f, -0.5f, 120.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.86f, -0.5f, 0.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.86f, 0.5f, 0.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.86f, 0.5f, 120.0f);

				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.86f, 0.5f, 0.0f);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.86f, 0.5f, 120.0f);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0f, 1.0f, 120.0f);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0f, 1.0f, 0.0f);
			glEnd();

			//mira do cano da arma

			glBegin(GL_LINES);
				glVertex3f(0.125f, 0.75f, 2.0f);
				glVertex3f(0.125f, 1.2f, 2.0f);

				glVertex3f(-0.125f, 0.75f, 2.0f);
				glVertex3f(-0.125f, 1.2f, 2.0f);

				glVertex3f(0.0f, 1.0f, 2.0f);
				glVertex3f(0.125f, 0.75f, 2.0f);

				glVertex3f(-0.125f, 0.75f, 2.0f);
				glVertex3f(0.0f, 1.0f, 2.0f);

				glVertex3f(0.125f, 1.2f, 2.0f);
				glVertex3f(-0.125f, 1.2f, 2.0f);

				glVertex3f(0.0f, 1.2f, 3.0f);
				glVertex3f(0.125f, 1.2f, 2.0f);

				glVertex3f(0.0f, 1.2f, 3.0f);
				glVertex3f(-0.125f, 1.2f, 2.0f);

				glVertex3f(0.0f, 1.2f, 3.0f);
				glVertex3f(0.0f, 1.0f, 5.0f);

				glVertex3f(0.0f, 1.0f, 5.0f);
				glVertex3f(0.125f, 0.75f, 2.0f);

				glVertex3f(0.0f, 1.0f, 5.0f);
				glVertex3f(-0.125f, 0.75f, 2.0f);
			glEnd();

		glPopMatrix();
}


/*
 * Move a arma de acordo com os movimentos do mouse
 */
void Arma::moveArma(float x, float y)
{

	//guarda os movimentos para referência futura
	ang_x = y;
	ang_y = x;

	//move a rolha da arma da mesma forma
	if (rolha_atual<3)
		rolhas[rolha_atual].moveRolha(x,y);

}


/*
 * Atira a arma. A rolha atual no cano é lançada
 * usando o seu próprio método 'atira' e então outra
 * rolha é carregada no seu lugar, se houver outra.
 */
void Arma::atira()
{

	if (rolha_atual<3) {
		//atira a rolha que está no cano
		rolhas[rolha_atual].atira();
		rolha_atual++;
		//se sobrarem rolhas na bancada, carregue a próxima no cano
		if (rolha_atual<3)
			rolhas[rolha_atual].carrega_na_arma(),
			rolhas[rolha_atual].moveRolha(ang_y,ang_x);
	}

}


/*
 * Devolve a arma para o seu estado inicial,
 * com 3 rolhas disponíveis.
 */
void Arma::reinicia_arma()
{

	//todas as rolhas voltam para a bancada
	for(int i=0; i<3; i++)
		rolhas[i].para_a_bancada();
	//e a primeira vai para o cano
	rolhas[0].carrega_na_arma();
	rolhas[0].moveRolha(ang_y,ang_x);

	rolha_atual = 0;

}

