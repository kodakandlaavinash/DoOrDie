/*
 * FactorialOfNumber.h
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

#ifndef FACTORIALOFNUMBER_H_
#define FACTORIALOFNUMBER_H_

unsigned int FactorialOfNumberRecursion(unsigned int number){
	return number == 1?1:number*FactorialOfNumber(number-1);
}

unsigned int FactorialOfNumberIteration(unsigned int number){
	unsigned int factorial = 1;
	for(int crawler = 1;crawler<=number;crawler++){
		factorial *= crawler;
	}
	return factorial;
}

#endif /* FACTORIALOFNUMBER_H_ */
