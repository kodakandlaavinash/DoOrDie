/*
 * InorderTraversalStack.h
 *
 *  Created on: Jul 26, 2013
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

#ifndef INORDERTRAVERSALSTACK_H_
#define INORDERTRAVERSALSTACK_H_

void InOrderTraversalUsingStack(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(1){
		if(currentNode == NULL && auxSpace.empty()){
			return;
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			printf("%d\t",auxSpace.top()->value);
			currentNode = auxSpace.top();
			currentNode = currentNode->right;
			auxSpace.pop();
		}
	}
}

#endif /* INORDERTRAVERSALSTACK_H_ */
