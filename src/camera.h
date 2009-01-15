
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glut.h>
#include "visual.h"

/*
 * Classe que implementa a câmera
 *
 * É responsável apenas por setar a matrix ModelView
 * corretamente a cada display da cena.
 */
class Camera: virtual public Visual {

	private:
		GLint cam_pos[3]; //posição da câmera
		GLint cam_olha[3]; //direção para onde a câmera olha
		GLint cam_orient[3]; //orientação da câmera

	public:
		Camera(): Visual()
		{
			//posição da câmera
			cam_pos[0] = 0;
			cam_pos[1] = 0;
			cam_pos[2] = 400;

			//direção para onde a câmera olha
			cam_olha[0] = 0;
			cam_olha[1] = 0;
			cam_olha[2] = 0;

			//orientação da câmera
			cam_orient[0] = 0;
			cam_orient[1] = 1;
			cam_orient[2] = 0;
		}

		void desenha ();

		/*
		 * Método que recebe as informações externas
		 * sobre a orientação que a câmera deve ter.
		 */
		void moveCamera (GLint x, GLint y);

		/*
		 * Estes métodos colocam a câmera em posições fixas
		 * nos eixos para vermos a cena de outros ângulos.
		 * TODO: remover eles do projeto final
		 */
		void x();
		void y();
		void z();

};

#endif //CAMERA_H

