/*
 * LinkedListUtil.h
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

#ifndef LINKEDLISTUTIL_H_
#define LINKEDLISTUTIL_H_
/*
 * Tested
 */
void CreateLinkedList(linkedListNode **ptr,int inputValue){
	/**
	 *Nodes are appended to the front node
	 */
	linkedListNode *newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
	newNode->value = inputValue;
	newNode->next = (*ptr);
	(*ptr) = newNode;
}

/*
 * Tested
 */
void PrintLinkedListIteration(linkedListNode *ptr){
	while(ptr != NULL){
		printf("%d->",ptr->value);
		ptr = ptr->next;
	}
	printf("NULL");
}

/*
 * Tested
 */
void PrintLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		printf("NULL");
		return;
	}
	printf("%d->",ptr->value);
	PrintLinkedList(ptr->next);
}

/*
 *Tested
 */
void PrintReverseOfLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintReverseOfLinkedList(ptr->next);
	printf("%d ",ptr->value);
}

/*
 * Tested
 */
void PrintReverseOfLinkedListAuxSpace(linkedListNode *ptr){
	stack<int> auxSpace;
	while(ptr != NULL){
		auxSpace.push(ptr->value);
		ptr = ptr->next;
	}
	while(!auxSpace.empty()){
		printf("%d->",auxSpace.top());
		auxSpace.pop();
	}
	printf("NULL");
}

/*
 * Tested
 */
int lengthOfLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+lengthOfLinkedList(ptr->next);
}

/*
 * Tested
 */
int lengthOfLinkedListIteration(linkedListNode *ptr){
	int count =0;
	while(ptr != null){
		count++;
		ptr = ptr->next;
	}
	return count;
}

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



/**
 * The predeccesor and successor values can also
 * be obtained using the binary search tree
 */

/*
 * Tested
 * If the number is less than all the numbers in the list
 * then the function returns int min value
 */
int GetPredeccesor(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MIN;
	}
	linkedListNode *crawler = ptr;
	int predeccesor = INT_MIN;
	while(crawler != NULL){
		if(crawler->value <= value && predeccesor <= crawler->value ){
			predeccesor = crawler->value;
		}
		crawler = crawler->next;
	}
	return predeccesor;
}

/*
 * Tested
 */
int GetPredeccesorRecursive(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MIN;
	}
	int predecessor = GetPredeccesorRecursive(ptr->next,value);
	if(predecessor <= ptr->value && ptr->value <= value){
		return ptr->value;
	}else{
		return predecessor;
	}
}

/*
 * Tested
 * If the number is greater than all the numbers in the list
 * then the function returns int max value
 */
int GetSuccessor(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MAX;
	}
	int successor = INT_MAX;
	linkedListNode *crawler = ptr;
	while(crawler != null){
		if(crawler->value >= value && successor >= crawler->value){
			successor = crawler->value;
		}
		crawler = crawler->next;
	}
	return successor;
}

/*
 * Tested
 */
int GetSuccessorRecursive(linkedListNode *ptr,int value){
	if(ptr == NULL){
		return INT_MAX;
	}
	int successor = GetSuccessorRecursive(ptr->next,value);
	if(ptr->value >= value && successor >= ptr->value){
		return ptr->value;
	}else{
		return successor;
	}
}

/*
 * 	Tested
 *	Assuming the position is always less than the length of the linked list
 */
void InsertANodeAtPosition(linkedListNode **ptr,int value,int position){
	if(position != 0){
		linkedListNode *crawler = *ptr;
		while(position--){
			crawler = crawler->next;
		}
		linkedListNode *newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = value;
		newNode->next = crawler->next;
		crawler->next = newNode;
	}else{
		linkedListNode * newNode = (linkedListNode *)malloc(sizeof(linkedListNode));
		newNode->value = value;
		newNode->next = *ptr;
		(*ptr) = newNode;
	}
}

#endif /* LINKEDLISTUTIL_H_ */
