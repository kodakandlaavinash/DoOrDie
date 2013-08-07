/*
 * TurnAnImageBy90.h
 *
 *  Created on: Aug 2, 2013
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

#ifndef TURNANIMAGEBY90_H_
#define TURNANIMAGEBY90_H_

#define NO_OF_ROWS 10

char *TurnAnImageBy90ClockWise(char originalImage[NO_OF_ROWS][],int noOfRows,int noOfColumn){
	if(originalImage == NULL || (noOfRows == 0 && noOfColumn ==0)){
		return null;
	}
	char *outputImage;
	outputImage = (char *)calloc(sizeof(char),noOfRows);
	for(int counter =0;counter < noOfColumn;counter++){
		outputImage[counter] = (char *)calloc(sizeof(char),noOfColumn);
	}

	for(int rowCounter = 0;rowCounter < noOfRows;rowCounter++){
		for(int columnCounter =0;columnCounter < noOfColumn;columnCounter++){
			outputImage[columnCounter][noOfRows - rowCounter - 1] = originalImage[rowCounter][columnCounter];
		}
	}
}

char *TurnAnImageBy180ClockWise(char originalImage[][],int noOfRows,int noOfColumn){
	if(originalImage == NULL || (noOfRows == 0 && noOfColumn ==0)){
		return null;
	}
	char *outputImage = TurnAnImageBy90ClockWise(originalImage,noOfRows,noOfColumn);
	outputImage = TurnAnImageBy90ClockWise(outputImage,noOfColumn,noOfRows);
	return outputImage;
}

char *TurnAnImageBy270Clockwise(char originalImage[][],int noOfRows,int noOfColumn){
	if(originalImage == NULL || (noOfRows == 0 && noOfColumn == 0)){
		return null;
	}
	char *outputImage = TurnAnImageBy90ClockWise(originalImage,noOfRows,noOfColumn);
	outputImage = TurnAnImageBy90ClockWise(originalImage,noOfRows,noOfColumn);
	return outputImage;
}

#endif /* TURNANIMAGEBY90_H_ */
