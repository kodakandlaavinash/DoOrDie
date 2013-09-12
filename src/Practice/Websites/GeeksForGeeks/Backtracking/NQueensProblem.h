/*
 * NQueensProblem.h
 *
 *  Created on: Sep 5, 2013
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

#ifndef NQUEENSPROBLEM_H_
#define NQUEENSPROBLEM_H_

#define N 8

bool isInSafeConfiguration(int userInput[][N],int noOfQueens,int currentQueen,int column){
	if(currentQueen >= noOfQueens){
		return false;
	}
	//Checking whether there exists another queen on same column
	for(int rowCounter =0;rowCounter < noOfQueens;rowCounter++){
		if(userInput[rowCounter][column] == 1){
			return false;
		}
	}
	//Checking for up diagonal top left to element
	for(int diagonalCounter=0;diagonalCounter < column;diagonalCounter++){
		if(userInput[diagonalCounter][diagonalCounter] == 1){
			return false;
		}
	}
	//Checking for up diagonal element to top right
	for(int diagonalCounter = column+1;diagonalCounter < N;diagonalCounter++){
		if(userInput[diagonalCounter][diagonalCounter] == 1){
			return false;
		}
	}
	return true;
}

void NQueensProblem(int userInput[][N],int noOfQueens,int currentQueen,int column){
	if(noOfQueens-1 == currentQueen){
		if(isInSafeConfiguration(userInput,noOfQueens,currentQueen,column)){
			for(int rowCounter = 0;rowCounter < N;rowCounter++){
				for(int columnCounter = 0;columnCounter < N;columnCounter++){
					printf("%d\t",userInput[rowCounter][columnCounter]);
				}
				printf("\n");
			}
		}
		return;
	}
	if(!isInSafeConfiguration(userInput,noOfQueens,currentQueen,column)){
		return;
	}
	for(int columnCounter = 0;columnCounter < noOfQueens;columnCounter++){
		userInput[currentQueen][columnCounter] = 1;
		NQueensProblem(userInput,noOfQueens,currentQueen+1,columnCounter);
		userInput[currentQueen][columnCounter] = 0;
	}
}

#endif /* NQUEENSPROBLEM_H_ */
