/*
 * SortedLinkedListToBST.h
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

#ifndef SORTEDLINKEDLISTTOBST_H_
#define SORTEDLINKEDLISTTOBST_H_

tNode *ConvertSortedVectorToBST(vector<int> sortedVector,tNode *ptr,int startIndex,int endIndex){
	if(startIndex > endIndex){
		ptr = NULL;
		return NULL;
	}
	int middleIndex  = (startIndex + endIndex)/2;
	ptr->value = sortedVector[middleIndex];
	ConvertSortedVectorToBST(sortedVector,ptr->left,startIndex,middleIndex-1);
	ConvertSortedVectorToBST(sortedVector,ptr->right,middleIndex+1,endIndex);
	return ptr;
}

tNode *SortedLinkedListToBSTAuxSpace(linkedListNode *ptr){
	if(ptr == NULL){
		return NULL;
	}
	vector<int> auxSpace;
	linkedListNode *crawler = ptr;
	while(crawler != NULL){
		auxSpace.push_back(crawler->value);
		crawler = crawler->next;
	}
	tNode *bstTree = (tNode *)malloc(sizeof(tNode));
	return ConvertSortedVectorToBST(auxSpace,bstTree,0,auxSpace.size()-1);

}

#endif /* SORTEDLINKEDLISTTOBST_H_ */
