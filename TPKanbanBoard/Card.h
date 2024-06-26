#define CARD_H_

#include <string>
#include "CardComment.h"
#include "State.h"

using std::string;
using KanbandBoardCardComment::CardComment;
using KanbanBoardState::State;

namespace KanbanBoardCard {
	struct Card;
	struct Node;
	struct List;

	/*
	 * Precondición: ninguna
	 * Postcondición: Devuelve una instancia válida de Card con identificador @id y con el nombre @name, la cual
	 * ademas guarda la fecha y hora de creación. Si @name es vacio establece como nombre de la @card
	 * el valor "<Sin Nombre>"
	 */
	Card* CreateCard(string id, string name);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard. @comment fue creado con
	 * la primitiva KanbanBoardCardComment::CardComment.
	 * Postcondición: Agrega un nuevo comentario, @comment, en @card. El @comment es agregado como ultimo comentario.
	 */
	void AddComment(Card* card, CardComment* comment);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve el comentario en la posición @commentPosition. Las posiciones comienzan en cero.
	 * Si no existe un comentario en la posición especificada en @commentPosition devuelve NULL
	 */
	CardComment* GetComment(Card* card, unsigned int commentPosition);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve la cantidad de comentarios que tiene @card
	 */
	unsigned int GetCommentCount(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve el primer comentario de @card. Si no hay comentarios en @card devuelve NULL
	 */
	CardComment* GetFirstComment(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve el último comentario de @card. Si no hay comentarios en @card devuelve NULL
	 */
	CardComment* GetLastComment(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve el identificador de @card
	 */
	string GetId(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Cambia el nombre de @card por @name
	 */
	void SetName(Card* card, string name);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Devuelve el nombre de @card
	 */
	string GetName(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Cambia la descripción de @card por @description
	 */
	void SetDescription(Card* card, string description);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Obtiene la descripción de @card
	 */
	string GetDescription(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Cambia el responsable asignado de @card por @assigned
	 */
	void SetAssigned(Card* card, string assigned);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Obtiene el responsable asignado de @card
	 */
	string GetAssigned(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Obtiene la fecha y hora de creación de @card en formato [dd/mm/aaaa HH:mm:ss]
	 */
	string GetCreationDate(Card* card);

	/*
	 * Precondición: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondición: Libera todos los recursos asociados de @card
	 */
	void DestroyCard(Card* card);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Cambia el estado de @card por @state
	 */
	void SetState(Card* card, State* state);

	/*
	 * Precondici�n: @card fue creado con la primitiva KanbanBoardCard::CreateCard.
	 * Postcondici�n: Obtiene el estado de @card
	 */
	State* GetState(Card* card);
}