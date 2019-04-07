/*******************************************************************
*   CharacterList.h
*   Alexander Abel-Boozer
*   Programming Assignment 2
*
*   This program is entirely my own work
*******************************************************************/

#pragma once

#include "Character.h"
#include "Item.h"

class CharacterList{
private:
	Character *m_pHead;

public:
	CharacterList(); //default constructor
	~CharacterList(); //default destructor
	bool addCharacter(Character *newCharacter);
	Character *removeCharacter(const char *characterName);
	bool addItem(const char *characterName, Item *newItem);
	Item *getItem(const char *characterName, char *itemName);
	Item *dropItem(const char *characterName, char *itemName);
	void printCharacters();
};