/*
 * RotateLinkedList.h
 *
 *  Created on: May 13, 2013
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

#ifndef ROTATELINKEDLIST_H_
#define ROTATELINKEDLIST_H_

void RotateLinkedList(linkedListNode *ptr,int kValue){
	if(ptr == NULL){
		return;
	}
	int lengthOfLinkedList = lengthOfLinkedListIteration(ptr);
	kValue = kValue % lengthOfLinkedList;
	if(kValue == 0 || kValue == lengthOfLinkedList-1){
		return;
	}

	linkedListNode *kNode,*kSuccessorNode,*tailNode = ptr;
	while(tailNode->next != NULL){
		tailNode = tailNode->next;
	}

	kNode = ptr;
	while(kValue--){
		kNode = kNode->next;
	}

	kSuccessorNode = kNode->next;
	tailNode->next = ptr;
	ptr = kSuccessorNode;
	kNode->next = NULL;
}

void RotateLinkedListWithoutFindingLength(linkedListNode *ptr,int kValue){
	if(ptr == NULL){
		return;
	}

	linkedListNode *crawler = ptr;
	while(kValue != 0){
		if(crawler->next == NULL){
			crawler = ptr;
		}else{
			crawler = crawler->next;
		}
	}

	linkedListNode *tailNode = ptr;
	while(tailNode->next != NULL){
		tailNode = tailNode->next;
	}

	if(crawler->next == NULL){
		//length == kValue %lengthOfLinkedList
		return;
	}

	tailNode->next = ptr;
	ptr = crawler->next;
	crawler->next = NULL;

}

#endif /* ROTATELINKEDLIST_H_ */
