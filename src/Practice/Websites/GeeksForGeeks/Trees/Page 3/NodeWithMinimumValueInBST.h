/*
 * NodeWithMinimumValueInBST.h
 *
 *  Created on: Apr 23, 2013
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

#include "../TreesDS.h"
#include "../TreesUtil.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef NODEWITHMINIMUMVALUEINBST_H_
#define NODEWITHMINIMUMVALUEINBST_H_

/**
 * Tested
 */
int MinimumValueInABST(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return ptr->value;
	}
	return MinimumValueInABST(ptr->left);
}

/**
 * Tested
 */
int MinimumValuesInBST(tNode *ptr){
	vector<int> inOrderNodes;
	GetValuesOfTreeInInOrder(ptr,inOrderNodes);
	return inOrderNodes[0];
}

int MinimumValuesInBSTLevelOrder(tNode *ptr){
	return INT_MIN;
}

int MinimumValueInBSTWithoutRecursion(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}

	tNode *crawler = ptr;
	while(crawler->left != NULL){
		crawler = crawler->left;
	}
	return crawler->value;
}
#endif /* NODEWITHMINIMUMVALUEINBST_H_ */
