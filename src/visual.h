
#ifndef VISUAL_H
#define VISUAL_H

#include <list>
#include <iostream>

/*
 * Classe Visual
 *
 * Esta classe virtual fornece ao programa principal uma forma
 * simples de listar todos os objetos da cena. Isso simplifica
 * o gerenciamento, principalmente durante o envio daqueles ao
 * OpenGL. Para isso, a função display associada ao OpenGL deve
 * apenas chamar o método público desenha da classe a ser
 * mostrada na tela.
 *
 * Ela requer que toda classe derivada implemente o método
 * desenha adequadamente. Veja um modelo de implementação de
 * uma classe derivada no diretório 'modelos' junto com este
 * código-fonte.
 */
class Visual {

	protected:
		//ponteiro estático para a lista externa de objetos visuais
		static std::list<Visual *> * lista_visual;

	public:
		/*
		 * Construtor padrão.
		 * Ele insere o objeto móvel criado na lista global de objetos móveis.
		 */
		Visual() {
			//a lista deve ter sido inicializada antes
			//de qualquer objeto visual ser criado
			if (lista_visual == NULL)
				std::cerr << "Falta inicializar a lista pai de objetos visuais!" << std::endl;
			else
				lista_visual->push_back(this);
		}


		/*
		 * Destrutor padrão.
		 * Ele é responsável por remover o objeto da lista de objetos visuais.
		 */
		virtual ~Visual() {
			lista_visual->remove(this);
		}


		/*
		 * Método puramente virtual que implementa o envio do objeto para
		 * o OpenGL. Deve ser obrigatoriamente implementada em toda na
		 * classe-filha.
		 */
		virtual void desenha () = 0;


		/*
		 * Método estático que altera a lista de objetos visuais da cena.
		 * É necessário chamar este método ao menos uma vez no início de
		 * qualquer programa que tente usar um objeto derivado da classe
		 * Visual.
		 */
		static void cena(std::list<Visual *> * lista_visual_externa);

};

#endif //VISUAL_H

