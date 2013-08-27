/*
 * SortElementsByFrequency.h
 *
 *  Created on: Apr 26, 2013
 *      Author: Avinash
 */
//
// Testing Status
//
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef SORTELEMENTSBYFREQUENCY_H_
#define SORTELEMENTSBYFREQUENCY_H_
struct auxDS{
	int value;
	int frequency;
};
bool frequencySortFunction(auxDS firstElement,auxDS secondElement){
	return firstElement.frequency > secondElement.frequency;
}

void SortElementsByFrequency(int userInput[],int sizeOfArray){
	hash_map<int,int> frequencyTable;
	hash_map<int,int>::iterator itToFrequencyTable;
	set<int> uniqueElements;
	set<int>::iterator itToUniqueElements;
	int numberOfUniqueElements = 0;
	int frequencyOfKey = -1;

	for(int counter=0;counter < sizeOfArray;counter++){
		if((itToFrequencyTable = frequencyTable.find(userInput[counter]))!=frequencyTable.end()){
			frequencyOfKey = itToFrequencyTable->second;
		}else{
			uniqueElements.insert(itToFrequencyTable->second);
			numberOfUniqueElements++;
		}
		frequencyTable[userInput[counter]] = ++frequencyOfKey;
	}

	auxDS arrayOfElements[numberOfUniqueElements];
	int crawlerToArray = -1;
	for(itToUniqueElements = uniqueElements.begin();itToFrequencyTable != uniqueElements.end();itToFrequencyTable++){
		arrayOfElements[++crawlerToArray].frequency = itToFrequencyTable->second;
		arrayOfElements[crawlerToArray].value = itToFrequencyTable->first;
	}

	//Sort Elements By Frequency and fill the input array
	sort(arrayOfElements,arrayOfElements+numberOfUniqueElements,frequencySortFunction);
	for(int counter=0;counter < numberOfUniqueElements;counter++){
		userInput[counter] = arrayOfElements[counter].value;
	}
}

struct BSTUpgradedNode{
	int value;
	int frequency;
	BSTUpgradedNode *left;
	BSTUpgradedNode *right;
	BSTUpgradedNode *parent;
};

void InsertElementInBSTForFrequencySort(BSTUpgradedNode **ptr,int value){
	if((*ptr) == NULL){
		BSTUpgradedNode *newNode;
		newNode = (BSTUpgradedNode *)malloc(sizeof(BSTUpgradedNode));
		newNode->frequency = 1;
		newNode->value = value;
		newNode->parent = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
	}else{
		BSTUpgradedNode *crawler = *ptr;
		while(crawler != NULL){
			if(crawler->value == value){
				crawler->frequency += 1;
				return;
			}
			if(crawler->value > value){
				if(crawler->left != NULL){
					crawler = crawler->left;
				}else{
					crawler->left = (BSTUpgradedNode *)malloc(sizeof(BSTUpgradedNode));
					crawler->left->frequency = 1;
					crawler->left->value = value;
					crawler->left->parent = crawler;
					crawler->left->left = NULL;
					crawler->left->right = NULL;
					return;
				}
			}else{
				if(crawler->right != NULL){
					crawler = crawler->right;
				}else{
					crawler->right = (BSTUpgradedNode *)malloc(sizeof(BSTUpgradedNode));
					crawler->right->frequency = 1;
					crawler->right->value = value;
					crawler->right->parent = crawler;
					crawler->right->left = NULL;
					crawler->right->right = NULL;
					return;
				}
			}
		}
	}
}

void GetInorderNodesBSTFrequencySort(BSTUpgradedNode *ptr,vector<int> &inOrderNodes){
	if(ptr == NULL){
		return;
	}
	GetInorderNodesBSTFrequencySort(ptr->left,inOrderNodes);
	auxDS node;
	node.value = ptr->value;
	node.frequency = ptr->frequency;
	inOrderNodes.push_back(node);
	GetInorderNodesBSTFrequencySort(ptr->right,inOrderNodes);
}

void SortElementsByBST(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return;
	}
	BSTUpgradedNode **rootToBST = null;
	for(int counter = 0;counter < sizeOfArray;counter++){
		InsertElementInBSTForFrequencySort(rootToBST,userInput[counter]);
	}
	vector<auxDS> inOrderNodes;
	GetInorderNodesBSTFrequencySort(*rootToBST,inOrderNodes);
	sort(inOrderNodes.begin(),inOrderNodes.end(),frequencySortFunction);
	int frequency,fillCounter = -1;
	for(int counter =0;counter < sizeOfArray;counter++){
		frequency = inOrderNodes[counter].frequency;
		while(frequency--){
			userInput[++fillCounter] = inOrderNodes[counter].value;
		}
	}
	return;
}

#endif /* SORTELEMENTSBYFREQUENCY_H_ */
