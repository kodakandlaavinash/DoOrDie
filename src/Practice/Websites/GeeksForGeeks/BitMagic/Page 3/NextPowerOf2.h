/*
 * NextPowerOf2.h
 *
 *  Created on: Aug 23, 2013
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

#ifndef NEXTPOWEROF2_H_
#define NEXTPOWEROF2_H_

int NextPowerOf2ByFindingSetBitLog(int userInput){
	int setBitPosition = log(userInput);
	return pow(2,setBitPosition);
}

int NextPowerOf2ByFindingSetBitIterative(int userInput){
	int setBitPosition = INT_MIN;
	bitset<32> userInputInBinaryFormat(userInput);
	for(int counter = 0;counter < 32;counter++){
		if(userInputInBinaryFormat[counter]){
			if(setBitPosition < counter){
				setBitPosition = counter;
			}
		}
	}
	return pow(2,setBitPosition);
}

int NextPowerOf2ByFindingSetBit(int userInput){
	if(userInput && !(userInput&(userInput-1))){
		return userInput;
	}
	int counter = 0;
	while(userInput){
		userInput /= 2;
		counter++;
	}
	return 1 << counter;
}

int NextPowerOf2ByShiftingOne(int userInput){
	if(userInput && !(userInput&(userInput-1))){
		return userInput;
	}
	unsigned int nextPower = 1;
	while(nextPower < userInput){
		nextPower  = nextPower << 1;
	}
	return nextPower;
}

int NextPowerOf2MITMethod(int userInput){
	if(userInput&&!(userInput & (userInput-1))){
		return userInput;
	}
	userInput = userInput - 1;
	userInput = userInput | userInput >> 1;
	userInput = userInput | userInput >> 2;
	userInput = userInput | userInput >> 4;
	userInput = userInput | userInput >> 8;
	userInput = userInput | userInput >> 16;
	return userInput+1;
}


#endif /* NEXTPOWEROF2_H_ */
