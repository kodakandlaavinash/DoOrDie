/*
 * TreesUtil.h
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

#include "TreesDS.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL

//int main(){
//	return -1;
//}

#ifndef TREESUTIL_H_
#define TREESUTIL_H_


/**
 * Tested
 */
/*
 * Returns
 * Null - if the tree is empty
 * node - if a suitable node is found
 *
 * Warning:
 * This function does not suggest whether new node is to
 * be added to left or right of the node
 */
tNode *GetPositionToInsertInBinaryTree(tNode *ptr){
	queue<tNode *> auxSpace;
	if(ptr == NULL){
		return NULL;
	}
	auxSpace.push(ptr);
	tNode *lastNode = ptr;
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		lastNode = currentNode;
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}else{
			return currentNode;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}else{
			return currentNode;
		}
		auxSpace.pop();
	}
	return lastNode;
}

/**
 * Tested
 */
void CreateBinaryTree(tNode **ptr,int value){
	if(*ptr == NULL){
		tNode *newNode = (tNode *)malloc(sizeof(tNode));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		(*ptr) = newNode;
	}else{
		tNode *newNode = (tNode *)malloc(sizeof(tNode));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		tNode *nodeToBeInsertedAt = GetPositionToInsertInBinaryTree(*ptr);
		if(nodeToBeInsertedAt->left == NULL){
			nodeToBeInsertedAt->left = newNode;
		}else{
			nodeToBeInsertedAt->right = newNode;
		}
	}
}

/**
 * Tested
 */
/*
 * LeftOrRight is set to
 * -1 - if the tree is empty
 * 0  - if the child is to be on the left side of the node
 * 1  - if the child is to be on the right side of the parent node
 */
tNode *GetPositionToInsertInBST(tNode *ptr,int value,int &leftOrRight){
	if(ptr == NULL){
		return NULL;
	}else{
		tNode *crawler = ptr;
		while(ptr != NULL){
			if(crawler->value > value){
				if(crawler->left != NULL){
					crawler = crawler->left;
				}else{
					return crawler;
				}
			}else{
				if(crawler->right != NULL){
					crawler = crawler->right;
				}else{
					leftOrRight = 1;
					return crawler;
				}
			}
		}
	}
	return NULL;
}

/**
 * Tested
 */
void CreateBinarySearchTree(tNode **ptr,int value){
	if((*ptr) == NULL){
		tNode *newNode = (tNode *)malloc(sizeof(tNode));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		(*ptr) = newNode;
	}else{
		tNode *newNode = (tNode *)malloc(sizeof(tNode));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		int leftOrRight = 0;
		tNode *nodeToBeInsertedAt = GetPositionToInsertInBST(*ptr,value,leftOrRight);
		if(leftOrRight == 0){
			nodeToBeInsertedAt->left = newNode;
		}else{
			nodeToBeInsertedAt->right = newNode;
		}
	}
}

void CreateBinaryTreeForArray(tNode **ptr,int inputValues[],int sizeOfArray){
	int counterArray = -1;
	queue<tNode *> auxSpace;
	while(sizeOfArray--){
		if(*ptr == NULL){
			tNode *newNode = (tNode *)malloc(sizeof(tNode));
			newNode->value = inputValues[++counterArray];
			newNode->left = NULL;
			newNode->right = NULL;
			auxSpace.push(newNode);
		}else{
			tNode *nodeToBeInsertedAt = auxSpace.front();
			tNode *newNode = (tNode *)malloc(sizeof(tNode));
			newNode->value = inputValues[++counterArray];
			newNode->left = NULL;
			newNode->right = NULL;
			auxSpace.push(newNode);
			if(nodeToBeInsertedAt->left == NULL){
				nodeToBeInsertedAt->left = newNode;
			}else{
				if(nodeToBeInsertedAt->right == NULL){
					nodeToBeInsertedAt->right = newNode;
					auxSpace.pop();
				}
			}
		}
	}
}

void CreateBinarySearchTreeForArray(tNode **ptr,int inputValues[],int sizeOfArray){
	int counterArray = -1;
	while(sizeOfArray--){
		if(*ptr == NULL){
			tNode *newNode = (tNode *)malloc(sizeof(tNode));
			newNode->value = inputValues[++counterArray];
			newNode->left = NULL;
			newNode->right = NULL;
			(*ptr) = newNode;
		}else{
			tNode *newNode = (tNode *)malloc(sizeof(tNode));
			newNode->value = inputValues[++counterArray];
			newNode->left = NULL;
			newNode->right = NULL;
			tNode *nodeToBeInsertedAt = GetPositionToInsertInBinaryTree(*ptr);
			if(nodeToBeInsertedAt->left == NULL){
				nodeToBeInsertedAt->left = newNode;
			}else{
				nodeToBeInsertedAt->right = newNode;
			}
		}
	}
}


