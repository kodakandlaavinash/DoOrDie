/*
 * LinkedList.cpp
 *
 *  Created on: Apr 17, 2013
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

struct linkedListNode{
	int value;
	linkedListNode *next;

	linkedListNode(){
		value =0;
		next = null;
	}

	linkedListNode(int value){
		this->value = value;
		next = null;
	}
};

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

int main(){
	linkedListNode *head = null;
	CreateLinkedList(&head,10);
	CreateLinkedList(&head,20);
	CreateLinkedList(&head,30);
	return -1;
}
