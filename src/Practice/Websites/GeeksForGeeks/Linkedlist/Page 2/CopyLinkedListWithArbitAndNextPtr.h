/*
 * CopyLinkedListWithArbitAndNextPtr.h
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

#ifndef COPYLINKEDLISTWITHARBITANDNEXTPTR_H_
#define COPYLINKEDLISTWITHARBITANDNEXTPTR_H_

arbitLinkedList *CopyLinkedListWithArbitAndNextPtrON2(arbitLinkedList *ptr){
	if(ptr == NULL){
		return NULL;
	}

	arbitLinkedList *crawler1 = ptr,*crawler2;
	arbitLinkedList *copy;
	arbitLinkedList *headOfCopy;

	//Making the copy of linked list for next pointers
	while(crawler1 != NULL){
		if(copy == NULL){
			copy = (arbitLinkedList *)malloc(sizeof(arbitLinkedList));
			copy->value = crawler1->value;
			copy->next = NULL;
			headOfCopy = copy;
		}else{
			copy->next = (arbitLinkedList *)malloc(sizeof(arbitLinkedList));
			copy->next->value = crawler1->value;
			copy->next->next = NULL;
			copy = copy->next;
		}
		crawler1 = crawler1->next;
	}

	arbitLinkedList *outerCrawler1 = ptr,*innerCrawler;
	int count;
	arbitLinkedList *outerCrawler2 = headOfCopy;
	while(outerCrawler1 != NULL){
		count = 0;
		while(outerCrawler1->arbit == innerCrawler){
			innerCrawler = innerCrawler->next;
			count++;
		}

		innerCrawler = headOfCopy;
		while(count--){
			innerCrawler = innerCrawler->next;
		}
		outerCrawler2->arbit = innerCrawler;

		outerCrawler1 = outerCrawler1->next;
		outerCrawler2 = outerCrawler2->next;
	}

	return headOfCopy;
}

arbitLinkedList *CopyLinkedListWithArbitAndNextPtrONSpace(arbitLinkedList *ptr){
	if(ptr == NULL){
		return NULL;
	}
	arbitLinkedList *crawler1 = ptr;
	arbitLinkedList *newList,*copy;

	vector<arbitLinkedList *> copyOfNextPointers;

	while(crawler1 != NULL){
		if(copy == NULL){
			copy = (arbitLinkedList *)malloc(sizeof(arbitLinkedList));
			copy->value = crawler1->value;
			copy->arbit = crawler1;
			copy->next = NULL;
			newList = copy;
		}else{
			copy->next = (arbitLinkedList *)malloc(sizeof(arbitLinkedList));
			copy->next->value = crawler1->value;
			copy->next->next = NULL;
			copy->next->arbit = crawler1;
			copy = copy->next;
		}
		copyOfNextPointers.push_back(crawler1);
		crawler1 = crawler1->next;
	}

	crawler1 = ptr;
	copy = newList;
	while(crawler1 != NULL){
		crawler1->next = copy;
		copy = copy->next;
		crawler1 = crawler1->next;
	}

	crawler1 = ptr;
	copy = newList;
	while(copy != NULL){
		copy->arbit = copy->arbit->arbit->next;
		copy = copy->next;
	}

	crawler1 = ptr;
	for(int counter = 0;counter < copyOfNextPointers.size();counter++){
		crawler1->next = copyOfNextPointers[counter];
		crawler1 = crawler1->next;
	}
}

arbitLinkedList *CopyLinkedListWithArbitAndNextPtrNodeInMiddle(arbitLinkedList *ptr){
	if(ptr == NULL){
		return NULL;
	}
	arbitLinkedList *headOfCopiedList,*copyCrawler = NULL;
	arbitLinkedList *crawler1 = ptr;

	while(crawler1 != NULL){
		arbitLinkedList *newNode =(arbitLinkedList *)malloc(sizeof(arbitLinkedList));
		newNode->value = crawler1->value;
		newNode->next = crawler1->next;
		crawler1->next =newNode;
		crawler1 = crawler1->next->next;
	}

	crawler1 = ptr;
	while(crawler1 != NULL){
		crawler1->next->arbit = crawler1->arbit->next;
		crawler1 = crawler1->next->next;
	}

	crawler1 = ptr;
	arbitLinkedList *temp;
	while(crawler1 != NULL){
		crawler1->next->arbit = crawler1->arbit->next;
		if(crawler1->next->next->next != NULL){
			crawler1->next->next = crawler1->next->next->next->next;
		}else{
			crawler1->next->next = NULL;
		}
		crawler1->next = crawler1->next->next;
	}

	return headOfCopiedList;
}

#endif /* COPYLINKEDLISTWITHARBITANDNEXTPTR_H_ */
