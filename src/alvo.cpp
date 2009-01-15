
#include "alvo.h"

//descritor da textura do alvo
GLuint * Alvo::img_pato;


/*
 * Mostra o alvo na tela.
 * A direção do alvo indica se a textura precisa
 * ser invertida ou não.
 */
void Alvo::desenha()
{

	glPushMatrix();	
		glColor3f(1,1,1);
		glBindTexture(GL_TEXTURE_2D, *img_pato);
		glNormal3f(0,0,1);
		glBegin(GL_QUADS);
		if (velocidade.x()<0) {
				glTexCoord2f(0.0f, 1.0f);   glVertex3f(pos_atual.x()-10,pos_atual.y()-10,pos_atual.z());
				glTexCoord2f(1.0f, 1.0f);   glVertex3f(pos_atual.x()+10,pos_atual.y()-10,pos_atual.z());
				glTexCoord2f(1.0f, 0.0f);   glVertex3f(pos_atual.x()+10,pos_atual.y()+10,pos_atual.z());
				glTexCoord2f(0.0f, 0.0f);   glVertex3f(pos_atual.x()-10,pos_atual.y()+10,pos_atual.z());
		} else {
				glTexCoord2f(1.0f, 1.0f);   glVertex3f(pos_atual.x()-10,pos_atual.y()-10,pos_atual.z());
				glTexCoord2f(0.0f, 1.0f);   glVertex3f(pos_atual.x()+10,pos_atual.y()-10,pos_atual.z());
				glTexCoord2f(0.0f, 0.0f);   glVertex3f(pos_atual.x()+10,pos_atual.y()+10,pos_atual.z());
				glTexCoord2f(1.0f, 0.0f);   glVertex3f(pos_atual.x()-10,pos_atual.y()+10,pos_atual.z());
		}
		glEnd();
	glPopMatrix();

}


/*
 * Move o alvo de acordo com a velocidade
 * e o tempo que ele está se movendo
 */
bool Alvo::atualiza(float dt)
{

	//acumula a fatia de tempo passada, em segundos
	tempo += dt/1000.0;

	//move o alvo em função da posição inicial, velocidade
	//dele e do tempo em que está se movendo
	pos_atual = pos_inicial + velocidade*tempo;

	//se ele sair da mesa
	if ((pos_atual.x()<-140)|| (pos_atual.x()>140))
		//ele precisa ser destruído
		morre();

	//diz se o alvo morreu - ele será destruído do lado de fora
	return morreu;

}


/*
 * Faz com que o alvo 'morra'
 * Isso cria outro alvo em algum ponto aleatório e marca
 * o atual para ser destruído na próxima atualização
 */
void Alvo::morre()
{
	new Alvo();
	morreu = true;
}

