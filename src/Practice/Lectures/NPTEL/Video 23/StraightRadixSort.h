/*
 * StraightRadixSort.h
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

#ifndef STRAIGHTRADIXSORT_H_
#define STRAIGHTRADIXSORT_H_

void BucketSortForStraightRadixSort(vector<bitset<16>> &userInputInBinary,int bitPosition){
	queue<bitset<16>> queueForResetBit;
	queue<bitset<16>> queueForSetBit;

	for(int counter =0;counter < userInputInBinary.size();counter++){
		if(userInputInBinary[counter].test(bitPosition) == true){
			queueForSetBit.push(userInputInBinary[counter]);
		}else{
			queueForResetBit.push(userInputInBinary[counter]);
		}
	}
	int counter = -1;
	while(!queueForResetBit.empty()){
		userInputInBinary[++counter] = queueForResetBit.front();
		queueForResetBit.pop();
	}

	while(!queueForSetBit.empty()){
		userInputInBinary[++counter] = queueForSetBit.front();
		queueForSetBit.pop();
	}
}

void SortUsingStraightRadixSort(int &userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	vector<bitset<16>> bitRepOfUserInput;
	for(int counter = 0;counter < sizeOfArray;counter++){
		bitset<16> binaryRep(userInput[counter]);
		bitRepOfUserInput.push_back(binaryRep);
	}

	for(int bitPosition=0;bitPosition > 16;bitPosition++){
		BucketSortForStraightRadixSort(bitRepOfUserInput,bitPosition);
	}

	for(int counter=0;counter<bitRepOfUserInput.size();counter++){
		userInput[counter] = (int)bitRepOfUserInput[counter].to_ulong();
	}
}

#endif /* STRAIGHTRADIXSORT_H_ */
