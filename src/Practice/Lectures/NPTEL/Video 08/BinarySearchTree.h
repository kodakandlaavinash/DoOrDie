/*
 * BinarySearchTree.h
 *
 *  Created on: May 27, 2013
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

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

void CreateBinarySearchTree(tNode **ptr,int key){
	if(*ptr ==  null){
		tNode *newNode  = (tNode *)malloc(sizeof(tNode));
		newNode->value = key;
		newNode->left = NULL;
		newNode->right = NULL;
		ptr = newNode;
		return;
	}else{
		if(ptr->value > key){
			return CreateBinarySearchTree(ptr->left,key);
		}else{
			return CreateBinarySearchTree(ptr->right,key);
		}
	}
}

void CreateBinarySearchTree(tNode **ptr,int key){
	tNode *crawler = *ptr;
	tNode *newNode;
	if(crawler == NULL){
		newNode = (tNode *)malloc(sizeof(tNode));
		newNode->value = key;
		newNode->left = NULL;
		newNode->right = NULL;
		*ptr = newNode;
		return;
	}

	while(crawler != NULL){
		if(crawler->value >key){
			if(crawler->left == NULL){
				newNode = (tNode *)malloc(sizeof(tNode));
				newNode->value = key;
				newNode->left = NULL;
				newNode->right = NULL;
				crawler->left = newNode;
				return;
			}
			crawler = crawler->left;
		}else{
			if(crawler->right == NULL){
				newNode = (tNode *)malloc(sizeof(tNode));
				newNode->value = key;
				newNode->left = NULL;
				newNode->right = NULL;
				crawler->right = newNode;
				return;
			}
			crawler = crawler->right;
		}
	}
}

/**
 * check
 */
tNode *GetSuccessorUsingAncestors(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}
	tNode *crawler = ptr ,*ptrToParent = NULL;
	while(crawler->value == key){
		if(crawler->value > key){
			ptrToParent = crawler;
			crawler = crawler->left;
		}else{
			ptrToParent = crawler;
			crawler = crawler->right;
		}
	}
	return ptrToParent;
}


tNode *GetSuccessorOfKey(tNode *ptr,int key){
	tNode *ptrToKey = SearchForKeyInBST(ptr,key);
	if(ptrToKey == NULL){
		printf("Key not found");
		return NULL;
	}
	if(ptrToKey->right != NULL){
		return GetMinimumNode(ptr->right);
	}else{
		return GetSuccessorUsingAncestors(ptr,key);
	}
}


/**
 * check
 */
tNode *GetPredeseccorUsingAncestor(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}

	tNode *crawler = ptr,*ptrToParent = NULL;
	while(crawler->value != key){
		if(crawler->value > key){
			ptrToParent = crawler;
			crawler = crawler->left;
		}else{
			ptrToParent = crawler;
			crawler = crawler->right;
		}
	}

	return ptrToParent;

}

tNode *GetPredecessorOfKey(tNode *ptr,int key){
	tNode *ptrToKey = SearchForKeyInBST(ptr,key);
	if(ptrToKey == NULL){
		printf("Key not found");
		return NULL;
	}
	if(ptrToKey->left != NULL){
		return GetMaximumNodeInBST(ptrToKey->left);
	}else{
		return GetPredeseccorUsingAncestors(ptr,key);
	}
}

tNode *GetMinimumNode(tNode *ptr){
	if(ptr== NULL){
		return NULL;
	}
	if(ptr->left != NULL){
		return GetMinimumFromBST(ptr->left);
	}else{
		return ptr;
	}
}

int GetMinimumFromBST(tNode *ptr){
	if(ptr== NULL){
		return INT_MIN;
	}
	if(ptr->left != NULL){
		return GetMinimumFromBST(ptr->left);
	}else{
		return ptr->value;
	}
}

tNode *GetMaximumNodeInBST(tNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->right != NULL){
		return GetMaximumNodeInBST(ptr->right);
	}else{
		return ptr;
	}
}

int GetMaximumFromBST(tNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(ptr->right != NULL){
		return GetMaximumFromBST(ptr->right);
	}else{
		return ptr->value;
	}
}

tNode *SearchForKeyInBST(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}
	tNode *crawler = ptr;
	while(crawler != NULL){
		if(crawler->value == key){
			return crawler;
		}
		if(crawler->value > key){
			crawler = crawler->left;
		}else{
			crawler = crawler->right;
		}
	}
	return NULL;
}

void DeleteANodeInBinarySearchTree(tNode *ptr,int key){
	if(ptr == NULL){
		return NULL;
	}
	tNode *crawler = ptr;
	tNode *parentPTR = NULL;
	while(crawler != NULL && crawler->value == key){
		parentPTR = crawler;
		crawler = crawler->value > key ? crawler->left : crawler->right;
	}
	if(crawler == NULL){
		printf("Node not found");
		return;
	}

	tNode *nodeToBeDeleted;
	bool isLeftNode;
	if(crawler->left == NULL && crawler->right == NULL){
		nodeToBeDeleted = crawler;
		isLeftNode = parentPTR->left == crawler?true:false;
		isLeftNode?parentPTR->left = NULL:parentPTR->right = NULL;
		free(nodeToBeDeleted);
		return;
	}


}

#endif /* BINARYSEARCHTREE_H_ */
