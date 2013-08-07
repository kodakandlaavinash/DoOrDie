/*
 * TernarySearchTree.h
 *
 *  Created on: Jul 25, 2013
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

#ifndef TERNARYSEARCHTREE_H_
#define TERNARYSEARCHTREE_H_

struct ternarySearchTreeNode{
	char value;
	ternarySearchTreeNode *ptrToLessValueNode;
	ternarySearchTreeNode *ptrToEqualValueNode;
	ternarySearchTreeNode *ptrToMoreValueNode;
};

void ConstructTernarySearchTree(ternarySearchTreeNode **ptr,char *word){
	if(word == NULL){
		return;
	}
	char ch;
	if(ptr == NULL){

	}else{
		ch = *word;
		if((*ptr)->value == ch){

		}else{
			if((*ptr)->value < ch){

			}else{

			}
		}
	}
}

bool SearchTernarySearchTree(ternarySearchTreeNode *ptr,char *searchWord){

}

void PrintAllSuggestions(ternarySearchTreeNode *ptr,char *searchWord){

}

#endif /* TERNARYSEARCHTREE_H_ */

