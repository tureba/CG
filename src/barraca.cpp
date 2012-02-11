
#include "barraca.h"

#include <GL/glut.h>


/*
 * Método que desenha a barraca e tudo o que compoe o cenário.
 * Isso inclui:
 *  - Barraca que envolve o cenário
 *  - Bancada sob a arma e o espectador
 *  - Mesas por onde os alvos se movem
 *  - Prateleira de prêmios
 *  - Skydome
 */
void Barraca::desenha ()
{

	glPushMatrix();
	glColor3f(1,1,1);


		//prateleira ===========================

		//face direita
		glBindTexture(GL_TEXTURE_2D, tex_5);
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f,1.0f);	glVertex3f(200,120,-360);
			glTexCoord2f(0.0f,1.0f);	glVertex3f(200,120,-450);
			glTexCoord2f(0.0f,0.0f);	glVertex3f(200,110,-450);
			glTexCoord2f(1.0f,0.0f);	glVertex3f(200,110,-360);
		glEnd();

		//face esquerda
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f,1.0f);	glVertex3f(-200,110,-360);
			glTexCoord2f(0.0f,1.0f);	glVertex3f(-200,110,-450);
			glTexCoord2f(0.0f,0.0f);	glVertex3f(-200,120,-450);
			glTexCoord2f(1.0f,0.0f);	glVertex3f(-200,120,-360);
		glEnd();

		//face de cima
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f,1.0f);	glVertex3f(-200,120,-360);
			glTexCoord2f(0.0f,1.0f);	glVertex3f(-200,120,-450);
			glTexCoord2f(0.0f,0.0f);	glVertex3f(200,120,-450);
			glTexCoord2f(1.0f,0.0f);	glVertex3f(200,120,-360);
		glEnd();

		//face de baixo
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f,1.0f);	glVertex3f(200,110,-360);
			glTexCoord2f(0.0f,1.0f);	glVertex3f(200,110,-450);
			glTexCoord2f(0.0f,0.0f);	glVertex3f(-200,110,-450);
			glTexCoord2f(1.0f,0.0f);	glVertex3f(-200,110,-360);
		glEnd();

		//face da frente
		glBindTexture(GL_TEXTURE_2D, tex_4);
		glBegin(GL_QUADS);
			glTexCoord2f(1.0f,1.0f);	glVertex3f(-200,120,-360);
			glTexCoord2f(0.0f,1.0f);	glVertex3f(200,120,-360);
			glTexCoord2f(0.0f,0.0f);	glVertex3f(200,110,-360);
			glTexCoord2f(1.0f,0.0f);	glVertex3f(-200,110,-360);
		glEnd();



