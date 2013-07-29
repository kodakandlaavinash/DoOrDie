/*
 * MatrixMultiplication.h
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

#ifndef MATRIXMULTIPLICATION_H_
#define MATRIXMULTIPLICATION_H_

#define M 10

int *MultiplicationOfMatrices(int userInput1[][M],int userInput2[M][],int totalSize){
	if(totalSize == 0){
		return null;
	}
	int N = totalSize/M;
	int *resultingMatrix = (int *)calloc(M*N,sizeof(int));
	for(int rowCrawler = 0;rowCrawler < N;rowCrawler++){
		for(int columnCrawler =0;columnCrawler < M;columnCrawler++){
			for(int innerCrawler;innerCrawler < M;innerCrawler++){
				resultingMatrix[rowCrawler][columnCrawler] = userInput1[rowCrawler][innerCrawler] *userInput2[innerCrawler][columnCrawler];
			}
		}
	}
	return resultingMatrix;
}

#endif /* MATRIXMULTIPLICATION_H_ */
