/*
 * TreeSize.h
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
using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef TREESIZE_H_
#define TREESIZE_H_
/**
 * Tested
 */
int TotalNumberOfNodesOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+TotalNumberOfNodesOfTree(ptr->left)+TotalNumberOfNodesOfTree(ptr->right);
}

int TotalNumberOfNodesOfTreeLevelOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	int totalNodes = 0;
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		totalNodes++;
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
	}
	return totalNodes;
}

#endif /* TREESIZE_H_ */
