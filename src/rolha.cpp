
#include "rolha.h"
#include "vetor3d.h"
#include "alvo.h"
#include "movel.h"

#include <GL/glut.h>
#include <math.h>
#include <list>
#include <typeinfo>


//esta função precisa ter sido implementada em algum outro ponto
//neste caso, ela foi imlementada no main.cpp
//ela avisa o programa que um alvo foi acertado.
void acerta_alvo();

//constantes da rolha que indicam o estado em que ela está
const int Rolha::estado_invisivel;
const int Rolha::estado_na_bancada;
const int Rolha::estado_na_arma;
const int Rolha::estado_no_ar;


/*
 * Método que desenha a rolha, se ela estiver em um
 * estado que permita isso.
 */
void Rolha::desenha()
{

	//ela será desenhada se estiver na arma ou no ar,
	//mas não na bancada ou invisível
	if ((estado != estado_invisivel) && (estado != estado_na_bancada)){

	glPushMatrix();

		//se ela estiver voando, então pos_atual sempre vai dizer
		//qual é a posição certa para se desenhar a rolha
		if (estado == estado_no_ar)
			glTranslatef(pos_atual.x(),pos_atual.y(),pos_atual.z());

		glColor3f(0.68f, 0.26f, 0.06f);
		glTranslatef(0.0f, -15.0f, 400.0f);
		glRotatef(ang_y, 0.0f, 1.0f, 0.0f);
		glRotatef(ang_x, 1.0f, 0.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, -125.0f);
		glScalef(3.0f,3.0f,1.0f);

		//rolha da arma

		//base 1 da rolha
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.8f, 0.0f);
			glVertex3f(0.66f, 0.4f, 0.0f);
			glVertex3f(0.66f, -0.4f, 0.0f);
			glVertex3f(0.0f, -0.8f, 0.0f);
			glVertex3f(-0.66f, -0.4f, 0.0f);
			glVertex3f(-0.66f, 0.4f, 0.0f);
		glEnd();

		// base 2 da rolha
		glBegin(GL_POLYGON);
			glVertex3f(0.0f, 0.8f, 5.0f);
			glVertex3f(0.66f, 0.4f, 5.0f);
			glVertex3f(0.66f, -0.4f, 5.0f);
			glVertex3f(0.0f, -0.8f, 5.0f);
			glVertex3f(-0.66f, -0.4f, 5.0f);
			glVertex3f(-0.66f, 0.4f, 5.0f);
		glEnd();

		//liga as bases da rolha
		glBegin(GL_QUADS);
			glVertex3f(0.0f, 0.8f, 0.0f);
			glVertex3f(0.0f, 0.8f, 5.0f);
			glVertex3f(0.66f, 0.4f, 5.0f);
			glVertex3f(0.66f, 0.4f, 0.0f);

			glVertex3f(0.66f, 0.4f, 0.0f);
			glVertex3f(0.66f, 0.4f, 5.0f);
			glVertex3f(0.66f, -0.4f, 5.0f);
			glVertex3f(0.66f, -0.4f, 0.0f);

			glVertex3f(0.66f, -0.4f, 0.0f);
			glVertex3f(0.66f, -0.4f, 5.0f);
			glVertex3f(0.0f, -0.8f, 5.0f);
			glVertex3f(0.0f, -0.8f, 0.0f);

			glVertex3f(0.0f, -0.8f, 0.0f);
			glVertex3f(0.0f, -0.8f, 5.0f);
			glVertex3f(-0.66f, -0.4f, 5.0f);
			glVertex3f(-0.66f, -0.4f, 0.0f);

			glVertex3f(-0.66f, -0.4f, 0.0f);
			glVertex3f(-0.66f, -0.4f, 5.0f);
			glVertex3f(-0.66f, 0.4f, 5.0f);
			glVertex3f(-0.66f, 0.4f, 0.0f);

			glVertex3f(-0.66f, 0.4f, 0.0f);
			glVertex3f(-0.66f, 0.4f, 5.0f);
			glVertex3f(0.0f, 0.8f, 5.0f);
			glVertex3f(0.0f, 0.8f, 0.0f);

		glEnd();
	glPopMatrix();

	}

}


/*
 * Método que faz com que a rolha acompanhe a orientação
 * da arma. Isso é importante para o momento do tiro, já
 * que a direção do tiro será calculada a partir disso.
 */
void Rolha::moveRolha(float x, float y)
{
	if (estado == estado_na_arma) {
		//muda a orientação da rolha de acordo com a da arma,
		//mas só se ela ainda estiver presa na arma
		ang_x = y;
		ang_y = x;
	}
}


/*
 * Método que calcula o movimento da rolha.
 * Este movimento só faz sentido
 */
bool Rolha::atualiza(float dt)
{

	if (estado == estado_no_ar) {

			//acumula as fatias de tempo desde o início do movimento (em segundos)
			tempo += dt/1000;

			//atualiza a posição da rolha
			pos_atual = pos_inicial + velocidade*tempo + aceleracao*tempo*tempo*0.5;

			//confere se ela caiu no chão
			if (pos_atual.y()<-400)
				estado = estado_invisivel;

			//checagem de colisão entre a rolha e todos os alvos:
			//para cada objeto móvel na cena...
			for(std::list<Movel *>::iterator obj = lista_movel->begin(); obj!=lista_movel->end(); obj++)
				//...se o objeto for um alvo...
				if (typeid(**obj)==typeid(Alvo)) {
					Alvo * a = dynamic_cast<Alvo*>(*obj);
					//...e a distância entre este alvo e esta rolha for pequena...
					if ((pos_atual-a->pos_atual).modulo()<30) {
						//então marque que um alvo foi atingido
						acerta_alvo();
						//remova o alvo
						a->morre();
						//e a rolha também
						estado = estado_invisivel;
						//não continua o laço - queremos apenas 1 acerto por vez
						break;
					}
				}
	}

	//a rolha nunca será destruída, ela só fica
	//invisível após certo momento
	return false;
}


/*
 * Método que faz com que a rolha comece a voar no ar.
 * Ele ajusta a velocidade vetorial da rolha em função
 * da direção para onde a arma estava apontando.
 */
void Rolha::atira()
{

	//só pode atirar se estiver na arma
	if (estado == estado_na_arma) {
		//vai para o ar
		estado = estado_no_ar;

		//começa a contagem do tempo que está no ar
		tempo = 0;

		//calcula o vetor da direção do tiro
		vetor3d<GLfloat> vel_vet(sin(ang_y*M_PI/180.0),sin(ang_x*M_PI/180.0),cos(ang_y*M_PI/180.0)*cos(ang_x*M_PI/180.0));

		//normaliza o vetor
		vel_vet *= 1/vel_vet.modulo();

		//o vetor toma a intencidade definida antes
		velocidade = vel_vet*vel;

		//ajustes devido à orientação da cena adotada
		velocidade.x() = -velocidade.x();
		velocidade.z() = -velocidade.z();

	}

}


/*
 * Método que reinicia o jogo colocando a rolha
 * de volta na bancada pronta para ser usada novamente.
 */
void Rolha::para_a_bancada()
{

	estado = estado_na_bancada;
	pos_atual = pos_inicial;

}


/*
 * Método que coloca a rolha na arma
 */
void Rolha::carrega_na_arma()
{

	//só é necessário alterar o estado da rolha
	estado = estado_na_arma;

}

