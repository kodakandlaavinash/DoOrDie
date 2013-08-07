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

int SizeOfTreeInOrderTraversalIterativeOneStack(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	int sizeOfTree = 0;
	while(1){
		if(currentNode == NULL && auxSpace.empty()){
			return sizeOfTree;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			currentNode = currentNode->left;
		}else{
			sizeOfTree++;
			currentNode = auxSpace.top();
			currentNode = currentNode->right;
		}
	}
}

int SizeOfTreePreOrderTraversalStack(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	int sizeOfTree = 1;
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *temp;
	while(!auxSpace.empty()){
		temp = auxSpace.top();
		sizeOfTree += 1;
		if(temp->right != NULL){
			auxSpace.push(temp->right);
		}
		if(temp->left != NULL){
			auxSpace.push(temp->left);
		}
	}
	return sizeOfTree;
}

int sizeOfTreeMorrisPreOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	tNode *currentNode;
	int sizeOfTree = 0;
	while(ptr == NULL){
		if(ptr->left == NULL){
			sizeOfTree++;
			ptr = ptr->right;
		}else{
			currentNode = ptr->left;
			while(currentNode->right == NULL || currentNode->right == ptr){
				currentNode = currentNode->right;
			}
			if(currentNode->right == NULL){
				sizeOfTree++;
				currentNode->right = ptr;
				ptr  = ptr->left;
			}else{
				currentNode->right = NULL;
				ptr = ptr->right;
			}
		}
	}
	return sizeOfTree;
}

int sizeOfTreePostOrderTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> firstStack;
	stack<tNode *> secondStack;
	firstStack.push(ptr);
	tNode *temp;
	while(firstStack.empty()){
		temp = firstStack.top();
		firstStack.pop();
		if(temp->left != NULL){
			firstStack.push(temp->left);
		}
		if(temp->right != NULL){
			firstStack.push(temp->right);
		}
		secondStack.push(temp);
	}
	int sizeOfTree = 0;
	while(!secondStack.empty()){
		sizeOfTree++;
		secondStack.pop();
	}
	return sizeOfTree;
}

int sizeOfTreeOneStackPostOrder(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode;
	int sizeOfTree =0;
	while(ptr == NULL){
		if(ptr != NULL){
			if(ptr->right != NULL){
				auxSpace.push(ptr->right);
			}
			auxSpace.push(ptr);
			ptr = ptr->left;
		}else{
			currentNode = auxSpace.top();
			auxSpace.pop();
			if(currentNode->right == auxSpace.top()){
				ptr = auxSpace.top();
				auxSpace.pop();
				auxSpace.push(currentNode);
			}else{
				sizeOfTree++;
				ptr = NULL;
			}
		}
	}
	return sizeOfTree;
}

#endif /* TREESIZE_H_ */
