/*
 * LCMAndHCFApplications.h
 *
 *  Created on: Jun 30, 2013
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

#ifndef LCMANDHCFAPPLICATIONS_H_
#define LCMANDHCFAPPLICATIONS_H_

int FindLargestNDigitNumberDivisible(int n,int divisor){
	int nLargestNumber = pow(10,n+1) - 1;
	int remainder = nLargestNumber %divisor;
	return nLargestNumber - remainder;
}

int FindSmallestNDigitNumberDivisible(int n,int divisor){
	int nSmallestNumber = pow(10,n);
	int remainder = nSmallestNumber % divisor;
	return nSmallestNumber + remainder;
}

int FindNumberWhichDividedSameRemainder(vector<int> divisor,int remainder){
	int lcmOfNumber = FindLCMOfNNumbers(divisor);
	return lcmOfNumber + remainder;
}

int FindNumberWhichDivisibleDifferentRemainder(vector<int> divisor,vector<int> remainder){

}

#endif /* LCMANDHCFAPPLICATIONS_H_ */
