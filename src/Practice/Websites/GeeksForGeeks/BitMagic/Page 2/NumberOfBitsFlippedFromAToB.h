/*
 * NumberOfBitsFlippedFromAToB.h
 *
 *  Created on: Aug 28, 2013
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

#ifndef NUMBEROFBITSFLIPPEDFROMATOB_H_
#define NUMBEROFBITSFLIPPEDFROMATOB_H_

int NoOfBitsFlippedFromAToB(int userInput1,int userInput2){
	int XORResult = userInput1 ^ userInput2;
	int setBitCounter = 0;
	while(XORResult){
		setBitCounter++;
		XORResult &= (XORResult -1);
	}
	return setBitCounter;
}

int NoOfBitsFlippedFromAToB(int userInput1,int userInput2){
	bitset<32> bitPatternForUserInput1(userInput1),bitPatternForUserInput2(userInput2);
	int noOfBitsFlipped = 0;
	for(int counter = 0;counter <32;counter++){
		if(bitPatternForUserInput1[counter] ==  bitPatternForUserInput2[counter]){
			noOfBitsFlipped++;
		}
	}
	return noOfBitsFlipped;
}

#endif /* NUMBEROFBITSFLIPPEDFROMATOB_H_ */
