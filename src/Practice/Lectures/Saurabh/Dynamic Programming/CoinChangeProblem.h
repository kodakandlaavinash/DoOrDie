/*
 * CoinChangeProblem.h
 *
 *  Created on: Aug 1, 2013
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

#ifndef COINCHANGEPROBLEM_H_
#define COINCHANGEPROBLEM_H_

int CoinChangeProblem(int coinsAvailable[],int sizeOfArray,int amount){
	if(coinsAvailable == NULL || sizeOfArray == 0){
		return 0;
	}
	if(amount < 0){
		return 0;
	}
	int minCoins = INT_MAX;
	int coins;
	for(int counter=0;counter < sizeOfArray;counter){
		if(coinsAvailable[counter] < amount){
			return 0;
		}
		coins = 1 + CoinChangeProblem(coinsAvailable,sizeOfArray,amount-coinsAvailable[counter]);
		if(minCoins > coins){
			minCoins = coins;
		}
	}
	return minCoins;
}

int MinCoinChangeProblemMemoziation(int coinsAvailable[],int sizeOfArray,int amount){

}

#endif /* COINCHANGEPROBLEM_H_ */