//sky =======================
	glBindTexture(GL_TEXTURE_2D, tex_6);

	glBegin(GL_QUADS);
	glNormal3f(0,0,1);//			     X    Y    Z
	glTexCoord2f(0.00f, 0.00f);	glVertex3f(   0, 750, 900);
	glTexCoord2f(0.05f, 0.00f);	glVertex3f(-278, 750, 856);
	glTexCoord2f(0.05f, 1.00f);	glVertex3f(-278,-130, 856);
	glTexCoord2f(0.00f, 1.00f);	glVertex3f(   0,-130, 900);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.05f, 0.00f);	glVertex3f(-278, 750, 856);
	glTexCoord2f(0.10f, 0.00f);	glVertex3f(-529, 750, 728);
	glTexCoord2f(0.10f, 1.00f);	glVertex3f(-529,-130, 728);
	glTexCoord2f(0.05f, 1.00f);	glVertex3f(-278,-130, 856);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.10f, 0.00f);	glVertex3f(-529, 750, 728);
	glTexCoord2f(0.15f, 0.00f);	glVertex3f(-728, 750, 529);
	glTexCoord2f(0.15f, 1.00f);	glVertex3f(-728,-130, 529);
	glTexCoord2f(0.10f, 1.00f);	glVertex3f(-529,-130, 728);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.15f, 0.00f);	glVertex3f(-728, 750, 529);
	glTexCoord2f(0.20f, 0.00f);	glVertex3f(-856, 750, 278);
	glTexCoord2f(0.20f, 1.00f);	glVertex3f(-856,-130, 278);
	glTexCoord2f(0.15f, 1.00f);	glVertex3f(-728,-130, 529);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.20f, 0.00f);	glVertex3f(-856, 750,278);
	glTexCoord2f(0.25f, 0.00f);	glVertex3f(-900, 750,  0);
	glTexCoord2f(0.25f, 1.00f);	glVertex3f(-900,-130,  0);
	glTexCoord2f(0.20f, 1.00f);	glVertex3f(-856,-130,278);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.25f, 0.00f);	glVertex3f(-900, 750,  0);
	glTexCoord2f(0.30f, 0.00f);	glVertex3f(-856, 750,-278);
	glTexCoord2f(0.30f, 1.00f);	glVertex3f(-856,-130,-278);
	glTexCoord2f(0.25f, 1.00f);	glVertex3f(-900,-130,  0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.30f, 0.00f);	glVertex3f(-856, 750,-278);
	glTexCoord2f(0.35f, 0.00f);	glVertex3f(-728, 750,-529);
	glTexCoord2f(0.35f, 1.00f);	glVertex3f(-728,-130,-529);
	glTexCoord2f(0.30f, 1.00f);	glVertex3f(-856,-130,-278);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.35f, 0.00f);	glVertex3f(-728, 750,-529);
	glTexCoord2f(0.40f, 0.00f);	glVertex3f(-529, 750,-728);
	glTexCoord2f(0.40f, 1.00f);	glVertex3f(-529,-130,-728);
	glTexCoord2f(0.35f, 1.00f);	glVertex3f(-728,-130,-529);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.40f, 0.00f);	glVertex3f(-529, 750,-728);
	glTexCoord2f(0.45f, 0.00f);	glVertex3f(-278, 750,-856);
	glTexCoord2f(0.45f, 1.00f);	glVertex3f(-278,-130,-856);
	glTexCoord2f(0.40f, 1.00f);	glVertex3f(-529,-130,-728);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.45f, 0.00f);	glVertex3f(-278, 750,-856);
	glTexCoord2f(0.50f, 0.00f);	glVertex3f(   0, 750,-900);
	glTexCoord2f(0.50f, 1.00f);	glVertex3f(   0,-130,-900);
	glTexCoord2f(0.45f, 1.00f);	glVertex3f(-278,-130,-856);
	glEnd();

	glBegin(GL_QUADS);
	glNormal3f(0,0,1);//			     X    Y    Z
	glTexCoord2f(0.50f, 0.00f);	glVertex3f(   0, 750,-900);
	glTexCoord2f(0.55f, 0.00f);	glVertex3f( 278, 750,-856);
	glTexCoord2f(0.55f, 1.00f);	glVertex3f( 278,-130,-856);
	glTexCoord2f(0.50f, 1.00f);	glVertex3f(   0,-130,-900);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.55f, 0.00f);	glVertex3f( 278, 750,-856);
	glTexCoord2f(0.60f, 0.00f);	glVertex3f( 529, 750,-728);
	glTexCoord2f(0.60f, 1.00f);	glVertex3f( 529,-130,-728);
	glTexCoord2f(0.55f, 1.00f);	glVertex3f( 278,-130,-856);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.60f, 0.00f);	glVertex3f( 529, 750,-728);
	glTexCoord2f(0.65f, 0.00f);	glVertex3f( 728, 750,-529);
	glTexCoord2f(0.65f, 1.00f);	glVertex3f( 728,-130,-529);
	glTexCoord2f(0.60f, 1.00f);	glVertex3f( 529,-130,-728);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.65f, 0.00f);	glVertex3f( 728, 750,-529);
	glTexCoord2f(0.70f, 0.00f);	glVertex3f( 856, 750,-278);
	glTexCoord2f(0.70f, 1.00f);	glVertex3f( 856,-130,-278);
	glTexCoord2f(0.65f, 1.00f);	glVertex3f( 728,-130,-529);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.70f, 0.00f);	glVertex3f( 856, 750,-278);
	glTexCoord2f(0.75f, 0.00f);	glVertex3f( 900, 750,   0);
	glTexCoord2f(0.75f, 1.00f);	glVertex3f( 900,-130,   0);
	glTexCoord2f(0.70f, 1.00f);	glVertex3f( 856,-130,-278);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.75f, 0.00f);	glVertex3f( 900, 750,   0);
	glTexCoord2f(0.80f, 0.00f);	glVertex3f( 856, 750, 278);
	glTexCoord2f(0.80f, 1.00f);	glVertex3f( 856,-130, 278);
	glTexCoord2f(0.75f, 1.00f);	glVertex3f( 900,-130,   0);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.80f, 0.00f);	glVertex3f( 856, 750, 278);
	glTexCoord2f(0.85f, 0.00f);	glVertex3f( 728, 750, 529);
	glTexCoord2f(0.85f, 1.00f);	glVertex3f( 728,-130, 529);
	glTexCoord2f(0.80f, 1.00f);	glVertex3f( 856,-130, 278);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.85f, 0.00f);	glVertex3f( 728, 750, 529);
	glTexCoord2f(0.90f, 0.00f);	glVertex3f( 529, 750, 728);
	glTexCoord2f(0.90f, 1.00f);	glVertex3f( 529,-130, 728);
	glTexCoord2f(0.85f, 1.00f);	glVertex3f( 728,-130, 529);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.90f, 0.00f);	glVertex3f( 529, 750, 728);
	glTexCoord2f(0.95f, 0.00f);	glVertex3f( 278, 750, 856);
	glTexCoord2f(0.95f, 1.00f);	glVertex3f( 278,-130, 856);
	glTexCoord2f(0.90f, 1.00f);	glVertex3f( 529,-130, 728);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.95f, 0.00f);	glVertex3f( 278, 750, 856);
	glTexCoord2f(1.00f, 0.00f);	glVertex3f(   0, 750, 900);
	glTexCoord2f(1.00f, 1.00f);	glVertex3f(   0,-130, 900);
	glTexCoord2f(0.95f, 1.00f);	glVertex3f( 278,-130, 856);
	glEnd();

