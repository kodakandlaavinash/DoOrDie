/*
 * DivisionOfPolynomialEquation.h
 *
 *  Created on: Jun 12, 2013
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

struct polynomialEquation{
	hash_map<int,int> powerCoefficientMap;
	int highestPower;
};

#ifndef DIVISIONOFPOLYNOMIALEQUATION_H_
#define DIVISIONOFPOLYNOMIALEQUATION_H_

hash_map<int,int>::iterator GetTheHighestPowerFromEquation(hash_map<int,int> powerCoefficientMap){
	if(powerCoefficientMap == NULL){
		return INT_MIN;
	}
	hash_map<int,int>::iterator *itToPowerCoefficientMap;
	int maxPower = INT_MIN;
	hash_map<int,int>::iterator *itToMaxPower;
	for(itToPowerCoefficientMap = powerCoefficientMap.begin();itToPowerCoefficientMap != powerCoefficientMap.end();itToPowerCoefficientMap++){
		if(maxPower < (*itToPowerCoefficientMap)->first){
			maxPower = (*itToPowerCoefficientMap)->first;
			itToMaxPower = itToPowerCoefficientMap;
		}
	}
	return itToMaxPower;
}

polynomialEquation *DividePolynomialEquations(polynomialEquation *divisor,polynomialEquation *dividend){
	if(divisor == NULL || dividend == NULL){
		return NULL;
	}
	int highestPowerCounter  = dividend->highestPower;
	hash_map<int,int>::iterator *itToDividend = dividend->powerCoefficientMap.begin();
	hash_map<int,int>::iterator *itToDivisor;
	hash_map<int,int> quotient;
	hash_map<int,int>::iterator *itToMaxPower;
	int highestPowerDivisorCounter = divisor->highestPower;
	int powerCalculation;
	int coefficientCalculation,currentCoefficientCounter;
	int currentDivisorCoefficient,currentDividendCoefficient;
	hash_map<int,int>::iterator itToCurrentDividend;
	hash_map<int,int> remainder;
	while((itToMaxPower = GetTheHighestPowerFromEquation(itToDividend)),(*itToMaxPower)->first > highestPowerDivisorCounter){
		itToDivisor = divisor->powerCoefficientMap[highestPowerDivisorCounter];
		powerCalculation = (*itToMaxPower)->first - (*itToDivisor)->first;
		for(currentCoefficientCounter = 1;(*itToDivisor)->second * currentCoefficientCounter >= (*itToDividend)->second;currentCoefficientCounter++);
		coefficientCalculation = currentCoefficientCounter-1;
		quotient.insert(pair<int,int>(powerCalculation,coefficientCalculation));
		for(itToDivisor = divisor->powerCoefficientMap.begin();;){
			if((*itToDivisor)->first != ((*itToDivisor)->first) - powerCalculation){
				itToDividend = dividend->powerCoefficientMap.find((*itToDivisor)->first);
				if(itToCurrentDividend != dividend->powerCoefficientMap.end()){
					coefficientCalculation = (*itToCurrentDividend)->second - (*itToDivisor)->second;
					dividend->powerCoefficientMap[(*itToDivisor)->first] = coefficientCalculation;
				}else{
					dividend->powerCoefficientMap.insert((*itToDivisor)->first,-1 * (*itToDivisor)->second);
				}
			}
		}
	}

	for(itToDividend = dividend->powerCoefficientMap.begin();itToDividend != dividend->powerCoefficientMap.end();itToDividend++){
		remainder.insert(pair<int,int>((*itToDividend)->first,(*itToDividend)->second));
	}

	polynomialEquation *quotientRemainderMap[2];
	quotientRemainderMap[0]->powerCoefficientMap = quotient;
	quotientRemainderMap[1]->powerCoefficientMap = remainder;

	return quotientRemainderMap;
}


#endif /* DIVISIONOFPOLYNOMIALEQUATION_H_ */
