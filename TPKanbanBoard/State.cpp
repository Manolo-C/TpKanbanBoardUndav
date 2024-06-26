#include <string>
#include "State.h"

using namespace std;
using namespace KanbanBoardState;

struct KanbanBoardState::State{
  string name;
};

State* KanbanBoardState::CreateState(string name) {
    State* nuevostate = new State;
    if (nuevostate != NULL) {
        nuevostate->name = name;
    }
    return nuevostate;
}

string KanbanBoardState::GetName(const State* state) {
    return state->name;
}

void KanbanBoardState::DestroyState(State* state) {
    // TODO: ¿Aplicar lo mismo que DestroyCard?
    delete state;
}
