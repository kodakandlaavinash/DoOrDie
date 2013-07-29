/*
 * DeleteATree.h
 *
 *  Created on: Jul 17, 2013
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

#ifndef DELETEATREE_H_
#define DELETEATREE_H_

void DeleteEntireTree(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL || ptr->right == NULL){
		return;
	}
	tNode *nodeToBeDeleted;
	DeleteEntireTree(ptr->left);
	nodeToBeDeleted = ptr->left;
	ptr->left = NULL;
	free(nodeToBeDeleted);
	DeleteEntireTree(ptr->right);
	nodeToBeDeleted = ptr->right;
	ptr->right = NULL;
	free(nodeToBeDeleted);
}

#endif /* DELETEATREE_H_ */
