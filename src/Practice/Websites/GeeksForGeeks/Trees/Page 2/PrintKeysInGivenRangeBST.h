/*
 * PrintKeysInGivenRangeBST.h
 *
 *  Created on: Apr 28, 2013
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

#ifndef PRINTKEYSINGIVENRANGEBST_H_
#define PRINTKEYSINGIVENRANGEBST_H_

void PrintKeysInGivenRangeBST(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return;
	}
	if(ptr->value > minKeyValue){
		PrintKeysInGivenRangeBST(ptr->left,minKeyValue,maxKeyValue);
	}
	if(ptr->value > minKeyValue && ptr->value < maxKeyValue){
		printf("%d\t",ptr->value);
	}
	if(ptr->value < maxKeyValue){
		PrintKeysInGivenRangeBST(ptr->right,minKeyValue,maxKeyValue);
	}
}

void PrintKeysInGivenRangeBSTInOrderTraversal(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return;
	}
	PrintKeysInGivenRangeBSTInOrderTraversal(ptr->left,minKeyValue,maxKeyValue);
	if(ptr->value > minKeyValue && ptr->value < maxKeyValue){
		printf("%d\t",ptr->value);
	}
	PrintKeysInGivenRangeBSTInOrderTraversal(ptr->right,minKeyValue,maxKeyValue);
}

/**
 * Assuming tree is complete binarytree
 */
void PrintKeysInGivenRangeBSTInOrderNodes(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return;
	}
	vector<int> inOrderNodes;
	GetInOrderTraversalNodes(ptr,inOrderNodes);

	for(int counter=0;counter < inOrderNodes.size();counter++){
		if(inOrderNodes[counter] > minKeyValue && inOrderNodes[counter] < maxKeyValue){
			printf("%d",inOrderNodes[counter]);
		}
	}
}

void PrintKeysInGivenRangeBSTStack(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;

}

#endif /* PRINTKEYSINGIVENRANGEBST_H_ */
