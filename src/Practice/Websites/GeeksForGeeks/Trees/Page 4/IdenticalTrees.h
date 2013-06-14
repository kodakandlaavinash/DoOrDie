/*
 * IdenticalTrees.h
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

#include "../TreesUtil.h"
#include "../../Utils/CommonUtils.h"

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef IDENTICALTREES_H_
#define IDENTICALTREES_H_

/**
 * Tested
 */
bool AreTreesIdentical(tNode *ptr1,tNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if((ptr1 == NULL && ptr2 != NULL)||(ptr1 != NULL && ptr2 == NULL)){
		return false;
	}

	return (ptr1->value == ptr2->value)&&AreTreesIdentical(ptr1->left,ptr2->left) && AreTreesIdentical(ptr1->right,ptr2->right);
}

/**
 * Tested
 */
bool AreTreesIdenticalQueue(tNode *ptr1,tNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}
	if((ptr1 == NULL && ptr2 != NULL)||(ptr1 != NULL && ptr2 == NULL)){
		return false;
	}

	vector<tNode *> levelOrderAuxSpaceTree1;
	tNode *currentNode;
	levelOrderAuxSpaceTree1.push_back(ptr1);
	tNode *endLevelIndicator = (tNode *)malloc(sizeof(tNode));;
	endLevelIndicator->value = INT_MAX;
	endLevelIndicator->left = NULL;
	endLevelIndicator->right = NULL;

	tNode *emptyNodeIndicator = (tNode *)malloc(sizeof(tNode));;
	emptyNodeIndicator->value = INT_MIN;
	emptyNodeIndicator->left = NULL;
	emptyNodeIndicator->right = NULL;
	levelOrderAuxSpaceTree1.push_back(endLevelIndicator);
	unsigned int vectorCrawler;

	for(vectorCrawler = 0;vectorCrawler < levelOrderAuxSpaceTree1.size();vectorCrawler++){
		currentNode = levelOrderAuxSpaceTree1[vectorCrawler];
		if(isEndOfLevelIndicator(currentNode)){
			if(vectorCrawler+1 < levelOrderAuxSpaceTree1.size()){
				levelOrderAuxSpaceTree1.push_back(endLevelIndicator);
			}
			continue;
		}
		if(isEmptyNode(currentNode)){
			continue;
		}

		if(currentNode->left == NULL && currentNode->right == NULL){
			continue;
		}
		if(currentNode->left != NULL){
			levelOrderAuxSpaceTree1.push_back(currentNode->left);
		}else{
			levelOrderAuxSpaceTree1.push_back(emptyNodeIndicator);
		}

		if(currentNode->right != NULL){
			levelOrderAuxSpaceTree1.push_back(currentNode->right);
		}else{
			levelOrderAuxSpaceTree1.push_back(emptyNodeIndicator);
		}

	}

	vector<tNode *> levelOrderAuxSpaceTree2;
	levelOrderAuxSpaceTree2.push_back(ptr2);
	levelOrderAuxSpaceTree2.push_back(endLevelIndicator);

	for(vectorCrawler = 0;vectorCrawler < levelOrderAuxSpaceTree2.size();vectorCrawler++){
		currentNode = levelOrderAuxSpaceTree2[vectorCrawler];
		if(isEndOfLevelIndicator(currentNode)){
			if(vectorCrawler+1 < levelOrderAuxSpaceTree2.size()){
				levelOrderAuxSpaceTree2.push_back(endLevelIndicator);
			}
			continue;
		}
		if(isEmptyNode(currentNode)){
			continue;
		}

		if(currentNode->left == NULL && currentNode->right == NULL){
			continue;
		}
		if(currentNode->left != NULL){
			levelOrderAuxSpaceTree2.push_back(currentNode->left);
		}else{
			levelOrderAuxSpaceTree2.push_back(emptyNodeIndicator);
		}

		if(currentNode->right != NULL){
			levelOrderAuxSpaceTree2.push_back(currentNode->right);
		}else{
			levelOrderAuxSpaceTree2.push_back(emptyNodeIndicator);
		}

	}
	return equal(levelOrderAuxSpaceTree1.begin(),levelOrderAuxSpaceTree1.end(),levelOrderAuxSpaceTree2.begin());
}

bool AreTreesIdenticalHashMap(tNode *ptr1,tNode *ptr2){
	if(ptr1 == NULL && ptr2 == NULL){
		return true;
	}

	if((ptr1 != NULL && ptr2 == NULL)||(ptr1 == NULL && ptr2 != NULL)){
		return false;
	}


	return true;
}

/**
 * Tested
 */
bool AreTreesIdenticalUsingTraversal(tNode *ptr1,tNode *ptr2){
	vector<int> preOrderValuesOfTree1;
	vector<int> preOrderValuesOfTree2;
	vector<int> inOrderValuesOfTree1;
	vector<int> inOrderValuesOfTree2;

	GetValuesOfTreeInPreOrder(ptr1,preOrderValuesOfTree1);
	GetValuesOfTreeInPreOrder(ptr2,preOrderValuesOfTree2);

	GetValuesOfTreeInInOrder(ptr1,inOrderValuesOfTree1);
	GetValuesOfTreeInInOrder(ptr2,inOrderValuesOfTree2);

	return equal(preOrderValuesOfTree1.begin(),preOrderValuesOfTree1.end(),preOrderValuesOfTree2.begin()) && equal(inOrderValuesOfTree1.begin(),inOrderValuesOfTree1.end(),inOrderValuesOfTree2.begin());
}

#endif /* IDENTICALTREES_H_ */
