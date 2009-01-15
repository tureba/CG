
#include "visual.h"

/*
 * Lista de objetos visuais da cena
 *
 * É necessária para centralizar e simplificar o envio
 * dos objetos visuais para o OpenGL através da função display
 * associada. Desta forma é possível encontrar diretamente
 * todos os objetos que precisam ser mostrados na cena.
 *
 * É uma variável estática dentro da classe Visual.
 */
std::list<Visual *> * Visual::lista_visual;


/*
 * Método estático que altera a lista de objetos visuais da cena.
 * É necessário chamar este método ao menos uma vez no início de
 * qualquer programa que tente usar um objeto derivado da classe
 * Visual.
 *
 * O parâmetro que ele recebe é um ponteiro para uma lista externa
 * que será usada para todos os objetos visuais.
 */
void Visual::cena(std::list<Visual *> * lista_visual_externa)
{
	lista_visual = lista_visual_externa;
}

