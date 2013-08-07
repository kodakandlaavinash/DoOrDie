/*
 * ReverseLevelOrderTraversal.h
 *
 *  Created on: Aug 1, 2013
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

#ifndef REVERSELEVELORDERTRAVERSAL_H_
#define REVERSELEVELORDERTRAVERSAL_H_

void PrintReversalOfLevelOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	queue<tNode *> auxSpaceForLevelTraversal;
	stack<tNode *> auxSpaceForReversal;
	tNode *temp;
	auxSpaceForLevelTraversal.push(ptr);
	auxSpaceForReversal.push(NULL);
	while(!auxSpaceForLevelTraversal.empty()){
		temp = auxSpaceForLevelTraversal.front();
		auxSpaceForLevelTraversal.pop();
		if(temp  == null){
			while(!auxSpaceForReversal.empty()){
				printf("%d",auxSpaceForReversal.top()->value);
				auxSpaceForReversal.pop();
			}
			if(auxSpaceForLevelTraversal.size() > 0){
				auxSpaceForLevelTraversal.push(null);
			}else{
				break;
			}
			continue;
		}
		if(temp->left != NULL){
			auxSpaceForLevelTraversal.push(temp->left);
		}
		if(temp->right != NULL){
			auxSpaceForLevelTraversal.push(temp->right);
		}
		auxSpaceForReversal.push(temp);
	}
}

void PrintLevelUsingCounter(tNode *ptr,unsigned int level,int targetLevel){
	if(ptr == NULL){
		return;
	}
	if(level == targetLevel){
		printf("%d",ptr->value);
		return;
	}
	PrintLevelUsingCounter(ptr->left,level+1,targetLevel);
	PrintLevelUsingCounter(ptr->right,level+1,targetLevel);
}

void PrintingByFindingHeight(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	int height = HeightOfTree(ptr);
	for(int levelCounter =height;levelCounter >= 0;levelCounter){
		PrintLevelUsingCounter(ptr,0,levelCounter);
	}
}

void PrintReversalLevelOrderByPruningTree(tNode *ptr,int level){
	if(ptr == NULL){
		return;
	}
	if(ptr->left== NULL && ptr->right == NULL){
		return;
	}
	if(ptr->left->left == NULL && ptr->left->right == NULL){
		//Left child is a leaf node
		printf("%d->%d\t",ptr->left->value,level+1);
		temp = ptr->left;
		ptr->left = NULL;
		free(temp);

	}
	if(ptr->right->left == NULL && ptr->right->right == NULL){
		//Right child is a leaf node
		printf("%d->%d\t",ptr->right->value,level+1);
		temp = ptr->right;
		ptr->right = NULL;
		free(temp);
	}
	tNode *temp;
	PrintReversalLevelOrderByPruningTree(ptr->left,level+1);
	PrintReversalLevelOrderByPruningTree(ptr->right,level+1);
}

void PrintReverseLevelOrderTraversalDriver(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintReversalLevelOrderByPruningTree(ptr,0);
	if(!ptr->left == NULL && !ptr->right == NULL){
		printf("Something went bad");
		return;
	}
	printf("%d->0",ptr->value);
	free(ptr);
}
#endif /* REVERSELEVELORDERTRAVERSAL_H_ */
