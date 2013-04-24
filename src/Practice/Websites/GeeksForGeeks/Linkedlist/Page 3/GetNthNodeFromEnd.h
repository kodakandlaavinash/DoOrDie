/*
 * GetNthNodeFromEnd.h
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

#ifndef GETNTHNODEFROMEND_H_
#define GETNTHNODEFROMEND_H_

/*
 * Tested
 */
linkedListNode *GetNthNodeFromEndUsingLength(linkedListNode *ptr,int nValue){
	if(ptr == NULL){
		return NULL;
	}
	int length = lengthOfLinkedList(ptr);
	if(nValue > length || nValue < 0){
		return NULL;
	}
	int lengthToTraversed = length - nValue;
	linkedListNode *crawler = ptr;
	while(lengthToTraversed--){
		crawler = crawler->next;
	}
	return crawler;
}

/*
 * Tested
 */
linkedListNode *GetNthNodeFromEnd(linkedListNode *ptr,int nValue){
	if(ptr == NULL){
		return NULL;
	}
	int length = lengthOfLinkedList(ptr);
	if(nValue > length || nValue < 0){
		return NULL;
	}

	linkedListNode *leadPtr = ptr;
	linkedListNode *trailPtr = ptr;
	while(nValue--){
		leadPtr = leadPtr->next;
	}

	while(leadPtr != NULL){
		leadPtr = leadPtr->next;
		trailPtr = trailPtr->next;
	}

	return trailPtr;
}

/*
 * Tested
 */
linkedListNode *GetNthNodeFromEndRecursion(linkedListNode *ptr,int &nValue){
	if(ptr == NULL){
		return NULL;
	}
	linkedListNode *returnedPtr = GetNthNodeFromEndRecursion(ptr->next,nValue);
	if(nValue == 0){
		nValue = INT_MAX;
		return ptr;
	}
	nValue--;
	if(returnedPtr == NULL){
		return null;
	}else{
		return returnedPtr;
	}

}

/*
 * Tested
 */
linkedListNode *GetNthNodeFromEndAuxSpace(linkedListNode *ptr,int nValue){
	if(ptr == NULL){
		return NULL;
	}
	int length = lengthOfLinkedList(ptr);
	if(nValue > length || nValue < 0){
		return NULL;
	}
	stack<linkedListNode *> auxSpace;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}

	while(!auxSpace.empty() && nValue--){
		auxSpace.pop();
	}
	return auxSpace.top();
}

/*
 * Tested
 */
linkedListNode *GetNthNodeFromEndHashMap(linkedListNode *ptr,int nValue){
	if(ptr == NULL){
		return NULL;
	}
	int length = lengthOfLinkedList(ptr);
	if(nValue > length || nValue < 0){
		return NULL;
	}

	hash_map<int,linkedListNode *> auxSpace;
	int counter = 0;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		auxSpace.insert(pair<int,linkedListNode *>(counter,crawler));
		crawler = crawler->next;
		counter++;
	}

	return auxSpace[counter - nValue -1];
}

#endif /* GETNTHNODEFROMEND_H_ */
