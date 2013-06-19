/*
 * FactorsAndMultiples.h
 *
 *  Created on: Jun 19, 2013
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
#ifndef FACTORSANDMULTIPLES_H_
#define FACTORSANDMULTIPLES_H_

bool isMultipleOfLater(int firstNumber,int secondNumber){
	return firstNumber % secondNumber == 0?true:false;
}

bool isDivisorOfLater(int firstNumber,int secondNumber){
	return secondNumber %firstNumber == 0?true:false;
}

int MultiplicationOfTwoNumbers(int multiplicand,int multiplier){
	int sum = 0;
	for(int counter = 1;counter < multiplier;counter++){
		sum += multiplicand;
	}
	return sum;
}

int MultiplicationOfTwoNumbersRecursion(int multiplicand,int multiplier){
	if(multiplier == 0){
		return 0;
	}
	return multiplicand + MultiplicationOfTwoNumbersRecursion(multiplicand,multiplier-1);
}

/**
 * Gives only quotient
 */
int DivisionOfTwoNumbersRecursion(int dividend,int divisor){
	if(dividend == 0){
		return 0;
	}
	return 1+DivisionOfTwoNumbers(dividend-divisor,divisor);
}

int DivisionOfTwoNumbers(int dividend,int divisor){
	int quotient = 0;
	while(dividend){
		quotient += 1;
		dividend -= divisor;
	}

	return quotient;
}

int NumberOfFactorsOfGivenNumber(int number){
	hash_map<int,int> factorsOfGivenNumber;
	int numberOfFactors = 0;
	hash_map<int,int>::iterator *itToFactorsOfGivenNumber;
	for(itToFactorsOfGivenNumber = factorsOfGivenNumber.begin();itToFactorsOfGivenNumber != factorsOfGivenNumber.end();itToFactorsOfGivenNumber++){
		numberOfFactors += ((*itToFactorsOfGivenNumber)->second + 1);
	}
	return numberOfFactors;
 }

int SumOfFactorsOfGivenNumber(int number){
	hash_map<int,int> factorsOfGivenNumber;
	int sumOfFactorsOfGivenNumber;
	hash_map<int,int>::iterator *itToFactorsOfGivenNumber;
	for(itToFactorsOfGivenNumber = factorsOfGivenNumber.begin();itToFactorsOfGivenNumber != factorsOfGivenNumber.end();itToFactorsOfGivenNumber++){
		sumOfFactorsOfGivenNumber += ((pow((*itToFactorsOfGivenNumber)->first,(*itToFactorsOfGivenNumber)->second + 1) - 1)/((*itToFactorsOfGivenNumber)->first)-1);
	}
	return sumOfFactorsOfGivenNumber;
}

bool FindWhetherANumberIsPerfectSquareOrNot(int number){
	hash_map<int,int> factorsOfGivenNumbers;
	hash_map<int,int>::iterator *itToFactorsOfGivenNumber;
	bool isPerfectSquare = true;
	for(itToFactorsOfGivenNumber = factorsOfGivenNumbers.begin();itToFactorsOfGivenNumber != factorsOfGivenNumbers.end();itToFactorsOfGivenNumber++){
		if((*itToFactorsOfGivenNumber)->second %2 == 0){
			isPerfectSquare = false;
			break;
		}
	}
	return isPerfectSquare;
}

int NumberOfWaysANumberCanBeWritternAsProductOfFactors(int number,int includePerfectSquare){
	bool isPerfectSquare = FindWhetherANumberIsPerfectSquareOrNot(number);
	if(isPerfectSquare){
		if(includePerfectSquare){
			return (SumOfFactorsOfGivenNumber(number)+1)/2;
		}else{
			return (SumOfFactorsOfGivenNumber(number)-1)/2;
		}
	}else{
		return SumOfFactorsOfGivenNumber(number)/2;
	}
}

bool isNumberAPerfectNumberOrNot(int number){
	return SumOfFactorsOfGivenNumber(number) == number?true:false;
}



#endif
