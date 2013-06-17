/*
 * RadixSort.h
 *
 *  Created on: Jun 17, 2013
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

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

void SortRadixSortUsingRecursion(vector<bitset<16>> &userInput,int startArray,int endArray,int bitPosition);
void SortNumbersUsingRadixSortDriver(int &userInput[],int sizeOfUserInput){
	if(userInput == NULL){
		return;
	}
	vector<bitset<16>> numbersInBits;
	bitset<16> tempForSwap;
	for(int counter = 0;counter < sizeOfUserInput;counter++){
		bitset<16> userInputInBinary(userInput[counter]);
		numbersInBits.push_back(userInputInBinary);
	}

	SortRadixSortUsingRecursion(numbersInBits,0,numbersInBits.size()-1,15);
	for(int counter = 0;counter < numbersInBits.size();counter++){
		userInput[counter] = (int)numbersInBits[counter].to_ulong();
	}

}


void SortRadixSortUsingRecursion(vector<bitset<16>> &userInput,int startArray,int endArray,int bitPosition){
	if(bitPosition < 0){
		return;
	}
	int startCounter = 0;
	int endCounter = numbersInBits.size();
	while(startCounter < endCounter){
		while(numbersInBits[startCounter].test(bitsCounter) != 1){
			startCounter++;
		}
		while(numbersInBits[endCounter].test(bitsCounter) != 0){
			endCounter++;
		}
		if(startCounter < endCounter){
			tempForSwap = numbersInBits[startCounter];
			numbersInBits[startCounter] = numbersInBits[endCounter];
			numbersInBits[endCounter] = tempForSwap;
		}
	}

	SortRadixSortUsingRecursion(userInput,startArray,endCounter,bitPosition-1);
	SortRadixSortUsingRecursion(userInput,endCounter+1,endArray,bitPosition-1);
}
#endif /* RADIXSORT_H_ */
