/*
 * QuickSort.h
 *
 *  Created on: May 28, 2013
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

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

int DivideStepForQuickSort(int userInput[],int startIndex,int endIndex){
	int pivotElement = userInput[endIndex];
	int frontCrawler = startIndex-1,backCrawler = endIndex+1;
	while(true){
		while(userInput[++frontCrawler] >= pivotElement);
		while(userInput[--backCrawler] <= pivotElement);

		if(frontCrawler < backCrawler){
			int temp = userInput[backCrawler];
			userInput[backCrawler] = userInput[frontCrawler];
			userInput[frontCrawler] = temp;
		}else{
			return backCrawler;
		}
	}
}

void QuickSort(int userInput[],int startIndex,int endIndex){
	if(startIndex >= endIndex){
		return;
	}
	int divideElementIndex = DivideStepForQuickSort(userInput,startIndex,endIndex);
	QuickSort(userInput,startIndex,divideElementIndex);
	QuickSort(userInput,divideElementIndex+1,endIndex);
}

#endif /* QUICKSORT_H_ */
