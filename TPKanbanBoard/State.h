#define STATE_H_

#include <string>

using std::string;

namespace KanbanBoardState {
	struct State;

	/*
	 * Precondici�n: ninguna
	 * Postcondici�n: Devuelve una instancia v�lida de State con con el nombre @name. Si @name es vacio establece como nombre de @state
	 * el valor "<Sin Nombre>"
	 */
	State* CreateState(string name);

	/*
	 * Precondici�n: @state fue creado con la primitiva KanbanBoardState::CreateState.
	 * Postcondici�n: Devuelve el nombre de @state
	 */
	string GetName(const State* state);

	/*
	 * Precondici�n: @state fue creada con la primitiva KanbanBoardState::DestroyState
	 * Postcondici�n: Libera todos los recursos asociados de @state
	 */
	void DestroyState(State* state);
}