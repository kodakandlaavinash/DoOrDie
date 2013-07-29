/*
 * SumOfNumbers.h
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

#ifndef SUMOFNUMBERS_H_
#define SUMOFNUMBERS_H_

int SumOfNumbersON(int totalNumbers){
	for(int counter = 1,sum = 0;counter <= totalNumbers;counter++){
		sum += counter;
	}
	return sum;
}

int SumOfNumberO1(int totalNumbers){
	return ((totalNumbers)(totalNumbers+1)/2);
}

#endif /* SUMOFNUMBERS_H_ */
