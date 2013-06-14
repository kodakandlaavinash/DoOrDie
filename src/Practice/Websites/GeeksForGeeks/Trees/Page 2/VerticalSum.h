/*
 * VerticalSum.h
 *
 *  Created on: Apr 28, 2013
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

#ifndef VERTICALSUM_H_
#define VERTICALSUM_H_

void VerticalSumInBinaryTree(tNode *ptr,int index,int verticalLevel){
	if(ptr == NULL){
		return;
	}
	if(index == verticalLevel){
		printf("%d\t",ptr->value);
	}
	VerticalSumInBinaryTree(ptr->left,index-1,verticalLevel);
	VerticalSumInBinaryTree(ptr->right,index+1,verticalLevel);
}

void VerticalSumInBinaryTree(tNode *ptr,hash_map<int,int> &verticalLevelAuxSpace,int index){
	if(ptr == NULL){
		return;
	}
	hash_map<int,int>::iterator itToAuxSpace;
	if((itToAuxSpace = verticalLevelAuxSpace.find(index)) != verticalLevelAuxSpace.end()){
		verticalLevelAuxSpace[index]= itToAuxSpace->second + ptr->value;
	}else{
		verticalLevelAuxSpace[index] = ptr->value;
	}
	VerticalSumInBinaryTree(ptr->left,verticalLevelAuxSpace,index-1);
	VerticalSumInBinaryTree(ptr->right,verticalLevelAuxSpace,index+1);
}

#endif /* VERTICALSUM_H_ */
