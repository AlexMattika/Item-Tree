/*******************************************************************
*   Character.cpp
*   Alexander Abel-Boozer
*******************************************************************/

#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1

#include "Character.h"
#include "Item.h"
#include "Possessions.h"
#include <iostream>
#include <iomanip>



using namespace std;

//Default class constructor
Character::Character() {

	m_pNext = NULL;

	m_iCharacterTraits = new int [6];

	strcpy_s(m_sName, "");
	m_iClass = 0;
	m_iAlignment = 0;
	m_iHitPoints = 0;

	for (int i = 0; i < 6; ++i) {
		m_iCharacterTraits[i] = 0;
	}

	m_pBattleItems = new Possessions();
	m_pTreasureItems = new Possessions();

	//cout << "Now executing Character constructor." << endl;


}

//Paramterized constructor
//Initialize character traits array
Character::Character(char *name, int Class, int Alignment, int HitPoints, int Strength,
             int Dexterity, int Constitution, int Intelligence, int Wisdom,
             int Charisma) {
	
	m_pNext = NULL;
	
	m_iCharacterTraits = new int[6];

	strcpy_s(m_sName, name);
	m_iClass = Class;
	m_iAlignment = Alignment;
	m_iHitPoints = HitPoints;

	m_iCharacterTraits[0] = Strength;
	m_iCharacterTraits[1] = Dexterity;
	m_iCharacterTraits[2] = Constitution;
	m_iCharacterTraits[3] = Intelligence;
	m_iCharacterTraits[4] = Wisdom;
	m_iCharacterTraits[5] = Charisma;

	m_pBattleItems = new Possessions();
	m_pTreasureItems = new Possessions();

	//cout << "Now executing Character constructor." << endl;

	//cout << "Now executing Character parameterized constructor." << endl;
}

//Class destructor
//Delete character traits array
Character::~Character() {
	
	delete[] m_iCharacterTraits;

	delete m_pBattleItems;
	delete m_pTreasureItems;

	//cout << "Now executing Character destructor." << endl;
}

char *Character::getName() {

	return m_sName;

	//cout << "Now executing Character::getName function." << endl;
}

void Character::setName(char *name) {

	strcpy(m_sName, name);

	//cout << "Now executing Character::setName function." << endl;
}

int Character::getClass() {

	return m_iClass;

	//cout << "Now executing Character::getClass function." << endl;
}

void Character::setClass(int cl) {

	m_iClass = cl;

	//cout << "Now executing Character::setClass function." << endl;
}

int Character::getAlignment() {

	return m_iAlignment;

	//cout << "Now executing Character::getAlignment function." << endl;
}

void Character::setAlignment(int al) {

	m_iAlignment = al;

	//cout << "Now executing Character::setAlignment function." << endl;
}

int Character::getHitPoints() {

	return m_iHitPoints;

	//cout << "Now executing Character::getHitPoints function." << endl;
}

void Character::setHitPoints(int hp) {

	m_iHitPoints = hp;

	//cout << "Now executing Character::setHitPoints function." << endl;
}

int Character::getStrength() {

	return m_iCharacterTraits[0];

	//cout << "Now executing Character::getStrength function." << endl;
}

void Character::setStrength(int str) {

	m_iCharacterTraits[0] = str;

	//cout << "Now executing Character::setStrength function." << endl;
}

int Character::getDexterity() {

	return m_iCharacterTraits[1];

	//cout << "Now executing Character::getDexterity function." << endl;
}

void Character::setDexterity(int dex) {

	m_iCharacterTraits[1] = dex;

	//cout << "Now executing Character::setDexterity function." << endl;
}

int Character::getConstitution() {

	return m_iCharacterTraits[2];

	//cout << "Now executing Character::getConstitution function." << endl;
}

void Character::setConstitution(int con) {

	m_iCharacterTraits[2] = con;

	//cout << "Now executing Character::setConstitution function." << endl;
}

int Character::getIntelligence() {

	return m_iCharacterTraits[3];

	//cout << "Now executing Character::getIntelligence function." << endl;
}

void Character::setIntelligence(int itl) {

	m_iCharacterTraits[3] = itl;

	//cout << "Now executing Character::setIntelligence function." << endl;
}

int Character::getWisdom() {

	return m_iCharacterTraits[4];

	//cout << "Now executing Character::getWisdom function." << endl;
}

void Character::setWisdom(int wis) {

	m_iCharacterTraits[4] = wis;

	//cout << "Now executing Character::setWisdom function." << endl;
}

int Character::getCharisma() {

	return m_iCharacterTraits[5];

	//cout << "Now executing Character::getCharisma function." << endl;
}

void Character::setCharisma(int chr) {

	m_iCharacterTraits[5] = chr;

	//cout << "Now executing Character::setCharisma function." << endl;
}


//-----------------------------------------------
// Add an item to the tree of items
//-----------------------------------------------
bool Character::addItem(Item *item)
{

	if(item->m_iType == 1)
		return m_pBattleItems->addItem(item);
	else
		return m_pTreasureItems->addItem(item);

}

//-----------------------------------------------
// Get a pointer to an item in the tree
//-----------------------------------------------
Item *Character::getItem(char *itemName)
{
	if(m_pBattleItems->getItem(itemName) != NULL)
		return m_pBattleItems->getItem(itemName);
	else
		return m_pTreasureItems->getItem(itemName);
}


//-----------------------------------------------
// Delete an item from the tree of items.  Return
// pointer to item if the item was found or NULL
// if it was not found in the tree.
//-----------------------------------------------
Item *Character::dropItem(char *itemName)
{
	
	Item *returnItem;

	returnItem = m_pBattleItems->dropItem(itemName);

	if(returnItem != NULL)
		return returnItem;
	else
		return m_pTreasureItems->dropItem(itemName);

    //return NULL;
}

void Character::printAll() {

	//cout << "Now executing Character::printAll function." << endl;

	cout << endl << m_sName << setw(6) << m_iClass << setw(6) << m_iAlignment << setw(6) << m_iHitPoints << setw(6);

	for (int i = 0; i < 6; ++i) {
		cout << m_iCharacterTraits[i] << setw(4);
	}

	cout << endl << '\t' << '\t' << "Battle Items Carried:" << endl;
	m_pBattleItems->printTree();
	cout << endl << '\t' << '\t' << "Treasure Items Carried:" << endl;
	m_pTreasureItems->printTree();
	
	cout << endl;

}