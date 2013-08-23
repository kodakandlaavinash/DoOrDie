/*
 * FindIncreasingSubSequenceOfLength3MaxProduct.h
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

#ifndef FINDINCREASINGSUBSEQUENCEOFLENGTH3MAXPRODUCT_H_
#define FINDINCREASINGSUBSEQUENCEOFLENGTH3MAXPRODUCT_H_

int FindIncreasingSubSequenceOfLength3MaxProductON2(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return INT_MIN;
	}
	int outerCounter,innerCounter;
	int LSL,LSR,keyElement;
	for(outerCounter = 1;outerCounter < sizeOfArray;outerCounter++){
		keyElement = userInput[outerCounter];
		for(innerCounter =0;innerCounter < outerCounter;innerCounter++){

		}
	}
}

#endif /* FINDINCREASINGSUBSEQUENCEOFLENGTH3MAXPRODUCT_H_ */
