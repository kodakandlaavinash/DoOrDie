/*
 * UnboundedTree.h
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

#ifndef UNBOUNDEDTREE_H_
#define UNBOUNDEDTREE_H_

struct unboundedTree{
	int value;
	unboundedTree *firstChild;
	unboundedTree *nextSibling;
	unboundedTree *parent;
};

void CreateUnBoundedTree(unboundedTree **ptr,int value,int level){
	unboundedTree *crawler = *ptr;
	unboundedTree *newNode = NULL;
	if(crawler == NULL){
		newNode = (unboundedTree *)malloc(sizeof(unboundedTree));
		newNode->value = value;
		newNode->firstChild = NULL;
		newNode->nextSibling = NULL;
		newNode->parent = NULL;
		*ptr = newNode;
	}else{
		crawler = *ptr;

	}
}

#endif /* UNBOUNDEDTREE_H_ */
