/*
 * DeleteAlternateNodesInLinkedList.h
 *
 *  Created on: May 3, 2013
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

#ifndef DELETEALTERNATENODESINLINKEDLIST_H_
#define DELETEALTERNATENODESINLINKEDLIST_H_

void DeleteAlternateNodesInLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *nodeToBeDeleted;
	while(ptr != NULL && ptr->next != NULL){
		nodeToBeDeleted = ptr->next;
		ptr->next = ptr->next->next;
		free(nodeToBeDeleted);
		ptr = ptr->next;
	}
}

void DeleteAlternateNodeInLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *crawler = ptr;
	queue<int> valuesToBeList;
	valuesToBeList.push(crawler->value);
	while(crawler != NULL){
		valuesToBeList.push(crawler->value);
		if(crawler->next != NULL){
			crawler = crawler->next->next;
		}else{
			crawler = crawler->next;
		}
	}

	// Insert into the linked list
	crawler = ptr;
	linkedListNode *endOfLinkedList;
	while(!valuesToBeList.empty()){
		crawler->value = valuesToBeList.front();
		valuesToBeList.pop();
		endOfLinkedList = crawler;
		crawler = crawler->next;
	}
	endOfLinkedList->next = NULL;
	DeleteEntireLinkedList(crawler);
}

void DeleteAlternateNodesInLinkedListRecursion(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->next != NULL){
		linkedListNode *nodeToBeDeleted = ptr->next;
		ptr->next = ptr->next->next;
		free(nodeToBeDeleted);
	}else{
		return;
	}
	DeleteAlternateNodesInLinkedListRecursion(ptr->next);
}

void DeleteAlternateNodesInLinkedListByCreatingNewOne(linkedListNode **ptr){
	if(*ptr == NULL){
		return;
	}
	linkedListNode *crawler = *ptr;
	linkedListNode *newList = (linkedListNode *)malloc(sizeof(linkedListNode));
	newList->value = crawler->value;
	newList->next  = NULL;

	crawler = crawler->next;
	while(crawler != NULL){
		newList->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		newList->next->value = crawler->value;
		newList->next->next = NULL;
		newList = newList->next;
		crawler = crawler->next;
	}

	DeleteEntireLinkedList(*ptr);
	*ptr = newList;
}


#endif /* DELETEALTERNATENODESINLINKEDLIST_H_ */
