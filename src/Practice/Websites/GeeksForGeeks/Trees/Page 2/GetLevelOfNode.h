/*
 * GetLevelOfNode.h
 *
 *  Created on: Apr 25, 2013
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

#ifndef GETLEVELOFNODE_H_
#define GETLEVELOFNODE_H_

int GetLevelOfNode(tNode *ptr,int level,int key){
	if(ptr == NULL){
		return -1;
	}
	if(ptr->value == key){
		return level;
	}
	int leftLevel = GetLevelOfNode(ptr->left,level+1,key);
	if(leftLevel >=0){
		return level;
	}
	int rightLevel = GetLevelOfNode(ptr->right,level+1,key);
	if(rightLevel >=0){
		return level;
	}else{
		return -1;
	}

}

int GetLevelOfNodeLevelOrder(tNode *ptr,int key){
	if(ptr == NULL){
		return -1;
	}
	queue<tNode *> auxSpaceLevelOrder;
	auxSpaceLevelOrder.push(ptr);
	tNode *endLevelIndicator = (tNode *)malloc(sizeof(tNode));
	endLevelIndicator->value = INT_MAX;
	endLevelIndicator->left = NULL;
	endLevelIndicator->right = NULL;
	auxSpaceLevelOrder.push(endLevelIndicator);
	int levelCounter = 0;
	tNode *currentNode;
	while(!auxSpaceLevelOrder.empty()){
		currentNode = auxSpaceLevelOrder.front();
		if(currentNode->value == key){
			return levelCounter;
		}
		auxSpaceLevelOrder.pop();
		if(isEndOfLevelIndicator(currentNode)){
			if(auxSpaceLevelOrder.size() > 1){
				auxSpaceLevelOrder.push(endLevelIndicator);
			}
			levelCounter++;
		}
	}
}


#endif /* GETLEVELOFNODE_H_ */
