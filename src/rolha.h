
#ifndef ROLHA_H
#define ROLHA_H

#include <GL/glut.h>

#include "movel.h"
#include "vetor3d.h"


/*
 * Classe Rolha
 *
 * Modela uma rolha que é usada como munição da Arma.
 * Ela se move junto com a arma se não tiver sido atirada;
 * se move em função do tempo se já tiver sido atirada; e
 * não se move se estiver invisível ou na bancada. Também
 * só é mostrada na cena se estiver presa na arma ou em
 * vôo no ar.
 */
class Rolha: virtual public Movel {

	private:
		//variável que marca o estado da rolha
		int estado;

		//constantes que indicam os estados possíveis
		const static int estado_invisivel = 0;
		const static int estado_na_bancada = 1;
		const static int estado_na_arma = 3;
		const static int estado_no_ar = 4;

		//ângulos da rolha no ar
		float ang_x, ang_y;
		//tempo que a rolha está no ar
		float tempo;
		//módulo da velocidade da rolha
		float vel;

		//informações vetoriais da rolha: posições, velodicade, aceleração
		vetor3d<GLfloat> pos_inicial, pos_atual, velocidade, aceleracao;


	public:
		/*
		 * Construtor padrão.
		 * Inicia todos os atributos da rolha, inclusive o seu estado inicial
		 */
		Rolha(): Movel(), estado(estado_na_bancada), ang_x(0), ang_y(0), tempo(0), vel(1000), pos_inicial(0,0,0), pos_atual(0,0,0), velocidade(0,0,0), aceleracao(0,-100,0) { }


		/*
		 * Método que mostra a rolha na tela se ela estiver
		 * em um estado adequado.
		 */
		void desenha ();


		/*
		 * Método que move a rolha se ela estiver voando no ar.
		 */
		bool atualiza (float);


		/*
		 * Método que é usado para passar as informações de
		 * orientação da arma para a rolha.
		 */
		void moveRolha (float, float);


		/*
		 * Método que faz com que a arma passe a voar na cena.
		 * Ela precisa ter saído da arma.
		 */
		void atira();


		/*
		 * Método que faz com que a rolha seja recolocada na
		 * bancada para reiniciar o jogo.
		 */
		void para_a_bancada();


		/*
		 * Método que faz com que a rolha seja colocada na arma,
		 * vindo da bancada.
		 */
		void carrega_na_arma();
};

#endif //ROLHA_H

