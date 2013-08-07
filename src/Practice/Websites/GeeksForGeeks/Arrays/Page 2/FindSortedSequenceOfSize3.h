/*
 * FindSortedSequenceOfSize3.h
 *
 *  Created on: Aug 6, 2013
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

#ifndef FINDSORTEDSEQUENCEOFSIZE3_H_
#define FINDSORTEDSEQUENCEOFSIZE3_H_

int *FindSortedSequenceOfSizeThree(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}

	int innerCounter1,innerCounter2;
	bool smallerElementFound,largerElementFound;
	for(int outerCounter = 1;outerCounter < sizeOfArray-1;outerCounter++){
		smallerElementFound = false;largerElementFound = false;
		for(innerCounter1 = 0;innerCounter1 < outerCounter;innerCounter1++){
			if(userInput[innerCounter1] < userInput[outerCounter]){
				smallerElementFound = true;
				break;
			}
		}
		for(innerCounter2 = outerCounter+1;innerCounter2 < sizeOfArray;innerCounter2++){
			if(userInput[innerCounter2] > userInput[outerCounter]){
				largerElementFound = true;
				break;
			}
		}
		if(smallerElementFound && largerElementFound){
			int result[3];
			result[0] = userInput[innerCounter1];
			result[1] = userInput[outerCounter];
			result[2] = userInput[innerCounter2];
			return result;
		}
	}
}

int *FindSortedSequenceOfSizeThreeONAuxSpace(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return NULL;
	}
	int arrayOfSmallElementLR[sizeOfArray],arrayOfLargerElementsRL[sizeOfArray];
	arrayOfSmallElementLR[0] = -1;
	for(int counter = 1;counter < sizeOfArray;counter++){
		if(userInput[counter-1] < userInput[counter]){
			arrayOfSmallElementLR[counter] = counter-1;
		}else{
			arrayOfSmallElementLR[counter] = arrayOfSmallElementLR[counter-1];
		}
	}

	arrayOfLargerElementsRL[sizeOfArray-1] = userInput[sizeOfArray-1];
	for(int counter = sizeOfArray-2;counter >= 0;counter--){
		if(userInput[counter+1] > userInput[counter]){
			arrayOfLargerElementsRL[counter] = counter+1;
		}else{
			arrayOfLargerElementsRL[counter] = arrayOfLargerElementsRL[counter+1];
		}
	}

	for(int counter = 0;counte < sizeOfArray;counter++){
		if(arrayOfSmallElementLR[counter] != -1 && arrayOfLargerElementsRL[counter] != -1){
			int result[3];
			result[0] = userInput[arrayOfSmallElementLR[counter]];
			result[1] = userInput[counter];
			result[2] = userInput[arrayOfLargerElementsRL[counter]];
			return result;
		}
	}
	return NULL;
}

void FindSortedSequenceOfSizeThreeRecusion(int userInput[],int sizeOfArray,int index,int smallElementLR,int &greaterElementRL,int **result){
	if(index >= sizeOfArray || userInput == NULL){
		return;
	}
	if(index ==  sizeOfArray-1){

	}
	if(userInput[index] >smallElement){
		smallElementLR = userInput[index];
	}
	FindSortedSequenceOfSizeThreeRecusion(userInput,sizeOfArray,index+1,smallElement,result);

	//Incomplete
}

#endif /* FINDSORTEDSEQUENCEOFSIZE3_H_ */
