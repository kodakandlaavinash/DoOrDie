/*
 * MinimumDistanceBetweenNumbers.h
 *
 *  Created on: Aug 5, 2013
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

#ifndef MINIMUMDISTANCEBETWEENNUMBERS_H_
#define MINIMUMDISTANCEBETWEENNUMBERS_H_

int MinimumDistanceBetweenNumbers(int userInput[],int sizeOfArray,int firstNumber,int secondNumber){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MAX;
	}
	int minDistance = INT_MAX;
	int prevNumber,prevNumberIndex;
	int difference;
	for(int counter =0;counter < sizeOfArray;counter++){
		if(userInput[counter] == firstNumber || userInput[counter] == secondNumber){
			if(userInput[counter] == prevNumber){
				difference = counter - prevNumberIndex + 1;
				if(minDistance > difference){
					difference = minDistance;
				}
				prevNumber = userInput[counter];
				prevNumberIndex = counter;
			}else{
				prevNumber = userInput[counter];
				prevNumberIndex = counter;
			}
		}
	}
	return minDistance;
}

int MinimumDistanceBetweenTwoNumbers(int userInput[],int sizeOfArray,int firstNumber,int secondNumber){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MAX;
	}

	int outerCounter,innerCounter;
	bool isFirstNumber;
	int minDistance = INT_MAX;
	int distance;
	for(outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		if(userInput[outerCounter] != firstNumber || userInput[outerCounter] != secondNumber){
			continue;
		}
		if(userInput[outerCounter] == firstNumber){
			isFirstNumber = true;
		}else{
			isFirstNumber = false;
		}
		for(innerCounter = outerCounter+1;innerCounter < sizeOfArray;innerCounter++){
			if(isFirstNumber){
				if(userInput[innerCounter] == firstNumber){
					continue;
				}
				distance = innerCounter - outerCounter + 1;
				if(minDistance > distance){
					minDistance = distance;
				}
			}else{
				if(userInput[innerCounter] == secondNumber){
					continue;
				}
				distance =  innerCounter - outerCounter +1;
				if(minDistance > distance){
					minDistance = distance;
				}
			}
		}
	}
	return minDistance;
}

#endif /* MINIMUMDISTANCEBETWEENNUMBERS_H_ */
