/*
 * HCF.h
 *
 *  Created on: May 28, 2013
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

#ifndef HCF_H_
#define HCF_H_

int FindHCFOfTwoNumbers(int divisor,int dividend){
	int tempForSwap;
	if(dividend < divisor){
		tempForSwap = dividend;
		dividend = divisor;
		divisor = tempForSwap;
	}
	int remainder;
	while((remainder = dividend%divisor) != 0){
		dividend = divisor;
		divisor = remainder;
	}
	return divisor;
}

int FindHCFOfTwoNumbers(int divisor,int dividend){
	int remainder;
	if((remainder = dividend % divisor) == 0){
		return divisor;
	}
	return FindHCFOfTwoNumbers(remainder,divisor);
}

int FindHCFOfTwoNumbersOneStep(int divisor,int dividend){
	return dividend%divisor == 0? divisor:FindHCFOfTwoNumbersOneStep(dividend%divisor,divisor);
}

#endif /* HCF_H_ */
