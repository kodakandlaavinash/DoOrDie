/*
 * MoveLastElementToFront.h
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

#ifndef MOVELASTELEMENTTOFRONT_H_
#define MOVELASTELEMENTTOFRONT_H_

void MoveElementToFrontLinkedList(linkedListNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}

	linkedListNode *crawler = ptr;

	while(crawler->next->next != NULL){
		crawler = crawler->next;
	}

	crawler->next->next = ptr;
	ptr = crawler->next;
	crawler->next = NULL;
}

void MoveElementToFrontOfLinkedListRecurstion(linkedListNode *ptr,linkedListNode *head){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	if(ptr->next->next == NULL){
		ptr->next->next = head;
		head = ptr->next;
		ptr->next = NULL;
		return;
	}
	MoveElementToFrontOfLinkedListRecurstion(ptr->left,head);
}

#endif /* MOVELASTELEMENTTOFRONT_H_ */
