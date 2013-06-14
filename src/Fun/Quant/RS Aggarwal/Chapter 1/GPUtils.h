/*
 * GPUtils.h
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

#ifndef GPUTILS_H_
#define GPUTILS_H_

int GetNthTermGP(int startTerm,int commonRatio,int n){
	return (startTerm *(commonRatio ^ (n-1)));
}

int SumOfNTermsInGP(int startTerm,int commonRatio,int n){
	if(commonRatio > 1){
		return (startTerm *((commonRatio ^ n)-1)/(commonRatio -1));
	}else{
		return (startTerm *(1-(commonRatio ^ n))/(1-commonRatio));
	}
}

long int SumOfNTermsInGPRecurstion(int startTerm,int commonRatio,int n){
	return n==0?1:startTerm * SumOfNTermsInGP(startTerm*commonRatio,commonRatio,n-1);
}

long int SumOfNTermsInGPIteration(int startTerm,int commonRatio,int n){
	int sumOfGPTerms = 0;
	for(int crawler = 0;crawler < n;crawler++){
		sumOfGPTerms += startTerm * pow(crawler*commonRatio);
	}
	return sumOfGPTerms;
}

#endif /* GPUTILS_H_ */
