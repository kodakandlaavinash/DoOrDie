/*
 * InOrderWithoutRecursion.h
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

#ifndef INORDERWITHOUTRECURSION_H_
#define INORDERWITHOUTRECURSION_H_

/**
 * Tested
 */
void InorderTraversalWithouthRecursion(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	tNode *currentNode = ptr;
	while(1){
		if(currentNode != NULL){
			auxSpace.push(currentNode);
			currentNode = currentNode->left;
		}else{
			if(!auxSpace.empty()){
				currentNode = auxSpace.top();
				auxSpace.pop();
				printf("%d\t",currentNode->value);
				currentNode = currentNode->right;
			}else{
				break;
			}
		}
	}
}

#endif /* INORDERWITHOUTRECURSION_H_ */
