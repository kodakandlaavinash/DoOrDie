/*
 * RatioAndProportions.h
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

#ifndef RATIOANDPROPORTIONS_H_
#define RATIOANDPROPORTIONS_H_

int *FindIndividualAmountIfRatioAndTotal(int totalAmount,int antecedent,int consequent){
	int respectiveAmounts[2];
	respectiveAmounts[0] = (antecedent/(antecedent + consequent)) *totalAmount;
	respectiveAmounts[0] = (consequent/(antecedent + consequent)) *totalAmount;
	return respectiveAmounts;
}

int *SimplifyRatios(int antecedent,int consequent){
	hash_map<int,int> factorsOfAntecedent;
	hash_map<int,int> factorsOfConsequent;
	hash_map<int,int>::iterator *itToFactorsOfAntecedent;
	hash_map<int,int>::iterator *itToFactorsOfConsequent;

	int divideByAmount = 1;
	for(itToFactorsOfAntecedent = factorsOfAntecedent.begin();itToFactorsOfAntecedent != factorsOfAntecedent.end();itToFactorsOfAntecedent++){
		if((itToFactorsOfConsequent = factorsOfConsequent.find((*itToFactorsOfAntecedent)->first)) != factorsOfConsequent.end()){
			divideByAmount *= pow((*itToFactorsOfAntecedent),abs((*itToFactorsOfAntecedent)->second,(*itToFactorsOfConsequent)->second));
		}
	}

	int simplifiedRatios[2];
	simplifiedRatios[0] = antecedent/divideByAmount;
	simplifiedRatios[1] = antecedent/divideByAmount;

	return simplifiedRatios;
}

#endif /* RATIOANDPROPORTIONS_H_ */
