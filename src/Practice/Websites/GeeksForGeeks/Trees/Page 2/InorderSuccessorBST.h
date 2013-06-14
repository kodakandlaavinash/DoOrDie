/*
 * InorderSuccessorBST.h
 *
 *  Created on: Apr 27, 2013
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

#ifndef INORDERSUCCESSORBST_H_
#define INORDERSUCCESSORBST_H_

int InOrderSuccessorInABST(tNode *ptr,tNode *ptrToKey){
	if(ptrToKey->right != NULL){
		return minOfBinarySearchTree(ptrToKey->right);
	}

	tNode *crawler = ptr;
	int successor;
	while(crawler != NULL){
		if(crawler->value == ptrToKey->value){
			return successor;
		}
		successor = crawler->value;
		if(crawler->value > ptrToKey->value){
			crawler = crawler->left;
		}else{
			crawler = crawler->right;
		}
	}
}

int InOrderSuccesorInBST(tNode *ptr,tNode *ptrToKey){
	if(ptr == NULL){
		return INT_MIN;
	}
	vector<int> inOrderNodes;
	GetInOrderTraversalNodes(ptr,inOrderNodes);

	// The In order Nodes will be sorted
	vector<int>::iterator itToKey;
	itToKey = upper_bound(inOrderNodes.begin(),inOrderNodes.end(),ptrToKey->value);
	if(itToKey+1 == inOrderNodes.end()){
		return INT_MAX;
	}
	return *(itToKey+1);
}

#endif /* INORDERSUCCESSORBST_H_ */
