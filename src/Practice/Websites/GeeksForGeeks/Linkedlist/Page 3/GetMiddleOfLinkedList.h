/*
 * GetMiddleOfLinkedList.h
 *
 *  Created on: Apr 18, 2013
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
#include "../LinkedListUtil.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef GETMIDDLEOFLINKEDLIST_H_
#define GETMIDDLEOFLINKEDLIST_H_

/*
 * Tested
 */
linkedListNode *MiddleOfLinkedList(linkedListNode *ptr){
	int length = lengthOfLinkedList(ptr);
	if(length == 0){
		return NULL;
	}
	linkedListNode *middleLinkedList = ptr;
	int middleIndex = length/2;
	while(middleIndex--){
		middleLinkedList = middleLinkedList->next;
	}
	return middleLinkedList;
}

/*
 * Tested
 */
linkedListNode *GetMiddleOfMiddleLinkedListHashMap(linkedListNode *ptr){
	hash_map<int,linkedListNode *> visitedNodes;
	int counter = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		visitedNodes.insert(pair<int,linkedListNode *>(counter,crawler));
		counter++;
		crawler = crawler->next;
	}
	return visitedNodes[counter/2];
}

/*
 * Tested
 */
linkedListNode *GetMiddleListUsingRunningPtrs(linkedListNode *ptr){
	linkedListNode *slowPtr = ptr;
	linkedListNode *fastPtr = ptr;
	while(slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL){
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}

/*
 * Tested
 */
linkedListNode * GetMiddleOfLinkedListRecursion(linkedListNode *ptr,int &middle,int count){
	if(ptr == NULL){
		middle = count/2;
		return NULL;
	}
	linkedListNode *isMiddle = GetMiddleOfLinkedListRecursion(ptr->next,middle,count+1);
	if(middle == count && middle > 0){
		return ptr;
	}else{
		if(isMiddle != NULL){
			return isMiddle;
		}else{
			return NULL;
		}
	}
}

/*
 * Tested
 */
linkedListNode *GetMiddleOfLinkedListRace(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	int count = 0;
	linkedListNode *mid = ptr;
	linkedListNode *crawler = ptr;
	while(crawler!= NULL){
		if(count&2){
			mid = mid->next;
		}
		count++;
		crawler = crawler->next;
	}
	return mid;
}

#endif /* GETMIDDLEOFLINKEDLIST_H_ */
