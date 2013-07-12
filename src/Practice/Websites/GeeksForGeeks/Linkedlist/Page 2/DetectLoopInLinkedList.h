	/*
 * DetectLoopInLinkedList.h
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

bool DetectLoopInLinkedListHashMap(linkedListNode *ptr){
	set<linkedListNode *> visitedNodes;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		if(visitedNodes.find(crawler) != visitedNodes.end()){
			return false;
		}
		visitedNodes.insert(crawler);
	}
	return true;
}

bool DetectLoopInLinkedList(linkedListNode *ptr){
	linkedListNode *leadPtr  = ptr;
	linkedListNode *trailPtr = ptr;
	while(trailPtr != NULL && leadPtr != NULL && leadPtr->next != NULL){
		leadPtr = leadPtr->next->next;
		trailPtr = trailPtr->next;
		if(leadPtr == trailPtr){
			return true;
		}
	}
	return false;
}

bool DetectLoopInLinkedListRecursion(linkedListNode *ptr,linkedListNode **tail){
	if(ptr == NULL){
		return false;
	}
	if(ptr->next == NULL){
		*tail = ptr;
		return false;
	}
	bool truthValue = DetectLoopInLinkedList(ptr->next,tail);
	if(truthValue){
		return true;
	}else{
		if((*tail)->next == ptr){
			return true;
		}else{
			return false;
		}
	}
}

bool DetectLoopInLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return false;
	}
	hash_map<int,list<linkedListNode *>> mapOfElementsAndPtr;
	hash_map<int,list<linkedListNode *>>::iterator *itToMapOfElementsAndPtr;
	linkedListNode *crawler = ptr;
	list<linkedListNode *> tempList;
	list<linkedListNode *>::iterator *itToTempList;
	while(crawler != NULL){
		if((itToMapOfElementsAndPtr = mapOfElementsAndPtr.find(crawler->value)) == mapOfElementsAndPtr.end()){
			list<linkedListNode *> newListForElement;
			newListForElement.push_back(crawler);
			mapOfElementsAndPtr.insert(pair<int,list<linkedListNode *>>(crawler->value,newListForElement));
		}else{
			tempList = (*itToMapOfElementsAndPtr)->second;
			for(itToTempList = tempList.begin();itToTempList != tempList.end();itToTempList++){
				if(*itToTempList == crawler){
					return true;
				}
			}
			tempList.push_back(crawler);
			mapOfElementsAndPtr[crawler->value] = tempList;
		}
	}
	return false;
}
