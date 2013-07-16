/*
 * MemoryEfficientDoublyLinkedList.h
 *
 *  Created on: Jul 15, 2013
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

#ifndef MEMORYEFFICIENTDOUBLYLINKEDLIST_H_
#define MEMORYEFFICIENTDOUBLYLINKEDLIST_H_

struct xorDoublyLinkedList{
	int value;
	xorDoublyLinkedList *xorPtr;
};

xorDoublyLinkedList *FindXORValue(xorDoublyLinkedList *firstPtr,xorDoublyLinkedList *secondPtr){
	return (xorDoublyLinkedList *)((unsigned int)firstPtr ^ (unsigned int)secondPtr);
}

void CreateXORDoublyLinkedList(xorDoublyLinkedList **headOfXorDoublyLinkedList,int userInput){
	xorDoublyLinkedList *newNode = (xorDoublyLinkedList *)malloc(sizeof(xorDoublyLinkedList));
	newNode->value = userInput;
	if(*headOfXorDoublyLinkedList == NULL){
		newNode->xorPtr = FindXORValue(0,0);
		*headOfXorDoublyLinkedList = newNode;
	}else{
		xorDoublyLinkedList *traversalForLinkedList = headOfXorDoublyLinkedList;
		xorDoublyLinkedList *prevPtr = NULL;
		while(traversalForLinkedList != NULL){
			traversalForLinkedList = (traversalForLinkedList->xorPtr ^ prevPtr);
			prevPtr = traversalForLinkedList;
		}
		traversalForLinkedList->xorPtr = FindXORValue(newNode,prevPtr);
		newNode->xorPtr = FindXORValue(traversalForLinkedList,null);
	}
}

void TraverseXORDoublyLinkedList(xorDoublyLinkedList *headOfXorDoublyLinkedList){
	xorDoublyLinkedList *traverseXORList = headOfXorDoublyLinkedList;
	xorDoublyLinkedList *prevNode = null;
	while(traverseXORList == NULL){
		printf("%d",traverseXORList->value);
		traverseXORList = FindXORValue(traverseXORList->xorPtr,prevNode);
		prevNode = traverseXORList;
	}
}
#endif /* MEMORYEFFICIENTDOUBLYLINKEDLIST_H_ */
