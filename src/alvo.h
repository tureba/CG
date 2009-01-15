
#ifndef ALVO_H
#define ALVO_H

#include "movel.h"
#include "vetor3d.h"
#include "rolha.h"

#include <GL/glut.h>
#include <IL/ilut.h>
#include <stdlib.h>
#include <string.h>


/*
 * Classe Alvo
 * Implementa um alvo que se move sobre as mesas em ambas as
 * direções e com velocidades aleatórias.
 */
class Alvo: virtual public Movel {

	private:
		//mesa sobre a qual o alvo está se movendo
		int na_mesa;

		//estado do alvo
		int estado;

		//o alvo foi atingido ou chegou no final da mesa?
		bool morreu;

		//a quanto tempo o alvo está se movendo na mesa
		float tempo;

		//informações vetoriais sobre o movimento do alvo
		vetor3d<GLfloat> pos_atual, pos_inicial, velocidade;

		//identificador da textura
		static GLuint * img_pato;

	public:
		/*
		 * Construtor padrão de um alvo
		 * Ele escolhe aleatoriamente uma mesa e uma direção e
		 * gera a posição inicial e a velocidade do alvo em
		 * função dessas escolhas.
		 */
		Alvo(): Movel(), morreu(false), tempo(0) {
			//se esse for o primero alvo, é necessário carregar
			//a textura do alvo, o pato
			if (img_pato==NULL) {
				img_pato = new GLuint;
			    char nome_arquivo[40];
				strcpy(nome_arquivo,"imagens/pato.png");
				*img_pato = ilutGLLoadImage(nome_arquivo);
			}

			//escolhe uma das 3 mesas aleatoriamente
			na_mesa = random()%3;
			//e uma velocidade também aleatoriamente
			velocidade = vetor3d<GLfloat>((random()%50)+30,0,0);
			//esquerda para a direita
			if (random()%2) {
					switch (na_mesa) {
						case 0:
							pos_inicial = vetor3d<GLfloat>(-140,-60,-117);
							break;
						case 1:
							pos_inicial = vetor3d<GLfloat>(-140,-20,-216);
							break;
						case 2:
							pos_inicial = vetor3d<GLfloat>(-140,20,-315);
							break;
					}
			}
			//direita para a esquerda
			else {
				velocidade *= -1; //inverte a direção do movimento
					switch (na_mesa) {
						case 0:
							pos_inicial = vetor3d<GLfloat>(140,-60,-117);
							break;
						case 1:
							pos_inicial = vetor3d<GLfloat>(140,-20,-216);
							break;
						case 2:
							pos_inicial = vetor3d<GLfloat>(140,20,-315);
							break;
					}
			}
			//começa no começo
			pos_atual = pos_inicial;
		}


		/*
		 * Mostra o alvo na tela
		 */
		void desenha ();


		/*
		 * Move o alvo
		 */
		bool atualiza(float dt);


		/*
		 * Faz com que um alvo 'morra'
		 */
		void morre();


		/*
		 * a rolha pode acessar as informações do alvo
		 * para fins de detecção de colisão
		 */
		friend bool Rolha::atualiza(float dt);

};

#endif //ALVO_H

