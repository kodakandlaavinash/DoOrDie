/*
 * LargestSumContigousArray.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef LARGESTSUMCONTIGOUSARRAY_H_
#define LARGESTSUMCONTIGOUSARRAY_H_

/*
 * Kandane Algorithm
 */
/**
 * Tested
 */
int LargestSumContigousArray(int userInput[],int sizeOfArray){
	int maxSum=0,cummulativeSum=0;
	for(int crawler=0;crawler < sizeOfArray;crawler++){
		cummulativeSum += userInput[crawler];
		if(cummulativeSum < 0){
			cummulativeSum = 0;
		}else{
			if(maxSum < cummulativeSum){
				maxSum = cummulativeSum;
			}
		}
	}
	return maxSum;
}

/**
 * Tested
 */
int LargestSumContigousArrayON2(int userInput[],int sizeOfArray){
	int outerCrawler,innerCrawler;
	int maxSum = INT_MIN;
	int counter=0;
	for(outerCrawler = 0;outerCrawler < sizeOfArray;outerCrawler++){
		counter = userInput[outerCrawler];
		for(innerCrawler = outerCrawler+1;innerCrawler < sizeOfArray;innerCrawler++){
			counter += userInput[innerCrawler];
			if(maxSum < counter){
				maxSum = counter;
			}
		}
	}
	return maxSum;
}
#endif /* LARGESTSUMCONTIGOUSARRAY_H_ */