/**
 * Tested
 */
int HeightOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	return 1+max(HeightOfTree(ptr->left),HeightOfTree(ptr->right));
}

/**
 * Tested
 */
void GetPreOrderTraversalNodes(tNode *ptr,vector<tNode *> &preOrderNodes){
	if(ptr == NULL){
		return;
	}
	preOrderNodes.push_back(ptr);
	GetPreOrderTraversalNodes(ptr->left,preOrderNodes);
	GetPreOrderTraversalNodes(ptr->right,preOrderNodes);
}

/**
 * Tested
 */
void GetInOrderTraversalNodes(tNode *ptr,vector<tNode *> &inOrderNodes){
	if(ptr == NULL){
		return;
	}
	GetInOrderTraversalNodes(ptr->left,inOrderNodes);
	inOrderNodes.push_back(ptr);
	GetInOrderTraversalNodes(ptr->right,inOrderNodes);
}

/**
 * Tested
 */
void GetPostOrderTraversalNodes(tNode *ptr,vector<tNode *> &postOrderNodes){
	if(ptr == NULL){
		return;
	}
	GetPostOrderTraversalNodes(ptr->left,postOrderNodes);
	GetPostOrderTraversalNodes(ptr->right,postOrderNodes);
	postOrderNodes.push_back(ptr);
}

void GetValuesOfTreeInPreOrder(tNode *ptr,vector<int> &preOrderValues){
	if(ptr == NULL){
		return;
	}
	preOrderValues.push_back(ptr->value);
	GetValuesOfTreeInPreOrder(ptr->left,preOrderValues);
	GetValuesOfTreeInPreOrder(ptr->right,preOrderValues);
}

void GetValuesOfTreeInInOrder(tNode *ptr,vector<int> &inOrderValues){
	if(ptr == NULL){
		return;
	}
	GetValuesOfTreeInInOrder(ptr->left,inOrderValues);
	inOrderValues.push_back(ptr->value);
	GetValuesOfTreeInInOrder(ptr->right,inOrderValues);
}

void GetValuesOfTreeInPostOrder(tNode *ptr,vector<int> &postOrderValues){
	if(ptr == NULL){
		return;
	}
	GetValuesOfTreeInPostOrder(ptr->left,postOrderValues);
	GetValuesOfTreeInPostOrder(ptr->right,postOrderValues);
	postOrderValues.push_back(ptr->value);
}

tNode *GetEmptyNodeIndicator(){
	tNode *ptr = (tNode *)malloc(sizeof(tNode));
	ptr->value = INT_MIN;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

bool isEmptyNode(tNode *ptr){
	if(ptr->value == INT_MIN && ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	return false;
}

tNode *GetEndOfLevelIndicator(){
	tNode *ptr = (tNode *)malloc(sizeof(tNode));
	ptr->value = INT_MAX;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

bool isEndOfLevelIndicator(tNode *ptr){
	if(ptr->value == INT_MAX && ptr->left == NULL && ptr->right == NULL){
		return true;
	}
	return false;
}

levelOrderDS *LevelOrderOfTree(tNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	queue<tNode *> auxSpace;
	int currentNodeIndex;
	hash_map<int,tNode *> indexNodeMap;
	hash_map<int,int> valueIndexMap;
	hash_map<int,tNode *> valueNodeMap;
	hash_map<int,int>::iterator itToValueIndexMap;
	tNode *currentNode;
	auxSpace.push(ptr);
	indexNodeMap.insert(pair<int,tNode *>(0,ptr));
	valueIndexMap.insert(pair<int,int>(ptr->value,0));
	valueNodeMap.insert(pair<int,tNode *>(ptr->value,ptr));
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		itToValueIndexMap = (valueIndexMap.find(currentNode->value));
		currentNodeIndex = (itToValueIndexMap)->second;
		if(currentNode->left != NULL){
			indexNodeMap.insert(pair<int,tNode *>(2*currentNodeIndex,currentNode->left));
			valueIndexMap.insert(pair<int,int>(currentNode->left->value,2*currentNodeIndex));
			valueNodeMap.insert(pair<int,tNode *>(currentNode->left->value,currentNode->left));
		}
		if(currentNode->right != NULL){
			indexNodeMap.insert(pair<int,tNode *>((2*currentNodeIndex)+1,currentNode->right));
			valueIndexMap.insert(pair<int,int>(currentNode->right->value,(2*currentNodeIndex)+1));
			valueNodeMap.insert(pair<int,tNode *>(currentNode->right->value,currentNode->right));
		}
	}

	levelOrderDS *returnDS = new levelOrderDS();
	returnDS->indexNodeMap = indexNodeMap;
	returnDS->valueIndexMap = valueIndexMap;
	returnDS->valueNodeMap = valueNodeMap;
	return returnDS;

}

#endif /* TREESUTIL_H_ */


