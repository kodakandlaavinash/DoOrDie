/*
 * MaximumLenghtBitonicSequence.h
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

#ifndef MAXIMUMLENGHTBITONICSEQUENCE_H_
#define MAXIMUMLENGHTBITONICSEQUENCE_H_

int MaximumLengthOfBitonicSequence(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray){
		return 0;
	}
	int increasingSeqLengthFrontBack[sizeOfArray],increasingSeqLengthBackFront[sizeOfArray];
	increasingSeqLengthFrontBack[0] = 1;
	for(int counter = 1;counter < sizeOfArray;counter++){
		if(userInput[counter] > userInput[counter-1]){
			increasingSeqLengthFrontBack[counter] = increasingSeqLengthFrontBack[counter-1]+1;
		}else{
			increasingSeqLengthFrontBack[counter] = 1;
		}
	}

	increasingSeqLengthBackFront[sizeOfArray-1] = 1;
	for(int counter = sizeOfArray-2;counter >= 0;counter--){
		if(userInput[counter] > userInput[counter+1]){
			increasingSeqLengthBackFront[counter] = increasingSeqLengthBackFront[counter+1] + 1;
		}else{
			increasingSeqLengthBackFront[counter] =  1;
		}
	}

	int maxLengthBitonicSequence = INT_MIN;
	int lengthOfBitonicSequence;
	for(int counter = 0;counter < sizeOfArray;counter++){
		lengthOfBitonicSequence = increasingSeqLengthBackFront[counter] +  increasingSeqLengthFrontBack[counter] + 1;
		if(maxLengthBitonicSequence <lengthOfBitonicSequence){
			maxLengthBitonicSequence = lengthOfBitonicSequence;
		}
	}

	return maxLengthBitonicSequence;
}




#endif /* MAXIMUMLENGHTBITONICSEQUENCE_H_ */
