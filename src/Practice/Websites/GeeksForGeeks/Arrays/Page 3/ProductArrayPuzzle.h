/*
 * ProductArrayPuzzle.h
 *
 *  Created on: Jun 20, 2013
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

#ifndef PRODUCTARRAYPUZZLE_H_
#define PRODUCTARRAYPUZZLE_H_

int *FindProductArray(int userInput[],int sizeOfArray){
	if(userInput == null || sizeOfArray == 0){
		return NULL;
	}
	int *leftProduct = (int *)calloc(sizeOfArray,sizeof(int));
	int *rightProduct = (int *)calloc(sizeOfArray,sizeof(int));
	leftProduct[0] = 1;
	rightProduct[sizeOfArray - 1] = 1;
	for(int counter = 1;counter < sizeOfArray;counter++){
		leftProduct[counter] = leftProduct[counter-1] * userInput[counter-1];
	}

	for(int counter = sizeOfArray-2;counter >= 0;counter++){
		rightProduct[counter] = rightProduct[counter+1] * userInput[counter+1];
	}

	for(int counter = 0;counter < sizeOfArray;counter++){
		leftProduct[counter] = leftProduct[counter]*rightProduct[counter];
	}

	return leftProduct;
}

int *ProductArrayPuzzleLimitedSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int *productArray = (int *)calloc(sizeOfArray,sizeof(int));
	productArray[0] = 1;
	for(int counter = 1;counter < sizeOfArray;counter++){
		productArray[counter] = productArray[counter-1] * userInput[counter-1];
	}

	int rightProduct = 1;
	for(int counter = sizeOfArray-2;counter >=0;counter--){
		productArray[counter+1] *= rightProduct;
		rightProduct *= userInput[counter];
	}
	return productArray;
}

int *ProductArrayPuzzleON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}

	int *productArray = (int *)calloc(sizeOfArray,sizeof(int));
	int outerCounter,innerCounter;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		productArray[outerCounter] = 1;
		for(innerCounter = 0;innerCounter < outerCounter;innerCounter++){
			productArray[outerCounter] *= productArray[innerCounter];
		}

		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			productArray[outerCounter] *= productArray[innerCounter];
		}
	}

	return productArray;
}

#endif /* PRODUCTARRAYPUZZLE_H_ */
