/*
 * AddTwoNumbersRepresentedByLinkedListInReverse.h
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

#ifndef ADDTWONUMBERSREPRESENTEDBYLINKEDLISTINREVERSE_H_
#define ADDTWONUMBERSREPRESENTEDBYLINKEDLISTINREVERSE_H_

linkedListNode *AddTwoNumbersPresentInReverse(linkedListNode *ptr1,linkedListNode *ptr2,bool shouldRecursiveFirst){

}

linkedListNode *AddTwoNumbersPresentInReverseAuxSpace(linkedListNode *ptr1,linkedListNode *ptr2){
	stack<int> nodesInList1,nodesInList2;
	linkedListNode *crawler1;
	linkedListNode *newList,*newListCrawler = NULL;

	crawler1 = ptr1;
	while(crawler1 != NULL){
		nodesInList1.push(crawler1->value);
		crawler1 = crawler1->next;
	}

	crawler1 = ptr2;
	while(crawler1 != NULL){
		nodesInList2.push(crawler1->value);
		crawler1 = crawler1->next;
	}

	int carry = 0,sum = 0;
	while(!nodesInList1.empty() && !nodesInList2.empty()){
		sum = nodesInList1.top() + nodesInList2.top() + carry;
		carry = sum/10;
		if(newListCrawler == NULL){
			newListCrawler = (linkedListNode *)malloc(sizeof(linkedListNode));
			newListCrawler->value = sum%10;
			newListCrawler->next = NULL;
		}else{
			newListCrawler = (linkedListNode *)malloc(sizeof(linkedListNode));
			newListCrawler->next = newList;
			newListCrawler->value = sum%10;
		}
		newList = newListCrawler;
		nodesInList1.pop();
		nodesInList2.pop();
	}

	while(!nodesInList1.empty()){
		sum = nodesInList1.top()+carry;
		carry = sum /10;
		newListCrawler = (linkedListNode *)malloc(sizeof(linkedListNode));
		newListCrawler->value =  sum %10;
		newListCrawler->next = newList;
		newList  = newListCrawler;
		nodesInList1.pop();
	}


	while(!nodesInList2.empty()){
		sum = nodesInList2.top()+carry;
		carry = sum/10;
		newListCrawler = (linkedListNode *)malloc(sizeof(linkedListNode));
		newListCrawler->value = sum%10;
		newListCrawler->next = newList;
		newList = newListCrawler;
		nodesInList2.pop();
	}
	return newList;
}

#endif /* ADDTWONUMBERSREPRESENTEDBYLINKEDLISTINREVERSE_H_ */
