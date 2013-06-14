/*
 * TreesDS.h
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

#ifndef TREESDS_H_
#define TREESDS_H_

struct tNode{
	int value;
	tNode *left;
	tNode *right;
};

struct enhancedTNode{
	int value;
	enhancedTNode *left;
	enhancedTNode *right;
	enhancedTNode *parent;
};

struct levelOrderDS{
	hash_map<int,tNode *> indexNodeMap;
	hash_map<int,int> valueIndexMap;
	hash_map<int,tNode *> valueNodeMap;
};

struct augumentedTNode{
	int value;
	augumentedTNode *left;
	augumentedTNode *right;
	int helperVar;
};

struct nextRightTNode{
	int value;
	nextRightTNode *left;
	nextRightTNode *right;
	nextRightTNode *nextRight;
};

struct inOrderSuccessor{
	int value;
	inOrderSuccessor *left;
	inOrderSuccessor *right;
	inOrderSuccessor *successor;
};


struct rankHelper{
	tNode *ptrToNode;
	int rank;
};

#endif /* TREESDS_H_ */
