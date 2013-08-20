/*
 * ConvertBase2NumberToBase4.h
 *
 *  Created on: Aug 20, 2013
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

#ifndef CONVERTBASE2NUMBERTOBASE4_H_
#define CONVERTBASE2NUMBERTOBASE4_H_

int ConvertBase2NumberToBase4(long userInput){
	int decimalNumber,numberInBase4;
	int lastDigit;
	int multiply = 1;
	while(userInput){
		lastDigit = userInput % 10;
		userInput /= 10;
		decimalNumber += (lastDigit * multiply);
		multiply *= 2;
	}
	while(decimalNumber < 4){
		lastDigit = userInput %4;
		userInput /= 4;
		numberInBase4 = (numberInBase4 *10) + lastDigit;
	}
	return numberInBase4;
}

int ConvertBase2NumberToBase4Merging2Digits(long userInput){
	int lastTwoDigits,cummulativeSum,numberInBase4 = 0;
	while(userInput){
		lastTwoDigits = userInput % 100;
		cummulativeSum = lastTwoDigits%10;
		lastTwoDigits /= 10;
		cummulativeSum = 2 * (lastTwoDigits %10);
		numberInBase4 = numberInBase4 << 3 + numberInBase4 << 1 + cummulativeSum;
		userInput /= 100;
	}
	return numberInBase4;
}

#endif /* CONVERTBASE2NUMBERTOBASE4_H_ */
