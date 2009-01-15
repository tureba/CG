
#include "movel.h"

/*
 * Lista de objetos móveis da cena
 *
 * É necessária para centralizar e simplificar a física
 * do programa. Desta forma é possível encontrar diretamente
 * todos os objetos que se movem na cena tanto para 
 * a detecção de colisões quanto para apenas movê-los de
 * forma uniforme.
 *
 * É uma variável estática dentro da classe Movel.
 */
std::list<Movel *> * Movel::lista_movel;


/*
 * Método estático que altera a lista de objetos móveis da cena.
 * É necessário chamar este método ao menos uma vez no início de
 * qualquer programa que tente usar um objeto derivado da classe
 * Movel.
 *
 * O parâmetro que ele recebe é um ponteiro para uma lista externa
 * que será usada para todos os objetos móveis.
 */
void Movel::cena(std::list<Movel *> * lista_movel_externa)
{
	lista_movel = lista_movel_externa;
}

