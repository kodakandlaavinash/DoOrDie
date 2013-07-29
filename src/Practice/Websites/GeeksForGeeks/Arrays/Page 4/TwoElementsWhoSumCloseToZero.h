/*
 * TwoElementsWhoSumCloseToZero.h
 *
 *  Created on: Jul 29, 2013
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

#ifndef TWOELEMENTSWHOSUMCLOSETOZERO_H_
#define TWOELEMENTSWHOSUMCLOSETOZERO_H_

int TwoElementsWhoSumIsCloseToZeroON2(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MIN;
	}
	int sumOfElements;
	int sumCloseToZero = INT_MAX;
	for(int outerCounter =0;outerCounter <  sizeOfArray;outerCounter++){
		for(int innerCounter = 0;innerCounter < sizeOfArray;innerCounter++){
			sumOfElements = userInput[outerCounter] + userInput[innerCounter];
			if(sumOfElements < 0){
				if(sumCloseToZero < sumOfElements){
					sumCloseToZero = sumOfElements;
				}
			}else{
				if(sumCloseToZero > sumOfElements){
					sumCloseToZero = sumOfElements;
				}
			}
		}
	}
	return sumCloseToZero;
}

int SumCloseToZeroSorting(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return INT_MIN;
	}
	sort(userInput,userInput+sizeOfArray);
	int frontCrawler = 0,backCrawler = sizeOfArray-1;
	int minSum,sumOfElements;
	while(frontCrawler > backCrawler){
		sumOfElements = userInput[frontCrawler] + userInput[backCrawler];
		if(sumOfElements < 0){
			if(minSum < sumOfElements){
				minSum = sumOfElements;
			}
			frontCrawler++;
		}else{
			if(minSum > sumOfElements){
				minSum = sumOfElements;
			}
			backCrawler--;
		}
	}
}


#endif /* TWOELEMENTSWHOSUMCLOSETOZERO_H_ */
