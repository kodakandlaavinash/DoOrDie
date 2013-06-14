/*
 * ConstructTreeFromSpecialPreOrder.h
 *
 *  Created on: May 11, 2013
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
#define LEAF_NODE -1
#define NON_LEAF_NODE 1
//int main(){
//	return -1;
//}

#ifndef CONSTRUCTTREEFROMSPECIALPREORDER_H_
#define CONSTRUCTTREEFROMSPECIALPREORDER_H_

void ConstructTreeUsingPreOrder(int preOrder[],int preOrderHelper[],int sizeOfPreOrder){
	if(sizeOfPreOrder == 0){
		return;
	}
	int crawler = 0;
	tNode *ptr;
	queue<tNode *> auxSpace;
	tNode *ptr = (tNode *)malloc(sizeof(tNode));
	ptr->value = preOrder[crawler];
	ptr->left = NULL;
	ptr->right = NULL;
	if(preOrderHelper[crawler] != NON_LEAF_NODE){
		auxSpace.push(ptr);
	}
	crawler++;
	tNode *currentNode;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		if(currentNode->left == NULL){
			currentNode->left = (tNode *)malloc(sizeof(tNode));
			currentNode->value = preOrder[crawler];
			currentNode->left->left= NULL;
			currentNode->left->right = NULL;
			if(preOrderHelper[crawler]!= NON_LEAF_NODE){
				auxSpace.push(currentNode->left);
			}
		}else{
			currentNode->right = (tNode *)malloc(sizeof(tNode));
			currentNode->value = preOrder[crawler];
			currentNode->right->left= NULL;
			currentNode->right->right = NULL;
			if(preOrderHelper[crawler] != NON_LEAF_NODE){
				auxSpace.push(currentNode->right);
			}
			auxSpace.pop();
		}
		crawler++;
	}
}

tNode *ConstructPreOrderTraversalRecursion(int preOrderTraversal[],int preOrderHelper[],int sizeOfPreOrder,int index){
	if(index == sizeOfPreOrder){
		return NULL;
	}

	tNode *ptr;
	ptr->value = preOrderTraversal[index];
	if(preOrderHelper[index] == NON_LEAF_NODE){
		ptr->left = ConstructPreOrderTraversalRecursion(preOrderTraversal,preOrderHelper,sizeOfPreOrder,index+1);
		ptr->right = ConstructPreOrderTraversalRecursion(preOrderTraversal,preOrderHelper,sizeOfPreOrder,index+2);
	}else{
		ptr->left = NULL;
		ptr->right = NULL;
	}
	return ptr;
}

#endif /* CONSTRUCTTREEFROMSPECIALPREORDER_H_ */
