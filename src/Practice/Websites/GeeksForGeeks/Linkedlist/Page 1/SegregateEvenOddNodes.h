/*
 * SegregateEvenOddNodes.h
 *
 *  Created on: May 12, 2013
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

#ifndef SEGREGATEEVENODDNODES_H_
#define SEGREGATEEVENODDNODES_H_

void SegregateEvenOddListsAuxSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<int> oddQueue;
	queue<int> evenQueue;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		if(crawler->value %2 == 0){
			evenQueue.push(crawler->value);
		}else{
			oddQueue.push(crawler->value);
		}
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!evenQueue.empty()){
		crawler->value = evenQueue.front();
		evenQueue.pop();
		crawler = crawler->next;
	}

	while(!oddQueue.empty()){
		crawler->value = oddQueue.front();
		oddQueue.pop();
		crawler = crawler->next;
	}
}

void SegregateEvenOddNodesUsingSeparateLists(linkedListNode **ptr){
	if(ptr == NULL){
		return NULL;
	}
	linkedListNode *evenNodes = NULL,*oddNodes = NULL;
	linkedListNode *evenNodesCrawler,*oddNodesCrawler;
	linkedListNode *crawler = *ptr;
	while(crawler != NULL){
		if(crawler->value %2 == 0){
			if(evenNodesCrawler == NULL){
				evenNodesCrawler = crawler;
				evenNodes = evenNodesCrawler;
			}else{
				evenNodesCrawler->next = crawler;
				evenNodesCrawler = evenNodesCrawler->next;
			}
		}else{
			if(oddNodesCrawler == NULL){
				oddNodesCrawler = crawler;
				oddNodes = oddNodesCrawler;
			}else{
				oddNodesCrawler->next = crawler;
				oddNodesCrawler = oddNodesCrawler->next;
			}
		}
		crawler = crawler->next;
	}
	if(evenNodesCrawler != NULL){
		evenNodesCrawler->next = oddNodes;
		*ptr = evenNodes;
	}else{
		*ptr = oddNodes;
	}
}

void SegregateEvenOddNodesByAppending(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	linkedListNode *crawler,*tailOfLinkedList;
	while(crawler->next != NULL){
		crawler = crawler->next;
	}
	tailOfLinkedList = crawler;
	linkedListNode *tailCrawler = tailOfLinkedList;

	crawler = ptr;

// Not Completed

}

#endif /* SEGREGATEEVENODDNODES_H_ */
