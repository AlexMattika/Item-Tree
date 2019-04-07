/*******************************************************************
*   CharacterList.cpp
*   Alexander Abel-Boozer
*
*   Driver for testing this program
*******************************************************************/

#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1

#include "Character.h"
#include "Possessions.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void addItems(Character *player);
void TestClass(string classname, int& testresult, int& expectedresult);
void deleteItem(Character *character, char *itemname);

int main() {

	Item *testitem;
	testitem = new Item;
	strcpy(testitem->m_sItemName, "Axe");
	strcpy(testitem->m_sDesc, "Description");
	testitem->m_dValue = 8.5;
	testitem->m_dWeight = 11.4;
	testitem->m_iType = BATTLE_ITEM;
	testitem->m_pLeft = testitem->m_pRight = NULL;

	Item *item4 = new Item;
	strcpy(item4->m_sItemName, "B_TItem_4");
	strcpy(item4->m_sDesc, "Description");
	item4->m_dValue = 8.5;
	item4->m_dWeight = 11.4;
	item4->m_iType = TREASURE_ITEM;
	item4->m_pLeft = item4->m_pRight = NULL;


	Character *character = new Character("Brumble", 1, 2, 3, 4, 5, 6, 7, 8, 9);
	//TestClass("Character constructor", testresult, expectedresult);

	character->printAll();

	cout << endl << endl;



	

	cout << endl << endl;
	character->printAll();
	cout << endl << endl;

	cout << endl << endl << "Now testing Possessions class." << endl;

	//Possessions *possessions = new Possessions;
	
	addItems(character);

	character->printAll();

	//delete testitem;

	cout << "Testing getItem function." << endl << endl;

	testitem = character->getItem("B_TItem_4");

	if(testitem == NULL)
		cout << "Item not returned." << endl;
	else{
		cout << "Item returned successfully." << endl;
		cout << "Item:" << '\t'
		<< "Name=" << testitem->m_sItemName << '\t'
		<< "Val=" << testitem->m_dValue << '\t'
		<< "Wt=" << testitem->m_dWeight << '\t'
		<< "m_iType=" << testitem->m_iType << endl;

		cout << "m_sDesc=" << testitem->m_sDesc << endl;}

	cout << endl << endl << "Testing dropItem function." << endl << endl;

	deleteItem(character, "B_TItem_167");
	character->printAll();
	deleteItem(character, "B_TItem_7");
	character->printAll();
	deleteItem(character, "B_TItem_2");
	character->printAll();
	deleteItem(character, "B_TItem_6");
	character->printAll();
	deleteItem(character, "B_TItem_1");
	character->printAll();
	deleteItem(character, "B_TItem_4");
	character->printAll();
	deleteItem(character, "B_TItem_3");
	character->printAll();
	character->addItem(item4);
	character->printAll();
	deleteItem(character, "B_TItem_5");
	character->printAll();
	deleteItem(character, "B_TItem_4");


	character->printAll();

	delete character;

	//character->printAll();

	do {
		cout << '\n' << "Press the Enter key to continue.";
	} while (cin.get() != '\n');

	return 0;
}

void TestClass(string classname, int& testresult, int& expectedresult){

	char ans;

	cout << "Did you see printed:\n\t\"Now executing " << classname << "\"? (Press Y or N)";
	cin.get(ans);
	if ((ans == 'Y' || ans == 'y'))
		testresult++;
	expectedresult++;
	cin.ignore(10, '\n');
	cout << endl << endl;
}

void addItems(Character *player){
	Item *item;
	char index[2];
	char initials[3];
	char *cpt;
	int i;
	double points = 0.0;

	// Battle Items
	for(i=1; i <= 7; ++i){
		switch(i){
			case 1 : strcpy(index, "4"); break;
			case 2 : strcpy(index, "2"); break;
			case 3 : strcpy(index, "6"); break;
			case 4 : strcpy(index, "1"); break;
			case 5 : strcpy(index, "3"); break;
			case 6 : strcpy(index, "5"); break;
			case 7 : strcpy(index, "7"); break;
		}
		item = new Item();
		initials[0] = player->getName()[0];
		initials[1] = '\0';

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_BItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Battle item");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, player->getName());
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = BATTLE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		if(!player->addItem(item)){
			cout << "Failed to add battle item " << item->m_sItemName <<
				" to " << player->getName() << "'s list.\n";
		}
	}
	// Treasure Items
	for(i=1; i <= 7; ++i){
		switch(i){
			case 1 : strcpy(index, "4"); break;
			case 2 : strcpy(index, "2"); break;
			case 3 : strcpy(index, "6"); break;
			case 4 : strcpy(index, "1"); break;
			case 5 : strcpy(index, "3"); break;
			case 6 : strcpy(index, "5"); break;
			case 7 : strcpy(index, "7"); break;
		}
		item = new Item();
		initials[0] = player->getName()[0];
		initials[1] = '\0';

		strcpy(item->m_sItemName, initials);
		strcat(item->m_sItemName, "_TItem_");
		strcat(item->m_sItemName, index);
		strcpy(item->m_sDesc, "Treasure item");
		strcat(item->m_sDesc, index);
		strcat(item->m_sDesc, " for ");
		strcat(item->m_sDesc, player->getName());
		item->m_dValue = i*2;
		item->m_dWeight = i*3;
		item->m_iType = TREASURE_ITEM;
		item->m_pLeft = item->m_pRight = NULL;
		if(!player->addItem(item)){
			cout << "Failed to add treasure item " << item->m_sItemName <<
				" to " << player->getName() << "'s list.\n";
		}
	}
}

void deleteItem(Character *character, char *itemname){
	
	Item *testitem = new Item;

	testitem = character->dropItem(itemname);

	if(testitem == NULL)
		cout << "Item not returned." << endl;
	else{
		cout << "Item returned successfully." << endl;
		cout << "Item:" << '\t'
		<< "Name=" << testitem->m_sItemName << endl;
	}
}