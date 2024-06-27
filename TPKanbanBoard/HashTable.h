#include "Card.h"
#pragma once
using KanbanBoardCard::Card;

namespace KanbanBoardHashTable {
	struct HashTable;

	HashTable* CreateHashTable(int sizeTable);

	void Insert(int k, Card* card);
	void Delete(int k);
	KanbanBoardCard::Card* Search(int k, string idCard);

	int HashFunction(int k);
	int StringToInt(string cardId); // TODO: Esto puede ser una funcion "externa" en el cpp... ¿Rompe la cohesion?

	void DeleteTable(HashTable* table);
}