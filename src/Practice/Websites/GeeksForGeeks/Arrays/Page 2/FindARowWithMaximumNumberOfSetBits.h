/*
 * FindARowWithMaximumNumberOfSetBits.h
 *
 *  Created on: Aug 12, 2013
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

#ifndef FINDAROWWITHMAXIMUMNUMBEROFSETBITS_H_
#define FINDAROWWITHMAXIMUMNUMBEROFSETBITS_H_

#define ROW_WITH_MAX_SET_BITS_TOTAL_ROWS 10
#define ROW_WITH_MAX_SET_BITS_TOTAL_COLUMN 10

int FindARowWithMaxNumberOfSetBitsNaiveMethod(bool userInput[ROW_WITH_MAX_SET_BITS_TOTAL_ROWS][],int totalRows,int totalColumn){
	if(userInput== NULL){
		return INT_MAX;
	}
	int rowCounter,columnCounter;
	int maxRow,maxRowCount = INT_MIN;
	int setBitsCounter;
	for(rowCounter = 0;rowCounter < totalRows;rowCounter++){
		setBitsCounter = 0;
		for(columnCounter = 0;columnCounter < totalColumn;columnCounter++){
			if(userInput[rowCounter][columnCounter] == true){
				setBitsCounter++;
			}
		}
		if(setBitsCounter > maxRowCount){
			maxRow = rowCounter;
			maxRowCount = setBitsCounter;
		}
	}
	return maxRow;
}

int FindARowWithMaxSetBitsNaiveOptimized(int userInput[ROW_WITH_MAX_SET_BITS_TOTAL_ROWS][],int totalRows,int totalColumn){
	if(userInput == NULL){
		return INT_MIN;
	}
	int rowCounter,columnCounter = INT_MAX;
	int maxSetBitRow,maxSetBitCounter,leastColumn;
	for(columnCounter = totalColumn-1;columnCounter >=0;columnCounter--){
		if(userInput[0][columnCounter] == true){
			if(columnCounter+1 > maxSetBitCounter){
				maxSetBitCounter = totalColumn - columnCounter + 1;
				leastColumn = columnCounter;
				maxSetBitRow = 0;
			}
		}
	}
	for(rowCounter = 1;rowCounter < totalRows;rowCounter++){
		if(userInput[rowCounter][leastColumn-1] == 1){
			for(columnCounter = leastColumn-1;columnCounter >=0;columnCounter--){
				if(userInput[rowCounter][columnCounter] == true){
					maxSetBitCounter = totalColumn - columnCounter + 1;
					leastColumn = columnCounter;
					maxSetBitRow = rowCounter;
					if(leastColumn == 0){
						break;
					}
				}
			}
		}
	}
	return rowCounter;
}

int GetMinimumIndexForAKey(bool userInput[],int startArray,int endArray,bool key){
	if(userInput == NULL){
		return INT_MAX;
	}
	int middleIndex = (startArray + endArray)/2;
	if(userInput[middleIndex] == key){
		if(middleIndex-1 >= 0){
			if(userInput[middleIndex-1] == key){
				return GetMinimumIndexForAKey(userInput,startArray,endArray,key);
			}
		}else{
			return middleIndex;
		}
	}else{
		return GetMinimumIndexForAKey(userInput,middleIndex+1,endArray,key);
	}

}

int FindARowWithMaximumNumberOfSetBitsBinarySearch(bool userInput[][],int totalRows,int totalColumns){
	if(userInput == NULL){
		return INT_MIN;
	}
	int minColumn = INT_MAX,columnIndexInRow;
	for(int rowCounter=0;rowCounter < totalRows;rowCounter++){
		if(minColumn != INT_MAX){
			if(!userInput[rowCounter][minColumn-1]){
				continue;
			}
			columnIndexInRow = GetMinimumIndexForAKey(userInput[rowCounter],0,columnIndexInRow-1,true);
		}else{
			columnIndexInRow = GetMinimumIndexForAKey(userInput[rowCounter],0,totalColumns,true);
		}
		if(columnIndexInRow != INT_MAX){
			if(minColumn > columnIndexInRow){
				minColumn = columnIndexInRow;
			}
		}
	}
}


#endif /* FINDAROWWITHMAXIMUMNUMBEROFSETBITS_H_ */
