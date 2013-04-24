/*
 * PrintAllRootToLeafPaths.h
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
#include "../TreesUtil.h"
#include "../../Utils/CommonUtils.h"

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef PRINTALLROOTTOLEAFPATHS_H_
#define PRINTALLROOTTOLEAFPATHS_H_

/**
 * Tested
 */
void PrintAllRootToLeafPaths(tNode *ptr,stack<tNode *> rootToLeafAuxSpace){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		printf("%d\t",ptr->value);
		PrintStackContents(rootToLeafAuxSpace);
		return;
	}
	rootToLeafAuxSpace.push(ptr);
	PrintAllRootToLeafPaths(ptr->left,rootToLeafAuxSpace);
	PrintAllRootToLeafPaths(ptr->right,rootToLeafAuxSpace);
}

/**
 * Tested
 */
void PrintAllRootToLeafDriver(tNode *ptr){
	stack<tNode *> rootToLeafAuxSpace;
	PrintAllRootToLeafPaths(ptr,rootToLeafAuxSpace);
}
//void PrintAllRootToLeafPathsLevelOrder(tNode *ptr){
//	if(ptr == NULL){
//		return;
//	}
//	queue<tNode *> auxSpace;
//	set<int> leafNodes;
//	hash_map<int,tNode *> indexNodeMap;
//	hash_map<tNode *,int> nodeIndexMap;
//	tNode *currentNode;
//	hash_map<int,tNode *>::iterator itToKeyNode;
//	int currentNodeIndex;
//	int runningIndex = -1;
//	auxSpace.push(ptr);
//	indexNodeMap.insert(pair<int,tNode *>(++runningIndex,ptr));
//	nodeIndexMap.insert(pair<tNode *,int>(ptr,runningIndex));
//
//	while(!auxSpace.empty()){
//		currentNode = auxSpace.front();
//		itToKeyNode = nodeIndexMap.find(currentNode);
//		if(itToKeyNode == nodeIndexMap.end()){
//			printf("Something is wrong");
//			return;
//		}
//		if(currentNode->left == NULL && currentNode->right == NULL){
//			leafNodes.insert(currentNodeIndex);
//			continue;
//		}
//		if(currentNode->left != NULL){
//			auxSpace.push(currentNode->left);
//			indexNodeMap.insert(pair<int,tNode *>((currentNodeIndex*2),currentNode->left));
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode->left,(currentNodeIndex*2)));
//		}
//		if(currentNode->right != NULL){
//			auxSpace.push(currentNode->right);
//			indexNodeMap.insert(pair<int,tNode *>((currentNodeIndex*2 +1),currentNode->right));
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode->right,(currentNodeIndex*2 + 1)));
//		}
//	}
//
//	//Print Paths using the set and hash map
//	for(set<int>::iterator crawlerLeafIndexes = leafNodes.begin();crawlerLeafIndexes != leafNodes.end();crawlerLeafIndexes++){
//		int indexOfLeafNode = *crawlerLeafIndexes;
//		while(indexOfLeafNode){
//			itToKeyNode = indexNodeMap.find(indexOfLeafNode);
//			printf("%d\t",itToKeyNode->second->value);
//			indexOfLeafNode /= 2;
//		}
//		itToKeyNode = indexNodeMap.find(indexOfLeafNode);
//		printf("%d\t",itToKeyNode->second->value);
//		PRINT_NEW_LINE;
//	}
//}

#endif /* PRINTALLROOTTOLEAFPATHS_H_ */
