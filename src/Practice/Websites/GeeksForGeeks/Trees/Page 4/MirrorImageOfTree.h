/*
 * MirrorImageOfTree.h
 *
 *  Created on: Apr 22, 2013
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

#ifndef MIRRORIMAGEOFTREE_H_
#define MIRRORIMAGEOFTREE_H_

/**
 * Tested
 */
void MirrorImageOfTree(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	if(ptr->left == NULL && ptr->right == NULL){
		return;
	}
	MirrorImageOfTree(ptr->left);
	MirrorImageOfTree(ptr->right);
	tNode *temp;
	temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

//void MirrorImageOfTreeHashMap(tNode *ptr){
//	if(ptr == NULL){
//		return;
//	}
//	queue<tNode *> auxSpace;
//	hash_map<int,tNode *> indexNodeMap;
//	hash_map<tNode *,int> nodeIndexMap;
//	auxSpace.push(ptr);
//	auxSpace.push(NULL);
//	tNode *currentNode;
//	int value = 0;
//	int currentNodeIndex;
//	hash_map<tNode *,int>::iterator itToCurrentNodeInNodeIndexMap;
//	while(!auxSpace.empty()){
//		currentNode = auxSpace.front();
//		auxSpace.pop();
//		if((itToCurrentNodeInNodeIndexMap = nodeIndexMap.find(currentNode)) != nodeIndexMap.end()){
//			currentNodeIndex = itToCurrentNodeInNodeIndexMap->second;
//		}else{
//			printf("Something went wrong");
//			return;
//		}
//
//		if(currentNode->left != NULL){
//			indexNodeMap.insert(pair<int,tNode *>((2*currentNodeIndex),currentNode->left));
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode->left,(2*currentNodeIndex)));
//		}
//
//		if(currentNode->right != NULL){
//			indexNodeMap.insert(pair<int,tNode *>((2*currentNodeIndex)+1,currentNode->right));
//			nodeIndexMap.insert(pair<tNode *,int>(currentNode->right,(2*currentNodeIndex)+1));
//		}
//	}
//
//
//}

void MirrorImageOfTreeByCreatingANewTree(){

}

#endif /* MIRRORIMAGEOFTREE_H_ */
