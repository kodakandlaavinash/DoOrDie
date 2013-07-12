/*
 * DeleteALinkedList.h
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

#ifndef DELETEALINKEDLIST_H_
#define DELETEALINKEDLIST_H_

void DeleteAEntireLinkedListRecursive(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	DeleteAEntireLinkedList(ptr->next);
	linkedListNode *temp = ptr->next;
	ptr->next = NULL;
	if(temp != NULL){
		free(temp);
	}
}

void DeleteEntireLinkedListIterative(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<linkedListNode *> ptrToLinkedListNodes;
	linkedListNode *linkedListCrawler = ptr;
	while(linkedListCrawler->next != null){
		ptrToLinkedListNodes.push(linkedListCrawler);
		linkedListCrawler = linkedListCrawler->next;
	}

	linkedListNode *nodeToBeDeleted;
	while(!ptrToLinkedListNodes.empty()){
		nodeToBeDeleted = ptrToLinkedListNodes.top()->next;
		ptrToLinkedListNodes.top()->next = NULL;
		free(nodeToBeDeleted);
	}

	free(ptr);
}

void DeleteEntireLinkedList(linkedListNode *ptr){
	linkedListNode *nodeToBeDeleted;
	while(ptr != NULL){
		nodeToBeDeleted = ptr;
		ptr = ptr->next;
		free(nodeToBeDeleted);
	}
}

#endif /* DELETEALINKEDLIST_H_ */
