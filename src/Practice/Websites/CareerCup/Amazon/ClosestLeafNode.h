/*
 * ClosestLeafNode.h
 *
 *  Created on: Sep 12, 2013
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

#ifndef CLOSESTLEAFNODE_H_
#define CLOSESTLEAFNODE_H_

void ClosestLeafNodeToRoot(tNode *ptr,int level,int &minHeight,int &minLeafValue){
	if(ptr == NULL){
		return 0;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		if(minHeight > level){
			minHeight = level;
			minLeafValue = ptr->value;
			return;
		}
	}
	ClosestLeafNodeToRoot(ptr->left,level+1,minHeight,minLeafValue);
	ClosestLeafNodeToRoot(ptr->right,level+1,minHeight,minLeafValue);
}

void ClosestLeafNodeToRootIterative(tNode *ptr){

}

#endif /* CLOSESTLEAFNODE_H_ */
