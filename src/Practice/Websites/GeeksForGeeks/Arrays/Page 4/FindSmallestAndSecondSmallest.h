/*
 * FindSmallestAndSecondSmallest.h
 *
 *  Created on: May 15, 2013
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

#ifndef FINDSMALLESTANDSECONDSMALLEST_H_
#define FINDSMALLESTANDSECONDSMALLEST_H_

int *FindSmallestAndSecondSmallest(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}

	int twoSmallestElements[2];
	if(sizeOfArray == 1){
		twoSmallestElements[0] = userInput[0];
		twoSmallestElements[1] = INT_MIN;
		return twoSmallestElements;
	}
	int max_element = INT_MIN;
	int second_max_element = INT_MIN;

	for(int crawler = 0;crawler < sizeOfArray;crawler++){
		if(max_element < userInput[crawler]){
			second_max_element = max_element;
			max_element = userInput[crawler];
		}else{
			if(second_max_element < userInput[crawler]){
				second_max_element = userInput[crawler];
			}
		}
	}

	twoSmallestElements[0] = max_element;
	twoSmallestElements[1] = second_max_element;
	return twoSmallestElements;
}

int *FindSmallestAndSecondSmallest(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}
	int twoSmallestElements[2];
	if(sizeOfArray == 1){
		twoSmallestElements[0] = userInput[0];
		twoSmallestElements[1] = INT_MIN;
		return twoSmallestElements;
	}

	sort(userInput,userInput+sizeOfArray);

	twoSmallestElements[0] = max_element;
	twoSmallestElements[1] = second_max_element;
	return twoSmallestElements;
}

int *FindSmallestAndSecondSmallest(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return NULL;
	}
	int twoSmallestElements[2];
	if(sizeOfArray == 1){
		twoSmallestElements[0] = userInput[0];
		twoSmallestElements[1] = INT_MIN;
		return twoSmallestElements;
	}
	int crawler = 0;
	twoSmallestElements[0] = INT_MIN;
	twoSmallestElements[1] = INT_MIN;
	for(crawler =0 ;crawler < sizeOfArray;crawler++){
		if(twoSmallestElements[0]> userInput[crawler]){
			twoSmallestElements[0] = userInput[crawler];
		}
	}

	for(crawler=0;crawler < sizeOfArray;crawler++){
		if(twoSmallestElements[1] > userInput[crawler] && userInput[crawler] != twoSmallestElements[0]){
			twoSmallestElements[1] = userInput[crawler];
		}
	}
	return twoSmallestElements;
}

#endif /* FINDSMALLESTANDSECONDSMALLEST_H_ */
