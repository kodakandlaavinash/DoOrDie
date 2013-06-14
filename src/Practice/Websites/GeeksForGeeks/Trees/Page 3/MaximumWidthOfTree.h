/*
 * MaximumWidthOfTree.h
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

#ifndef MAXIMUMWIDTHOFTREE_H_
#define MAXIMUMWIDTHOFTREE_H_

/**
 * Tested
 */
int MaximumWidthOfTree(tNode *ptr){
	if(ptr == NULL){
		return 0;
	}
	queue<tNode *> auxSpace;
	auxSpace.push(ptr);
	tNode *endOfLevelIndicator = (tNode *)malloc(sizeof(tNode));
	endOfLevelIndicator->value = INT_MAX;
	endOfLevelIndicator->left = NULL;
	endOfLevelIndicator->right = NULL;
	auxSpace.push(endOfLevelIndicator);
	tNode *currentNode;
	int levelCounter = 0;
	int maxWidth = 1;
	while(!auxSpace.empty()){
		currentNode = auxSpace.front();
		auxSpace.pop();
		if(isEndOfLevelIndicator(currentNode)){
			if(maxWidth < levelCounter){
				maxWidth = levelCounter;
			}
			levelCounter = 0;
			if(auxSpace.size() > 0){
				auxSpace.push(endOfLevelIndicator);
			}
		}
		if(currentNode->left != NULL){
			auxSpace.push(currentNode->left);
			levelCounter++;
		}
		if(currentNode->right != NULL){
			auxSpace.push(currentNode->right);
			levelCounter++;
		}
	}
	return maxWidth;
}

void GetMaxWidthHashMap(tNode *ptr,hash_map<int,int> &levelCounter,int level,set<int> &levelsVisited){
	if(ptr == NULL){
		return;
	}
	hash_map<int,int>::iterator itToLevelCounter;
	if((itToLevelCounter = levelCounter.find(level)) != levelCounter.end()){
		levelCounter[level] = itToLevelCounter->second+1;
	}else{
		levelCounter.insert(pair<int,int>(level,1));
		levelsVisited.insert(level);
	}
	GetMaxWidthHashMap(ptr->left,levelCounter,level+1,levelsVisited);
	GetMaxWidthHashMap(ptr->right,levelCounter,level+1,levelsVisited);
}

int GetMaxWidthHashMapDriver(tNode *ptr){
	hash_map<int,int> levelNodeCounter;
	set<int> levels;
	GetMaxWidthHashMap(ptr,levelNodeCounter,0,levels);

	set<int>::iterator itToLevels;
	hash_map<int,int>::iterator itToLevelNodeCounter;
	int maxWidth = INT_MIN;
	for(itToLevels = levels.begin();itToLevels != levels.end();itToLevels++){
		itToLevelNodeCounter = levelNodeCounter.find(*itToLevels);
		if(maxWidth < itToLevelNodeCounter->second){
			maxWidth = itToLevelNodeCounter->second;
		}
	}

	return maxWidth;
}
#endif /* MAXIMUMWIDTHOFTREE_H_ */
