/*
 * MaximumSubSequenceSum.h
 *
 *  Created on: Aug 1, 2013
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

#ifndef MAXIMUMSUBSEQUENCESUM_H_
#define MAXIMUMSUBSEQUENCESUM_H_

int MaximumSubSequenceSum(int userInput[],int i){
	/*if(i<0){
		return 0;
	}
	if(i == 0){
		return userInput[0];
	}
	int maxSum = INT_MIN;
	int subsequenceSum = 0;
	for(int counter =i-1;counter >= 0;counter--){
		subsequenceSum = max(userInput[counter] + MaximumSubSequenceSum(userInput,counter-1),userInput[counter]);
		if(maxSum < subsequenceSum){
			maxSum = subsequenceSum;
		}
	}
	return maxSum;*/
}

int MaximumSubSequenceSumMemoziation(int userInput[],int sizeOfArray,int crawler){

}
#endif /* MAXIMUMSUBSEQUENCESUM_H_ */
