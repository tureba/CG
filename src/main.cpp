/* Trabalho de Computação Gráfica
 *
 * Grupo:
 * 	-	Arthur Filipe Martins Nascimento
 * 	-	Rafael Piovesan da Costa Machado
 * 	-	Valter Domingos de Morais Junior
 * 	-	Ulisses Francamar Soares
 *
 * */

//bibliotecas do sistema
#include <iostream>
#include <list>
using namespace std;

//OpenGL e glut
#include <GL/glut.h>
#include <math.h>
#define PI M_PI
#include <IL/ilut.h>

//bibliotecas locais
#include "visual.h"
#include "movel.h"

//objetos da cena
#include "barraca.h"
#include "camera.h"
#include "arma.h"
#include "painel.h"
#include "alvo.h"
#include "premio.h"


//variáveis globais

float fps = 30; //fps desejados

Painel * painel;
Premio * premio;

//dados da arma
Arma * arma;

//dados da câmera
Camera * camera;
GLfloat mouse_ang_twist = 40, mouse_ang_tilt = 0;

//tamanhos da janela
int window_size_x = 800;
int window_size_y = 600;

//lista de todos os objetos visuais
//é necessária para a classe Visual
list<Visual *> osObjetosVisuais;
//lista de todos os objetos móveis
//é necessária para a classe Movel
list<Movel *> osObjetosMoveis;


/*
 * Função que é chamada quando um alvo é acertado
 */
void acerta_alvo()
{
	premio->retira();
}


/*
 * Função que é registrada no OpenGL e chamada quando uma cena
 * precisa ser redesenhada na tela. Ela se preocupa em chamar o
 * método 'desenha' de todos os objetos atualmente na cena.
 */
void display()
{

	//limpa tudo para desenharmos a cena inteira a partir do zero
	glClear (GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	//itera a lista de objetos visuais desenhando todos eles
	//(obs: a ordem de chamada destes objetos não é determinística)
	for(list<Visual *>::iterator obj = osObjetosVisuais.begin(); obj!=osObjetosVisuais.end(); obj++)
		(*obj)->desenha();

	//troca os buffers, já que estamos usando double buffering
	glutSwapBuffers();

}


/*
 * Função que é registrada no OpenGL para tratar o redimensionamento
 * da janela. Ela redefine a janela de visualização, entre outras coisas.
 */
void reshape (int x, int y)
{

	//guarda as novas dimensões da janela
	//para ser usada em outras partes do programa
	window_size_x = x;
	window_size_y = y;

	//redefine a janela de visualização como sendo
	//do mesmo tamanho da janela do programa
	glViewport(0,0,x,y);

	//se for necessario, redefine a matriz Projection...
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	//...com o prisma do espaço na mesma proporção da nova janela
	gluPerspective(45, (GLfloat) x/(GLfloat) y, 0.1, -1000.0);

	//redefine a matriz ModelView também
	camera->desenha();

	//e pede para o OpenGL redesenhar a cena
	glutPostRedisplay();

}


/*
 * Função que é registrada no OpenGL para tratar
 * as teclas apertadas.
 */
void keyboard (unsigned char key, int x, int y)
{

	switch(key) {
		//a tecla ESC finaliza o programa
		case 27:
			exit(0);
			break;

		//qualquer outra tecla é ignorada
		default:
			break;
	}

}


/*
 * Função que é registrada no OpenGL para tratar os cliques
 * do mouse. São duas possibilidades: atirar ou recarregar.
 */
void gerencia_mouse(int button, int state, int x, int y)
{

	//se o botão esquerdo é pressionado, então a arma atira uma rolha
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		arma->atira(),
		painel->atualiza();

	//se o botão direito é pressionado, então o jogo é reiniciado
	if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
		arma->reinicia_arma(),
		painel->reinicia(),
		premio->reinicia();

}


/*
 * Função que é registrada no OpenGL para tratar o
 * movimento passivo do mouse. Ela deve fazer a
 * câmera e a arma acompanharem o mouse pela tela.
 */
void mouse_movimento_passivo(int x, int y)
{

	//centraliza os pontos na janela e
	//acerta a orientação do eixo y
	x -= window_size_x/2;
	y -= window_size_y/2;
	y = -y;

	//informa a nova posição do mouse e
	//faz com que a câmera acompanhe
	camera->moveCamera(x,y);

	//a arma também deve acompanhar o movimento
	arma->moveArma(-atan2(x,400)*180/PI, atan2(y+15,400)*180/PI);

	//e redesenha tudo com a nova orientação
	glutPostRedisplay();

}


/*
 * Função que trata a movimentação dos objetos móveis.
 * Ela é responsável por chamar os métodos individuais
 * que recalculam a movimentação/animação dos objetos
 * da cena. Quando um objeto informa sobre o fim do seu
 * trajeto, esta função o remove da lista de objetos
 * móveis e libera a sua memória.
 */
void move_tudo(int valor)
{

	//para cada objeto móvel registrado nesta cena...
	for(list<Movel *>::iterator obj = osObjetosMoveis.begin(); obj!=osObjetosMoveis.end(); )
		//execute a função de recálculo da animação
		if ((*obj)->atualiza(1000.0/fps)) {
			//e se ele expirou, o remove seguindo em frente na lista
			delete *obj;
			obj = osObjetosMoveis.erase(obj);
		}
		else
			//caso contrário, apenas segue em frente na lista
			obj++;

	//como esta função é chamada periodicamente, precisamos
	//re-registrar ela para ser chamada a cada chamada
	glutTimerFunc(1000.0/fps,move_tudo,0);

	//depois das movimentações, muitos objetos podem
	//precisar ser redesenhados em novas posições
	glutPostRedisplay();

}


/*
 * Função principal e ponto de entrada do programa
 */
int main (int argc, char ** argv, char ** envp)
{

	//inicializações do OpenGL e glut
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (window_size_x, window_size_y);
	glutInitWindowPosition (100, 80);
	glutCreateWindow ("Trabalho de Computacao Grafica - Tiro ao Alvo");
	glutSetCursor(GLUT_CURSOR_NONE);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	//inicializações da biblioteca de imagens
	ilInit();
	ilutRenderer(ILUT_OPENGL);

	//registra todas as funções de tratamento de eventos no OpenGL
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouse_movimento_passivo);
	glutMouseFunc(gerencia_mouse);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000.0/fps,move_tudo,0);

	//algumas classes precisam de uma semente mais aleatória do que 1
	//ou então ficam completamente determinísticos
	srandom(clock());

	//inicializações da cena
	Visual::cena(&osObjetosVisuais);
	Movel::cena(&osObjetosMoveis);

	//cria todos os objetos da cena
	Barraca b;
	camera = new Camera();
	arma = new Arma();
	painel = new Painel();
	premio = new Premio();
	new Alvo();
	new Alvo();
	new Alvo();
	new Alvo();

	glMatrixMode (GL_TEXTURE);
	glLoadIdentity();
	glScalef(1.0f, -1.0f, 1.0f);

	//vamos jogar!
	glutMainLoop();

	return 0;

}

