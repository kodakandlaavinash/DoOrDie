/*
 * AlternativeSplitOfLinkedList.h
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

#ifndef ALTERNATIVESPLITOFLINKEDLIST_H_
#define ALTERNATIVESPLITOFLINKEDLIST_H_

linkedListNode *AlternativeSplitOfLinkedList(linkedListNode *ptr1){
	if(ptr1 == NULL){
		return NULL;
	}
	linkedListNode *twoLinkedList[2];
	linkedListNode *crawler,*crawlerNewList1,*crawlerNewList2;
	twoLinkedList[0] = ptr1;
	if(ptr1->next == NULL){
		twoLinkedList[1] = NULL;
		return twoLinkedList;
	}

	twoLinkedList[1] = ptr1->next;
	bool isFlag = true;
	crawler = ptr1->next->next;
	crawlerNewList1 = twoLinkedList[0];
	crawlerNewList2 = twoLinkedList[1];
	while(crawler != NULL){
		if(isFlag){
			crawlerNewList1->next = crawler;
			crawlerNewList1 = crawlerNewList1->next;
		}else{
			crawlerNewList2->next = crawler;
			crawlerNewList2 = crawlerNewList2->next;
		}
		isFlag = !isFlag;
		crawler = crawler->next;
	}

	return twoLinkedList;
}

linkedListNode *AlternativeSplitOfLinkedListAuxSpace(linkedListNode *ptr){
	queue<int> firstList;
	queue<int> secondList;
	bool alternate = true;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		if(alternate){
			firstList.push(crawler->value);
		}else{
			secondList.push(crawler->value);
		}
		alternate = !alternate;
		crawler = crawler->next;
	}

	linkedListNode *twoLists[2];
	twoLists[0] = ptr;
	crawler = ptr;
	linkedListNode *predecessorNode;
	while(!firstList.empty()){
		crawler->value = firstList.front();
		predecessorNode = crawler;
		crawler = crawler->next;
		firstList.pop();
	}

	twoLists[1] = crawler;
	predecessorNode->next = NULL;

	while(!secondList.empty()){
		crawler->value = secondList.front();
		crawler = crawler->next;
		secondList.pop();
	}

	return twoLists;
}

#endif /* ALTERNATIVESPLITOFLINKEDLIST_H_ */
