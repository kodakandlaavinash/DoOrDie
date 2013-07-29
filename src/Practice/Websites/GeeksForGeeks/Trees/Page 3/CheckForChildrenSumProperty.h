/*
 * CheckForChildrenSumProperty.h
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

#ifndef CHECKFORCHILDRENSUMPROPERTY_H_
#define CHECKFORCHILDRENSUMPROPERTY_H_

/**
 * Tested
 */
int GetSumOfValuesOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return ptr->value + GetSumOfValuesOfTree(ptr->left) + GetSumOfValuesOfTree(ptr->right);
}

/**
 * Tested
 */
bool CheckForChildrenSumProperty(tNode *ptr){
	if(ptr == NULL){
		return false;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	int leftSum = GetSumOfValuesOfTree(ptr->left);
	int rightSum = GetSumOfValuesOfTree(ptr->right);
	return (ptr->value == leftSum+rightSum) && CheckForChildrenSumProperty(ptr->left) && CheckForChildrenSumProperty(ptr->right);
}

/**
 * Tested
 */
int CheckForChildrenSumPropertyBottomUp(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value;
	}
	int left = CheckForChildrenSumPropertyBottomUp(ptr->left);
	int right = CheckForChildrenSumPropertyBottomUp(ptr->right);
	if(left == INT_MAX || right == INT_MAX){
		return INT_MAX;
	}
	if(ptr->value == left+right){
		return 2*ptr->value;
	}else{
		return INT_MAX;
	}
}

/**
 * Tested
 */
bool CheckForChildrenSumPropertyBottomUpDriver(tNode *ptr){
	int sumOfNodes = GetSumOfValuesOfTree(ptr);
	if(sumOfNodes == CheckForChildrenSumPropertyBottomUp(ptr)){
		return true;
	}else{
		return false;
	}
}

bool CheckForChildrenSumPropertyLevelOrderTopBottom(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	hashmapForTreeDS *levelOrderTreeDS = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *> rankNodeMap = levelOrderTreeDS->rankNodeMap;
	hash_map<int,tNode *>::iterator *itToRankNodeMap;
	hash_map<int,tNode *>::iterator *itToLeftChild;
	hash_map<int,tNode *>::iterator *itToRightChild;
	int currentRank;
	int sum;
	for(itToRankNodeMap = rankNodeMap.begin();itToRankNodeMap != rankNodeMap.end();itToRankNodeMap++){
		currentRank = (*itToRankNodeMap)->first;
		itToLeftChild = rankNodeMap.find((2*currentRank)+1);
		itToRightChild = rankNodeMap.find((2*currentRank)+2);
		sum = 0;
		if(itToLeftChild == NULL){
			sum += (*itToLeftChild)->second->value;
		}else{
			sum += (*itToRightChild)->second->value;
		}
		if(sum != (*itToRankNodeMap)->second->value){
			return false;
		}
	}
	return true;
}

#endif /* CHECKFORCHILDRENSUMPROPERTY_H_ */
