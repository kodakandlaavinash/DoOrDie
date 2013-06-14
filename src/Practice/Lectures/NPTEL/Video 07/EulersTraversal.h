/*
 * EulersTraversal.h
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

#ifndef EULERSTRAVERSAL_H_
#define EULERSTRAVERSAL_H_

void PerformWhileComingFromTop(tNode *ptr){
	printf("%d\t",ptr->value);
}

void PerformWhileComingFromLeft(tNode *ptr){
	printf("%d\t",ptr->value);
}

void PerformWhileComingFromRight(tNode *ptr){
	printf("%d\t",ptr->value);
}

void EulersTraversal(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	PerformWhileComingFromTop(ptr);
	EulersTraversal(ptr->left);
	PerformWhileComingFromLeft(ptr);
	EulersTraversal(ptr->right);
	PerformWhileComingFromRight(ptr);
}

#endif /* EULERSTRAVERSAL_H_ */
