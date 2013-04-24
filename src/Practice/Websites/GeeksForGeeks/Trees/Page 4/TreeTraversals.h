/*
 * TreeTraversals.h
 *
 *  Created on: Apr 22, 2013
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

//int main(){
//	return -1;
//}

#ifndef TREETRAVERSALS_H_
#define TREETRAVERSALS_H_
/**
 * Tested
 */
void PrintTreeInPreOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	printf("%d\t",ptr->value);
	PrintTreeInPreOrder(ptr->left);
	PrintTreeInPreOrder(ptr->right);
}

/**
 * Tested
 */
void PrintTreeInPostOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintTreeInPostOrder(ptr->left);
	PrintTreeInPostOrder(ptr->right);
	printf("%d\t",ptr->value);
}

/**
 * Tested
 */
void PrintTreeInInOrder(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	PrintTreeInInOrder(ptr->left);
	printf("%d\t",ptr->value);
	PrintTreeInInOrder(ptr->right);
}

#endif /* TREETRAVERSALS_H_ */
