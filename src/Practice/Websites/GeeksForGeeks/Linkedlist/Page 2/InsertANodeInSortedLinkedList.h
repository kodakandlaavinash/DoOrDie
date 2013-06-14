/*
 * InsertANodeInSortedLinkedList.h
 *
 *  Created on: Apr 19, 2013
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

#ifndef INSERTANODEINSORTEDLINKEDLIST_H_
#define INSERTANODEINSORTEDLINKEDLIST_H_

void InsertANodeInSortedLinkedList(linkedListNode **ptr,int newValueToBeAdded){
	linkedListNode *newNode;
	if(*ptr == NULL){
		// the list is empty
		newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = newValueToBeAdded;
		newNode->next = NULL;
		return;
	}else{
		linkedListNode *crawler = *ptr;
		if(crawler->value > newValueToBeAdded){
			// Head Node
			newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
			newNode->value = crawler->value;
			newNode->next = crawler->next;
			crawler->value = newValueToBeAdded;
		}else{
			// Any other node
			// loop
			newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
			newNode->value = crawler->value;
			while(crawler != ptr && crawler->next == ptr &&crawler->next->value < newValueToBeAdded){
				crawler = crawler->next;
			}
			newNode->next = crawler->next;
			crawler->next = newNode;
		}
	}
}

linkedListNode *GetThePtrToLastNodeInCirularLinkedList(linkedListNode *ptr,linkedListNode *head){
	if(ptr == NULL){
		return ptr;
	}
	if(ptr->next == head){
		return ptr;
	}
	return GetThePtrToLastNodeInCirularLinkedList(ptr->next,head);
}

void InsertIntoCircularLinkedList(linkedListNode *ptr,int newValueToBeAdded){
	linkedListNode *newNode;
	if(*ptr == NULL){
		// the list is empty
		newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = newValueToBeAdded;
		newNode->next = NULL;
		return;
	}else{
		linkedListNode *crawler = *ptr;
		if(crawler->value > newValueToBeAdded){
			// Head Node
			newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
			newNode->value = newValueToBeAdded;
			newNode->next = crawler->next;
			linkedListNode *ptrToLastNode = GetThePtrToLastNodeInCirularLinkedList(ptr,ptr);
			ptrToLastNode->next = newNode;
			*(ptr) = newNode;
		}else{
			// Any other node
			// loop
			newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
			newNode->value = crawler->value;
			while(crawler != ptr && crawler->next == ptr &&crawler->next->value < newValueToBeAdded){
				crawler = crawler->next;
			}
			newNode->next = crawler->next;
			crawler->next = newNode;
		}
	}
}

#endif /* INSERTANODEINSORTEDLINKEDLIST_H_ */
