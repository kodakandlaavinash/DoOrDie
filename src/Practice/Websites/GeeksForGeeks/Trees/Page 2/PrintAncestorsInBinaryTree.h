/*
 * PrintAncestorsInBinaryTree.h
 *
 *  Created on: Apr 28, 2013
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

#ifndef PRINTANCESTORSINBINARYTREE_H_
#define PRINTANCESTORSINBINARYTREE_H_

bool PrintAncestorsInBinaryTree(tNode *ptr,int target){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == target){
		return true;
	}
	if(PrintAncestorsInBinaryTree(ptr->left,target) || PrintAncestorsInBinaryTree(ptr->right,target)){
		printf("%d\t",ptr->value);
	}
}

bool IsNodePresentInSubTree(tNode *ptr,int key){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == key){
		return true;
	}
	return IsNodePresentInSubTree(ptr->left,key)||IsNodePresentInSubTree(ptr->right,key);
}

void PrintAncestorsInBinaryTree(tNode *ptr,int target){
	if(ptr==NULL){
		return;
	}
	if(ptr->value == target){
		return;
	}
	if(IsNodePresentInSubTree(ptr->left,target) || IsNodePresentInSubTree(ptr->right,target)){
		printf("%d\t",ptr->value);
	}
	PrintAncestorsInBinaryTree(ptr->left,target);
	PrintAncestorsInBinaryTree(ptr->right,target);
}

bool PrintAncestorsAuxStack(tNode *ptr,int target,stack<tNode *> auxSpace){
	if(ptr == NULL){
		return false;
	}
	if(ptr->value == target){
		PrintStackContents(auxSpace);
		return true;
	}
	auxSpace.push(ptr->value);
	bool truthValueLeftTree = PrintAncestorsAuxStack(ptr->left,target,auxSpace);
	if(truthValueLeftTree){
		return true;
	}
	bool truthValueRightTree = PrintAncestorsAuxStack(ptr->right,target,auxSpace);
}

#endif /* PRINTANCESTORSINBINARYTREE_H_ */
