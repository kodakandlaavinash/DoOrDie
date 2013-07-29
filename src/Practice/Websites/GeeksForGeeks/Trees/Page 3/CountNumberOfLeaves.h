/*
 * CountNumberOfLeaves.h
 *
 *  Created on: Apr 23, 2013
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

#ifndef COUNTNUMBEROFLEAVES_H_
#define COUNTNUMBEROFLEAVES_H_

/**
 * Tested
 */
int CountNumberOfLeaves(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return 1;
	}

	return CountNumberOfLeaves(ptr->left)+CountNumberOfLeaves(ptr->right);
}

int CountNumberOfLeavesLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	hashmapForTreeDS *levelOrderAuxSpace = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *>::iterator *itToRankNodeMap;
	hash_map<int,tNode *>::iterator *itToLeftNode;
	hash_map<int,tNode *>::iterator *itToRightNode;
	int currentNodeRank;
	int leafCounter;
	for(itToRankNodeMap = levelOrderAuxSpace->rankNodeMap.begin();itToRankNodeMap != levelOrderAuxSpace->rankNodeMap.end();itToRankNodeMap++){
		currentNodeRank = (*itToRankNodeMap)->first;
		if(((itToLeftNode = levelOrderAuxSpace->rankNodeMap.find((2*currentNodeRank)+1)) == levelOrderAuxSpace->rankNodeMap.end()) && ((itToLeftNode = levelOrderAuxSpace->rankNodeMap.find((2*currentNodeRank)+2)) == levelOrderAuxSpace->rankNodeMap.end())){
			leafCounter += 1;
		}
	}
	return leafCounter;
}

int CountNumbeOfLeavesPreOrderTravesalOneStack(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode;
	int totalNumberOfLeaves = 0;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		auxSpace.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			totalNumberOfLeaves++;
		}else{
			if(currentNode->left != NULL){
				auxSpace.push(currentNode->left);
			}else{
				auxSpace.push(currentNode->right);
			}
		}
	}
	return totalNumberOfLeaves;
}

int NumberOfLeavesPostOrderTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> firstStack,secondStack;
	tNode *currentNode;
	int countNumberLeaves = 0;
	while(!firstStack.empty()){
		currentNode = firstStack.top();
		firstStack.pop();
		if(currentNode->left == NULL && currentNode->right == NULL){
			currentNode++;
		}else{
			if(currentNode->left != NULL){
				firstStack.push(currentNode->left);
			}
			if(currentNode->right != NULL){
				firstStack.push(currentNode->right);
			}
		}
	}
	return countNumberLeaves;
}

int NumberOfLeavesPostOrderOneStack(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
}

int NumberOfLeavesInOrderStack(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *temp = ptr;
	int numberOfLeaves = 0;
	while(1){
		if(ptr != NULL){
			auxSpace.push(ptr);
			ptr = ptr->left;
		}else{
			ptr = auxSpace.top();
			auxSpace.pop();
			if(ptr->right != NULL){
				auxSpace.push(ptr->right);
				ptr = ptr->right;
			}else{
				if(ptr->left == NULL && ptr->right == NULL){
					numberOfLeaves++;
				}
			}
		}
	}
	return numberOfLeaves;
}
#endif /* COUNTNUMBEROFLEAVES_H_ */
