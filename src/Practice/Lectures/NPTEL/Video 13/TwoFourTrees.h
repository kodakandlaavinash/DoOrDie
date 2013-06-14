/*
 * TwoFourTrees.h
 *
 *  Created on: May 30, 2013
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

#ifndef TWOFOURTREES_H_
#define TWOFOURTREES_H_

#define NO_OF_NODES 3
#define FIRST_CHILD 0

struct _24Node{
	int values[NO_OF_NODES] = {INT_MAX};
	_24Node *ptrToChild[NO_OF_NODES];
	_24Node *ptrToParent;
	int noOfKeysFilled;
};

_24Node *SearchForInsertion(_24Node *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	_24Node *crawler = ptr;
	while(1){
		if(crawler->values[FIRST_CHILD] > value){
			if(crawler->ptrToChild[FIRST_CHILD] == NULL){
				return crawler;
			}else{
				crawler = crawler->ptrToChild[FIRST_CHILD];
			}
		}else{
			for(int crawlerInNode = 0;crawlerInNode < 2;crawler++){
				if(crawler->values[crawlerInNode] == INT_MIN){
					return crawler;
				}
				if(crawler->values[crawlerInNode] > value && crawler->values[crawlerInNode+1] < value){
					if(crawler->ptrToChild[crawler+1] != NULL){
						crawler = crawler->ptrToChild[crawler+1];
						break;
					}else{
						return crawler;
					}
				}
			}
			if(crawler->values[2] < value){
				if(crawler->ptrToChild[3] != NULL){
					crawler = crawler->ptrToChild[3];
				}else{
					return crawler;
				}
			}
		}
	}
}

void InsertAtRightPlaceInNode(_24Node *ptr,int value){
	for(int crawler = NO_OF_NODES-1;crawler >=0;crawler--){
		if(ptr->values[crawler] == INT_MIN){
			continue;
		}
		if(ptr->values[crawler] > value){
			ptr->values[crawler+1] = ptr->values[crawler];
		}else{
			ptr->values[crawler] = value;
			return;
		}
	}
}

_24Node *SplitNode(_24Node *ptr,int value){
	_24Node *newSplitNode  = (_24Node *)malloc(sizeof(_24Node));
	if(value > ptr->values[2]){
		newSplitNode->values[1] = value;
		newSplitNode->values[0] = ptr->values[2];
		ptr->values[2] = INT_MIN;
	}else{
		if(value > ptr->values[1]){
			newSplitNode->values[1] = ptr->values[2];
			newSplitNode->values[0] = value;
			ptr->values[2] = INT_MIN;
		}else{
			newSplitNode->values[1] = ptr->values[2];
			newSplitNode->values[0] = ptr->values[1];
			ptr->values[2] = INT_MIN;
			ptr->values[1] = value;
		}
	}
	return newSplitNode;
}

int FindChildPositionForParent(_24Node *ptr,_24Node *child){
	for(int crawler =0;crawler < NO_OF_NODES+1;crawler++){
		if(ptr->ptrToChild[crawler] == child){
			return crawler;
		}
	}
	return INT_MIN;
}

void CreateTwoFourTree(_24Node **ptr,int value){
	if(*ptr == NULL){
		_24Node *newNode = (_24Node *)malloc(sizeof(_24Node));
		newNode->values[0] = value;
		newNode->ptrToParent = NULL;
		newNode->noOfKeysFilled += 1;
		return;
	}else{
		_24Node *toBeInserted = SearchForInsertion(*ptr,value);
		if(toBeInserted == 3){
			// The node is full so we should split the node;
			_24Node *newSplitNode = (_24Node *)malloc(sizeof(_24Node));
			if(toBeInserted->ptrToParent == NULL){
				// To Be inserted node is a root node
				_24Node *newSplitNode = SplitNode(toBeInserted,value);
				_24Node *newRootNode  = (_24Node *)malloc(sizeof(_24Node));
				newRootNode->values[FIRST_CHILD] = toBeInserted[1];
				toBeInserted[1] = INT_MIN;
				*ptr = newRootNode;
				newRootNode->ptrToChild[0] = toBeInserted;
				newRootNode->ptrToChild[1] = newSplitNode;
				toBeInserted->ptrToParent = newRootNode;
				newSplitNode->ptrToParent = newRootNode;
			}else{
				_24Node *parentNode  = toBeInserted->ptrToParent;
				if(parentNode->noOfKeysFilled == NO_OF_NODES){
					// Parent Node has no space

				}else{
					// Parent has some space
					_24Node *newSplitNode  = SplitNode(toBeInserted,value);

				}
			}
		}else{
			InsertAtRightPlaceInNode(toBeInserted,value);
		}
	}
}

void DeleteAKeyInTwoFourTree(_24Node *ptr,int value){

}

void InOrderTraversalOfTwoFourTree(_24Node *ptr){
	if(ptr == NULL){
		return;
	}

}

void SearchForAKeyInTwoFourTree(){

}

void GetPredecessorInTwoFourTree(){

}

void GetSuccessorInTwoFourTree(){

}

void GetMinValueFromTwoFourTree(){

}

void GetMaxValueFromTwoFourTree(){

}

#endif /* TWOFOURTREES_H_ */
