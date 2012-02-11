
#ifndef PAINEL_H
#define PAINEL_H

#include "visual.h"
#include <IL/ilut.h>
#include <string.h>


/*
 * Classe que mostra um painel em 2D na tela.
 * Este painel mostra a contagem de rolhas disponíveis
 * para serem atiradas pelo usuário.
 */
class Painel: virtual public Visual {

	private:
		//contagem dos tiros disponíveis
		int tiros;

		//descritores das texturas dos números
		GLuint tex_1;
		GLuint tex_2;
		GLuint tex_3;
		GLuint tex_4;

	public:
		/*
		 * Construtor padrão
		 * Cria um painel que começa com 3 tiros
		 */
		Painel(): Visual(), tiros(3) {

			char nome_arquivo[40];
			strcpy(nome_arquivo,"imagens/painel_0.png");
			tex_1 = ilutGLLoadImage(nome_arquivo);//zero

			strcpy(nome_arquivo,"imagens/painel_1.png");
			tex_2 = ilutGLLoadImage(nome_arquivo);//um

			strcpy(nome_arquivo,"imagens/painel_2.png");
			tex_3 = ilutGLLoadImage(nome_arquivo);//dois

			strcpy(nome_arquivo,"imagens/painel_3.png");
			tex_4 = ilutGLLoadImage(nome_arquivo);//tres

		}


		/*
		 * Método que mostra o painel na tela
		 */
		void desenha ();


		/*
		 * Método que diminui a contagem do painel
		 */
		void atualiza ();


		/*
		 * Método que reinicia a contagem no painel
		 */
		void reinicia ();

};

#endif //PAINEL_H

