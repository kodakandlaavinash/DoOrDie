/*
 * MergeTwoBST.h
 *
 *  Created on: May 13, 2013
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

#ifndef MERGETWOBST_H_
#define MERGETWOBST_H_

void MergeTwoBSTAuxSpace(tNode *bst1,tNode *bst2){
	if(bst1 == NULL || bst2 == NULL){
		return;
	}
	vector<int> inOrderNodes1;
	vector<int> inOrderNodes2;
	GetInOrderTraversalNodes(bst1,inOrderNodes1);
	GetInOrderTraversalNodes(bst2,inOrderNodes2);

	vector<int> mergedInOrderNodes;
	int inOrderCrawler1 = 0,inOrderCrawler2 = 0;
	while(inOrderCrawler1 < inOrderNodes1.size() && inOrderCrawler2 < inOrderNodes2.size()){
		if(inOrderNodes1[inOrderCrawler1] < inOrderNodes2[inOrderCrawler2]){
			mergedInOrderNodes.push_back(inOrderNodes1[inOrderCrawler1]);
			inOrderCrawler1++;
		}else{
			mergedInOrderNodes.push_back(inOrderNodes2[inOrderCrawler2]);
			inOrderCrawler2++;
		}
	}
	int mergedInOrderArray[1000];
	for(int crawler = 0;crawler < mergedInOrderNodes.size();crawler++){
		mergedInOrderArray[crawler] = mergedInOrderNodes[crawler];
	}
	ConstructBSTUsingSortedArray(mergedInOrderArray,0,mergedInOrderNodes.size());
}

void MergeTwoBST(tNode *bst1,tNode *bst2){
	if(bst1 == NULL || bst2 == NULL){
		return;
	}

	vector<int> inOrderNodesBST1;
	GetInOrderTraversalNodes(bst1,inOrderNodesBST1);

	for(int crawler =0;crawler < inOrderNodesBST1.size();crawler++){
		CreateBinarySearchTree(&bst2,inOrderNodesBST1[crawler]);
	}
}

#endif /* MERGETWOBST_H_ */
