/*
 * ConstructATreeFromSpecialInorder.h
 *
 *  Created on: May 13, 2013
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

#ifndef CONSTRUCTATREEFROMSPECIALINORDER_H_
#define CONSTRUCTATREEFROMSPECIALINORDER_H_

int *GetMaxNodeValueIndex(int inOrderNodes[],int startIndex,int endIndex){
	int maxNodeValueIndex[2];
	maxNodeValueIndex[0] = INT_MIN;
	for(int crawler = startIndex;crawler <= endIndex;crawler++){
		if(maxNodeValueIndex[0] < inOrderNodes[crawler]){
			maxNodeValueIndex[0] = inOrderNodes[crawler];
			maxNodeValueIndex[1] = crawler;
		}
	}
	return maxNodeValueIndex;
}

tNode *ConstructATreeFromSpecialInOrder(int inOrderNodes[],int startIndex,int endIndex){
	if(startIndex > endIndex){
		return NULL;
	}
	int maxNodeValueIndex[2]  = max_element(inOrderNodes+startIndex,inOrderNodes+endIndex);
	tNode *root = (tNode *)malloc(sizeof(tNode));
	root->value = maxNode[0];
	root->left = ConstructATreeFromSpecialInOrder(inOrderNodes,startIndex,maxNodeValueIndex[1]-1);
	root->right = ConstructATreeFromSpecialInOrder(inOrderNodes,maxNodeValueIndex[1]+1,endIndex);
	return root;
}

tNode *ConstructATreeFromSpecialInOrderIterative(int inOrderNodes[],int sizeOfInOrder){

}

#endif /* CONSTRUCTATREEFROMSPECIALINORDER_H_ */
