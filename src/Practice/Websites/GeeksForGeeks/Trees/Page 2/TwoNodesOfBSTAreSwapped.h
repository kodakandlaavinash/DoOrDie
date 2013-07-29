/*
 * TwoNodesOfBSTAreSwapped.h
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

#ifndef TWONODESOFBSTARESWAPPED_H_
#define TWONODESOFBSTARESWAPPED_H_

void CorrectBST(tNode *ptr,vector<int> inOrderOfNodes,int &index){
	if(ptr == NULL){
		return;
	}
	TransitionOfBST(ptr->left,inOrderOfNodes,index);
	ptr->value = inOrderOfNodes[index++];
	TransitionOfBST(ptr->right,inOrderOfNodes,index);
}

void CorrectBSTTrigger(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	vector<int> inOrderOfNodes;
	GetValuesOfTreeInInOrder(ptr,inOrderOfNodes);
	CorrectBST(ptr,inOrderOfNodes,0);
}


#endif /* TWONODESOFBSTARESWAPPED_H_ */
