/*
 * RootToLeafPathSum.h
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

#ifndef ROOTTOLEAFPATHSUM_H_
#define ROOTTOLEAFPATHSUM_H_

/**
 * Tested
 */
bool hasPathSumRootToLeaf(tNode *ptr,int sumTillNow,int key){
	if(ptr == NULL){
		return false;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		if(sumTillNow+ptr->value == key){
			return true;
		}
		return false;
	}
	return hasPathSumRootToLeaf(ptr->left,sumTillNow+ptr->value,key) || hasPathSumRootToLeaf(ptr->right,sumTillNow+ptr->value,key);
}

bool hasPathSumRootToLeafIterative(tNode *ptr,int key){
	if(ptr == NULL){
		return false;
	}
	hashmapForTreeDS *hashmapOfATree = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *>::iterator *itToHashMapOfTree;
	hash_map<int,tNode *>::iterator *itToLeftOfCurrentNode;
	hash_map<int,tNode *>::iterator *itToRightOfCurrentNode;
	hash_map<int,tNode *>::iterator *itToTempNode;
	int currentNodeRank,sum =0;
	for(itToHashMapOfTree = hashmapOfATree->nodeRankMap.begin();itToHashMapOfTree != hashmapOfATree->nodeRankMap.end();++itToHashMapOfTree){
		currentNodeRank = (*itToHashMapOfTree)->first;
		if((itToLeftOfCurrentNode = hashmapOfATree->nodeRankMap.find(2*currentNodeRank + 1) == NULL) && (itToRightOfCurrentNode = hashmapOfATree->nodeRankMap.find(2*currentNodeRank + 2) == NULL)){
			sum = 0;
			while(currentNodeRank >= 0){
				itToTempNode = hashmapOfATree->nodeRankMap.find(currentNodeRank);
				sum += (*itToTempNode)->second;
				currentNodeRank  /= 2;
			}
			if(sum == key){
				return true;
			}
		}
	}
	return false;
}
#endif /* ROOTTOLEAFPATHSUM_H_ */