//chao estendido =======================
	glBindTexture(GL_TEXTURE_2D, tex_8);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glBegin(GL_QUADS);
	glTexCoord2f(0.00f, 0.00f);	glVertex3f(-900,-130, 900);
	glTexCoord2f(1.00f, 0.00f);	glVertex3f(-900,-130,-900);
	glTexCoord2f(1.00f, 1.00f);	glVertex3f(-200,-130,-900);
	glTexCoord2f(0.00f, 1.00f);	glVertex3f(-200,-130, 900);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.00f, 0.00f);	glVertex3f( 200,-130, 900);
	glTexCoord2f(1.00f, 0.00f);	glVertex3f( 200,-130,-900);
	glTexCoord2f(1.00f, 1.00f);	glVertex3f( 900,-130,-900);
	glTexCoord2f(0.00f, 1.00f);	glVertex3f( 900,-130, 900);
	glEnd();
//sky estendido =======================
	glBindTexture(GL_TEXTURE_2D, tex_9);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

	glBegin(GL_QUADS);
	glTexCoord2f(0.00f, 0.00f);	glVertex3f(-900, 750, 900);
	glTexCoord2f(1.00f, 0.00f);	glVertex3f(-900, 750,-900);
	glTexCoord2f(1.00f, 1.00f);	glVertex3f( 900, 750,-900);
	glTexCoord2f(0.00f, 1.00f);	glVertex3f( 900, 750, 900);
	glEnd();

	glColor3f(1,1,1);
