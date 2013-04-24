/*
 * CheckIfBinaryTreeIsBST.h
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

#ifndef CHECKIFBINARYTREEISBST_H_
#define CHECKIFBINARYTREEISBST_H_

/**
 * Tested
 */
/**
 * Condition
 * -1  : Are all nodes less than the key
 *  0  : Are all nodes equal to the key
 *  1  : Are all nodes greater than the key
 */
bool AreAllNodesSatisfyCondition(tNode *ptr,int key,int condition){
	if(ptr == NULL){
		return true;
	}
	bool truthValue = false;
	switch(condition){
	case -1:
		if(ptr->value < key){
			truthValue = true;
		}
		break;
	case 0:
		if(ptr->value == key){
			truthValue = true;
		}
	case 1:
		if(ptr->value > key){
			truthValue = true;
		}
	}

	return truthValue && AreAllNodesSatisfyCondition(ptr->left,key,condition) && AreAllNodesSatisfyCondition(ptr->right,key,condition);
}

/**
 * Tested
 */
bool CheckIfATreeIsBSTOrNot(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	bool leftTruthValue = AreAllNodesSatisfyCondition(ptr->left,ptr->value,-1);
	bool rightTruthValue = AreAllNodesSatisfyCondition(ptr->right,ptr->value,1);
	return leftTruthValue && rightTruthValue && CheckIfATreeIsBSTOrNot(ptr->left) && CheckIfATreeIsBSTOrNot(ptr->right);
}

/**
 * Tested
 */
bool CheckIfATreeIsBSTOrNotInOrder(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	vector<int> inOrderValues;
	GetValuesOfTreeInInOrder(ptr,inOrderValues);
	for(vector<int>::iterator itToInOrderNodes = inOrderValues.begin();itToInOrderNodes != inOrderValues.end() - 1;itToInOrderNodes++){
		if((*itToInOrderNodes) > *(itToInOrderNodes+1)){
			return false;
		}
	}
	return true;
}

/**
 * Tested
 */
bool IsBinaryTreeABSTTopBottom(tNode *ptr,int min,int max){
	if(ptr == NULL){
		return true;
	}
	if(ptr->value > min && ptr->value < max){
		return IsBinaryTreeABSTTopBottom(ptr->left,min,ptr->value) && IsBinaryTreeABSTTopBottom(ptr->right,ptr->value,max);
	}else{
		return false;
	}
}

/**
 * Tested
 */
bool IsBinaryTreeABSTTopBottomDriver(tNode *ptr){
	return IsBinaryTreeABSTTopBottom(ptr,INT_MIN,INT_MAX);
}

#endif /* CHECKIFBINARYTREEISBST_H_ */
