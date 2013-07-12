/*
 * FindLastDigitOfPower.h
 *
 *  Created on: Jul 9, 2013
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

#ifndef FINDLASTDIGITOFPOWER_H_
#define FINDLASTDIGITOFPOWER_H_

int FindLastDigitOfPower(int base,int power){
	queue<int> possibleLastDigit;
	int value;
	int lastDigit;
	if(base%10 == 5){
		return 5;
	}
	if(base%10 == 0){
		return 0;
	}
	for(int counter = 1;counter <= power;counter++){
		value = pow(base,counter);
		lastDigit = value %10;
		if(possibleLastDigit.empty()){
			possibleLastDigit.push(lastDigit);
		}else{
			if(lastDigit == possibleLastDigit.front()){
				int sizeOfQueue = possibleLastDigit.size();
				int remainderOfPower = power % sizeOfQueue;

			}else{
				possibleLastDigit.push(lastDigit);
			}
		}
	}
}

#endif /* FINDLASTDIGITOFPOWER_H_ */
