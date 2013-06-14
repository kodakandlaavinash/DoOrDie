/*
 * DoubleTree.h
 *
 *  Created on: Apr 25, 2013
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

#ifndef DOUBLETREE_H_
#define DOUBLETREE_H_

/**
 * Tested
 */
void ConvertTreeToDoubleTree(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	ConvertTreeToDoubleTree(ptr->left);
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	newNode->value = ptr->value;
	if(ptr->left != NULL){
		newNode->left = ptr->left;
	}else{
		newNode->left = NULL;
	}
	newNode->right = NULL;
	ptr->left = newNode;
	ConvertTreeToDoubleTree(ptr->right);
}

void ConvertTreeToDoubleTreeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	//Incomplete
}

#endif /* DOUBLETREE_H_ */
