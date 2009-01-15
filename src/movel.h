
#ifndef MOVEL_H
#define MOVEL_H

#include "visual.h"

#include <list>
#include <iostream>

/*
 * Classe Movel
 *
 * Esta classe virtual extende a classe Visual de forma a
 * possibilitar que o objeto instanciado possa se mover a
 * partir de chamadas repetidas ao seu método público
 * 'atualiza'.
 *
 * Ela requer que toda classe derivada implemente o método
 * atualiza adequadamente, além do método desenha requerido
 * pela classe Visual. Veja um modelo de implementação de uma
 * classe derivada no diretório 'modelos' junto com este
 * código-fonte.
 */
class Movel: virtual public Visual {

	protected:
		//ponteiro estático para a lista externa de objetos móveis
		static std::list<Movel *> * lista_movel;


	public:
		/*
		 * Construtor padrão.
		 * Ele chama o construtor da sua classe-pai (Visual) e insere
		 * o objeto móvel criado na lista global de objetos móveis.
		 */
		Movel(): Visual()
		{
			//a lista deve ter sido inicializada antes
			//de qualquer objeto móvel ser criado
			if (lista_movel == NULL)
				std::cerr << "Falta inicializar a lista de objetos móveis da cena!" << std::endl;
			else
				lista_movel->push_front(this);
		}


		/*
		 * Destrutor padrão
		 * Ele trata da remoção do objeto da lista de objetos visuais
		 * e da lista de objetos móveis. Contudo, como a remoção da lista
		 * de objetos móveis está sendo feita no programa principal, ela
		 * não precisa ser implementada aqui. E como a classe-pai já
		 * implementa a remoção da lista dos objetos visuais no destrutor
		 * e a classe Movel herda esse construtor, não é necessário
		 * reimplementar tal código nesta classe.
		 */
		/*
		~Movel()
		{
			lista_movel->remove(this);
			lista_visual->remove(this);
		}
		*/


		/*
		 * Método puramente virtual que implementa a movimentação do
		 * objeto móvel. Deve ser obrigatoriamente implementada em
		 * toda na classe-filha.
		 */
		virtual bool atualiza (float) = 0;


		/*
		 * Método estático que altera a lista de objetos móveis da cena.
		 * É necessário chamar este método ao menos uma vez no início de
		 * qualquer programa que tente usar um objeto derivado da classe
		 * Movel.
		 */
		static void cena(std::list<Movel *> * lista_movel_externa);

};

#endif //MOVEL_H

