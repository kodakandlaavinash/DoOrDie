/*
 * HCF.h
 *
 *  Created on: Jul 12, 2013
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

vector<int> primeNumber= {};

hash_map<int,int> FactoriseANumber(int number){
	hash_map<int,int> factorsOfNumbers;
	hash_map<int,int>::iterator itToFactorsOfNumbers;
	if(number == 0){
		factorsOfNumbers.insert(pair<int,int>(0,1));
		return factorsOfNumbers;
	}

	for(int counter=0;counter < primeNumber.size() && number != 1;counter++){
		if(number%primeNumber[counter] == 0){
			if((itToFactorsOfNumbers = factorsOfNumbers.find(primeNumber[counter])) != factorsOfNumbers.end()){
				factorsOfNumbers[itToFactorsOfNumbers->first] = itToFactorsOfNumbers->second+1;
			}else{
				factorsOfNumbers.insert(pair<int,int>(primeNumber[counter],1));
			}
			number /= primeNumber[counter];
		}
	}

	if(factorsOfNumbers.size() == 0){
		factorsOfNumbers.insert(pair<int,int>(number,1));
	}
}

int HCFOfTwoNumbers(int number1,int number2){
	if(number1 == 0 || number2 == 0){
		return INT_MIN;
	}
	if(number1 == 1 || number2 == 1){
		return 1;
	}
	hash_map<int,int> factorsOfNumber1 = FactoriseANumber(number1);
	hash_map<int,int> factorsOfNumber2 = FactoriseANumber(number2);
	hash_map<int,int> commonFactors;
	hash_map<int,int>::iterator *itToFactors1;
	hash_map<int,int>::iterator *itToFactors2;
	int minPower;
	for(itToFactors1 = factorsOfNumber1.begin();itToFactors2 != factorsOfNumber2.end();itToFactors1++){
		if((itToFactors2 = factorsOfNumber2.find((*itToFactors1)->first)) != factorsOfNumber2.end()){
			minPower = min((*itToFactors1)->second,(*itToFactors2)->second);
			commonFactors.insert(pair<int,int>((*itToFactors1)->first),minPower);
		}
	}
	if(commonFactors.size() == 0){
		return 1;
	}
	hash_map<int,int>::iterator *itToCommonFactors;
	int HCFOfNumbers = 1;
	for(itToCommonFactors = commonFactors.begin();itToCommonFactors != commonFactors.end();itToCommonFactors++){
		HCFOfNumbers *= pow((*itToCommonFactors)->first,(*itToCommonFactors)->second);
	}
	return HCFOfNumbers;
}

int HCFOfNumbers(int userInput1,int userInput2){
	if(userInput1 ==0 || userInput2 == 0){
		return INT_MIN;
	}
	if(userInput1 == 1|| userInput2 == 1){
		return 1;
	}
	int dividend,divisor,remainder;
	divisor = min(userInput1,userInput2);
	remainder = divisor;
	dividend = divisor == userInput1?userInput2:userInput1;

	while(remainder > 0){
		remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}

	return dividend;
}

#endif /* HCF_H_ */
