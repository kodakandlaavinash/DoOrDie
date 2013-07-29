/*
 * IterativePreorderTraversal.h
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

#ifndef ITERATIVEPREORDERTRAVERSAL_H_
#define ITERATIVEPREORDERTRAVERSAL_H_

void IterativePreOrderTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	stack<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *topNode;
	while(!auxSpace.empty()){
		topNode = auxSpace.top();
		printf("%d",topNode->value);
		auxSpace.pop();
		if(topNode->left != NULL){
			auxSpace.push(topNode->left);
		}
		if(topNode->right != NULL){
			auxSpace.push(topNode->right);
		}
	}
}

#endif /* ITERATIVEPREORDERTRAVERSAL_H_ */
