/*
 * ConvertTreeToBinarySumTree.h
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

#ifndef CONVERTTREETOBINARYSUMTREE_H_
#define CONVERTTREETOBINARYSUMTREE_H_

/**
 * Tested
 */
int ConvertATreeToSumTree(tNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value;
	}
	int leftSumValue = ConvertATreeToSumTree(ptr->left);
	int rightSumValue = ConvertATreeToSumTree(ptr->right);
	ptr->value = leftSumValue + rightSumValue;
	return 2*(ptr->value);
}

void ConvertATreeSumTree(tNode *ptr,int rank,hash_map<int,int> &rankNodeMap){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return;
	}
	ConvertATreeSumTree(ptr->left,2*rank+1,rankNodeMap);
	ConvertATreeSumTree(ptr->right,(2*rank)+2,rankNodeMap);
	int sum = 0;
	hash_map<int,int>::iterator itHelperToRankNodeMap;
	if((itHelperToRankNodeMap = rankNodeMap.find((2*rank)+1)) != rankNodeMap.end()){
		sum += itHelperToRankNodeMap->second;
	}
	if((itHelperToRankNodeMap = rankNodeMap.find((2*rank)+2)) != rankNodeMap.end()){
		sum += itHelperToRankNodeMap->second;
	}
	ptr->value = sum;
	rankNodeMap[rank] = 2 * ptr->value;
}

void ConvertATreeToSumTreeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}

	hash_map<int,int> rankNodeMap;
	queue<rankHelper *> auxSpace;

	rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
	newNode->ptrToNode = ptr;
	newNode->rank = 0;
	rankNodeMap.insert(pair<int,int>(0,ptr->value));
	rankHelper *currentNode;
	int currentNodeRank;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		currentNodeRank = currentNode->rank;
		if(currentNode->ptrToNode->left != NULL){
			rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
			newNode->ptrToNode = currentNode->ptrToNode->left;
			newNode->rank = (2*currentNodeRank)+1;
			rankNodeMap.insert(pair<int,int>((2*currentNodeRank)+1,newNode->ptrToNode->value));
		}

		if(currentNode->ptrToNode->right != NULL){
			rankHelper *newNode = (rankHelper *)malloc(sizeof(rankHelper));
			newNode->ptrToNode = currentNode->ptrToNode->right;
			newNode->rank = (2*currentNodeRank)+2;
			rankNodeMap.insert(pair<int,int>((2*currentNodeRank)+2,newNode->ptrToNode->value));
		}
	}


}


#endif /* CONVERTTREETOBINARYSUMTREE_H_ */
