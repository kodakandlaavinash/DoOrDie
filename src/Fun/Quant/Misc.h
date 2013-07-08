/*
 * Misc.h
 *
 *  Created on: May 30, 2013
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

#ifndef MISC_H_
#define MISC_H_

unsigned int FindPOWOfNumberRecursive(int base,int power){
	if(power == 0){
		return 1;
	}
	if(power == 1){
		return base;
	}
	return base * FindPOWOfNumber(base,power-1);
}

unsigned int FindPOWOfNumberIterative(int base,int power){
	unsigned int powOfNumber = 1;
	for(int counter =0;counter < power;counter){
		powOfNumber *= base;
	}
	return powOfNumber;
}

unsigned int FindPOWOfNumberInSingleLine(int base,int power){
	return power == 0?1:(power == 1)?base:base*FindPOWOfNumberInSingleLine(base,power-1);
}

void PrintMultiplicationTableOfNumber(unsigned int userInput,int upto){
	for(int crawler = 1;crawler <= upto;crawler++){
		printf("%d * %d = %d\n",userInput,crawler,userInput*crawler);
	}
}

bool CheckIfNumberIsPerfectSquareOrNot(int number){
	double squareRootOfNumber = sqrt(number);
	int integerPart = squareRootOfNumber;
	if(squareRootOfNumber - integerPart > 0){
		return false;
	}
	return true;
}

int FindNumberOfDecimalDigits(decimal userInput){
	decimal fractionPart = userInput - (int)userInput;
	int counter = 0;
	for(;10*fraction > 0;counter++,fraction = fractionPart*10 - (int)(fractionPart*10));
	return counter;
}

int FindNumberOfDigitsInNumbers(int number){
	int countNumberOfDigits;
	while(number){
		countNumberOfDigits+=1;
		number /= 10;
	}
	return countNumberOfDigits;
}

int FindNumberOfDigitsInNumberRecursion(int number){
	if(number == 0){
		return 0;
	}
	return 1+FindNumberOfDigitsInNumberRecursion(number/10);
}

bool CheckWhetherTwoNumbersAreCoPrimesOrNot(){
	//hash_map<int,int>
}

#endif /* MISC_H_ */
