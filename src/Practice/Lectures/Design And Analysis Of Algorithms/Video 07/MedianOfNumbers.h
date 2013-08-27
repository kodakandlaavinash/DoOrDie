/*
 * MediaOfNumbers.h
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

#ifndef MEDIAOFNUMBERS_H_
#define MEDIAOFNUMBERS_H_

int MedianOfNumbersON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int middleIndex = (sizeOfArray)/2;
	int totalLess;
	int totalGreater;
	for(int outerCounter = 0;outerCounter < sizeOfArray;outerCounter++){
		totalLess = 0;
		totalGreater = 0;
		for(int innerCounter =0;innerCounter < sizeOfArray;innerCounter++){
			if(innerCounter  == outerCounter){
				continue;
			}
			if(userInput[outerCounter] > userInput[innerCounter]){
				totalLess++;
			}else{
				totalGreater++;
			}
		}
		if(totalLess == totalGreater){
			return userInput[outerCounter];
		}
	}
}

int MedianOfNumberONLOGN(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	sort(userInput,userInput+sizeOfArray);
	return userInput[sizeOfArray/2];
}

int MedianOfSmallGroup(vector<int> userInput){
	sort(userInput.begin(),userInput.end());
	return userInput[userInput.size()/2 - 1];
}

int MedianOfNumbersON(vector<int> userInput);

int FindApproximateMedianOfNumbers(vector<int> userInput){
	if(userInput.size() <= 5){
		return MedianOfSmallGroup(userInput);
	}
	vector<int> mediansOfSmallerGroup;
	vector<int> temp,tempSize;
	for(int counter = 0;counter < userInput.size();){
		temp.clear();
		tempSize = 5;
		while(counter < userInput.size()&&tempSize != 0){
			temp.push_back(userInput[counter]);
			counter++;
			tempSize--;
		}
		mediansOfSmallerGroup.push_back(MedianOfSmallGroup(temp));
	}
	return MedianOfNumbersON(mediansOfSmallerGroup,mediansOfSmallerGroup.size()/2);
}

int MedianOfNumbersON(vector<int> userInput,int rank){
	if(userInput.size() <= 5){
		return MedianOfSmallGroup(userInput);
	}
	int approximateMedian = FindApproximateMedianOfNumbers(userInput);
	int frontCounter = 0,backCounter = userInput.size(),tempForSwap,rankOfApproximateMedian;
	while(frontCounter < backCounter){
		while(userInput[frontCounter] >= approximateMedian){
			frontCounter++;
			if(userInput[frontCounter] == approximateMedian){
				rankOfApproximateMedian = frontCounter;
			}
		}
		while(userInput[backCounter] < approximateMedian && backCounter > frontCounter){
			backCounter--;
			if(userInput[backCounter] == approximateMedian){
				rankOfApproximateMedian = backCounter;
			}
		}
		if(frontCounter < backCounter){
			tempForSwap = userInput[frontCounter];
			userInput[frontCounter] = userInput[backCounter];
			userInput[backCounter] = tempForSwap;
		}
	}
	if(rankOfApproximateMedian == rank){
		return userInput[rankOfApproximateMedian];
	}
	vector<int> tempVector;
	if(rankOfApproximateMedian > rank){
		return MedianOfNumbersON(copy(userInput.begin(),userInput.begin() + rankOfApproximateMedian,tempVector.begin()),rank);
	}else{
		return MedianOfNumbersON(copy(userInput.begin()+rankOfApproximateMedian+1,userInput.end(),tempVector.begin()),rank-rankOfApproximateMedian);
	}
}
#endif /* MEDIAOFNUMBERS_H_ */
