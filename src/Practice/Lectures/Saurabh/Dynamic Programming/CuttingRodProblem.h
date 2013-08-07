/*
 * CuttingRodProblem.h
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

#ifndef CUTTINGRODPROBLEM_H_
#define CUTTINGRODPROBLEM_H_

int CuttingRodProblem(int rodSizes[],int totalNumberOfRods,int minSizeOfRod,int remainingLength){
	if(minSizeOfRod < remainingLength){
		return 0;
	}
	int minNumberOfPieces = INT_MAX;
	int totalPieces = 0;
	for(int counter=0;counter < totalNumberOfRods;counter++){

	}
}

int CuttingRodProblemMemoziation(int rodSizes[],int totalNumberOfRods){

}
#endif /* CUTTINGRODPROBLEM_H_ */
