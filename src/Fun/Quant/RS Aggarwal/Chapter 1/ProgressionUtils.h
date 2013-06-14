/*
 * ProgressionUtils.h
 *
 *  Created on: May 15, 2013
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

#ifndef PROGRESSIONUTILS_H_
#define PROGRESSIONUTILS_H_

int SumOfNaturalNumbers(int numberOfTerms){
	return (numberOfTerms) * (numberOfTerms+1)/2;
}

int SumOfSquareOfNaturalNumbers(int numberOfTerms){
	return (numberOfTerms/6) * (numberOfTerms+1) *((2*numberOfTerms)+ 1);
}

int SumOfCubesOfNaturalNumbers(int numberOfTerms){
	return pow(2,SumOfNaturalNumbers(numberOfTerms));
}

#endif /* PROGRESSIONUTILS_H_ */
