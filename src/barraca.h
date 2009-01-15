
#ifndef BARRACA_H
#define BARRACA_H

#include "visual.h"
#include <GL/glut.h>
#include <IL/ilut.h>
#include <string.h>


/*
 * Classe Barraca
 *
 * Esta classe engloba todos os objetos relativos ao cenário.
 * Ou seja, além da própria barraca que envolve a cena, também
 * gerencia e mostra a bancada sobre a qual a arma está apoiada,
 * as mesas por onde os alvos trafegam e a prateleira onde os
 * prêmios repousam.
 */
class Barraca: virtual public Visual {

	private:
		//descritores das texturas usadas no cenário
		GLuint tex_1;
		GLuint tex_2;
		GLuint tex_3;
		GLuint tex_4;
		GLuint tex_5;
		GLuint tex_6;
		GLuint tex_7;
		GLuint tex_8;
		GLuint tex_9;

	public:
		/*
		 * Construtor padrão que se encarrega de carregar as
		 * texturas necessárias para mostrar a barraca e o
		 * cenário corretamente.
		 */
		Barraca(): Visual() {
			char nome_arquivo[40];

			strcpy(nome_arquivo,"imagens/grama_3.jpg");
			tex_1 = ilutGLLoadImage(nome_arquivo);//Chao

			strcpy(nome_arquivo,"imagens/Plastic0034_S2.png");
			tex_2 = ilutGLLoadImage(nome_arquivo);//Lona azul furada

			strcpy(nome_arquivo,"imagens/WoodPainted0110_1_S.bmp");
			tex_3 = ilutGLLoadImage(nome_arquivo);//Balcao frontal

			strcpy(nome_arquivo,"imagens/WoodPainted0111_1_S.bmp");
			tex_4 = ilutGLLoadImage(nome_arquivo);//Prateleira frontal

			strcpy(nome_arquivo,"imagens/PlanksOld0176_1_S.bmp");
			tex_5 = ilutGLLoadImage(nome_arquivo);//Superficies

			strcpy(nome_arquivo,"imagens/sky_4.jpg");
			tex_6 = ilutGLLoadImage(nome_arquivo);//Sky

			strcpy(nome_arquivo,"imagens/Plastic0034_S2.bmp");
			tex_7 = ilutGLLoadImage(nome_arquivo);//Lona azul cima

			strcpy(nome_arquivo,"imagens/grama_1.jpg");
			tex_8 = ilutGLLoadImage(nome_arquivo);//grama expandida

			strcpy(nome_arquivo,"imagens/sky_estendido.jpg");
			tex_9 = ilutGLLoadImage(nome_arquivo);//grama expandida

		}

		
		/*
		 * Método que mostra a barraca e tudo o que compoe o cenário
		 */
		void desenha ();

};

#endif //BARRACA_H

