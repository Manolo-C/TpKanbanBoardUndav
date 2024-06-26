#include "Card.h"
#include "State.h"
#include "Column.h"
#include <string>

using namespace std;
using namespace KanbanBoardCard;
using namespace KanbanBoardColumn;

struct KanbanBoardColumn::Column {
	string title;
	State* state;
	List* cards;
};

struct KanbanBoardColumn::Node {
	Card* card;
	Node* next;
};

struct KanbanBoardColumn::List {
	Node* first;
	Node* last;
	int itemsCount;
};

KanbanBoardColumn::Node* CreateLastNode(Card* card) {
	KanbanBoardColumn::Node* node = new KanbanBoardColumn::Node;
	node->card = card;
	node->next = nullptr;
	return node;
}

// TODO: (CONSULTA) Misma funcion que en card.cpp para crear una lista vacia de cartas en CreateColumn.
KanbanBoardColumn::List* CreateEmptyList()
{
	KanbanBoardColumn::List* newList = new KanbanBoardColumn::List;
	newList->first = nullptr;
	newList->last = nullptr;
	newList->itemsCount = 0;
	return newList;
}

Column* KanbanBoardColumn::CreateColumn(string title, State* state)
{
	Column* newColumn = new Column();
	newColumn->title = title;
	newColumn->state = state;
	newColumn->cards = CreateEmptyList();
	return newColumn;
}

string KanbanBoardColumn::GetTitle(Column* column)
{
	return column->title;
}

void KanbanBoardColumn::SetTitle(Column* column, string title)
{
	column->title = title;
}

State* KanbanBoardColumn::GetState(Column* column)
{
	return column->state;
}

void KanbanBoardColumn::SetState(Column* column, State* state)
{
	column->state = state;
}

void KanbanBoardColumn::AddCard(Column* column, Card* card)
{
	// TODO: (LISTO) replanteo AddCard
	if (GetCard(column, KanbanBoardCard::GetId(card)) == nullptr) {
		if (column->cards->first == nullptr) {
			column->cards->first = CreateLastNode(card);
			KanbanBoardCard::SetState(column->cards->first->card, column->state);
		}
		else {
			Node* iteratorNode = column->cards->first;
			while (iteratorNode->next != nullptr) {
				iteratorNode = iteratorNode->next;
			}
			iteratorNode->next = CreateLastNode(card);
			column->cards->last = iteratorNode->next;
			KanbanBoardCard::SetState(column->cards->last->card, column->state);
		}
		column->cards->itemsCount++;
	}
}

void KanbanBoardColumn::RemoveCard(Column* column, Card* card)
{
	// TODO: (LISTO?) RemoveCard, revisar esos if raris
	Node* iteratorNode = column->cards->first;
	Node* prevNode = nullptr;

	if (iteratorNode == nullptr) return;
	while (iteratorNode != nullptr && iteratorNode->card != card) {
		prevNode = iteratorNode;
		iteratorNode = iteratorNode->next;
	}
	if (iteratorNode == nullptr) return;
	if (prevNode == nullptr) {
		column->cards->first = iteratorNode->next;
	}
	else {
		prevNode->next = iteratorNode->next;
	}
	if (iteratorNode == column->cards->last) {
		column->cards->last == nullptr;
	}
	delete iteratorNode;
	column->cards->itemsCount--;
}

Card* KanbanBoardColumn::GetNextCard(Column* column, Card* previousCard) {
	// TODO: (LISTO) replanteo GetNextCard
	/*if () {
		return column->nextCard;
	}
	else {
		return NULL;
	}*/
	Node* iteratorNode = column->cards->first;
	while (iteratorNode != nullptr && iteratorNode->card != previousCard) {
		iteratorNode = iteratorNode->next;
	}
	if (iteratorNode != nullptr && iteratorNode->next != nullptr)
	{
		return iteratorNode->next->card;
	}
	else {
		return nullptr;
	}
}

Card* KanbanBoardColumn::GetCard(Column* column, string id) {
	// TODO: (LISTO) replanteo GetCard.
	/*Card* card = column->topPriorityCard;
	while (card != NULL) {
		if (GetId(card) == id) {
			return card;
		}
		card.
	}
	return NULL;*/
	Node* iteratorNode = column->cards->first;
	while (iteratorNode != nullptr) {
		if (KanbanBoardCard::GetId(iteratorNode->card) == id) {
			return iteratorNode->card;
		}
		iteratorNode = iteratorNode->next;
	}
	return nullptr;
}

void KanbanBoardColumn::UpCardPriority(Column* column, string cardId) {
	// TODO: (LISTO?) replanteo UpCardPriority.
	Card* aimCard = GetCard(column, cardId);

	if (aimCard != nullptr && column->cards->first->card != aimCard) {
		Node* prevAuxAimNode = nullptr;
		Node* aimNode = column->cards->first;
		Node* prevNode = nullptr;

		while (aimNode != nullptr && aimNode->card != aimCard) {
			prevNode = aimNode;
			aimNode = aimNode->next;
		}

		if (aimNode != nullptr && prevNode != nullptr) {
			if (aimNode->next != nullptr) {
				prevNode->next = aimNode->next;
			}
			else {
				prevNode->next = nullptr;
			}

			if (prevNode == column->cards->first) {
				aimNode->next = column->cards->first;
				column->cards->first = aimNode;
			}
			else {
				Node* prevPrevNode = column->cards->first;
				while (prevPrevNode->next != prevNode) {
					prevPrevNode = prevPrevNode->next;
				}
				prevPrevNode->next = aimNode;
				aimNode->next = prevNode;
			}
			if (aimNode == column->cards->last) {
				column->cards->last = prevNode;
			}
		}
	}
}

void KanbanBoardColumn::UpCardToTopPriority(Column* column, string cardId) {
	// TODO: (LISTO?) replanteo UpCardToTopPriority.
	Card* objectiveCard = GetCard(column, cardId);

	if (objectiveCard != nullptr && column->cards->first->card != objectiveCard) {
		Node* prevNode = nullptr;
		Node* iteratorNode = column->cards->first;

		while (iteratorNode != nullptr && iteratorNode->next->card != objectiveCard) {
			iteratorNode = iteratorNode->next;
		}

		if (iteratorNode != nullptr && iteratorNode->next != nullptr) {
			Node* aimNode = iteratorNode->next;
			iteratorNode->next = aimNode->next;

			if (aimNode == column->cards->last) {
				column->cards->last = iteratorNode;
			}

			aimNode->next = column->cards->first;
			column->cards->first = aimNode;
		}
	}
}

int KanbanBoardColumn::CountCards(Column* column)
{
	// TODO: (LISTO) replanteo CountCards.
	/*int cardsCount=0;
	Card* firstCard = column->nextCard;
	while (!firstCard==NULL) {
		cardsCount++;
	}
	return cardsCount;*/
	return column->cards->itemsCount;
}

Card* KanbanBoardColumn::GetTopPriorityCard(Column* column)
{
	if (column->cards->first != nullptr) {
		return column->cards->first->card;
	}
	else {
		return nullptr;
	}
}

Card* KanbanBoardColumn::GetLastPriorityCard(Column* column)
{
	if (column->cards->last->card != nullptr) {
		return column->cards->last->card;
	}
	else {
		return nullptr;
	}
}

void KanbanBoardColumn::DestroyColumn(Column* column) {
	// TODO: ¿Aplicar lo mismo que en DestroyCard?
	delete column;
}