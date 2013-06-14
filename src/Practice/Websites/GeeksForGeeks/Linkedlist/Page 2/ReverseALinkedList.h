/*
 * ReverseALinkedList.h
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

using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef REVERSEALINKEDLIST_H_
#define REVERSEALINKEDLIST_H_
/*
 * Tested
 */
linkedListNode *ReverseLinkedListRecursive(linkedListNode *ptr,linkedListNode **ptr2){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->next == NULL){
		*ptr2 = ptr;
		return ptr;
	}
	ReverseLinkedListRecursive(ptr->next,ptr2);
	ptr->next->next = ptr;
	return ptr;
}

/*
 * Tested
 */
void ReverseLinkedListRecursiveDriver(linkedListNode **ptr){
	linkedListNode *lastPtr = ReverseLinkedListRecursive(*ptr,ptr);
	lastPtr->next = NULL;
}

/*
 * Tested
 */
void ReverseLinkedListIterationAuxSpace(linkedListNode *ptr){
	stack<int> auxSpace;
	linkedListNode *crawler = ptr;
	while(crawler!=NULL){
		auxSpace.push(crawler->value);
		crawler = crawler->next;
	}
	crawler = ptr;

	while(ptr != NULL){
		ptr->value = auxSpace.top();
		auxSpace.pop();
		ptr = ptr->next;
	}

	return;
}

/*
 *	Tested
 */
linkedListNode * ReverseLinkedListFrontCrawling(linkedListNode *ptr){
	linkedListNode *temp;
	linkedListNode *headOfReverseLinkedList = NULL;
	temp = ptr;
	while(temp->next != NULL){
		temp = ptr->next;
		ptr->next = headOfReverseLinkedList;
		headOfReverseLinkedList = ptr;
		ptr = temp;
	}
	temp->next = headOfReverseLinkedList;
	headOfReverseLinkedList = temp;
	return headOfReverseLinkedList;
}

/*
 * Tested
 */
linkedListNode * ReverseLinkedListNewList(linkedListNode *ptr){
	queue<int> auxSpace;
	linkedListNode *reverseHead = NULL;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		auxSpace.push(crawler->value);
		crawler = crawler->next;
	}

	while(!auxSpace.empty()){
		CreateLinkedList(&reverseHead,auxSpace.front());
		auxSpace.pop();
	}
	return reverseHead;
}

/*
 * Tested
 *
 * Before testing this function you should store the head pointer in temp variable
 * Because we are double pointers
 *
 * int middle = 0;
 * linkedListNode *temp = head;
 * ReverseLinkedListReference(head,&head,middle,0);
 * head = temp;
 */
void ReverseLinkedListReference(linkedListNode *crawlerPtr,linkedListNode **beginPtr,int &middle,int count){
	if(crawlerPtr == NULL){
		middle = count/2;
		return;
	}
	ReverseLinkedListReference(crawlerPtr->next,beginPtr,middle,count+1);
	int temp;
	if(count >= middle){
		temp = crawlerPtr->value;
		crawlerPtr->value =  (*beginPtr)->value;
		(*beginPtr)->value = temp;
		*beginPtr = (*beginPtr)->next;
	}
	return;
}

#endif /* REVERSEALINKEDLIST_H_ */
