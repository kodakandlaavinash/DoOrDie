/*
 * MinimumOfNumbers.h
 *
 *  Created on: Jul 12, 2013
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

#ifndef MINIMUMOFNUMBERS_H_
#define MINIMUMOFNUMBERS_H_

int MinimumOfNumber(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int minOfNumber = INT_MAX;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(minOfNumber > userInput[counter]){
			minOfNumber = userInput[counter];
		}
	}
	return minOfNumber;
}

int MinimumOfNumberComparisonInPairsDivideAndConquer(int userInput[],int startIndex,int endIndex){
	if(startIndex > endIndex){
		return INT_MAX;
	}
	if(endIndex - startIndex == 0){
		return userInput[startIndex];
	}
	if(endIndex - startIndex == 1){
		return min(userInput[startIndex],userInput[endIndex]);
	}
	int middleIndex = (startIndex+endIndex)/2;
	return min(MinimumOfNumber(userInput,startIndex,middleIndex),MinimumOfNumber(userInput,middleIndex+1,endIndex));
}


int MinimumOfNumberComparisonOfPairsIterative(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0 || userInput == null){
		return INT_MIN;
	}
	queue<int> auxSpace;
	queue<int> auxSpace2;
	for(int counter =0;counter < sizeOfArray;counter+=2){
		if(counter+1 >= sizeOfArray){
			auxSpace.push(userInput[counter]);
			break;
		}
		auxSpace.push(min(userInput[counter],userInput[counter+1]));
	}
	int temp;
	while(auxSpace.size() > 1){
		while(!auxSpace.empty()){
			if(auxSpace.size() == 1){
				auxSpace2.push(auxSpace.front());
				auxSpace.pop();
				break;
			}
			temp = auxSpace.front();
			auxSpace.pop();
			auxSpace2.push(min(temp,auxSpace.front()));
			auxSpace.pop();
		}

		while(!auxSpace2.empty()){
			auxSpace.push(auxSpace2.front());
			auxSpace2.pop();
		}
	}
	return auxSpace.front();
}

int MinimumOfNumber(int userInput[],int sizeOfArray){
	if(sizeOfArray == 0 || userInput == NULL){
		return INT_MAX;
	}
	if(sizeOfArray == 1){
		return userInput[0];
	}
	int minimumRunning = min(userInput[0],userInput[1]);
	for(int counter = 2;counter < sizeOfArray;counter++){
		minimumRunning = min(minimumRunning,userInput[counter]);
	}
	return minimumRunning;
}

#endif /* MINIMUMOFNUMBERS_H_ */
