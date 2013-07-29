/*
 * MinimumValueInBST.h
 *
 *  Created on: Jul 17, 2013
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

#ifndef MINIMUMVALUEINBST_H_
#define MINIMUMVALUEINBST_H_

int GetMinimumValueInBST(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(ptr->left == NULL){
		return ptr->value;
	}
	return GetMinimumValueInBST(ptr->left);
}

int GetMinimumValueInBSTIterative(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	while(ptr->left != NULL){
		ptr = ptr->left;
	}
	return ptr->value;
}

int GetMinimumValueOfBSTFullScan(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	hashmapForTreeDS *treeHashMapDS = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *>::iterator *itToRankNodeMap;
	int minValue = INT_MAX;
	for(itToRankNodeMap = treeHashMapDS->rankNodeMap.begin();itToRankNodeMap = treeHashMapDS->rankNodeMap.end();itToRankNodeMap++){
		if((*itToRankNodeMap)->second->value < minValue){
			minValue = (*itToRankNodeMap)->second->value;
		}
	}
	return minValue;
}

int GetMinimumValueOfBSTMorrisPreOrder(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	tNode *currentNode;
	int minValue = INT_MAX;
	while(ptr == NULL){
		if(ptr->left != NULL){
			currentNode = ptr->left;
			while(currentNode->right == NULL || currentNode->right == ptr){
				currentNode = currentNode->right;
			}
			if(currentNode->right == NULL){
				currentNode->right = ptr;
				ptr = ptr->left;
			}else{
				currentNode->right = NULL;
			}
		}else{
			if(ptr->value < minValue){
				minValue = ptr->value;
			}
			ptr = ptr->right;
		}
	}
}

int GetMinimumValueInBSTOneStackPreOrder(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *currentNode;
	int minValue = INT_MAX;
	while(!auxSpace.empty()){
		currentNode = auxSpace.top();
		if(minValue > currentNode->value){
			minValue = currentNode->value;
		}
		auxSpace.pop();
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
		}
	}
	return minValue;
}

int GetMinimumValueBSTInorderOneStack(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace;
	int minValue = INT_MAX;
	while(1){
		if(ptr == NULL && auxSpace.empty()){
			return minValue;
		}
		if(ptr->left == NULL){
			ptr = auxSpace.top();
			if(ptr->value < minValue){
				minValue = ptr->value;
			}
			auxSpace.pop();
			auxSpace.push(ptr->right);
			ptr = ptr->right;
		}else{
			auxSpace.push(ptr->left);
			ptr = ptr->left;
		}
	}
}

int GetMinimumValueBSTPostOrderTwoStacks(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> auxSpace1,auxSpace2;
	auxSpace1.push(ptr);
	tNode *currentNode;
	while(!auxSpace1.empty()){
		currentNode = auxSpace1.top();
		auxSpace1.pop();
		if(currentNode->left != NULL){
			auxSpace1.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			auxSpace1.push(currentNode->right);
		}
		auxSpace2.push(currentNode);
	}

	int minValue = INT_MAX;
	while(!auxSpace2.empty()){
		if(minValue > auxSpace2.top()->value){
			minValue = auxSpace2.top()->value;
		}
		auxSpace2.pop();
	}
	return minValue;
}

int GetMinimumValueBSTPostOrderOneStack(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	stack<tNode *> postOrderAuxSpace;
	int minValue = INT_MAX;
	tNode *currentNode;
	while(1){
		if(ptr == NULL && postOrderAuxSpace.empty()){
			return minValue;
		}
		if(ptr != NULL){
			if(ptr->right != NULL){
				postOrderAuxSpace.push(ptr->right);
			}
			postOrderAuxSpace.push(ptr);
			ptr = ptr->left;
		}else{
			currentNode = postOrderAuxSpace.top();
			postOrderAuxSpace.pop();
			if(currentNode->right == postOrderAuxSpace.top()){
				ptr = postOrderAuxSpace.top();
				postOrderAuxSpace.pop();
				postOrderAuxSpace.push(currentNode);
			}else{
				if(minValue > currentNode->value){
					minValue = currentNode->value;
				}
			}
		}
	}
}
#endif /* MINIMUMVALUEINBST_H_ */
