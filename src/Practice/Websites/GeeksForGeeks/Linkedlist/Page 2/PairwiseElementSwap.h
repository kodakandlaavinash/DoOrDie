/*
 * PairwiseElementSwap.h
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

#ifndef PAIRWISEELEMENTSWAP_H_
#define PAIRWISEELEMENTSWAP_H_

void PairWiseElementSwapLinkedList(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}

	while(ptr->next != NULL || ptr != NULL){
		int temp;
		temp = ptr->value;
		ptr->value = ptr->next->value;
		ptr->next->value = temp;
		ptr = ptr->next->next;
	}

	return;
}

void PairWiseElementSwapRecursion(linkedListNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}

	int temp;
	temp = ptr->value;
	ptr->value = ptr->next->value;
	ptr->next->value = temp;
	PairWiseElementSwapRecursion(ptr->next->next);
}

void PairWiseElementSwapAuxSpace(linkedListNode *ptr){
	if(ptr == NULL || ptr->next == NULL){
		return;
	}
	queue<int> oddNumberQueue;
	queue<int> evenNumberQueue;
	linkedListNode *crawler = ptr;
	bool isOddNumber = true;
	while(crawler != NULL){
		if(isOddNumber){
			oddNumberQueue.push(crawler->value);
		}else{
			evenNumberQueue.push(crawler->value);
		}
		isOddNumber = !isOddNumber;
		crawler = crawler->next;
	}
	crawler = ptr;
	isOddNumber = true;
	while(!oddNumberQueue.empty() && !evenNumberQueue.empty()){
		if(isOddNumber){
			crawler->value = evenNumberQueue.front();
			evenNumberQueue.pop();
		}else{
			crawler->value = oddNumberQueue.front();
			oddNumberQueue.pop();
		}
		crawler = crawler->next;
	}
	while(!oddNumberQueue.empty()){
		crawler->value = oddNumberQueue.front();
		oddNumberQueue.pop();
		crawler = crawler->next;
	}
}

void PairwiseElementSwapAuxArraysSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	vector<int> auxSpace;
	int counter = -1;
	linkedListNode *crawler = ptr;
	while(crawler){
		auxSpace[++counter] = crawler->value;
		crawler = crawler->next;
	}

	int tempForSwap;
	for(int counter = 1;counter < auxSpace.size();counter+=2){
		tempForSwap = auxSpace[counter/2];
		auxSpace[counter/2] = auxSpace[counter];
		auxSpace[counter] = tempForSwap;
	}
	crawler = ptr;
	for(int counter = 0;counter < auxSpace.size();counter++){
		crawler = auxSpace[counter];
		crawler = crawler->next;
	}
	return;
}

#endif /* PAIRWISEELEMENTSWAP_H_ */
