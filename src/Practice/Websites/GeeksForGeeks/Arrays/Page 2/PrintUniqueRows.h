/*
 * PrintUniqueRows.h
 *
 *  Created on: Aug 15, 2013
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

#ifndef PRINTUNIQUEROWS_H_
#define PRINTUNIQUEROWS_H_

#define MAX_ROWS_PRINT_UNIQUE_ROWS 10
#define MAX_COLUMN_PRINT_UNIQUE_COLUMNS 10

void PrintUniqueRows(bool userInput[MAX_ROWS_PRINT_UNIQUE_ROWS][],int totalRows,int totalColumns){
	if(userInput == NULL){
		return;
	}
	int outerRowCounter,outerColumnCounter,innerRowCounter,innerColumnCounter;
	bool uniqueRow;
	for(outerRowCounter=0;outerRowCounter < totalRows;outerRowCounter++){
		for(outerColumnCounter = 0;outerColumnCounter < totalColumns;){
			uniqueRow = true;
			for(innerRowCounter = outerRowCounter+1;innerRowCounter < totalRows;innerRowCounter++){
				for(innerColumnCounter = 0;innerColumnCounter < totalColumns;innerColumnCounter++){
					if(userInput[outerRowCounter][outerColumnCounter] == userInput[innerRowCounter][innerColumnCounter]){
						uniqueRow = false;
						break;
					}
					outerColumnCounter++;
				}
			}
			if(uniqueRow){
				for(int columnCounter = 0;columnCounter < totalColumns;columnCounter++){
					printf("%d\t",userInput[outerRowCounter][columnCounter]);
				}
				printf("\n");
			}
		}
	}
}

void PrintUniqueRowsBoolToInt(int userInput[MAX_ROWS_PRINT_UNIQUE_ROWS][],int totalRows,int totalColumns){
	if(userInput == NULL){
		return;
	}
	hash_map<int,list<int>> frequencyMap;
	hash_map<int,list<int>>::iterator itToFrequencyMap;
	list<int> temp;
	int rowCounter,columnCounter;
	int decimalRep;
	int powerOf2;
	for(rowCounter = 0;rowCounter < totalRows;rowCounter++){
		decimalRep = 0;
		powerOf2 = 0;
		for(columnCounter = 0;columnCounter < totalColumns;columnCounter++){
			decimalRep += userInput[rowCounter][columnCounter] * pow(2,powerOf2);
			powerOf2++;
			if((itToFrequencyMap = frequencyMap.find(decimalRep)) != frequencyMap.end()){
				temp = itToFrequencyMap->second;
				temp.push_back(rowCounter);
			}else{
				temp.clear();
				temp.push_back(rowCounter);
			}
			frequencyMap[decimalRep] = temp;
		}
	}
	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second.size() == 1){
			for(int columnCounter = 0;columnCounter < totalColumns;columnCounter++){
				printf("%d\t",userInput[itToFrequencyMap->second[0]][columnCounter]);
			}
		}
	}
}

struct augumentedBST{
	int value;
	int frequency;
	list<int> rowsWithThisFrequency;
};

void PrintUniqueRowBinarySearchTree(int userInput[][],int totalRows,int totalColumns){
	if(userInput == NULL){
		return;
	}
	int rowCounter,columnCounter,decimalRep,powerOf2;
	for(rowCounter = 0;rowCounter < totalRows;rowCounter++){
		decimalRep = 0;
		powerOf2 = 0;
		for(columnCounter = 0;columnCounter < totalColumns;columnCounter++){
			decimalRep += userInput[rowCounter][columnCounter] *pow(2,powerOf2);
			powerOf2++;
		}
	}
}

#endif /* PRINTUNIQUEROWS_H_ */
