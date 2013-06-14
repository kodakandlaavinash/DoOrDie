/*
 * SplitACircularLinkedListIntoHalf.h
 *
 *  Created on: May 3, 2013
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

#ifndef SPLITACIRCULARLINKEDLISTINTOHALF_H_
#define SPLITACIRCULARLINKEDLISTINTOHALF_H_

void SplitACircularLinkedListIntoHalf(linkedListNode *firstHalfPtr,linkedListNode **secondHalfPtr){
	linkedListNode *fastPtr = firstHalfPtr;
	linkedListNode *slowPtr = firstHalfPtr;
	linkedListNode *shouldCheck = false;
	linkedListNode *midOfCircularLinkedList;
	while(fastPtr != NULL && slowPtr != NULL && slowPtr->next != NULL && fastPtr != slowPtr){
		if(shouldCheck){
			if(fastPtr == slowPtr->next){
				secondHalfPtr = slowPtr->next;
				slowPtr->next = NULL;
			}
		}
		shouldCheck = true;
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}
	return;
}

linkedListNode *SplitCircularLinkedListIntoHalfRecursion(linkedListNode *slowPtr,linkedListNode *fastPtr,linkedListNode **secondHalfPtr){
	if(slowPtr == NULL || fastPtr == NULL || fastPtr->next == NULL){
		return slowPtr;
	}
	return SplitCircularLinkedListIntoHalfRecursion(slowPtr->next,fastPtr->next->next);
}

#endif /* SPLITACIRCULARLINKEDLISTINTOHALF_H_ */
