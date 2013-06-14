/*
 * PlaceFaceValueOfDigitInNumber.h
 *
 *  Created on: May 14, 2013
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

#ifndef PLACEFACEVALUEOFDIGITINNUMBER_H_
#define PLACEFACEVALUEOFDIGITINNUMBER_H_

vector<int> PlaceValueOfDigit(int userInputNumber,int userInputDigit){
	vector<int> placeValueOfDigits;
	int lastDigit;
	int placeValue = 1;
	while(userInputNumber){
		lastDigit = userInputNumber % 10;
		if(lastDigit == userInputDigit){
			placeValueOfDigits.push_back(lastDigit * placeValue);
		}
		userInputNumber /= 10;
		placeValue *= 10;
	}
	return placeValueOfDigits;
}

#endif /* PLACEFACEVALUEOFDIGITINNUMBER_H_ */