//====================barraca =======================
//===================face direita====================
	glBindTexture(GL_TEXTURE_2D, tex_2);
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200, 450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(200,-200,-450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(200, 200,-450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200, 200, 450);
	glEnd();

		//face esquerda
	glBindTexture(GL_TEXTURE_2D, tex_2);
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-200,-200, 450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,-450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200, 200,-450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-200, 200, 450);
	glEnd();

		//face de tras
	glBindTexture(GL_TEXTURE_2D, tex_2);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,-450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,-450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,200,-450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200,200,-450);
	glEnd();

		//face da frente
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,200,450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200,200,450);
	glEnd();

		//face de cima
	glBindTexture(GL_TEXTURE_2D, tex_7);
	glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(200,200,-450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,200,-450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-200,200,450);
	glEnd();

		//face de baixo
	glBindTexture(GL_TEXTURE_2D, tex_1);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(200,-200,-450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,-200,-450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-200,-200,450);
	glEnd();

		//bancada =========================
		//face direita
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(200,-200,360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(200,-40,360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200,-40,450);
	glEnd();

		//face esquerda
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-200,-200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,-40,360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-200,-40,450);
	glEnd();

		//face da frente
	glBindTexture(GL_TEXTURE_2D, tex_3);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,450);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,-40,450);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200,-40,450);
	glEnd();

		//face de tras
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-200,360);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-200,-200,360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,-40,360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(200,-40,360);
	glEnd();

		//face de cima
	glBindTexture(GL_TEXTURE_2D, tex_5);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(200,-40,450);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(200,-40,360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-200,-40,360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-200,-40,450);
	glEnd();

		//mesa 3 ===============================

		//face direita
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-270);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-200,-360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(160,0,-360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(160,0,-270);
	glEnd();

		//face esquerda
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-160,-200,-270);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-160,-200,-360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,0,-360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,0,-270);
	glEnd();

		//face de tras
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-360);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,0,-360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,0,-360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-360);
	glEnd();

		//face da frente
	glBindTexture(GL_TEXTURE_2D, tex_4);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-270);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,0,-270);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,0,-270);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-270);
	glEnd();

		//face de cima
	glBindTexture(GL_TEXTURE_2D, tex_5);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,0,-270);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,0,-360);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,0,-360);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,0,-270);
	glEnd();

		//mesa 2 =============================

		//face direita
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-171);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-200,-261);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(160,-40,-261);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(160,-40,-171);
	glEnd();

		//face esquerda
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-160,-200,-171);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-160,-200,-261);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-40,-261);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-40,-171);
	glEnd();

		//face de tras
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-261);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-40,-261);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-40,-261);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-261);
	glEnd();

		//face da frente
	glNormal3f(0,0,1);
	glBindTexture(GL_TEXTURE_2D, tex_4);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-171);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-40,-171);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-40,-171);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-171);
	glEnd();

		//face de cima
	glBindTexture(GL_TEXTURE_2D, tex_5);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-40,-171);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-40,-261);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-40,-261);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-40,-171);
	glEnd();

		//mesa 1 =============================

		//face direita
	glBegin(GL_QUADS);
	glNormal3f(1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-72);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-200,-162);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(160,-80,-162);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(160,-80,-72);
	glEnd();

		//face esquerda
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(-160,-200,-72);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(-160,-200,-162);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-80,-162);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-80,-72);
	glEnd();

		//face de tras
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-162);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-80,-162);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-80,-162);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-162);
	glEnd();

		//face da frente
	glBindTexture(GL_TEXTURE_2D, tex_4);
	glBegin(GL_QUADS);
	glNormal3f(0,0,1);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-200,-72);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-80,-72);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-80,-72);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-200,-72);
	glEnd();

		//face de cima
	glBindTexture(GL_TEXTURE_2D, tex_5);
	glBegin(GL_QUADS);
	glNormal3f(0,1,0);
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(160,-80,-72);
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(160,-80,-162);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(-160,-80,-162);
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(-160,-80,-72);
	glEnd();

	glPopMatrix();

}

