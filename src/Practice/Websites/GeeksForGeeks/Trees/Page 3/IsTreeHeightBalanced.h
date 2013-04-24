/*
 * IsTreeHeightBalanced.h
 *
 *  Created on: Apr 24, 2013
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

#ifndef ISTREEHEIGHTBALANCED_H_
#define ISTREEHEIGHTBALANCED_H_

/**
 * Tested
 */
bool isTreeHeightBalanced(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	int leftSubTreeHeight  = HeightOfTree(ptr->left);
	int rightSubTreeHeight = HeightOfTree(ptr->right);
	if(abs(leftSubTreeHeight - rightSubTreeHeight) == 1 || abs(leftSubTreeHeight - rightSubTreeHeight) == 0){
		return isTreeHeightBalanced(ptr->left) && isTreeHeightBalanced(ptr->right);
	}
	return false;
}

/**
 * Tested
 */
int isTreeHeightBalancedBottomUp(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return 1;
	}
	int leftSideHeight = isTreeHeightBalancedBottomUp(ptr->left);
	int rightSideHeight = isTreeHeightBalancedBottomUp(ptr->right);
	if(leftSideHeight == INT_MIN || rightSideHeight == INT_MIN){
		return INT_MIN;
	}
	if(abs(leftSideHeight-rightSideHeight) == 1|| abs(leftSideHeight-rightSideHeight) == 0){
		return 1+max(leftSideHeight,rightSideHeight);
	}else{
		return INT_MIN;
	}
}

/**
 * Tested
 */
bool isHeightBalancedBottomUpDriver(tNode *ptr){
	if(INT_MIN == isTreeHeightBalancedBottomUp(ptr)){
		return false;
	}else{
		return true;
	}
}


#endif /* ISTREEHEIGHTBALANCED_H_ */
