/*
 * SquareRootOfNumber.h
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

#ifndef SQUAREROOTOFNUMBER_H_
#define SQUAREROOTOFNUMBER_H_



int FindSquareRootOfNumberDivisonMethod(int userInput,int precision){
	stack<int> orderForSquareRootOperation;
	int remainder;
	while(orderForSquareRootOperation){
		remainder = userInput % 100;
		userInput /= 100;
	}

	bool flagForCompletionOfRealPart = false;
	int divisor;
	int squareRootNumber = 0;

	int squareOfNumbers[] ={1,4,9,16,25,36,49,64,81};
	int arrayLength = squareOfNumbers/(sizeof(squareOfNumber[0]));
	int currentDividend;
	int previousRemainder = 0;
	bool firstTime = true;
	int divisor,divisorCounter = 9;
	int precisionCounter=0;
	do{
		/**
		 * -1 is the delimiter for the determining the decimal part of
		 * the square root
		 */
		if(orderForSquareRootOperation.top() == -1){
			flagForCompletionOfRealPart = true;
		}
		if(flagForCompletionOfRealPart){
			currentDividend = previousRemainder * 100;
			orderForSquareRootOperation.pop();
			divisor = 2 * squareOfNumbers * pow(10,precisionCounter);
			while(divisor * 10 + divisorCounter < currentDividend){
				divisorCounter--;
			}
			squareOfNumbers = squareOfNumbers + divisorCounter/pow(10,++precisionCounter);
			previousRemainder = currentDividend - (divisor*10 + divisorCounter);
		} else{
			currentDividend = previousRemainder *100 + orderForSquareRootOperation.top();
			orderForSquareRootOperation.pop();
			if(firstNumber){
				int arrayCrawler;
				for(arrayCrawler = arrayLength-1;arrayCrawler >= 0;arrayCrawler--){
					if(squareOfNumbers[arrayCrawler] < currentDividend){
						break;
					}
				}
				previousRemainder = currentDividend - squareOfNumbers[arrayCrawler];
				squareOfNumbers = (squareOfNumbers << 3)+(squareOfNumbers << 1)+previousRemainder;
			}else{
				divisor = 2 * squareOfNumbers;
				while(divisor * 10 + divisorCounter < currentDividend){
					divisorCounter--;
				}
				squareOfNumbers = (squareOfNumbers << 3) + (squareOfNumbers << 1)+divisorCounter;
				previousRemainder = currentDividend - (divisor*10 + divisorCounter);
			}
		}
	}while(!orderForSquareRootOperation.empty());
}

hash_map<int,int> GetSquareRootsForCommonPrimeNumbers(){

}

double FindSquareRootOfNumberUsingFactorizationMethod(int userInput){
	if(userInput < 0){
		return INT_MIN;
	}
	if(userInput == 0){
		return 0;
	}
	if(userInput == 1){
		return 1;
	}
	hash_map<int,int> squareRootsOfCommonPrimeNumbers=GetSquareRootsForCommonPrimeNumbers();
	hash_map<int,int> factorsOfNumbers = FactoriseANumber(userInput);

	hash_map<int,int>::iterator itToFactorsOfNumbers;
	int squareRootOfNumber = 1;
	for(itToFactorsOfNumbers = factorsOfNumbers.begin();itToFactorsOfNumbers != factorsOfNumbers.end();itToFactorsOfNumbers++){
		squareRootOfNumber = pow(itToFactorsOfNumbers->first,(itToFactorsOfNumbers->second/2));
		if(itToFactorsOfNumbers->second % 2 == 1){
			squareRootOfNumber = squareRootsOfCommonPrimeNumbers[itToFactorsOfNumbers->first];
		}
	}
}


double FindSquareRootOfNumberUsingFactorizationMethodForDecimal(decimal userInput){


}

#endif /* SQUAREROOTOFNUMBER_H_ */
