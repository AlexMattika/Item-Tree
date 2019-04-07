/*******************************************************************
*   CharacterList.cpp
*   Alexander Abel-Boozer
*   Programming Assignment 2
*
*   This program is entirely my own work
*******************************************************************/

#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1

#include "CharacterList.h"
#include "Character.h"
#include <iostream>
#include <iomanip>

using namespace std;

//default constructor
CharacterList::CharacterList(){

	m_pHead = NULL;

	//cout << "Now executing CharacterList::CharacterList default constructor function." << endl;
}

//default destructor
CharacterList::~CharacterList(){
	
	//cout << "Now executing CharacterList::~CharacterList default destructor function." << endl;

	Character *temp;

	if(m_pHead != NULL)
	{
		temp = m_pHead;

		// Scan list and free all nodes
		while(m_pHead != NULL)
		{
			temp = m_pHead;
			m_pHead = temp->m_pNext;
			delete temp;
		}
	}
}

bool CharacterList::addCharacter(Character *newCharacter){
	
	Character *temp = NULL, *back = NULL, *newnode = NULL;

	if (newnode == NULL)
		return false;
	newnode = newCharacter;
	newnode->m_pNext = NULL;

	//if list is empty insert new node at the head
	if(m_pHead == NULL){
		m_pHead = newnode;
	}
	else{

		//find a location for the new node
		temp = m_pHead;
		back = NULL;
		while((temp != NULL) && (strcmp(temp->getName(),newnode->getName())) < 0){
			back = temp;
			temp = temp->m_pNext;
		}
		// check to see if adding at the head of the list
		if(back == NULL){
			newnode->m_pNext = m_pHead;
			m_pHead = newnode;
		}
		else{ //insert elsewhere
			back->m_pNext = newnode;
			newnode->m_pNext = temp;
		}
	}

	//cout << "Now executing CharacterList::addCharacter function." << endl;

	return true; //successful insertion
}

Character *CharacterList::removeCharacter(const char *characterName){
	
	Character *temp = m_pHead, *back = NULL;

	//check if list is empty
	if(m_pHead == NULL)
		return NULL;

	//search for the item to delete
	while((temp != NULL) && (strcmp(temp->getName(),characterName) != 0)){
		back = temp;
		temp = temp->m_pNext;
	}

	//check to see if the character was found
	if (temp == NULL) //not found so return null
		return NULL;
	else if (back == NULL){ //if the character is the first in the list
		m_pHead = m_pHead->m_pNext;
		return temp; //return the removed node
	}
	else{ //delete node elsewhere
		back->m_pNext = temp->m_pNext;
		return temp; //return the removed node
	}

	
	
	//cout << "Now executing CharacterList::*removeCharacter function." << endl;

	return NULL; //to keep the compiler from giving a warning
}

bool CharacterList::addItem(const char *characterName, Item *newItem){
	//cout << "Now executing CharacterList::addItem function." << endl;

	Character *temp;

	temp = m_pHead;

	while((temp != NULL) && (strcmp(temp->getName(),characterName) != 0)){
		temp = temp->m_pNext;
	}

	//check to see if the character was found
	if (temp == NULL) //not found so return null
		return NULL;
	else{
		return temp->addItem(newItem); //item added
	}

	return NULL; //avoid compiler warning
}

Item *CharacterList::getItem(const char *characterName, char *itemName){
	//cout << "Now executing CharacterList::*getItem function." << endl;

	Character *temp;

	temp = m_pHead;

	while((temp != NULL) && (strcmp(temp->getName(),characterName) != 0)){
		temp = temp->m_pNext;
	}

	//check to see if the character was found
	if (temp == NULL) //not found so return null
		return NULL;
	else{
		return temp->getItem(itemName); //return the item
	}

	return NULL; //avoid compiler warning
}

Item *CharacterList::dropItem(const char *characterName, char *itemName){
	//cout << "Now executing CharacterList::*dropItem function." << endl;

		Character *temp;

	temp = m_pHead;

	while((temp != NULL) && (strcmp(temp->getName(),characterName) != 0)){
		temp = temp->m_pNext;
	}

	//check to see if the character was found
	if (temp == NULL) //not found so return null
		return NULL;
	else{
		return temp->dropItem(itemName); //return the item
	}

	return NULL; //avoid compiler warning

}

void CharacterList::printCharacters(){
	//cout << "Now executing CharacterList::printCharacters function." << endl;

	Character *temp;

	temp = m_pHead;

	while(temp != NULL){
	temp->printAll();
	temp = temp->m_pNext;
	}
}