/*
 * MergeTwoArrays.h
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

#ifndef MERGETWOARRAYS_H_
#define MERGETWOARRAYS_H_

/**
 * Tested
 */
int MoveAllElementsToEnd(int largeSortedArray[],int sizeOfLargeSortedArray){
	int lastIndex= sizeOfLargeSortedArray;
	for(int crawlerFromEnd = sizeOfLargeSortedArray-1;crawlerFromEnd >=0;crawlerFromEnd--){
		if(largeSortedArray[crawlerFromEnd] != -1){
			largeSortedArray[--lastIndex] = largeSortedArray[crawlerFromEnd];
		}
	}
	return lastIndex;
}

/**
 * Tested
 */
void MergeTwoArrays(int largeSortedArray[],int sizeOfLargeArray,int smallSortedArray[],int sizeOfSmallArray){
	int crawlerForLargeArray = MoveAllElementsToEnd(largeSortedArray,sizeOfLargeArray);
	int crawlerForSmallArray = 0;
	int crawler;
	for(crawler =0;crawler < sizeOfLargeArray+sizeOfSmallArray && crawlerForLargeArray < sizeOfLargeArray && crawlerForSmallArray < sizeOfSmallArray;crawler++){
		if(largeSortedArray[crawlerForLargeArray] == smallSortedArray[crawlerForSmallArray]){
			largeSortedArray[crawler] = largeSortedArray[crawlerForLargeArray];
			crawler++;
			largeSortedArray[crawler] = smallSortedArray[crawlerForSmallArray];
			crawlerForLargeArray++;
			crawlerForSmallArray++;
		}else{
			if(largeSortedArray[crawlerForLargeArray] > smallSortedArray[crawlerForSmallArray]){
				largeSortedArray[crawler] = smallSortedArray[crawlerForSmallArray];
				crawlerForSmallArray++;
			}else{
				largeSortedArray[crawler] = largeSortedArray[crawlerForLargeArray];
				crawlerForLargeArray++;
			}
		}
	}

	while(crawlerForLargeArray < sizeOfLargeArray){
		largeSortedArray[crawler] = largeSortedArray[crawlerForLargeArray];
		crawler++;
		crawlerForLargeArray++;
	}

	while(crawlerForSmallArray < sizeOfSmallArray){
		largeSortedArray[crawler] = smallSortedArray[crawlerForSmallArray];
		crawler++;
		crawlerForSmallArray++;
	}
}

/**
 * This cannot be done because what if all the elements are in the start of the elements and all the elements in
 * the small array area greater ... ie we have to make space for inserting the elements into the array
 */
void MergeTwoSortedArraysWithoutMovingElements(int largeSortedArray[],int sizeOfLargeArray,int smallSortedArray[],int sizeOfSmallArray);
#endif /* MERGETWOARRAYS_H_ */
