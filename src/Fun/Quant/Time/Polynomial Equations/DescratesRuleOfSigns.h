/*
 * DescratesRuleOfSigns.h
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

#ifndef DESCRATESRULEOFSIGNS_H_
#define DESCRATESRULEOFSIGNS_H_

struct polynomialEquation{
	vector<int> powersOfEquation;
	vector<int> coefficientsOfEquation;
	int highestPower;
};

equation *BuildEquationByMultiplyingByNeg1(polynomialEquation *equation){
	if(equation == NULL){
		return NULL;
	}

	polynomialEquation *enhancedEquation = (equation *)malloc(sizeof(polynomialEquation));
	for(int counter =0;counter < equation->powersOfEquation.size();counter){
		enhancedEquation->powersOfEquation.push_back(equation->powersOfEquation[counter]);
		if(equation->powersOfEquation[counter]%2 == 1){
			enhancedEquation->coefficientsOfEquation.push_back(-1 * equation->coefficientsOfEquation[counter]);
		}else{
			enhancedEquation->coefficientsOfEquation.push_back(equation->coefficientsOfEquation[counter]);
		}
	}

	enhancedEquation->highestPower = equation->highestPower;
	return enhancedEquation;
}

void AnalyzePolynomialEquationUsingDescratesRuleOfSigns(polynomialEquation *equation){
	if(equation == NULL){
		cout << "User input is null" << endl;
		return;
	}
	//Assuming that the powers of the equation are given in the sorted decreasing order
	int signChange = 0;
	for(int counter = 0;counter < equation->powersOfEquation.size()-1;counter++){
		if(equation->coefficientsOfEquation[counter] * equation->coefficientsOfEquation[counter+1] < 0){
			signChange += 1;
		}
	}
	printf("Maximum number of positive roots that a equation can have is %d",signChange);

	int signChangesForNegativeX = 0;
	polynomialEquation *newEquation  = BuildEquationByMultiplyingByNeg1(equation);
	for(int counter = 0;counter < equation->powersOfEquation.size()-1;counter++){
		if(equation->coefficientsOfEquation[counter] * equation->coefficientsOfEquation[counter+1] < 0){
			signChangesForNegativeX += 1;
		}
	}

	printf("Maximum number of negative roots that a equation can have is %d",signChangesForNegativeX);
}

#endif /* DESCRATESRULEOFSIGNS_H_ */
