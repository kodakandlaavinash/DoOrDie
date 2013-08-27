/*
 * StockBuySellMaxProfit.h
 *
 *  Created on: Aug 26, 2013
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

#ifndef STOCKBUYSELLMAXPROFIT_H_
#define STOCKBUYSELLMAXPROFIT_H_

int MaxProfitStockBuySellNaiveAlgorithm(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int outerCounter,innerCounter;
	int maxProfit = INT_MIN;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(maxProfit < userInput[innerCounter] - userInput[outerCounter]){
				maxProfit = userInput[innerCounter] - userInput[outerCounter];
			}
		}
	}
	return maxProfit;
}

int MaxProfitStockBuySellON(int userInput[],int sizeOfArray){
	if(userInput == NULL ||  sizeOfArray == 0){
		return INT_MIN;
	}
	stack<int> auxSpaceForIndexes;
	for(int counter = 0;counter < sizeOfArray;counter++){

	}
}

#endif /* STOCKBUYSELLMAXPROFIT_H_ */
