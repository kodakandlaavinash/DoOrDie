`/*
 * AVLTrees.h
 *
 *  Created on: May 29, 2013
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

#ifndef AVLTREES_H_
#define AVLTREES_H_

struct avlNode{
	int value;
	avlNode *left;
	avlNode *right;
	avlNode *parent;
};

avlNode *PerformSingleRotation(avlNode **parent,avlNode *child){
	avlNode *grandParent = parent->parent;
	avlNode *temp;
	bool isParentLeftSideOfGrandParent;
	if(grandParent == NULL){
		//Parent is root
		temp = child->right;
		child->right = parent;
		parent->left = temp;
		child->parent = NULL;
		*ptr = child;
		return;
	}
	if(grandParent->left == parent){
		isParentLeftSideOfGrandParent = true;
	}else{
		isParentLeftSideOfGrandParent = false;
	}
	if(isParentLeftSideOfGrandParent){
		grandParent->left = child;
	}else{
		grandParent->right = child;
	}
	if(parent->left == child){
		temp = child->right;
		child->right = parent;
		parent->left = temp;

	}else{
		temp = child->left;
		child->left = parent;
		parent->right = temp;
	}
	child->parent = grandParent;
	parent->parent = child;
	return child;
}

void PerformDoubleRotation(avlNode *grandParent,avlNode *parent,avlNode *child){
	PerformSingleRotation(parent,child);
	return PerformSingleRotation(grandParent,child);
}

void InsertANodeInAVLTree(avlNode **ptr,int value){
	avlNode *newNode;
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	if(*ptr == NULL){
		//AVL Tree is empty
		*ptr = newNode;
		return;
	}else{
		//AVL Tree is non empty
		avlNode * crawler = *ptr;
		while(1){
			if(crawler->value > value){
				if(crawler->left == NULL){
					crawler->left = newNode;
					newNode->parent = crawler;
					break;
				}else{
					crawler = crawler->left;
				}
			}else{
				if(crawler->right == NULL){
					crawler->right = newNode;
					crawler->parent = crawler;
					break;
				}else{
					crawler = crawler->right;
				}
			}
		}
		int leftHeight,rightHeight;
		avlNode *x,*y,*z;
		crawler = newNode->parent;
		x  = newNode;
		y = crawler;
		if(crawler->parent ==  null){
			return;
		}else{
			z = crawler->parent;
		}
		do{
			leftHeight = HeightOfTree(z->left);
			rightHeight = HeightOfTree(z->right);
			if(abs(leftHeight - rightHeight) > 1){
				if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
					PerformSingleRotation(z,y);
					return;
				}else{
					PerformDoubleRotation(z,y,x);
					return;
				}
			}else{
				y = y->parent;
				x = x->parent;
				z = z->parent;
			}
		}while(z != NULL);

	}
}

avlNode *SearchForKeyInAVLTreeRecursive(avlNode *ptr,int value){
	if(ptr == NULL){
		return NULL;
	}
	if(ptr->value == value){
		return ptr;
	}
	if(ptr->value > value){
		return SearchForKeyInAVLTreeRecursive(ptr->left,value);
	}else{
		return SearchForKeyInAVLTreeRecursive(ptr->right,value);
	}
}

avlNode *SearchForKeyInAVLTreeIterative(avlNode *ptr,int value){
	if(ptr == NULL){
		//AVL Tree is empty
		return NULL;
	}
	avlNode *crawler = ptr;
	while(crawler->value == ptr || crawler != NULL){
		if(crawler->value > value){
			crawler = crawler->left;
		}else{
			crawler = crawler->right;
		}
	}
	if(crawler == NULL){
		return NULL;
	}else{
		return crawler;
	}
}

avlNode *ReplaceAnElementInAVLTreeIterative(avlNode *ptr,int originalValue,int latestValue){
	if(ptr == NULL){
		// AVL Tree is empty
		return NULL;
	}
	avlNode *ptrToKey = SearchForKeyInAVLTreeRecursive(ptr,originalValue);

}

int GetMinimumValueFromAVLTreeRecursive(avlNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(ptr->left == NULL){
		return ptr->value;
	}
	return GetMinimumValueFromAVLTreeRecursive(ptr->left);
}

int GetMaximumValueFromAVLTree(avlNode *ptr){
	if(ptr == NULL){
		return INT_MAX;
	}
	if(ptr->right == NULL){
		return ptr->value;
	}
	return GetMaximumValueFromAVLTree(ptr->right);
}

avlNode *GetSuccessorFromAVLTree(avlNode *ptr,int value){
	avlNode *ptrToKey = SearchForKeyInAVLTreeRecursive(ptr,value);
	if(ptrToKey == NULL){
		return NULL;
	}
	avlNode *crawler;
	if(ptrToKey->right != NULL){
		crawler = ptrToKey->right;
		while(crawler->left != NULL){
			crawler = crawler->left;
		}
	}else{
		crawler = ptrToKey->parent;
		while(crawler != NULL && crawler->value > ptrToKey->value){
			crawler = crawler->parent;
		}
	}
	return crawler;
}

avlNode *GetPredessecorFromAVLTree(avlNode *ptr,int value){
	avlNode *ptrToKey = SearchForKeyInAVLTreeRecursive(ptr,value);
	if(ptrToKey == NULL){
		return NULL;
	}
	avlNode *crawler;
	if(ptrToKey->left != NULL){
		crawler = ptrToKey->left;
		while(crawler->right != NULL){
			crawler = crawler->right;
		}
	}else{
		crawler = ptrToKey->parent;
		while(crawler != NULL && crawler->value < ptrToKey->value){
			crawler = crawler->parent;
		}
	}
	return crawler;
}

avlNode *HandleDeleteOperationForLeaf(avlNode **ptr,avlNode *ptrToKey){
	avlNode *x;
	//leaf node
	if(ptrToKey->parent == NULL){
		//AVL Tree consists of only one node
		*ptr = NULL;
		return NULL;
	}
	x = ptrToKey->parent;
	avlNode *nodeToBeDeleted = ptrToKey;
	if(x->left == ptrToKey){
		//Node to be deleted is left child of parent
		ptrToKey->left = NULL;
	}else{
		// Node to be deleted is right child of parent
		ptrToKey->right = NULL;
	}
	return x;
}

avlNode *HandleDeleteOperationForNodeWithOnlyOneChild(avlNode *ptrToKey){
	avlNode *nodeToBeDeleted,*x;
	if(ptrToKey->left != NULL){
		// Since the node has only one child that child should be a leaf to height balance
		ptrToKey->value = ptrToKey->left->value;
		x = ptrToKey;
		nodeToBeDeleted = ptrToKey->left;
		ptrToKey->left = NULL;
	}else{
		ptrToKey->value = ptrToKey->right->value;
		x = ptrToKey;
		nodeToBeDeleted = ptrToKey->right;
		ptrToKey->right = NULL;
	}
	free(nodeToBeDeleted);
	return x;
}

void DeleteANodeInAVLTree(avlNode **ptr,int value){
	if(ptr == NULL){
		return;
	}
	avlNode *ptrToKey = SearchForKeyInAVLTreeRecursive(*ptr,value);
	if(ptrToKey == NULL){
		cout << "Key doesnt exists in avl tree" << endl;
		return;
	}
	avlNode *x,*y,*z;
	avlNode *nodeToBeDeleted;
	if(ptrToKey->left == NULL && ptrToKey->right == NULL){
		x = HandleDeleteOperationForLeaf(*ptr,ptrToKey);
		if(x == NULL){
			return;
		}
	}else{
		if(ptrToKey->left == NULL || ptrToKey->right == NULL){
			// Internal node with either left or right child as null
			x = HandleDeleteOperationForNodeWithOnlyOneChild(ptrToKey);
		}else{
			// Internal node with no child equal to null
			avlNode *successor = GetSuccessorFromAVLTree(ptr,value);
			ptrToKey->value = successor->value;
			if(successor->left == NULL && successor->right == NULL){
				x = HandleDeleteOperationForLeaf(*ptr,ptrToKey);
				if(x == NULL){
					return;
				}
			}else{
				x = HandleDeleteOperationForNodeWithOnlyOneChild(ptrToKey);
			}
		}
	}

	// Restructuring the AVL Tree
	if(x->parent == NULL){
		return;
	}
	y = x->parent;
	if(y->parent == NULL){
		return;
	}
	z = y->parent;
	int rightHeight,leftHeight;
	bool leftOrRightMax;
	int rightYHeight,leftYHeight;
	do{
		leftHeight = HeightOfTree(z->left);
		rightHeight = HeightOfTree(z->right);
		if(abs(leftHeight - rightHeight) > 1){
			leftOrRightMax =leftHeight > rightHeight?true:false;
			if(leftOrRightMax){
				y = z->left;
			}else{
				y = z->right;
			}

			leftYHeight = HeightOfTree(y->left);
			rightYHeight = HeightOfTree(y->right);

			leftOrRightMax = leftYHeight > rightYHeight?true:false;
			if(leftOrRightMax){
				x = y->left;
			}else{
				x = y->right;
			}
			if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
				// All are in the line
				z = PerformSingleRotation(&z,y);
				leftHeight = HeightOfTree(z->left);
				rightHeight = HeightOfTree(z->right);
				if(leftHeight = rightHeight){
					break;
				}
				z = z->parent;
			}else{
				z = PerformDoubleRotation(z,y,x);
				// We should definitely go upwards
				z = z->parent;
			}
		}else{
			z = z->parent;
		}
	}while(z != NULL);
}

#endif /* AVLTREES_H_ */
