/*
 * FactorizeANumber.h
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

#ifndef FACTORIZEANUMBER_H_
#define FACTORIZEANUMBER_H_

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

#endif /* FACTORIZEANUMBER_H_ */
