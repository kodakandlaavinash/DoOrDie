/*
 * MaximumProductSubArray.h
 *
 *  Created on: Aug 15, 2013
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

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

int MaximumProductSubArray(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	if(sizeOfArray == 1){
		return userInput[0];
	}
	int maxProduct=1,minProduct=1,maximumProduct = 1;
	for(int counter = 0;counter < sizeOfArray;counter++){
		if(userInput[counter] == 0){
			maxProduct = 1;
			minProduct = 1;
		}
		if(userInput[counter]>0){
			maxProduct = maxProduct*userInput[counter];
			minProduct = min(minProduct*userInput[counter],1);
		}else{
			int temp = maxProduct;
			maxProduct = max(minProduct*userInput[counter],1);
			minProduct = temp*userInput[counter];
		}
		if(maximumProduct < maxProduct){
			maximumProduct = maxProduct;
		}
	}
	return maximumProduct;
}

int MaximumProductSubArrayON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int maxProduct = INT_MIN;
	int innerCounter,outerCounter;
	int product;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		product = userInput[outerCounter] == 0?1:userInput[outerCounter];
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter){
			product *= userInput[innerCounter];
		}
		if(maxProduct < product){
			maxProduct = product;
		}
	}
	return maxProduct;
}

#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */
