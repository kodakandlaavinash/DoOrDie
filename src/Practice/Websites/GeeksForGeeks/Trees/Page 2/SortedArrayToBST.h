/*
 * SortedArrayToBST.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef SORTEDARRAYTOBST_H_
#define SORTEDARRAYTOBST_H_

tNode *ConstructBSTUsingSortedArray(int userInput[],int startIndex,int endIndex){
	if(sizeOfArray == 0){
		return NULL;
	}

	int middleOfArray = (startIndex+endIndex)/2;
	tNode *nodeOfBST = (tNode *)malloc(sizeof(tNode));
	nodeOfBST->value = userInput[middleOfArray];
	nodeOfBST->left = ConstructBSTUsingSortedArray(userInput,startIndex,middleOfArray-1);
	nodeOfBST->right = ConstructBSTUsingSortedArray(userInput,middleOfArray+1,endIndex);
	return nodeOfBST;
}

struct auxSpaceForConversion{
	int startIndex;
	int endIndex;
};

tNode *ConstructBSTUsingSortedArrayIterative(int userInput[],int sizeOfUserInput){
	if(sizeOfUserInput == 0 || userInput == NULL){
		return NULL;
	}
	queue<auxSpaceForConversion> auxSpace;
	queue<tNode *>	auxSpaceForNodes;
	auxSpaceForConversion temp,currentElement;
	tNode *currentNode;
	temp.startIndex = 0;
	temp.endIndex = sizeOfUserInput -1;
	int middleElement;
	while(!auxSpace.empty()){
		currentElement = auxSpace.front();
		middleElement = (currentElement.startIndex +  currentElement.endIndex)/2;

	}
}

#endif /* SORTEDARRAYTOBST_H_ */
