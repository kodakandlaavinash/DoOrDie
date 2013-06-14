/*
 * DeleteNodesHavingGreaterValueOnRightSide.h
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

#ifndef DELETENODESHAVINGGREATERVALUEONRIGHTSIDE_H_
#define DELETENODESHAVINGGREATERVALUEONRIGHTSIDE_H_

void DeleteNodesHavingGreaterValueOnRightSide(linkedListNode *ptr,int &maxValue){
	if(ptr == NULL){
		maxValue = INT_MIN;
		return;
	}
	DeleteNodesHavingGreaterValueOnRightSide(ptr->next,maxValue);
	if(maxValue > ptr->value){
		//should delete this node
		//The tail node can never be lesser because it is equal to maxValue
		ptr->value = ptr->next->value;
		linkedListNode *nodeToBeDeleted = ptr->next;
		ptr->next = ptr->next->next;
	}else{
		maxValue = ptr->value;
	}
}

void DeleteNodesHavindGreatedValueOnRightSideON2(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}

	linkedListNode *outerCrawler = ptr,*innerCrawler;
	bool shouldDelete = false;
	while(outerCrawler != NULL){
		innerCrawler = outerCrawler+1;
		shouldDelete = false;
		while(innerCrawler != NULL){
			if(outerCrawler->value < innerCrawler->value){
				shouldDelete = true;
				break;
			}
		}

		if(shouldDelete){
			outerCrawler->value = outerCrawler->next->value;
			outerCrawler->next = outerCrawler->next->next;
		}else{
			outerCrawler = outerCrawler->next;
		}
	}
}

void DeleteNodesHavingGreatedValueOnRightSideAuxSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<linkedListNode *> auxSpace;
	linkedListNode *crawler = ptr;

	while(ptr != NULL){
		auxSpace.push(ptr);
		ptr = ptr->next;
	}

	int maxValue = INT_MIN;
	linkedListNode *currentNode,*nodeToBeDeleted;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		if(currentNode->value > maxValue){
			maxValue = currentNode->value;
		}else{
			currentNode->value = currentNode->next->value;
			nodeToBeDeleted = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(nodeToBeDeleted);
		}
		auxSpace.pop();
	}
}

void DeleteNodesHavingGreaterValueOnRightSideReverse(linkedListNode *ptr){
	if(ptr == NULL){
		return;
	}
	ReverseLinkedListFrontCrawling(ptr);
	int maxValue = INT_MIN;
	linkedListNode *crawler = ptr,*nodeToBeDeleted;
	bool shouldTailNodeBeDeleted = false;
	while(crawler != NULL){
		if(crawler->value > INT_MIN){
			maxValue = crawler->value;
			crawler = crawler->next;
		}else{
			if(crawler->next != NULL){
				crawler->value = crawler->next->value;
				nodeToBeDeleted = crawler->next;
				crawler->next = crawler->next->next;
				free(nodeToBeDeleted);
			}else{
				shouldTailNodeBeDeleted = true;
				break;
			}
		}
	}

	if(shouldTailNodeBeDeleted){
		crawler = ptr;
		while(crawler->next->next != NULL){
			crawler = crawler->next;
		}
		nodeToBeDeleted = crawler->next;
		crawler->next = NULL;
		free(nodeToBeDeleted);
	}
}

#endif /* DELETENODESHAVINGGREATERVALUEONRIGHTSIDE_H_ */
