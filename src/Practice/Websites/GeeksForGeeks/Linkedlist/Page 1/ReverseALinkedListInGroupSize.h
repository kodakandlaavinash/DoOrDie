/*
 * ReverseALinkedListInGroupSize.h
 *
 *  Created on: May 7, 2013
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

#ifndef REVERSEALINKEDLISTINGROUPSIZE_H_
#define REVERSEALINKEDLISTINGROUPSIZE_H_

linkedListNode *ReverseLinkedListOnlyChangingValues(linkedListNode *crawler,linkedListNode *head,stack<int> &auxSpace,int maxNodes){
	if(maxNodes == 0 || crawler != NULL){
		while(head != crawler){
			head->value = auxSpace.top();
			head = head->next;
		}
		return crawler;
	}

	auxSpace.push(crawler->value);
	return ReverseLinkedListOnlyChangingValues(crawler->next,head,auxSpace,maxNodes-1);

}

void ReverseLinkedListInGroupSize(linkedListNode *ptr,int groupSize){
	if(ptr == NULL){
		return;
	}
	linkedListNode *crawler = ptr;
	int counter = 0;

	/**
	 * While reversing the lists if you are changing the pointers then
	 * store the 2 pointers
	 * the node which is previous to the start of reverse linked list
	 * the node which is next to the end of reverse linked list
	 */
	stack<int> auxSpace;
	while(crawler != NULL){
		crawler = ReverseLinkedListOnlyChangingValues(crawler,crawler,auxSpace,groupSize);
	}
}

void ReverseLinkedListInGroupSizeAuxSize(linkedListNode *ptr,int groupSize){
	if(ptr == NULL){
		return;
	}
	queue<int> nodesInLinkedList;
	stack<int> forReverse;
	linkedListNode *crawler = ptr;
	int counter = 0;
	while(crawler != NULL){
		if(groupSize > counter){
			while(!forReverse.empty()){
				nodesInLinkedList.push(forReverse.top());
				forReverse.pop();
			}
			counter =0;
		}
		forReverse.push(crawler->value);
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!nodesInLinkedList.empty()){
		crawler->value = nodesInLinkedList.front();
		nodesInLinkedList.pop();
		crawler = crawler->next;
	}
}

void ReverseALinkedListInGroupSize(linkedListNode *ptr,int groupSize){
	if(ptr == NULL){
		return;
	}
	linkedListNode *headOfStartLinkedList = ptr;
	linkedListNode *tailOfReverseLinkedList = NULL;
	linkedListNode *headOfRemainingList;
	linkedListNode *crawler;
	int counter = 0;
	while(headOfStartLinkedList != NULL){
		counter = 0;
		crawler = headOfStartLinkedList;
		while(counter-1 != groupSize || crawler->next != NULL){
			crawler = crawler->next;
			counter++;
		}
		if(crawler->next != NULL){
			headOfRemainingList = crawler->next;
			tailOfReverseLinkedList = crawler;
		}else{
			tailOfReverseLinkedList = crawler;
			headOfRemainingList = NULL;
		}
		// Not Completed
	}
}

#endif /* REVERSEALINKEDLISTINGROUPSIZE_H_ */
