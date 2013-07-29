/*
 * MaximumSunLeafToRootInBinaryTree.h
 *
 *  Created on: Jul 17, 2013
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

#ifndef MAXIMUMSUMLEAFTOROOTINBINARYTREE_H_
#define MAXIMUMSUMLEAFTOROOTINBINARYTREE_H_

void MaximumSumLeafToRootInBinaryTree(tNode *ptr,int sum,int &maxValue){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		int sumWithLeaf = maxValue + ptr->value;
		if(maxValue < sumWithLeaf){
			maxValue = sumWithLeaf;
		}
		return;
	}
	MaximumSumLeafToRootInBinaryTree(ptr->left,sum+ptr->value,maxValue);
	MaximumSumLeafToRootInBinaryTree(ptr->right,sum+ptr->value,maxValue);
}

void MaximumSumLeafToRootInBinaryEnhancedTree(enhancedTNode *ptr,int &max){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		int sum = 0;
		enhancedTNode *crawler = ptr;
		while(crawler != NULL){
			sum += crawler->value;
			crawler = crawler->parent;
		}
		if(sum > max){
			max = sum;
		}
	}
	MaximumSumLeafToRootInBinaryEnhancedTree(ptr->left,max);
	MaximumSumLeafToRootInBinaryEnhancedTree(ptr->right,max);
}

int MaximumSumLeafToRootBinaryTreeHashMap(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	hashmapForTreeDS *hashMapOfNodes = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *>::iterator *itRankNodeMap;
	hash_map<int,tNode *>::iterator *itToLeftChild;
	hash_map<int,tNode *>::iterator *itToRightChild;
	hash_map<int,tNode *>::iterator *itToTemp;
	int currentNodeRank;
	int maxSum = INT_MIN;
	for(itRankNodeMap = hashMapOfNodes->rankNodeMap.begin();itRankNodeMap = hashMapOfNodes->rankNodeMap.end();itRankNodeMap++){
		currentNodeRank = (*itRankNodeMap)->first;
		itToLeftChild = hashMapOfNodes->rankNodeMap.find((2*currentNodeRank) + 1);
		itToRightChild = hashMapOfNodes->rankNodeMap.find((2*currentNodeRank)+ 2);
		if(itToLeftChild == hashMapOfNodes->rankNodeMap.end() && itToRightChild == hashMapOfNodes->rankNodeMap.end()){
			int sum = (*itRankNodeMap)->second->value;
			currentNodeRank /= 2;
			while(currentNodeRank >= 0){
				itToTemp = hashMapOfNodes->rankNodeMap(currentNodeRank);
				sum += (*itToTemp)->second->value;
			}
			if(maxSum < sum){
				maxSum = sum;
			}
		}
	}
	return maxSum;
}

#endif /* MAXIMUMSUNLEAFTOROOTINBINARYTREE_H_ */
