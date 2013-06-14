/*
 * ConvertTreeToBST.h
 *
 *  Created on: May 3, 2013
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

#ifndef CONVERTTREETOBST_H_
#define CONVERTTREETOBST_H_

void PushNodesInGivenOrderIntoTree(tNode *ptr,vector<int> nodes,int &vectorIndex){
	if(ptr == NULL || nodes.size() == 0 || nodes.size() == vectorIndex+1){
		return;
	}
	PushNodesInGivenOrderIntoTree(ptr->left,nodes,vectorIndex);
	ptr->value = nodes[++vectorIndex];
	PushNodesInGivenOrderIntoTree(ptr->right,nodes,vectorIndex);
}

void ConvertTreeIntoBSTWithoutChangingStructure(tNode *ptr){
	if(ptr == NULL){
		return;
	}
	vector<int> keysOfBinaryTree;
	GetInOrderTraversalNodes(ptr,keysOfBinaryTree);
	sort(keysOfBinaryTree.begin(),keysOfBinaryTree.end());
	PushNodesInGivenOrderIntoTree(ptr,keysOfBinaryTree);
}

void ConvertTreeToBSTUsingHeap(tNode *ptr,vector<int> &heapVector){
	if(ptr == NULL){
		return;
	}
	ConvertTreeToBSTUsingHeap(ptr->left,heapVector);
	pop_heap(heapVector.begin(),heapVector.end());
	int currentValue = heapVector.front();
	ptr->value = currentValue;
	heapVector.pop_back();
	ConvertTreeToBSTUsingHeap(ptr->right,heapVector);
}


void CovertTreeIntoBSTUsingHeapDriver(tNode *ptr){
	// Push all the elements into heap
	vector<int> inOrderOfNodes;
	GetInOrderTraversalNodes(ptr,inOrderOfNodes);
	make_heap(inOrderOfNodes.begin(),inOrderOfNodes.end());
	// Now the vector is converted into heap data structure
	ConvertTreeToBSTUsingHeap(ptr,inOrderOfNodes);
}

#endif /* CONVERTTREETOBST_H_ */
