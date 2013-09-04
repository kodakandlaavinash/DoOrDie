/*
 * CheckSingleLinkedListIsPalindromeOrNot.h
 *
 *  Created on: Sep 4, 2013
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

#ifndef CHECKSINGLELINKEDLISTISPALINDROMEORNOT_H_
#define CHECKSINGLELINKEDLISTISPALINDROMEORNOT_H_

bool CheckSingleLinkedListIsPalindromeOrNotNaiveMethod(linkedListNode *ptr){
	if(ptr == NULL){
		return true;
	}
	int lengthOfLinkedList = lengthOfLinkedListIteration(ptr);
	int middleOfLinkedList;
	if(lengthOfLinkedList%2 == 1){
		middleOfLinkedList = lengthOfLinkedList/2 - 1;
	}else{
		middleOfLinkedList = lengthOfLinkedList/2;
	}
	int counter = 0;
	int endPointer;
	linkedListNode *frontCrawler = ptr;
	linkedListNode *endCrawler;
	while(counter <= middleOfLinkedList){
		endPointer = lengthOfLinkedList - counter - 1;
		while(endPointer){
			endCrawler = endCrawler->next;
			endPointer--;
		}
		if(frontCrawler->value != endCrawler->value){
			return false;
		}
		frontCrawler = frontCrawler->next;
		counter++;
	}
	return true;
}

bool CheckSingleLinkedListIsPalindromeOrNotRecursion(linkedListNode *ptr,linkedListNode **begin){
	if(ptr == NULL){
		return true;
	}
	if(ptr->next == NULL){
		//Reached last node
		if(ptr->value  == (*begin)->value){
			*begin = (*begin)->next;
			return true;
		}
		return false;
	}
	bool truthValue = CheckSingleLinkedListIsPalindromeOrNot(ptr->next,begin);
	if(!truthValue){
		return false;
	}
	return ptr->value == (*begin)->value?(*begin)=(*begin)->next,true:false;
}

bool CheckSingleLinkedListIsPalindromeAuxSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return true;
	}
	linkedListNode *crawler = ptr;
	queue<linkedListNode *> auxSpace;
	while(crawler != NULL){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}
	crawler = ptr;
	while(!auxSpace.empty()){
		if(crawler->value != auxSpace.front()){
			return false;
		}
		crawler = crawler->next;
		auxSpace.pop();
	}
	return true;
}

bool CheckSingleLinkedListIsPalindromeMiddleReverse(linkedListNode *ptr){
	if(ptr == NULL){
		return true;
	}
	linkedListNode *middle = GetMiddleOfLinkedListRace(ptr);
	linkedListNode *crawler = ptr;
	while(crawler->next != middle){
		crawler = crawler->next;
	}
	crawler->next = NULL;
	middle = ReverseLinkedListFrontCrawling(middle);
	crawler->next = middle;
	linkedListNode *middleCrawler = middle;
	while(crawler->next != middle){
		if(crawler->value != middleCrawler->value){
			return false;
		}
		crawler = crawler->next;
		middleCrawler = middleCrawler->next;
	}
	crawler = ptr;
	while(crawler->next != middle){
		crawler = crawler->next;
	}
	crawler->next = NULL;
	middle = ReverseLinkedListFrontCrawling(middle);
	crawler->next = middle;
	return true;
}

bool CheckIfLinkedListIsPalindromeAuxStackSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return true;
	}
	stack<linkedListNode *> auxSpace;
	linkedListNode *crawler = ptr;
	while(crawler!= NULL){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}
	crawler= ptr;
	while(!auxSpace.empty()){
		if(crawler->value != auxSpace.top()->value){
			return false;
		}
		auxSpace.pop();
		crawler = crawler->next;
	}
	return true;
}

#endif /* CHECKSINGLELINKEDLISTISPALINDROMEORNOT_H_ */
