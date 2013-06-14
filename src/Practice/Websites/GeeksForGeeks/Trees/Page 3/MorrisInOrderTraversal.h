/*
 * MorrisInOrderTraversal.cpp
 *
 *  Created on: Apr 24, 2013
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

#ifndef MORRISINORDERTRAVERSAL_H_
#define MORRISINORDERTRAVERSAL_H_

void MorrisInOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode = ptr;
	tNode *pre;
	while(currentNode != NULL){
		if(currentNode->left != NULL){
			pre = currentNode->left;

			while(pre->right != NULL && pre->right != currentNode){
				pre = pre->right;
			}

			if(pre->right == NULL){
				pre->right = currentNode;
				currentNode = currentNode->left;
			}else{
				pre->right = NULL;
				printf("%d",currentNode->value);
				currentNode = currentNode->right;
			}
		}else{
			printf("%d",currentNode->value);
			currentNode = currentNode->right;
		}
	}
}

#endif /* MORRISINORDERTRAVERSAL_H_ */
