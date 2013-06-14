/*
 * APUtils.h
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

#ifndef APUTILS_H_
#define APUTILS_H_

long int GiveNthTermForAP(int startNumber,int commonDifference,int n){
	return (startNumber + ((n-1)*commonDifference));
}

long int GiveSumOfAP(int startNumber,int commonDifference,int n){
	return(((n/2)*((2 * startNumber)+ (n-1)*commonDifference)));
}

long int GiveSumOfAP(int startNumber,int n,int commonDifference){
	return n==0?0:startNumber+GiveSumOfAP(startNumber+commonDifference,n-1,commonDifference);
}

long int GiveSumOfAPGivenFirstAndLastTerm(int startNumber ,int endNumber,int n){
	return ((n/2)*(startNumber+endNumber));
}

long int GiveSumOfAPGivenFirstLastCommonDifference(int startNumber,int endNumber,int commonDiffernece){
	return (((((endNumber - startNumber)/commonDiffernece)+1)/2)*(startNumber+endNumber));
}

#endif /* APUTILS_H_ */
