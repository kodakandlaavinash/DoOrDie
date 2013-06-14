/*
 * LinkedListUtil.h
 *
 *  Created on: Apr 18, 2013
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

//int main(){
//	return -1;
//}

#ifndef LINKEDLISTUTIL_H_
#define LINKEDLISTUTIL_H_
/*
 * Tested
 */
void CreateLinkedList(linkedListNode **ptr,int inputValue){
	/**
	 *Nodes are appended to the front node
	 */
	linkedListNode *newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
	newNode->value = inputValue;
	newNode->next = (*ptr);
	(*ptr) = newNode;
}

/*
 * Tested
 */
void PrintLinkedListIteration(linkedListNode *ptr){
	while(ptr != NULL){
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}
	printf("NULL");
}

/*
 * Tested
 */
void PrintLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		printf("NULL");
		return;
	}
	printf("%d->",ptr->value);
	PrintLinkedList(ptr->next);
}

/*
 *Tested
 */
void PrintReverseOfLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintReverseOfLinkedList(ptr->next);
	printf("%d ",ptr->value);
}

/*
 * Tested
 */
void PrintReverseOfLinkedListAuxSpace(linkedListNode *ptr){
	stack<int> auxSpace;
	while(ptr != NULL){
		auxSpace.push(ptr->value);
		ptr = ptr->next;
	}
	while(!auxSpace.empty()){
		printf("%d->",auxSpace.top());
		auxSpace.pop();
	}
	printf("NULL");
}

/*
 * Tested
 */
int lengthOfLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+lengthOfLinkedList(ptr->next);
}

/*
 * Tested
 */
int lengthOfLinkedListIteration(linkedListNode *ptr){
	int count =0;
	while(ptr != null){
		count++;
		ptr = ptr->next;
	}
	return count;
}

/**
 * The predeccesor and successor values can also
 * be obtained using the binary search tree
 */

/*
 * Tested
 * If the number is less than all the numbers in the list
 * then the function returns int min value
 */
int GetPredeccesor(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MIN;
	}
	linkedListNode *crawler = ptr;
	int predeccesor = INT_MIN;
	while(crawler != NULL){
		if(crawler->value <= value && predeccesor <= crawler->value ){
			predeccesor = crawler->value;
		}
		crawler = crawler->next;
	}
	return predeccesor;
}

/*
 * Tested
 */
int GetPredeccesorRecursive(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MIN;
	}
	int predecessor = GetPredeccesorRecursive(ptr->next,value);
	if(predecessor <= ptr->value && ptr->value <= value){
		return ptr->value;
	}else{
		return predecessor;
	}
}

/*
 * Tested
 * If the number is greater than all the numbers in the list
 * then the function returns int max value
 */
int GetSuccessor(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MAX;
	}
	int successor = INT_MAX;
	linkedListNode *crawler = ptr;
	while(crawler != null){
		if(crawler->value >= value && successor >= crawler->value){
			successor = crawler->value;
		}
		crawler = crawler->next;
	}
	return successor;
}

/*
 * Tested
 */
int GetSuccessorRecursive(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MAX;
	}
	int successor = GetSuccessorRecursive(ptr->next,value);
	if(ptr->value >= value && successor >= ptr->value){
		return ptr->value;
	}else{
		return successor;
	}
}

/*
 * 	Tested
 *	Assuming the position is always less than the length of the linked list
 */
void InsertANodeAtPosition(linkedListNode **ptr,int value,int position){
	if(position != 0){
		linkedListNode *crawler = *ptr;
		while(position--){
			crawler = crawler->next;
		}
		linkedListNode *newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = value;
		newNode->next = crawler->next;
		crawler->next = newNode;
	}else{
		linkedListNode * newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = value;
		newNode->next = *ptr;
		(*ptr) = newNode;
	}
}

void DeleteEntireLinkedList(linkedListNode *ptr){
	linkedListNode *nodeToBeDeleted;
	while(ptr != NULL){
		nodeToBeDeleted = ptr;
		ptr = ptr->next;
		free(nodeToBeDeleted);
	}
}


void DeletePartOfLinkedList(linkedListNode *startPtr,linkedListNode *endPtr){
	linkedListNode *nodeToBeDeleted;
	while(startPtr != endPtr->next){
		nodeToBeDeleted = startPtr;
		startPtr = startPtr->next;
		free(nodeToBeDeleted);
	}
}
#endif /* LINKEDLISTUTIL_H_ */
