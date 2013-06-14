/*
 * TreeTraversal.h
 *
 *  Created on: May 27, 2013
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

#ifndef TREETRAVERSAL_H_
#define TREETRAVERSAL_H_

void PreOrderTraversalForNOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	printf("%d\t",ptr->value);
	list<tNode *> allChildNodes;
	list<tNode *>::iterator itToChildNodes;
	for(itToChildNodes = allChildNodes.begin();itToChildNodes != allChildNodes.end();itToChildNodes++){
		PreOrderTraversalForNOrder(*itToChildNodes);
	}
}

void PostOrderTraversalForNChildrenNodes(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	list<tNode *> allChildNodes;
	list<tNode *>::iterator itToChildNodes;
	for(itToChildNodes = allChildNodes.begin();itToChildNodes != allChildNodes.end();itToChildNodes++){
		PostOrderTraversalForNChildrenNodes(*itToChildNodes);
	}
	printf("%d\t",ptr->value);
}

#endif /* TREETRAVERSAL_H_ */
