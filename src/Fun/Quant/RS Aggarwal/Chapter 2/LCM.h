/*
 * LCM.h
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

#ifndef LCM_H_
#define LCM_H_

int FindLCMOfTwoNumbers(int firstNumber,int secondNumber){
	return (firstNumber*secondNumber)/FindHCFOfTwoNumbers(firstNumber,secondNumber);
}

int FindLCMOfNNumbers(vector<int> userInput){
	int lcmOfNumber = FindLCMOfTwoNumbers(userInput[0],userInput[1]);
	for(int counter = 2;counter < userInput.size();counter++){
		lcmOfNumber = FindLCMOfTwoNumbers(lcmOfNumber,userInput[counter]);
	}
	return lcmOfNumber;
}

int FindLCMOfTwoNumbersUsingFactorization(int firstNumber,int secondNumber){

}

int FindLCMOfTwoNumberUsingTraditionalMethod(int firstNumber,int secondNumber){

}

int FindLCMOfTwoNumbersUsingTraditionalMethodSlowMethod(int firstNumber,int secondNumber){
	do{

	}while(1);
}

#endif /* LCM_H_ */
