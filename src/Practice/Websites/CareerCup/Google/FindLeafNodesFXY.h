/*
 * FindLeafNodesFXY.h
 *	http://www.careercup.com/question?id=9538713
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

#ifndef FINDLEAFNODESFXY_H_
#define FINDLEAFNODESFXY_H_

struct augTNodeForFXY{
	int value;
	int sumFromRootToNode;
	int sumFromLeftLeafNode;
	int sumFromRightLeafNode;
	augTNodeForFXY *left;
	augTNodeForFXY *right;
};

int FillTheValuesInATree(augTNodeForFXY *ptr,int parentSumValue){
	if(ptr == NULL){
		return 0;
	}
	ptr->sumFromRootToNode = ptr->value + parentSumValue;
	ptr->sumFromLeftLeafNode = FillTheValuesInATree(ptr->left,ptr->sumFromRootToNode);
	ptr->sumFromRightLeafNode = FillTheValuesInATree(ptr->right,ptr->sumFromRootToNode);
	return max(ptr->sumFromLeftLeafNode,ptr->sumFromRightLeafNode);
}

int FindMaxFunctionalValueInTree(augTNodeForFXY *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	int leftValue = FindMaxFunctionalValueInTree(ptr->left);
	int rightValue = FindMaxFunctionalValueInTree(ptr->right);
	int value = ptr->sumFromLeftLeafNode + ptr->sumFromRightLeafNode - ptr->sumFromRootToNode;
	return leftValue>rightValue?(leftValue > value ? leftValue:value):(rightValue>value?rightValue:value);
}

void FindANodeWithMaxFXY(augTNodeForFXY *ptr){
	if(ptr == NULL){
		return;
	}
	FillTheValuesInATree(ptr,0);
	return FindMaxFunctionalValueInTree(ptr);
}

#endif /* FINDLEAFNODESFXY_H_ */
