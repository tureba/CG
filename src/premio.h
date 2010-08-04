
#ifndef PREMIO_H
#define PREMIO_H

#include "visual.h"
#include <IL/ilut.h>
#include <string.h>


/*
 * Classe Premio
 *
 * É usada para gerenciar os prêmios que o usuário acumulou,
 * assim como é responsável por mostrar os prêmios na prateleira
 * e a contagem de prêmios acumulados na tela.
 */
class Premio: virtual public Visual {

	private:
		//a quantidade de prêmios que estão na prateleira
		int nro_premios;
		//descritores das texturas
		GLuint premio;
		GLuint painel_0;
		GLuint painel_1;
		GLuint painel_2;
		GLuint painel_3;

	public:
		/*
		 * Construtor padrão
		 * Carrega as texturas dos troféus da prateleira e
		 * da contagem do painel.
		 */
		Premio(): Visual(), nro_premios(3) {
			char nome_arquivo[40];
			strcpy(nome_arquivo,"imagens/premio.png");
			premio = ilutGLLoadImage(nome_arquivo);

			strcpy(nome_arquivo,"imagens/trofeu_0.png");
			painel_0 = ilutGLLoadImage(nome_arquivo);

			strcpy(nome_arquivo,"imagens/trofeu_1.png");
			painel_1 = ilutGLLoadImage(nome_arquivo);

			strcpy(nome_arquivo,"imagens/trofeu_2.png");
			painel_2 = ilutGLLoadImage(nome_arquivo);

			strcpy(nome_arquivo,"imagens/trofeu_3.png");
			painel_3 = ilutGLLoadImage(nome_arquivo);

		}


		/*
		 * Mostra os prêmios na prateleira e a contagem no canto da tela
		 */
		void desenha ();


		/*
		 * Retira um troféu da prateleira e aumenta a quantidade de
		 * prêmios que o usuário ganhou.
		 */
		void retira ();


		/*
		 * Reinicia a contagem de prêmios
		 */
		void reinicia ();
};

#endif //PREMIO_H
