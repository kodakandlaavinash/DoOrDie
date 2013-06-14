/*
 * PolynomialEquationProperties.h
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

#ifndef POLYNOMIALEQUATIONPROPERTIES_H_
#define POLYNOMIALEQUATIONPROPERTIES_H_

struct polynomialEquation{
	hash_map<int,int> powerCoefficientMap;
	int highestPower;
};

int NumberOfPossibleRootsOfEquation(polynomialEquation *equation){
	if(equation == NULL){
		return 0;
	}
	return equation->highestPower;
}

int SumOfRootsOfPolynomialEquation(polynomialEquation *equation){
	if(equation == NULL){
		return 0;
	}

	int highestPower = equation->highestPower;
	return ((-1 * (equation->powerCoefficientMap[highestPower-1]))/(equation->powerCoefficientMap[highestPower]));
}

int ProductOfRootsOfPolynomialEquation(polynomialEquation *equation){
	if(equation == NULL){
		return 0;
	}

	int highestPower = equation->highestPower;
	if(highestPower % 2 == 0){
		return (equation->powerCoefficientMap[0]/(equation->powerCoefficientMap[highestPower]));
	}else{
		return (-1 * equation->powerCoefficientMap[0]/equation->powerCoefficientMap[highestPower]);
	}
}

void PrintAllPossibleWaysOfSumingTheRoots(polynomialEquation *equation){
	if(equation == NULL){
		return;
	}
	int counter = 0;
	int highestPower = equation->highestPower;
	int sum = 0;
	int changeSign = true;
	for(int counter=1;counter < equation->highestPower;counter++){
		sum = equation->powerCoefficientMap[highestPower-counter]/equation->powerCoefficientMap[highestPower];
		if(changeSign){
			sum *= -1;
		}
		printf("Sum of roots taken %d at a time is %d",counter,sum);
		changeSign = !changeSign;
	}
	return;
}


#endif /* POLYNOMIALEQUATIONPROPERTIES_H_ */
