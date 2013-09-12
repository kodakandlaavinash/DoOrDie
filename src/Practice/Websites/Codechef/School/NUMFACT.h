/*
 *  NUMFACT.h
 *	http://www.codechef.com/problems/NUMFACT
 *  Created on: Sep 9, 2013
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

#ifndef NUMFACT_H_
#define NUMFACT_H_

vector<int> primeNumbers;
hash_map<int,int> factorsOfNumbers;

vector<int> generatePrimeNumbersSieve(int userInput){
	vector<bool> truthValue(userInput);
	for(int counter = 0;counter < userInput;counter++){
		truthValue[counter] = true;
	}
	for(int counter = 2;counter <= userInput;counter++){
		if(truthValue[counter]){
			int multiplicationCounter = 2;
			for(int value = counter*multiplicationCounter;value <= userInput;value =counter*multiplicationCounter){
				truthValue[value] = false;
				multiplicationCounter++;
			}
		}
	}
	for(int counter = 2;counter <= userInput;counter++){
		if(truthValue[counter]){
			primeNumbers.push_back(counter);
		}
	}
	return primeNumbers;
}

void FactoriseANumber(int number){

	hash_map<int,int>::iterator itToFactorsOfNumbers;
	if(number == 0){
		factorsOfNumbers.insert(pair<int,int>(0,1));
		return;
	}

	for(unsigned int counter=0;counter < primeNumbers.size() && number != 1;counter++){
		if(number%primeNumbers[counter] == 0){
			if((itToFactorsOfNumbers = factorsOfNumbers.find(primeNumbers[counter])) != factorsOfNumbers.end()){
				factorsOfNumbers[itToFactorsOfNumbers->first] = itToFactorsOfNumbers->second+1;
			}else{
				factorsOfNumbers.insert(pair<int,int>(primeNumbers[counter],1));
			}
			number /= primeNumbers[counter];
			counter = -1;
		}
	}

	if(factorsOfNumbers.size() == 0){
		factorsOfNumbers.insert(pair<int,int>(number,1));
	}

	return;
}


int main(){
	int noOfTestCases;
	scanf("%d",&noOfTestCases);
	int inputSize,input;
	vector<int> userInput;
	generatePrimeNumbersSieve(1000000);
	while(noOfTestCases--){
		scanf("%d",&inputSize);
		userInput.clear();
		while(inputSize--){
			scanf("%d",&input);
			FactoriseANumber(input);
		}
		int totalNumberOfFactors = 1;
		hash_map<int,int>::iterator itToFrequencyMap;
		for(itToFrequencyMap = factorsOfNumbers.begin();itToFrequencyMap != factorsOfNumbers.end();itToFrequencyMap++){
			totalNumberOfFactors *= (itToFrequencyMap->second + 1);
		}
		factorsOfNumbers.clear();
		printf("%d\n",totalNumberOfFactors);
	}
}

#endif /* NUMFACT_H_ */
