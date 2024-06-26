#include <string>
#include "Card.h"
#include <time.h> 

using namespace std;
using namespace KanbanBoardCard;

struct KanbanBoardCard::Node {
	CardComment* cardComment;
	Node* next;
};

struct KanbanBoardCard::List {
	Node* first;
	Node* last;
	int itemsCount;
};

struct KanbanBoardCard::Card
{
	// TODO: ¿Agregar un TDA Type{Story, Task, Bug, Epic} a la carta?
	string id;
	string name;
	string description;
	string assigned;
	string creationDate;
	List* comments;
	State* state;
};

List* CreateEmptyList()
{
	List* newList = new List;
	newList->first = NULL;
	newList->last = NULL;
	newList->itemsCount = 0;
	return newList;
}

Node* CreateLastNode(CardComment* comment) {
	Node* newNode = new Node;
	newNode->cardComment = comment;
	newNode->next = NULL;
	return newNode;
}

bool IsEmpty(const List* list) {
	return list->itemsCount == 0;
}

Card* KanbanBoardCard::CreateCard(string id, string name) {
	time_t localHour;
	time(&localHour);
	Card* nuevaCard = new Card;
	nuevaCard->id = id;
	if (name[0] == 0)
	{
		nuevaCard->name = "<Sin Nombre>";
	}
	nuevaCard->name = name;
	// TODO: preguntar a valen como arreglar nuevamente esto :(
	nuevaCard->creationDate = "TIEMPO Y HORA OMG";//ctime(&localHour);
	nuevaCard->assigned;
	nuevaCard->description;
	// TODO: Iniciar el state en null indico el profe... ¿Y el resto? (En otro grupo estaba casi todo inicializado en null).
	nuevaCard->state = NULL;
	nuevaCard->comments = CreateEmptyList();

	return nuevaCard;
}

void KanbanBoardCard::DestroyCard(Card* card)
{
	//TODO: Destruir todos los comentarios (destroyCardComment por cada item de la lista).
	//TODO: Destruir lista (delate nodos y lista).
	//TODO: Destruir el state si no es null.
	delete card;
}

string KanbanBoardCard::GetId(Card* card)
{
	return card->id;
}

void KanbanBoardCard::SetAssigned(Card* card, string assigned)
{
	card->assigned = assigned;
}

string KanbanBoardCard::GetAssigned(Card* card) {
	return card->assigned;
}

string KanbanBoardCard::GetCreationDate(Card* card) {
	return card->creationDate;
}

string KanbanBoardCard::GetName(Card* card) {
	return card->name;
}

void KanbanBoardCard::SetName(Card* card, string name) {
	card->name = name;
}

void KanbanBoardCard::SetDescription(Card* card, string description)
{
	card->description = description;
}

string KanbanBoardCard::GetDescription(Card* card)
{
	return card->description;
}

void KanbanBoardCard::SetState(Card* card, State* state)
{
	// TODO: Si no es null llamar al destroy con el que estaba antes.
	card->state = state;
}

State* KanbanBoardCard::GetState(Card* card)
{
	return card->state;
}

void KanbanBoardCard::AddComment(Card* card, CardComment* comment) {
	Node* newLast = CreateLastNode(comment);
	if (IsEmpty(card->comments)) {
		card->comments->first = newLast;
		card->comments->last = newLast;
	}
	else {
		card->comments->last->next = newLast;
		card->comments->last = newLast;
	}
	card->comments->last = newLast;
	card->comments->itemsCount++;
}

unsigned int KanbanBoardCard::GetCommentCount(Card* card)
{
	return card->comments->itemsCount;
}

CardComment* KanbanBoardCard::GetFirstComment(Card* card) {
	return card->comments->first->cardComment;
}

CardComment* KanbanBoardCard::GetLastComment(Card* card) {
	return card->comments->last->cardComment;
}

CardComment* KanbanBoardCard::GetComment(Card* card, unsigned int commentPosition) {
	Node* nodeComment = NULL;
	if (commentPosition <= card->comments->itemsCount) {
		nodeComment = card->comments->first;
		for (int i = 0; i < commentPosition; i++)
		{
			nodeComment = nodeComment->next;
		}
		return nodeComment->cardComment;
	}
	else {
		return NULL;
	}
}