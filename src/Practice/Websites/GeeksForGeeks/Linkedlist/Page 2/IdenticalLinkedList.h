/*
 * IdenticalLinkedList.h
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

#ifndef IDENTICALLINKEDLIST_H_
#define IDENTICALLINKEDLIST_H_

bool AreLinkedListsIdenticalRecursion(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		return false;
	}
	return ptr1->value == ptr2->value && AreLinkedListsIdentical(ptr1->next,ptr2->next);
}

bool AreLinkedListsIdenticalIterative(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		return false;
	}
	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;

	while(crawler1 != NULL && crawler2 != NULL){
		if(crawler1->value != crawler2->value){
			return false;
		}
		crawler1 = crawler1->next;
		crawler2 = crawler2->next;
	}

	if(crawler1 != NULL  || crawler2 != NULL){
		return false;
	}
	return true;
}


bool AreTwoLinkedListIdenticalAuxSpace(linkedListNode *ptr1,linkedListNode *ptr2){
	queue<int> auxSpace;
	linkedListNode *crawler;
	crawler = ptr1;

	while(crawler != NULL){
		auxSpace.push(crawler->value);
	}

	crawler = ptr2;
	while(crawler != NULL && !auxSpace.empty()){
		if(crawler->value != auxSpace.front()){
			return false;
		}
		crawler = crawler->next;
		auxSpace.pop();
	}

	if(!auxSpace.empty() || crawler!= NULL){
		return false;
	}

	return true;
}


bool AreTwoListIdenticalRecursionAuxSpace(linkedListNode *ptr1,linkedListNode *ptr2,stack<int> &auxSpace,bool &recurseFirstLinkedList){
	if(recurseFirstLinkedList){
		if(ptr1 == NULL){
			return AreTwoListIdenticalRecursionAuxSpace(ptr1,ptr2,auxSpace,!recurseFirstLinkedList);
		}
		auxSpace.push(ptr1->value);
		return AreTwoListIdenticalRecursionAuxSpace(ptr1->next,ptr2,auxSpace,recurseFirstLinkedList);
	}else{
		if(ptr2 == NULL){
			return false;
		}
		bool truthValue = AreTwoListIdenticalRecursionAuxSpace(ptr1,ptr2->next,auxSpace,recurseFirstLinkedList);
		if(!truthValue){
			return false;
		}
		if(ptr2->value != auxSpace.top()){
			return false;
		}
		auxSpace.pop();
		return true;
	}
}


#endif /* IDENTICALLINKEDLIST_H_ */
