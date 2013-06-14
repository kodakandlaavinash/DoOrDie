/*
 * PrimeNumberOrComposite.h
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

#ifndef PRIMENUMBERORCOMPOSITE_H_
#define PRIMENUMBERORCOMPOSITE_H_

int primeNumbersLessThan100[] = {2,3,5,7,11,13,17,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool isAPrimeNumber(int userInput){
	if(userInput == 0){
		return false;
	}
	if(userInput == 1){
		return true;
	}

	int squareRootOfNumber = sqrt(userInput);
	int sizeOfArray = sizeof(primeNumbersLessThan100)/sizeof(primeNumbersLessThan100[0]);
	int counter = 0;
	if(userInput <= 100){
		for(counter = 0;counter < sizeOfArray;counter++){
			if(userInput == primeNumbersLessThan100[counter]){
				return true;
			}
		}
		return false;
	}
	if(userInput > 100 && userInput < 10000){
		while(primeNumbersLessThan100[counter] < squareRootOfNumber){
			if(userInput % primeNumbersLessThan100[counter] == 0){
				return false;
			}
		}
		return true;
	}
}

bool isAPrimeNumber(int userInput){
	if(userInput == 0 || userInput == 1){
		return false;
	}
	if(userInput%2 == 0){
		return false;
	}
	int squareRootOfNumber = sqrt(userInput);
	for(int counter = 3;counter <= squareRootOfNumber;counter+=2){
		if(userInput%counter == 0){
			return false;
		}
	}
	return true;
}


#endif /* PRIMENUMBERORCOMPOSITE_H_ */
