/*
 * FoldableTrees.h
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

#ifndef FOLDABLETREES_H_
#define FOLDABLETREES_H_



bool IsTreeFoldable(tNode *ptr){
	if(ptr == NULL){
		return true;
	}
	MirrorImageOfTree(ptr->left);
	bool result = AreTreesIdentical(ptr->left,ptr->right);
	MirrorImageOfTree(ptr->left);
	return result;
}

//bool IsTreeFoldable2(tNode *ptr){
//	if(ptr == NULL){
//		return true;
//	}
//}

#endif /* FOLDABLETREES_H_ */
