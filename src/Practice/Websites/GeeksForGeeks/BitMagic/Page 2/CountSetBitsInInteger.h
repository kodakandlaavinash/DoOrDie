/*
 * CountSetBitsInInteger.h
 *
 *  Created on: Aug 28, 2013
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

#ifndef COUNTSETBITSININTEGER_H_
#define COUNTSETBITSININTEGER_H_

int CountSetBitsInNumber(int userInput){
	int setBitCounter = 0;
	while(userInput){
		if(userInput%2){
			setBitCounter++;
		}
		userInput /= 2;
	}
	return setBitCounter;
}

int CountSetBitsAlgo(int userInput){
	int setBitCounter = 0;
	while(userInput){
		userInput = userInput & (userInput-1);
		setBitCounter++;
	}
	return setBitCounter;
}

#endif /* COUNTSETBITSININTEGER_H_ */
