/*
 * CountNumberOfLeaves.h
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

using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef COUNTNUMBEROFLEAVES_H_
#define COUNTNUMBEROFLEAVES_H_

/**
 * Tested
 */
int CountNumberOfLeaves(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return 1;
	}

	return CountNumberOfLeaves(ptr->left)+CountNumberOfLeaves(ptr->right);
}

int CountNumberOfLeavesLevelOrder(tNode *ptr){
	return 0;
}

#endif /* COUNTNUMBEROFLEAVES_H_ */
