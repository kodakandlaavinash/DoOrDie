/*
 * FindJMinusISuchThahArrayJGrArrayI.h
 *
 *  Created on: Aug 2, 2013
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

#ifndef FINDJMINUSISUCHTHAHARRAYJGRARRAYI_H_
#define FINDJMINUSISUCHTHAHARRAYJGRARRAYI_H_

int maxIndexDifferenceON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int innerCounter =0;
	int maxDifference = INT_MIN,difference;

	for(int outerCounter =0;outerCounter < sizeOfArray;outerCounter++){
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(userInput[outerCounter] < userInput[innerCounter]){
				difference = userInput[innerCounter] - userInput[outerCounter];
				if(difference > maxDifference){
					maxDifference = difference;
				}
			}
		}
	}
	return maxDifference;
}

int maxIndexDifferenceON(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}

	int minArray[sizeOfArray];
	minArray[0] = userInput[0];
	for(int counter =1;counter < sizeOfArray;counter++){
		if(minArray[counter-1] > userInput[counter]){
			minArray[counter] = userInput[counter];
		}else{
			minArray[counter] = minArray[counter-1];
		}
	}

	int maxArray[sizeOfArray];
	maxArray[sizeOfArray-1] = userInput[sizeOfArray-1];
	for(int counter = sizeOfArray-2;counter >= 0;counter--){
		if(userInput[counter] > maxArray[counter+1]){
			maxArray[counter] = userInput[counter];
		}else{
			maxArray[counter] =  maxArray[counter+1];
		}
	}
	int maxDifference = INT_MIN;
	int maxArrayCrawler = 0,minArrayCrawler = 0;
	while(maxArrayCrawler < sizeOfArray && minArrayCrawler < sizeOfArray){
		if(maxArrayCrawler < sizeOfArray && maxArray[maxArrayCrawler] > minArray[minArrayCrawler]){
			maxDifference = max(maxDifference,abs(minArrayCrawler - maxArrayCrawler));
			maxArrayCrawler++;
		}else{
			minArrayCrawler++;
		}
	}
	return maxDifference;
}

#endif /* FINDJMINUSISUCHTHAHARRAYJGRARRAYI_H_ */
