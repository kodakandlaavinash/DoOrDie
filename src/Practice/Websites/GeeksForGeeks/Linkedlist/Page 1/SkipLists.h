/*
 * SkipLists.h
 *
 *  Created on: Jul 16, 2013
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

#ifndef SKIPLISTS_H_
#define SKIPLISTS_H_

struct expressList{
	int value;
	expressList *next;
	linkedListNode *ptrToOriginalList;
};

expressList *CreateExpressList(linkedListNode *ptr){
	if(ptr == NULL){
		return null;
	}
	int lengthOfLinkedList = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		lengthOfLinkedList += 1;
		crawler = crawler->next;
	}

	int distanceBetweenSkipLists = sqrt(lengthOfLinkedList);
	expressList *headOfExpressLinkedList;
	expressList *expressListCrawler;
	int counter = distanceBetweenSkipLists;
	while(crawler != NULL){
		expressList *newNode = (expressList *)malloc(sizeof(expressList));
		newNode->value = crawler->value;
		newNode->ptrToOriginalList = crawler;
		if(headOfExpressLinkedList == NULL){
			headOfExpressLinkedList = newNode;
		}else{
			expressListCrawler->next = newNode;
		}
		expressListCrawler = newNode;
		while(counter-- && crawler != NULL){
			crawler = crawler->next;
		}
		counter = distanceBetweenSkipLists;
	}
	return headOfExpressLinkedList;
}

bool SearchUsingExpressLists(expressList *ptr,int key){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value > key){
		return false;
	}
	expressList *expressListCrawler = ptr;
	linkedListNode *linkedListCrawler;

	while(expressListCrawler->next != NULL){
		if(expressListCrawler->value == key){
			return true;
		}
		if(expressListCrawler->value > key && expressListCrawler->value < key){
			linkedListCrawler = expressListCrawler->ptrToOriginalList;
			while(linkedListCrawler->value != key && linkedListCrawler != expressListCrawler->next->ptrToOriginalList){
				if(linkedListCrawler->value == key){
					return true;
				}
				linkedListCrawler = linkedListCrawler->next;
			}
			return false;
		}else{
			expressListCrawler = expressListCrawler->next;
		}
	}
	linkedListCrawler = expressListCrawler->ptrToOriginalList;
	while(linkedListCrawler != NULL){
		if(linkedListCrawler->value == key){
			return key;
		}
		linkedListCrawler = linkedListCrawler->next;
	}
	return false;
}

#endif /* SKIPLISTS_H_ */
