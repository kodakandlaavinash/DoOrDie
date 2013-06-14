/*
 * PrintAllRootToLeafPaths.h
 *
 *  Created on: Apr 22, 2013
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

#include "../TreesDS.h"
#include "../TreesUtil.h"
#include "../../Utils/CommonUtils.h"

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef PRINTALLROOTTOLEAFPATHS_H_
#define PRINTALLROOTTOLEAFPATHS_H_

/**
 * Tested
 */
void PrintAllRootToLeafPaths(tNode *ptr,stack<tNode *> rootToLeafAuxSpace){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		printf("%d\t",ptr->value);
		PrintStackContents(rootToLeafAuxSpace);
		return;
	}
	rootToLeafAuxSpace.push(ptr);
	PrintAllRootToLeafPaths(ptr->left,rootToLeafAuxSpace);
	PrintAllRootToLeafPaths(ptr->right,rootToLeafAuxSpace);
}

/**
 * Tested
 */
void PrintAllRootToLeafDriver(tNode *ptr){
	stack<tNode *> rootToLeafAuxSpace;
	PrintAllRootToLeafPaths(ptr,rootToLeafAuxSpace);
}

void PrintAllRootToLeafNodes(tNode *ptr){
	if(ptr == NULL){
		return;
	}

	/**
	 * Rank Node Value Map
	 */
	hash_map<int,int> rankNodeMap;

	rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
	newNode->ptrToNode = ptr;
	newNode->rank = 0;
	queue<rankHelper *> levelOrderHelper;
	rankHelper *currentNode;
	int currentNodeRank;

	rankNodeMap.insert(pair<int,int>(0,newNode->ptrToNode->value));
	while(!levelOrderHelper.empty()){
		currentNode = levelOrderHelper.front();
		currentNodeRank = currentNode->rank;
		if(currentNode->ptrToNode->left != NULL){
			rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
			newNode->ptrToNode = currentNode->ptrToNode->left;
			newNode->rank = (2 *currentNodeRank) +1;
			levelOrderHelper.push(newNode);
			rankNodeMap.insert(pair<int,int>((2*currentNodeRank)+1,newNode->ptrToNode->value));
		}
		if(currentNode->ptrToNode->right != NULL){
			rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
			newNode->ptrToNode = currentNode->ptrToNode->right;
			newNode->rank = (2 *currentNodeRank) +2;
			levelOrderHelper.push(newNode);
			rankNodeMap.insert(pair<int,int>((2*currentNodeRank)+2,newNode->ptrToNode->value));
		}
	}

	hash_map<int,int>::iterator itToRankNodeMap;
	hash_map<int,int>::iterator itToKey;
	int rank;
	for(itToRankNodeMap = rankNodeMap.begin();itToRankNodeMap != rankNodeMap.end();itToRankNodeMap++){
		if((itToKey = rankNodeMap.find((2*itToRankNodeMap->first)+1)) == rankNodeMap.end()){
			// Found the leaf
			rank = itToKey->first;
			while(rank != 0){
				itToKey = rankNodeMap.find(rank);
				printf("%d\t",itToKey->second);
				rank = rank/2;
			}
			itToKey = rankNodeMap.find(0);
			printf("%d\t",itToKey->second);
			printf("\n");
		}
	}

}
#endif /* PRINTALLROOTTOLEAFPATHS_H_ */
