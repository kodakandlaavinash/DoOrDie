/*
 * LowestCommonAncestorInBST.h
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


using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")

//int main(){
//	return -1;
//}

#ifndef LOWESTCOMMONANCESTORINBST_H_
#define LOWESTCOMMONANCESTORINBST_H_

/**
 * Tested
 */
tNode * PrintLowestCommonAncestorInBST(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return NULL;
	}
	if(ptr->value > minKeyValue && maxKeyValue > ptr->value){
		return ptr;
	}
	tNode *left = PrintLowestCommonAncestorInBST(ptr->left,minKeyValue,maxKeyValue);
	if(left != NULL){
		return left;
	}
	tNode *right = PrintLowestCommonAncestorInBST(ptr->right,minKeyValue,maxKeyValue);
	if(right != NULL){
		return right;
	}else{
		return NULL;
	}
	return NULL;
}

//tNode *PrintLowestCommonAncestorInBSTLevelOrder(tNOde *ptr,int minKeyValue,int maxKeyValue){
//	if(ptr == NULL){
//		return NULL;
//	}
//	hash_map<tNode *,int> nodeIndexMap;
//	hash_map<int,tNode *> indexNodeMap;
//	queue<tNode *> levelOrderAuxSpace;
//	tNode *currentNode,*minKeyNode,*maxKeyNode;
//	int currentNodeIndex;
//	levelOrderAuxSpace.push(ptr);
//	nodeIndexMap.insert(pair<tNode *,int>(ptr,0));
//	indexNodeMap.insert(pair<int,tNode *>(0,ptr));
//	while(!levelOrderAuxSpace.empty()){
//		currentNode = levelOrderAuxSpace.front();
//		currentNodeIndex = nodeIndexMap.find(currentNode);
//		if(minKeyValue == currentNode->value){
//			minKeyNode = currentNode;
//		}
//		if(maxKeyValue == currentNode->value){
//			maxKeyNode = currentNode;
//		}
//		if(currentNode->left != NULL){
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode,2*currentNodeIndex));
//			indexNodeMap.insert(pair<int,tNode *>(2*currentNodeIndex,currentNode));
//		}
//		if(currentNode->right != NULL){
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode,(2*currentNodeIndex)+1));
//			indexNodeMap.insert(pair<int,tNode *>((2*currentNodeIndex)+1,currentNode));
//		}
//	}
//
//	int minNodeIndex = nodeIndexMap.find(minKeyNode);
//	int maxNodeIndex = nodeIndexMap.find(maxKeyNode);
//
//	set<int> ancestorsMin;
//	while(minNodeIndex){
//		ancestorsMin.insert(minNodeIndex);
//		minNodeIndex /= 2;
//	}
//
//	ancestorsMin.insert(0);
//	set<int> ancestorsMax;
//	while(maxNodeIndex){
//		ancestorsMax.insert(maxNodeIndex);
//		maxNodeIndex /=2;
//	}
//	ancestorsMax.insert(0);
//
//	set<int> ancestorsIntersection = set_intersection(ancestorsMin.begin(),ancestorsMin.end(),ancestorsMax.begin(),ancestorsMin.end());
//	int maxAncestoralIndex = max_element(ancestorsIntersection.begin(),ancestorsIntersection.end());
//	return indexNodeMap[maxAncestoralIndex];
//}

/**
 * Tested
 */
bool isNodePresentInTree(tNode *ptr,int keyValue){
	if(ptr == NULL){
		return false;
	}

	return ((ptr->value == keyValue)||isNodePresentInTree(ptr->left,keyValue)||isNodePresentInTree(ptr->right,keyValue));
}

/**
 * Tested
 */
tNode *LowestCommonAncestorInBST(tNode *ptr,int minKeyValue,int maxKeyValue){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return NULL;
	}
	bool truthValueForNodePresentOnLeftSide = isNodePresentInTree(ptr->left,minKeyValue);
	bool truthValueForNodePresentOnRightSide = isNodePresentInTree(ptr->right,maxKeyValue);
	if(truthValueForNodePresentOnLeftSide && truthValueForNodePresentOnRightSide){
		return ptr;
	}
	tNode *leftSide = LowestCommonAncestorInBST(ptr->left,minKeyValue,maxKeyValue);
	if(leftSide != NULL){
		return leftSide;
	}
	tNode *rightSide = LowestCommonAncestorInBST(ptr->right,minKeyValue,maxKeyValue);
	if(rightSide != NULL){
		return rightSide;
	}else{
		return NULL;
	}
}

#endif /* LOWESTCOMMONANCESTORINBST_H_ */
