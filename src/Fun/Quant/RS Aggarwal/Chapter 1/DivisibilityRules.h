/*
 * DivisibilityRules.h
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

#ifndef DIVISIBILITYRULES_H_
#define DIVISIBILITYRULES_H_

bool CheckWhetherANumberIsDivisibleBy2OrNot(int userInput){
	int lastDigit = userInput%10;
	return lastDigit%2 == 0?true:false;
}

bool CheckWhetherANumberIsDivisibleBy3OrNot(int userInput){
	int sumOfDigits = 0;
	while(userInput){
		sumOfDigits += userInput%10;
		userInput /= 10;
	}
	return sumOfDigits%3 == 0?true:false;
}

bool CheckWhetherANumberIsDivisibleBy4OrNot(int userInput){
	int lastTwoDigits = userInput % 100;
	return lastTwoDigits%4 == 0?true:false;
}

bool CheckWhetherANumberIsDivisbleBy5OrNot(int userInput){
	int lastDigit = userInput % 10;
	return lastDigit == 5?true:(lastDigit == 0?true:false);
}

bool CheckWhetherANumberIsDivisibleBy6OrNot(int userInput){
	return CheckWhetherANumberIsDivisibleBy2OrNot(userInput) && CheckWhetherANumberIsDivisibleBy3OrNot(userInput);
}

bool CheckWhetherANumberIsDivisibleBy8OrNot(int userInput){
	int lastThreeDigit = userInput % 1000;
	return userInput%8 == 0?true:false;
}

bool CheckWhetherANumberIsDivisibleBy9OrNot(int userInput){
	int sumOfDigits = 0;
	while(userInput){
		sumOfDigits += userInput%10;
		userInput /= 10;
	}
	return sumOfDigits%9 == 0?true:false;
}

bool CheckWhetherANumberIsDivisibleBy10OrNot(int userInput){
	int lastDigit = userInput % 10;
	return lastDigit ==0?true:false;
}

bool CheckWhetherANumberIsDivisibleBy11OrNot(int userInput){
	int sumOfOddDigits = 0;
	int sumOfEvenDigits = 0;
	bool flag = true;
	while(userInput){
		if(flag){
			sumOfOddDigits += userInput %10;
		}else{
			sumOfEvenDigits += userInput %10;
		}
		userInput /= 10;
		flag = !flag;
	}

	return abs(sumOfEvenDigits - sumOfOddDigits) == 0?true:(abs(sumOfEvenDigits - sumOfOddDigits)%11 == 0?true:false);
}


#endif /* DIVISIBILITYRULES_H_ */
