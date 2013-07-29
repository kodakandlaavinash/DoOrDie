/*
 * PrintBoundaryOfTree.h
 *
 *  Created on: Jul 25, 2013
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

#ifndef PRINTBOUNDARYOFTREE_H_
#define PRINTBOUNDARYOFTREE_H_

void PrintLeftSideOfTree(tNode *ptr,bool exceptLeftMostNode){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		if(!exceptLeftMostNode){
			printf("%d\t",ptr->value);
		}
		return;
	}
	printf("%d\t",ptr->value);
	PrintLeftSideOfTree(ptr->left,exceptLeftMostNode);
}

void PrintRightSideOfTree(tNode *ptr,bool exceptRightMostNode){
	if(ptr == NULL){
		return;
	}
	if(ptr->right == NULL && ptr->left == NULL){
		if(!exceptRightMostNode){
			printf("%d\t",ptr->value);
		}
		return;
	}
	printf("%d\t",ptr->value);
	PrintRightSideOfTree(ptr->right,exceptRightMostNode);
}

void PrintLeavesOfTreeLTR(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		printf("%d\t",ptr->value);
		return;
	}
	PrintLeavesOfTreeLTR(ptr->left);
	PrintLeavesOfTreeLTR(ptr->right);
}

void PrintLeavesOfTreeRTL(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		printf("%d\t",ptr->value);
		return;
	}
	PrintLeavesOfTreeRTL(ptr->right);
	PrintLeavesOfTreeRTL(ptr->left);
}

void BoundaryTraversalOfTree(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintLeftSideOfTree(ptr,true);
	PrintLeavesOfTreeLTR(ptr);
	PrintRightSideOfTree(ptr,true);
}
#endif /* PRINTBOUNDARYOFTREE_H_ */
