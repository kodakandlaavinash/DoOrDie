/*
 * MergeTwoLinkedList.h
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

#ifndef MERGETWOLINKEDLIST_H_
#define MERGETWOLINKEDLIST_H_

linkedListNode *MergeTwoLinkedListByCreatingNewList(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return NULL;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		if(ptr1!= NULL){
			return ptr1;
		}else{
			return ptr2;
		}
	}

	linkedListNode *sortedLinkedList = (linkedListNode *)malloc(sizeof(linkedListNode));
	sortedLinkedList->value = ptr1->value;
	sortedLinkedList->next = NULL;
	linkedListNode *crawlerSortedLinkedList = sortedLinkedList;

	while(ptr1 != NULL && ptr2 != NULL){
		crawlerSortedLinkedList->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		if(ptr1->value == ptr2->value){
			crawlerSortedLinkedList->next->value = ptr1->value;
			crawlerSortedLinkedList->next->next = (linkedListNode *)malloc(sizeof(linkedListNode));
			crawlerSortedLinkedList->next->next->value = ptr2->value;
			crawlerSortedLinkedList->next->next->next = NULL;
			crawlerSortedLinkedList = crawlerSortedLinkedList->next->next;
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}else{
			if(ptr1->value > ptr2->value){
				crawlerSortedLinkedList->next->value = ptr2->value;
				ptr2 = ptr2->next;
			}else{
				crawlerSortedLinkedList->next->value = ptr1->value;
				ptr1 = ptr1->next;
			}
			crawlerSortedLinkedList->next->next = NULL;
		}
	}

	while(ptr1 != NULL){
		crawlerSortedLinkedList->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		crawlerSortedLinkedList->next->value = ptr1->value;
		crawlerSortedLinkedList->next->next = NULL;
		ptr1 = ptr1->next;
		crawlerSortedLinkedList = crawlerSortedLinkedList->next;
	}

	while(ptr2 != NULL){
		crawlerSortedLinkedList->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		crawlerSortedLinkedList->next->value = ptr2->value;
		crawlerSortedLinkedList->next->next = NULL;
		ptr2 = ptr2->next;
		crawlerSortedLinkedList = crawlerSortedLinkedList->next;
	}

}

linkedListNode *MergeTwoLinkedListIteration(linkedListNode *ptr1,linkedListNode *ptr2){
	linkedListNode *crawlerLinkedList1= ptr1,*crawlerLinkedList2=ptr2;
	linkedListNode *ptrToRemainingList1,ptrToRemainingList2;
	while(crawlerLinkedList1->next != NULL || ptr2 != NULL){
		while(crawlerLinkedList1->next->value > crawlerLinkedList2->value){
			ptr1 = ptr1->next;
		}
		ptrToRemainingList1 = crawlerLinkedList1->next;
		ptrToRemainingList2 = crawlerLinkedList2->next;
		crawlerLinkedList1->next = crawlerLinkedList2;
		crawlerLinkedList2->next = ptrToRemainingList2;
		crawlerLinkedList1 = ptrToRemainingList1;
		crawlerLinkedList2 = ptrToRemainingList2;
	}

	if(crawlerLinkedList2 != NULL){
		crawlerLinkedList1->next = crawlerLinkedList2;
	}

	return crawlerLinkedList1;
}

void MergeTwoLinkedListRecursion(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr2 == NULL){
		return;
	}
	if(ptr1 == NULL){
		ptr1 = ptr2;
		return;
	}
	if(ptr1->next == NULL){
		ptr1->next = ptr2;
	}

	if(ptr1->next->value < ptr2->value){
		MergeTwoLinkedListRecursion(ptr1->next,ptr2);
	}else{
		linkedListNode *ptrToRemainingList1 = ptr1->next,*ptrToRemainingList2 = ptr2->next;
		ptr1->next = ptr2;
		ptr2->next = ptr1->next;
		MergeTwoLinkedListRecursion(ptrToRemainingList1,ptrToRemainingList2);
	}

}

void MergeTwoSortedLinkedListAuxSpace(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return;
	}
	if(ptr1 == NULL){
		//Should use double pointers
		ptr1 = ptr2;
		return;
	}
	queue<int> auxSpace;
	linkedListNode *crawler= ptr1;

	while(ptr1->next != NULL){
		auxSpace.push(ptr1->value);
		ptr1 = ptr1->next;
	}
	ptr1->next = ptr2;
	crawler = ptr1;
	int currentValue;
	while(!auxSpace.empty() && ptr2 != NULL){
		currentValue = auxSpace.front();
		if(currentValue < ptr2->value){
			crawler->value = currentValue;
			auxSpace.pop();
		}else{
			crawler->value = ptr2->value;
		}
		crawler = crawler->next;
	}

	while(!auxSpace.empty()){
		crawler->value = auxSpace.front();
		auxSpace.pop();
	}

	while(ptr2 != NULL){
		crawler->value = ptr2->value;
		ptr2 = ptr2->next;
	}
}

#endif /* MERGETWOLINKEDLIST_H_ */
