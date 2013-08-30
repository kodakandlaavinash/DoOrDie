/*
 * AddTwoListsWithoutRecursion.h
 *
 *  Created on: Aug 29, 2013
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

#ifndef ADDTWOLISTSWITHOUTRECURSION_H_
#define ADDTWOLISTSWITHOUTRECURSION_H_

linkedListNode *AddTwoListWithoutRecursion(linkedListNode *userInput1,linkedListNode *userInput2){
	if(userInput1 == NULL && userInput2 == NULL){
		return NULL;
	}
	if(userInput1 == NULL){
		return userInput2;
	}
	if(userInput2 == NULL){
		return userInput1;
	}

	linkedListNode *result,*crawler1 = userInput1,*crawler2 = userInput2,*resultCrawler = NULL;
	ReverseLinkedListFrontCrawling(userInput1);
	ReverseLinkedListFrontCrawling(userInput2);
	int sum,carry = 0;
	while(crawler1 != NULL && crawler2 != NULL){
		sum = crawler1->value + crawler2->value + carry;
		carry = sum/10;
		if(resultCrawler == NULL){
			result = (linkedListNode *)malloc(sizeof(linkedListNode));
			result->value =  sum%10;
			result->next = NULL;
			resultCrawler = result;
		}else{
			resultCrawler->next = (linkedListNode *)malloc(sizeof(linkedListNode));
			resultCrawler->next->value = sum%10;
			resultCrawler->next->next = NULL;
			resultCrawler = resultCrawler->next;
		}
		crawler1 = crawler1->next;
		crawler2 = crawler2->next;
	}
	while(crawler1 != NULL){
		sum = crawler1->value + carry;
		carry = sum/10;
		resultCrawler->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		resultCrawler->next->value = sum%10;
		resultCrawler->next->next = NULL;
		resultCrawler = resultCrawler->next;
	}
	while(crawler2 != NULL){
		sum = crawler2->value + carry;
		carry = sum/10;
		resultCrawler->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		resultCrawler->next->value = sum%10;
		resultCrawler->next->next = NULL;
		resultCrawler = resultCrawler->next;
	}
	while(carry){
		resultCrawler->next = (linkedListNode *)malloc(sizeof(linkedListNode));
		resultCrawler->next->value = carry%10;
		resultCrawler->next->next = NULL;
		resultCrawler = resultCrawler->next;
		carry /= 10;
	}
	ReverseLinkedListFrontCrawling(result);
	ReverseLinkedListFrontCrawling(userInput1);
	ReverseLinkedListFrontCrawling(userInput2);
	return result;
}

#endif /* ADDTWOLISTSWITHOUTRECURSION_H_ */
