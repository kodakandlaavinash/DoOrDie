/*
 * TwoElementsClosestToZero.h
 *
 *  Created on: May 14, 2013
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

#ifndef TWOELEMENTSCLOSESTTOZERO_H_
#define TWOELEMENTSCLOSESTTOZERO_H_

int *FindTwoElementsClosestToZero(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}
	sort(userInput,userInput+sizeOfArray);
	int leftCrawler =-1 , rightCrawler  = sizeOfArray;
	int minValue,minIndex1,minIndex2;
	int difference;
	while(leftCrawler < rightCrawler){
		difference = userInput[rightCrawler]+userInput[leftCrawler];

		if(minValue < difference){
			minValue = difference;
			minIndex1 = leftCrawler;
			minIndex2 = rightCrawler;
		}

		if(difference < 0){
			leftCrawler++;
		}else{
			rightCrawler--;
		}
	}

	int minElements[2] = {minIndex1,minIndex2};
	return minElements;
}

int *FindTwoElementsClosestToZeroON2(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}
	int outerCrawler = 0;
	int innerCrawler;

}


#endif /* TWOELEMENTSCLOSESTTOZERO_H_ */
