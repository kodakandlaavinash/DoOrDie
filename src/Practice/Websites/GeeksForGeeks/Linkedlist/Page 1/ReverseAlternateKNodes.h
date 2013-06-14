/*
 * ReverseAlternateKNodes.h
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

#ifndef REVERSEALTERNATEKNODES_H_
#define REVERSEALTERNATEKNODES_H_

void ReverseAlternateKNodesInLinkedList(linkedListNode *ptr,int kValue){
	if(ptr == NULL){
		return;
	}

	queue<int> nodesAfterReversing;
	stack<int> auxSpaceForReverse;
	linkedListNode *crawler = ptr;
	bool shouldReverse = true;
	int counter = 0;
	while(crawler != NULL){
		if(counter == kValue){
			shouldReverse = !shouldReverse;
			counter++;
			if(shouldReverse){
				while(!auxSpaceForReverse.empty()){
					nodesAfterReversing.push(auxSpaceForReverse.top());
					auxSpaceForReverse.pop();
				}
			}
		}
		if(shouldReverse){
			auxSpaceForReverse.push(crawler->value);
		}else{
			nodesAfterReversing.push(crawler->value);
		}
		counter++;
	}

	if(!auxSpaceForReverse.empty()){
		nodesAfterReversing.push(auxSpaceForReverse.top());
		auxSpaceForReverse.pop();
	}

	crawler = ptr;
	while(crawler != NULL || !nodesAfterReversing.empty()){
		crawler->value = nodesAfterReversing.front();
		nodesAfterReversing.pop();
		crawler = crawler->next;
	}
}

void ReverseAlternateKNodesRecursionAuxSpace(linkedListNode *ptr,stack<int> &inOrderStack,stack<int> &nodesAfterReversing,bool shouldReverse,int kValue,int counter){
	if(ptr == NULL){
		return;
	}
	if(counter == kValue){

	}
	if(shouldReverse){

	}else{

	}
	ReverseAlternateKNodesRecursionAuxSpace(ptr->next,inOrderStack,nodesAfterReversing,shouldReverse,kValue,counter+1);
}

void ReverseAlternateKNodesIterativeNoAuxSpace(linkedListNode *ptr,int kValue){

}

void ReverseAlternateKNodesRecursionNoAuxSpace(linkedListNode *ptr,int counter,int kValue){
	if(ptr == NULL){
		return;
	}
}

#endif /* REVERSEALTERNATEKNODES_H_ */
