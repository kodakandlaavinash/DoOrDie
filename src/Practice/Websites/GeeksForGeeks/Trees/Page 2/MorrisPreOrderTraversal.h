/*
 * MorrisPreOrderTraversal.h
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

#ifndef MORRISPREORDERTRAVERSAL_H_
#define MORRISPREORDERTRAVERSAL_H_

void MorrisPreOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	tNode *currentNode;
	while(ptr == NULL){
		if(ptr->left == NULL){
			printf("%d",ptr->value);
			ptr = ptr->right;
		}
		currentNode = ptr->left;
		while(currentNode->right == NULL || currentNode->right == ptr){
			currentNode = currentNode->right;
		}
		if(currentNode->right == ptr){
			currentNode->right = NULL;
			ptr = ptr->right;
		}else{
			printf("%d",ptr->value);
			currentNode->right = ptr;
			ptr = ptr->left;
		}
	}
}


#endif /* MORRISPREORDERTRAVERSAL_H_ */
