/*
 * AddTwoNumbersRepresentatedByLinkedList.h
 *
 *  Created on: May 8, 2013
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

#ifndef ADDTWONUMBERSREPRESENTATEDBYLINKEDLIST_H_
#define ADDTWONUMBERSREPRESENTATEDBYLINKEDLIST_H_

linkedListNode *AddTwoNumbersRepresentedAsLinkedListIterative(linkedListNode *ptr1,linkedListNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return NULL;
	}
	if(ptr1 == NULL || ptr2 == NULL){
		if(ptr1 != NULL){
			return ptr1;
		}else{
			return ptr2;
		}
	}

	linkedListNode *crawler1 = ptr1,*crawler2 = ptr2;
	linkedListNode *sumOfLists = NULL,*crawlerToSumOfLists;
	crawlerToSumOfLists = sumOfLists;
	int sum,carry = 0;
	while(crawler1 != NULL && crawler2 != NULL){
		sum  = crawler1->value + crawler2->value + carry;
		carry = sum/10;
		if(crawlerToSumOfLists == NULL){
			crawlerToSumOfLists = (linkedListNode *)malloc(sizeof(linkedListNode));
			crawlerToSumOfLists->value = sum%10;
			crawlerToSumOfLists->next = NULL;
			sumOfLists = crawlerToSumOfLists;
		}else{
			crawlerToSumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));
			crawlerToSumOfLists->next->value = sum%10;
			crawlerToSumOfLists->next->next = NULL;
			crawlerToSumOfLists = crawlerToSumOfLists->next;
		}
		crawler1 = crawler1->next;
		crawler2 = crawler2->next;
	}

	while(crawler1 != NULL){
		sum = crawler1->value + carry;
		carry = sum/10;
		crawlerToSumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		crawlerToSumOfLists->next->value = sum%10;
		crawlerToSumOfLists->next->next = NULL;
		crawlerToSumOfLists = crawlerToSumOfLists->next;
		crawler1 = crawler1->next;
	}

	while(crawler2 != NULL){
		sum = crawler2->value + carry;
		carry = sum/10;
		crawlerToSumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		crawlerToSumOfLists->next->value = sum%10;
		crawlerToSumOfLists->next->next = NULL;
		crawlerToSumOfLists = crawlerToSumOfLists->next;
		crawler2 = crawler2->next;
	}

	while(carry){
		crawlerToSumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		crawlerToSumOfLists->next->value = carry%10;
		crawlerToSumOfLists->next->next = NULL;
		carry /= 10;
	}

	return sumOfLists;
}

linkedListNode *AddTwoListsRecursion(linkedListNode *ptr1,linkedListNode *ptr2,int carry,linkedListNode *sumOfLists){
	if(ptr1 == NULL && ptr1 == NULL && carry == 0){
		return;
	}
	if(ptr1 == NULL || ptr2 == NULL || carry != 0){
		if(ptr1 != NULL){
			while(ptr1 == NULL){
				int sum = ptr1->value + carry;
				sumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));

			}
		}else{

		}
		if(carry){

		}
		return sumOfLists;
	}

	int sum;
	sum = ptr1->value + ptr2->value + carry;
	linkedListNode *returnPtr;
	if(sumOfLists == NULL){
		sumOfLists = (linkedListNode *)malloc(sizeof(linkedListNode));
		sumOfLists->value = sum%10;
		sumOfLists->next = NULL;
		returnPtr = sumOfLists;
	}else{
		sumOfLists->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		sumOfLists->next->value = sum%10;
		sumOfLists->next->next = NULL;
		returnPtr = sumOfLists->next;
	}
	carry = sum/10;
	AddTwoListsRecursion(ptr1->next,ptr2->next,carry,returnPtr);
	return returnPtr;

}

#endif /* ADDTWONUMBERSREPRESENTATEDBYLINKEDLIST_H_ */
