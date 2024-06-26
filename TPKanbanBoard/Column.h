#include <string>
#include "State.h"

using namespace std;
using KanbanBoardCard::Card;
using KanbanBoardState::State;

namespace KanbanBoardColumn {
	struct Column;
	struct Node;
	struct List;

	/*
	 * Precondici�n: @state fue creado con la primitiva KanbanBoardState::CreateState.
	 * Postcondici�n: Devuelve una instancia v�lida de Column con con el titulo @title y con estado @state.
	 */
	Column* CreateColumn(string title, State* state);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve el titulo de @column
	 */
	string GetTitle(Column* column);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Cambia el titulo de @column por @title
	 */
	void SetTitle(Column* column, string title);

	/*
	 * Precondici�n:@column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve el estado de @column
	 */
	State* GetState(Column* column);

	/*
	 * Precondic�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @state fue creado con su primitiva creacional
	 * Postcondici�n:Cambia el estado de @column por @state
	 */
	void SetState(Column* column, State* state);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @card fue creado con su primitiva creacional
	 * Postcondici�n: Si @card ya existe en @column no realiza acci�n, caso contrario agrega @card al final de la columna y le asigna a @card el estado de @column
	 */
	void AddCard(Column* column, Card* card);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @card fue creado con su primitiva creacional
	 * Postcondici�n: Si @column tiene a @card, quita @card de la columna. Caso contrario no realiza ninguna acci�n
	 */
	void RemoveCard(Column* column, Card* card);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve la cantidad de Cards que tiene @column
	 */
	int CountCards(Column* column);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve la Card que se encuentra en la cima de @column. Si no hay Cards en @column devuelve NULL
	 */
	Card* GetTopPriorityCard(Column* column);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve la Card que se encuentra abajo de toda la Columna. Si no hay Cards en @column devuelve NULL
	 */
	Card* GetLastPriorityCard(Column* column);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn. @previousCard fue creado con su primitiva creacional
	 * Postcondici�n: Devuelve la card que sigue (con menor prioridad) a @previousCard. Es decir de la cima hacia abajo de la columna.
	 * Si @previousCard no existe o es la �ltima Card o @column esta vacia, devuelve NULL
	 */
	Card* GetNextCard(Column* column, Card* previousCard);


	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Devuelve la Card en @column que tiene el identificador @cardId. Si no existe devuelve NULL
	 */
	Card* GetCard(Column* column, string cardId);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Aumenta la prioridad de la Card con el identificador @cardId subiendola hacia arriba de la cima. Si no existe no realiza ninguna acci�n
	 */
	void UpCardPriority(Column* column, string cardId);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Sube la Card con el identificador @cardId a la suma de @column. Si no existe no realiza ninguna acci�n.
	 */
	void UpCardToTopPriority(Column* column, string cardId);

	/*
	 * Precondici�n: @column fue creado con la primitiva KanbanBoardColumn::CreateColumn.
	 * Postcondici�n: Libera todos los recursos asociados a @column
	 */
	void DestroyColumn(Column* column);
}