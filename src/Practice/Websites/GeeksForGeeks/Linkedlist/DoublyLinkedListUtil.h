/*
 * DoublyLinkedListUtil.h
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

#include "LinkedListDS.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef DOUBLYLINKEDLISTUTIL_H_
#define DOUBLYLINKEDLISTUTIL_H_

int LengthOfDoublyLinkedList(doublyLinkedList *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+LengthOfDoublyLinkedList(ptr->next);
}

int LengthOfDoublyLinkedListIteration(doublyLinkedList *ptr){
	if(ptr == NULL){
		return 0;
	}
	doublyLinkedList *crawler;
	int counter = 0;
	while(crawler != NULL){
		counter++;
		crawler = crawler->next;
	}
	return counter;
}

void ReverseDoublyLinkedList(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}
	while(ptr != NULL){

	}
}

void ReverseDoublyLinkedListRecursion(doublyLinkedList *ptr){

}

void ReverseDoublyLinkedListAuxSpace(doublyLinkedList *ptr){

}

void ReverseDoublyLinkedListNewList(doublyLinkedList *ptr){

}

void ReverseDoublyLinkedListUsingFrontBackCrawler(doublyLinkedList *ptr){

}

doublyLinkedList *GetTailOfDoublyLinkedList(doublyLinkedList *ptr){

}

int GetPredecessorOfDoublyLinkedList(doublyLinkedList *ptr){

}

int GetPredecessorOfDoublyLinkedListRecursive(doublyLinkedList *ptr){

}

int GetSuccessorOfDoublyLinkedList(doublyLinkedList *ptr){

}

int GetSuccessorOfDoublyLinkedListRecursion(doublyLinkedList *ptr){

}

void CreateDoublyLinkedInsert(){

}

void DisplayDoublyLinkedList(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}
	printf("NULL<->");
	while(ptr != NULL){
		printf("%d<->",ptr->value);
		ptr = ptr->next;
	}
	printf("<->NULL");
}

void DisplayDoublyLinkedListRecursion(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->prev == NULL){
		printf("NULL<->");
	}
	printf("%d<->",ptr->value);
	if(ptr->next == NULL){
		printf("<->NULL");
	}
	DisplayDoublyLinkedListRecursion(ptr->next);
}

void DisplayReverseOfLinkedListRecursion(doublyLinkedList *ptr){
	if(ptr == NULL){
		return;
	}

}

void DisplayReverseOfLinkedListIteration(doublyLinkedList *ptr){

}

void DisplayReverseOfLinkedListStackAux(doublyLinkedList *ptr){
	stack<doublyLinkedList *> auxSpace;
	if(ptr == NULL){
		printf("NULL");
		return;
	}
	doublyLinkedList *crawler = ptr;
	while(ptr != NULL){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}

	while(!auxSpace.empty()){
		printf("%d ",auxSpace.top()->value);
		auxSpace.pop();
	}

	return;
}
#endif /* DOUBLYLINKEDLISTUTIL_H_ */
