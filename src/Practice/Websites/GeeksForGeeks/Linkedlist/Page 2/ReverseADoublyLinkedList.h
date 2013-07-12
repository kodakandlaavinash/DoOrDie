/*
 * ReverseADoublyLinkedList.h
 *
 *  Created on: Jul 9, 2013
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

#ifndef REVERSEADOUBLYLINKEDLIST_H_
#define REVERSEADOUBLYLINKEDLIST_H_

doublyLinkedList *GetTailOfDoublyLinkedList(doublyLinkedList *ptr){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->next == NULL){
		return ptr;
	}
	return GetTailOfDoublyLinkedList(ptr->next);

}

void ReverseADoublyLinkedListSwappingNumbers(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}
	doublyLinkedList *tailOfDoublyLinkedList = GetTailOfDoublyLinkedList(ptr);
	doublyLinkedList *crawler = ptr;
	int tempForSwap;
	while(crawler->next != tailOfDoublyLinkedList || crawler != tailOfDoublyLinkedList){
		tempForSwap = tailOfDoublyLinkedList->value;
		tailOfDoublyLinkedList->value = crawler->value;
		crawler->value = tempForSwap;
		tailOfDoublyLinkedList = tailOfDoublyLinkedList->prev;
		crawler = crawler->next;
	}
}

doublyLinkedList *ReverseADoublyLinkedListNewList(doublyLinkedList *ptr){
	if(ptr == NULL){
		return NULL;
	}
	doublyLinkedList *tail = GetTailOfDoublyLinkedList(ptr);
	doublyLinkedList *headOfReverseLinkedList;
	doublyLinkedList *tailOfReverseLinkedList;
	while(tail != null){
		doublyLinkedList *newNode = (doublyLinkedList *)malloc(sizeof(doublyLinkedList));
		newNode->value = tail->value;
		newNode->next = NULL;
		if(headOfReverseLinkedList != NULL){
			tailOfReverseLinkedList->next = newNode;
			newNode->prev = tailOfReverseLinkedList;
			tailOfReverseLinkedList = tailOfReverseLinkedList->next;
		}else{
			newNode->prev = NULL;
			headOfReverseLinkedList = newNode;
			tailOfReverseLinkedList = newNode;
		}
	}
	return headOfReverseLinkedList;
}

void ReverseADoublyLinkedListStackAux(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}
	stack<int> auxSpace;
	doublyLinkedList *crawler = ptr;
	while(crawler == NULL){
		auxSpace.push(crawler->value);
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!auxSpace.empty()){
		crawler = auxSpace.top();
		auxSpace.pop();
		crawler = crawler->next;
	}
	return;
}

void ReverseADoublyLinkedListRecursive(doublyLinkedList *ptr,doublyLinkedList **frontCrawler){
	if(ptr == NULL){
		return;
	}
	static bool shouldSwap = true;
	ReverseADoublyLinkedListRecursive(ptr->next,frontCrawler);
	if(shouldSwap){
		int tempForSwap = ptr->value;
		ptr->value = (*frontCrawler)->value;
		(*frontCrawler)->value = tempForSwap;
		if(ptr->next == frontCrawler || ptr == frontCrawler){
			shouldSwap = false;
		}
		*frontCrawler = (*frontCrawler)->next;
	}
}

void ReverseADoublyLinkedListNewListRecursive(doublyLinkedList *ptr,doublyLinkedList **headOfReverseLinkedList,doublyLinkedList *tailOfReverseLinkedList){
	if(ptr == NULL){
		return;
	}
	ReverseADoublyLinkedListNewListRecursive(ptr->next,headOfReverseLinkedList,tailOfReverseLinkedList);
	doublyLinkedList *newNode = (doublyLinkedList *)malloc(sizeof(doublyLinkedList));
	newNode->value = ptr->value;
	newNode->next = NULL;
	if((*headOfReverseLinkedList) == NULL){
		newNode->prev = NULL;
		*headOfReverseLinkedList = newNode;
		*tailOfReverseLinkedList = newNode;
	}else{
		newNode->prev = *tailOfReverseLinkedList;
		(*tailOfReverseLinkedList) = newNode;
	}
}

void ReverseADoublyLinkedListChangingPtr(doublyLinkedList *ptr){

}
#endif /* REVERSEADOUBLYLINKEDLIST_H_ */
