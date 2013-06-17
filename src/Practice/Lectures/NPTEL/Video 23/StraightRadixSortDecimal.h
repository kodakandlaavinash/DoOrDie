/*
 * StraightRadixSortDecimal.h
 *
 *  Created on: Jun 17, 2013
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

#ifndef STRAIGHTRADIXSORTDECIMAL_H_
#define STRAIGHTRADIXSORTDECIMAL_H_

void BucketSortForStraightRadixSort(vector<vector<int>> &userInput,int digitPosition){
	if(userInput.size() == 0){
		return;
	}
	vector<vector<int> > bucketsForDigits[10];
	for(int counter =0;counter < userInput.size();counter++){
		if(digitPosition < userInput[counter].size()){
			bucketsForDigits[userInput[counter][digitPosition]%10].push_back(userInput[counter]);
		}else{
			bucketsForDigits[0].push_back(userInput[counter]);
		}
	}
	return;
}

void StraightRadixSortForDecimal(int &userInput[],int sizeOfArray){
	if(sizeOfArray == 0){
		return;
	}
	vector<vector<int>> digitForm;
	int number;
	vector<int> temp;
	for(int counter =0;counter < userInput;counter++){
		number = userInput[counter];
		while(number){
			temp.push_back(number%10);
			number /= 10;
		}
		digitForm.push_back(temp);
	}

	int maxElement = max_element(userInput,userInput+sizeOfArray);
	int maxNumberOfDigits = log10(maxElement);

	for(int digitCrawler =0;digitCrawler < maxElement;digitCrawler++){
		BucketSortForStraightRadixSort(digitForm,digitCrawler);
	}

	int placeValue;
	int value;
	int fillCounter = -1;
	for(int counter =0;counter < digitForm;counter++){
		temp = digitForm[counter];
		placeValue = 0;
		for(int innerCounter =0;innerCounter < temp.size();innerCounter++){
			value += pow(10,placeValue);
			placeValue++;
		}
		userInput[++fillCounter] = value;
	}
}


#endif /* STRAIGHTRADIXSORTDECIMAL_H_ */
