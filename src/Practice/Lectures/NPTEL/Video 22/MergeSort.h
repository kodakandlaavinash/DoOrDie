/*
 * MergeSort.h
 *
 *  Created on: Jun 17, 2013
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

#ifndef MERGESORT_H_
#define MERGESORT_H_

void Merge(int userInput[],int start,int middle,int end,int sizeOfArray){
	if(end - start == 0){
		return;
	}
	int tempSpace[sizeOfArray];
	int firstPartOfCrawler = start;
	int secondPartOfCrawler = middle+1;
	int crawlerForFill = start-1;
	while(firstPartOfCrawler <= middle && secondPartOfCrawler <= end){
		if(userInput[firstPartOfCrawler] < userInput[secondPartOfCrawler]){
			tempSpace[++crawlerForFill] = userInput[firstPartOfCrawler];
			firstPartOfCrawler++;
		}else{
			tempSpace[++crawlerForFill] = userInput[secondPartOfCrawler];
			secondPartOfCrawler++;
		}
	}

	while(firstPartOfCrawler <= middle){
		tempSpace[++crawlerForFill] = userInput[firstPartOfCrawler];
	}

	while(secondPartOfCrawler <= middle){
		tempSpace[++crawlerForFill] = userInput[secondPartOfCrawler];
	}

	for(crawlerForFill = start;crawlerForFill;crawlerForFill++){
		userInput[crawlerForFill] = tempSpace[crawlerForFill];
	}

}

void MergeSort(int userInput[],int sizeOfArray,int startArrayIndex,int endArrayIndex){
	if(startArrayIndex < endArrayIndex){
		int middleIndex = (startArrayIndex + endArrayIndex)/2;
		MergeSort(userInput,startArrayIndex,middleIndex);
		MergeSort(userInput,middleIndex+1,endArrayIndex);
		Merge(userInput,startArrayIndex,middleIndex,endArrayIndex,sizeOfArray);
	}
}

#endif /* MERGESORT_H_ */
