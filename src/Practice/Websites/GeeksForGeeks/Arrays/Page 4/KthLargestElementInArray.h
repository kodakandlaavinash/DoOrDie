/*
 * KthLargestElementInArray.h
 *
 *  Created on: May 20, 2013
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

#ifndef KTHLARGESTELEMENTINARRAY_H_
#define KTHLARGESTELEMENTINARRAY_H_

int KthLargestElementInArrayBubbleSort(int userInput[],int sizeOfArray,int kValue){
	if(sizeOfArray == 0){
		return INT_MAX;
	}
	int outerCrawler = 0,innerCrawler =0;
	int temp;
	for(outerCrawler =0;outerCrawler < sizeOfArray;outerCrawler++){
		for(innerCrawler = 0;innerCrawler < kValue && innerCrawler < sizeOfArray-1;innerCrawler++){
			if(userInput[innerCrawler] > userInput[innerCrawler+1]){
				temp = userInput[innerCrawler];
				userInput[innerCrawler] = userInput[innerCrawler+1];
				userInput[innerCrawler+1] = temp;
			}
		}
	}
	return userInput[sizeOfArray - kValue -1];
}


int KthLargestElementInArraySelectionSort(int userInput[],int sizeOfArray,int kValue){
	if(sizeOfArray == 0){
		return INT_MAX;
	}
	int outerCrawler,innerCrawler;
	int maxInIteration;
	for(outerCrawler = sizeOfArray-1;outerCrawler >=0;outerCrawler--){
		maxInIteration = INT_MIN;
		for(innerCrawler = outerCrawler;innerCrawler >= k;innerCrawler--){
			if(maxInIteration > userInput[innerCrawler]){
				maxInIteration = userInput[innerCrawler];
			}
		}
		userInput[outerCrawler] = maxInIteration;
	}
	return userInput[sizeOfArray - kValue -1];
}

int KthLargestElementInArraySort(int userInput[],int sizeOfArray,int kValue){
	if(sizeOfArray == 0){
		return INT_MAX;
	}
	sort(userInput,userInput+sizeOfArray);
	return userInput[sizeOfArray-kValue-1];
}

int KthLargestElementInArrayHeap(int userInput[],int sizeOfArray,int kValue){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

	make_heap(userInput,userInput+sizeOfArray);

	for(int crawler=0;crawler < kValue;crawler++){
		pop_heap(userInput,userInput[sizeOfArray - crawler]);
	}

	return userInput[sizeOfArray - kValue -1];
}

int KthLargestElementInArrayTempArray(int userInput[],int sizeOfArray,int kValue){
	if(sizeOfArray == 0){
		return INT_MAX;
	}

}

int KthLargestElementInArrayMinHeap(int userInput[],int sizeOfArray,int kValue){

}

#endif /* KTHLARGESTELEMENTINARRAY_H_ */
