/*******************************************************************
*   CharacterList.cpp
*   Alexander Abel-Boozer
*******************************************************************/

#ifdef _CRT_SECURE_NO_WARNINGS
#undef _CRT_SECURE_NO_WARNINGS
#endif
#define _CRT_SECURE_NO_WARNINGS 1

#include "Item.h"
#include "Character.h"
#include "Possessions.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Class Constructor and Destructor
Possessions::Possessions(){

	//cout << endl << "Now inside of Possessions::Possessions default constructor." << endl;

	m_pRoot = NULL;
			
}

Possessions::~Possessions(){

	//cout << endl << "Now inside of Possessions::~Possessions destructor." << endl;

	Possessions::destroyTree(m_pRoot);

}

//Public Functions
bool Possessions::addItem(Item *newItem){
	
	//cout << endl << "Now inside of Possessions::addItem function." << endl;

	Item *temp = m_pRoot;
	Item *back = NULL;

	while(temp != NULL){
		back = temp;
		if(strcmp(newItem->m_sItemName, temp->m_sItemName) < 0)
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if(back == NULL)
		m_pRoot = newItem;
	else{
		if(strcmp(newItem->m_sItemName, back->m_sItemName) < 0)
			back->m_pLeft = newItem;
		else
			back->m_pRight = newItem;
	}
	return true;
}

Item *Possessions::dropItem(char *itemName){

	//cout << endl << "Now inside of Possessions::dropItem function." << endl;

	Item *back = NULL;
	Item *temp = m_pRoot;
	Item *delParent = NULL;
	Item *delNode = NULL;

	// Search for the node
	while((temp != NULL) && (strcmp(temp->m_sItemName, itemName) != 0)){
		back = temp; // advance back pointer
		// advance temp
		if(strcmp(temp->m_sItemName, itemName) > 0)
			temp = temp->m_pLeft;
		else
			temp = temp->m_pRight;
	}

	if(temp == NULL){ // Check to see if the pointer was NOT found
		return NULL;
	}
	else{
	delNode = temp;
	delParent = back;
	}

	// Case 1: Deleting node with no children or possibly one child on left
	if(delNode->m_pRight == NULL){
		if(delParent == NULL){ // Check to see if deleting the root
		m_pRoot = delNode->m_pLeft;
		delNode->m_pLeft = delNode->m_pRight = NULL;
		return delNode;
		}
		else{
			// Deleting node other than root
			if(delParent->m_pLeft == delNode)
				delParent->m_pLeft = delNode->m_pLeft;
			else
				delParent->m_pRight = delNode->m_pLeft;
			delNode->m_pLeft = delNode->m_pRight = NULL;
			return delNode;
		}
	}
	else{ // There is a right child on delNode
		if(delNode->m_pLeft == NULL){ // Check to see if there is a left child
			// Case 2: No left child so deleting node with one child on the right
			if(delParent == NULL){ // Check to see if deleting the root
				m_pRoot = delNode->m_pRight;
				delNode->m_pLeft = delNode->m_pRight = NULL;
				return delNode;
			}
			else{ // Deleting node other than root
				if(delParent->m_pLeft == delNode)
					delParent->m_pLeft = delNode->m_pRight;
				else
					delParent->m_pRight = delNode->m_pRight;
				delNode->m_pLeft = delNode->m_pRight = NULL;
				return delNode;
			}
		}
		else // Case 3: Deleting node with two children
		{

			Item *returnNode = NULL; // Node to return delNode's information

			// Set pointers to find the replacement value. Locate the node in delNode's
			// left sub-tree containing the largest key
			temp = delNode->m_pLeft;
			back = delNode;
			// Search for the replacement node
			while(temp->m_pRight != NULL){
				back = temp;
				temp = temp->m_pRight;
			}

			returnNode = new Item();
			*returnNode = *delNode;
			returnNode->m_pLeft = NULL;
			returnNode->m_pRight = NULL;

			// Code to copy the replacement values into delNode
			strcpy(delNode->m_sItemName, temp->m_sItemName);
			delNode->m_dValue = temp->m_dValue;
			delNode->m_dWeight = temp->m_dWeight;
			delNode->m_iType = temp->m_iType;
			strcpy(delNode->m_sDesc, temp->m_sDesc);

			// Remove the replacement node from the tree
			if(back == delNode) // Is the replacement node delNode's left child?
				back->m_pLeft = temp->m_pLeft; // Yes
			else
				back->m_pRight = temp->m_pRight; // No, it's a descendent of left child
			delete temp;
			return returnNode;
		}
	}

	return NULL;
}

Item *Possessions::getItem(char *itemName){

	//cout << endl << "Now inside of Possessions::getItem function." << endl;


	Item *temp = m_pRoot;

	while((temp != NULL) && (strcmp(temp->m_sItemName, itemName) != 0)){
	//cout << strcmp(temp->m_sItemName, itemName) << endl;
	if(strcmp(temp->m_sItemName, itemName) > 0)
		temp = temp->m_pLeft;
	else
		temp = temp->m_pRight;
	}
	if(temp == NULL)
		return NULL;
	else
		return temp;
}

void Possessions::printTree(){

	//cout << endl << "Now inside of Possessions::printTree function." << endl;

	Possessions::printAll(m_pRoot);

}

//Private Functions
void Possessions::printItem(Item *item){

	//cout << endl << "Now inside of Possessions::printItem function." << endl;

	cout << "Item:" << '\t'
		<< "Name=" << item->m_sItemName << '\t'
		<< "Val=" << item->m_dValue << '\t'
		<< "Wt=" << item->m_dWeight << '\t'
		<< "m_iType=" << item->m_iType << endl;

	cout << "m_sDesc=" << item->m_sDesc << endl;

}

void Possessions::destroyTree(Item *rt){

	//cout << endl << "Now inside of Possessions::destroyTree function." << endl;

	if(rt != NULL){
		if(rt->m_pLeft != NULL)
			destroyTree(rt->m_pLeft); // Clear left subtree
		if(rt->m_pRight != NULL)
			destroyTree(rt->m_pRight); // Clear right subtree
		delete rt;
	}

}

void Possessions::printAll(Item *rt){

	//cout << endl << "Now inside of Possessions::printAll function." << endl;

	if(rt != NULL){
	printAll(rt->m_pLeft);
	printItem(rt);
	printAll(rt->m_pRight);
	}

}