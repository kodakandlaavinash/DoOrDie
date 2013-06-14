/*
 * RemoveDuplicatesSortedLinkedList.h
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

#include "../LinkedListDS.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef REMOVEDUPLICATESSORTEDLINKEDLIST_H_
#define REMOVEDUPLICATESSORTEDLINKEDLIST_H_

void RemoveDuplicatesSortedLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *crawler = ptr;
	linkedListNode *nodeToBeDeleted;
	while(crawler != NULL || crawler->next != NULL){
		if(crawler->value == crawler->next->value){
			nodeToBeDeleted = crawler->next;
			crawler->next = crawler->next->next;
			free(nodeToBeDeleted);
		}
	}
}

void RemoveDuplicatesFromSortedLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	linkedListNode *startSortedKeyList = ptr;
	linkedListNode *endSortedKeyList = ptr;
	linkedListNode *beginOfNextList;
	while(endSortedKeyList != NULL){
		while(startSortedKeyList->value == endSortedKeyList->value){
			endSortedKeyList = endSortedKeyList->next;
		}
		beginOfNextList = endSortedKeyList->next;
		if(startSortedKeyList != endSortedKeyList){
			DeletePartOfLinkedList(startSortedKeyList->next,endSortedKeyList);
		}
		startSortedKeyList = beginOfNextList;
	}
}


#endif /* REMOVEDUPLICATESSORTEDLINKEDLIST_H_ */
