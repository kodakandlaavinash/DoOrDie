/*
 * PrintNodesAtKDistanceFromRoot.h
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

#ifndef PRINTNODESATKDISTANCEFROMROOT_H_
#define PRINTNODESATKDISTANCEFROMROOT_H_

/**
 * Tested
 * Root is considered as at zero distance
 */
void PrintNodesAtKDistanceFromRoot(tNode *ptr,int level){
	if(ptr == NULL){
		return;
	}
	if(!level){
		printf("%d\t",ptr->value);
		return;
	}
	PrintNodesAtKDistanceFromRoot(ptr->left,level-1);
	PrintNodesAtKDistanceFromRoot(ptr->right,level-1);
}

/**
 * Tested
 */
void PrintNodesAtKDistanceFromRootLevelOrder(tNode *ptr,int requiredLevel){
	if(ptr == NULL){
		return;
	}
	if(requiredLevel == 0){
		printf("%d",ptr->value);
		return;
	}
	tNode *currentNode;
	queue<tNode *> levelOrderAuxSpace;
	tNode *levelEndIndicator = (tNode *)malloc(sizeof(tNode));
	levelEndIndicator->value = INT_MAX;
	levelEndIndicator->left = NULL;
	levelEndIndicator->right = NULL;
	int levelCounter =0;
	levelOrderAuxSpace.push(ptr);
	levelOrderAuxSpace.push(levelEndIndicator);
	while(!levelOrderAuxSpace.empty()){
		currentNode = levelOrderAuxSpace.front();
		levelOrderAuxSpace.pop();
		if(isEndOfLevelIndicator(currentNode)){
			levelCounter++;
			if(levelOrderAuxSpace.size() > 1){
				levelOrderAuxSpace.push(levelEndIndicator);
			}else{
				break;
			}
			if(levelCounter == requiredLevel){
				do{
					currentNode = levelOrderAuxSpace.front();
					printf("%d\t",currentNode->value);
					levelOrderAuxSpace.pop();
				}while(!isEndOfLevelIndicator(levelOrderAuxSpace.front()));
				break;
			}

		}
		if(currentNode->left != NULL){
			levelOrderAuxSpace.push(currentNode->left);
		}
		if(currentNode->right != NULL){
			levelOrderAuxSpace.push(currentNode->right);
		}
	}
	return;
}

void PrintNodesAtKDistanceFromRoot(tNode *ptr,int K){
	if(ptr == NULL){
		return;
	}
	hashmapForTreeDS *hashMapDSForTree = GetHashMapForTreeDS(ptr);
	hash_map<int,tNode *>::iterator *itToRankNodeMap;
	for(int counter = pow(2,k)-1;counter < (pow(2,k)-1) + pow(2,k);counter++){
		if((itToRankNodeMap = hashMapDSForTree->rankNodeMap.find(counter)) != hashMapDSForTree->rankNodeMap.end()){
			printf("%d\t",(*itToRankNodeMap)->second);
		}
	}
}

#endif /* PRINTNODESATKDISTANCEFROMROOT_H_ */
