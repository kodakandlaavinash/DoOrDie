/*
 * GeneratePrimeNumbers.h
 *
 *  Created on: Jun 4, 2013
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

#ifndef GENERATEPRIMENUMBERS_H_
#define GENERATEPRIMENUMBERS_H_

vector<int> primeNumbers;

/**
 * Tested
 */
vector<int> generatePrimeNumbersSieve(int userInput){
	vector<bool> truthValue(userInput);
	for(int counter = 0;counter < userInput;counter++){
		truthValue[counter] = true;
	}
	for(int counter = 2;counter <= userInput;counter++){
		if(truthValue[counter]){
			int multiplicationCounter = 2;
			for(int value = counter*multiplicationCounter;value <= userInput;value =counter*multiplicationCounter){
				truthValue[value] = false;
				multiplicationCounter++;
			}
		}
	}
	for(int counter = 2;counter <= userInput;counter++){
		if(truthValue[counter]){
			primeNumbers.push_back(counter);
		}
	}
	return primeNumbers;
}

#endif /* GENERATEPRIMENUMBERS_H_ */
