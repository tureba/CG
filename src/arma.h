
#ifndef ARMA_H
#define ARMA_H

#include "visual.h"
#include "rolha.h"
#include <IL/ilut.h>
#include <string.h>


/*
 * Classe Arma
 *
 * É responsável por mostrar um modelo de arma com a
 * rolha na frente, se houver alguma carregada. Também
 * Gerencia a quantidade de rolhas disponíveis para
 * serem atiradas, podendo atirá-las à medida que
 * o usuário chama o método 'atira'.
 */
class Arma: virtual public Visual {

	private:
		//ângulos de direção da arma
		float ang_x, ang_y;
		//rolhas que a arma pode atirar
		Rolha rolhas[3];
		//marcação de qual rolha é a próxima
		int rolha_atual;
		//descritor da textura usada na arma
		GLuint tex_1;

	public:
		Arma(): Visual(), rolha_atual(0) {
			//carrega a textura do metal da arma
			char nome_arquivo[40];
			strcpy(nome_arquivo,"imagens/metal5.jpg");
			tex_1 = ilutGLLoadImage(nome_arquivo);//zero

			//carrega a arma com a primeira rolha
			rolhas[0].carrega_na_arma();
		}


		/*
		 * Mostra a arma e a rolha que está carregada
		 */
		void desenha ();


		/*
		 * Muda a direção para a qual a arma aponta,
		 * de acordo com o mouse.
		 */
		void moveArma(float, float);


		/*
		 * Atira uma rolha se houver uma no cano.
		 * Coloca a próxima rolha no cano, se houver
		 * alguma disponível.
		 */
		void atira();


		/*
		 * Retorna a arma ao estado inicial, com três
		 * rolhas disponíveis e a primeira no cano.
		 */
		void reinicia_arma();

};

#endif //ARMA_H

