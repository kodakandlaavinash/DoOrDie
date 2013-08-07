/*
 * FindWhetherArrayIsSubsetOfAnother.h
 *
 *  Created on: Aug 5, 2013
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

#ifndef FINDWHETHERARRAYISSUBSETOFANOTHER_H_
#define FINDWHETHERARRAYISSUBSETOFANOTHER_H_

bool FindWhetherAnArrayIsSubsetOfAnother(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(userInput1 == NULL || userInput2 == NULL || sizeOfArray1 == 0 || sizeOfArray2 == 0){
		return true;
	}
	int outerCounter,innerCounter;
	bool isFound;
	if(sizeOfArray1 > sizeOfArray2){
		for(outerCounter = 0;outerCounter < sizeOfArray2;outerCounter++){
			isFound = false;
			for(innerCounter = 0;innerCounter < sizeOfArray1;innerCounter++){
				if(userInput2[outerCounter] == userInput1[innerCounter]){
					isFound = true;
					break;
				}
			}
			if(!isFound){
				return false;
			}
		}
	}else{
		for(outerCounter = 0;outerCounter < sizeOfArray1;outerCounter++){
			isFound = false;
			for(innerCounter = 0;innerCounter < sizeOfArray2;innerCounter++){
				if(userInput1[outerCounter] == userInput2[innerCounter]){
					isFound = true;
					break;
				}
			}
			if(!isFound){
				return false;
			}
		}
	}
	return true;
}

bool FindWhetherArrayIsSubsetOfAnotherBinarySearch(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(userInput1 == NULL || sizeOfArray1 == 0|| userInput2 == NULL || sizeOfArray2 == 0){
		return true;
	}
	if(sizeOfArray1 > sizeOfArray2){
		sort(userInput1,userInput1+sizeOfArray1);
		bool valueExists;
		for(int innerCounter =0;innerCounter < sizeOfArray2;innerCounter++){
			valueExists = binary_search(userInput1,userInput1+sizeOfArray1,userInput2[innerCounter]);
			if(!valueExists){
				return false;
			}
		}
	}else{
		sort(userInput2,userInput2+sizeOfArray2);
		bool valueExists;
		for(int innerCounter =0;innerCounter < sizeOfArray1;innerCounter++){
			valueExists = binary_search(userInput2,userInput2+sizeOfArray2,userInput1[innerCounter]);
			if(!valueExists){
				return false;
			}
		}
	}
	return true;
}

bool FindWhetherArrayIsSubsetOfAnotherAuxSpace(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(userInput1 == NULL || sizeOfArray1 == 0||userInput2 == NULL || sizeOfArray2 == 0){
		return true;
	}
	hash_map<int,int> occurenceMap;
	hash_map<int,int>::iterator itToOccurenceMap;
	if(sizeOfArray1 > sizeOfArray2){
		for(int counter = 0;counter < sizeOfArray1;counter++){
			if((itToOccurenceMap = occurenceMap.find(userInput1[counter]))!=occurenceMap.end()){
				occurenceMap.insert(pair<int,int>(userInput1[counter],itToOccurenceMap->second+1));
			}else{
				occurenceMap.insert(pair<int,int>(userInput1[counter],1));
			}
		}
		for(int counter =0;counter < sizeOfArray2;counter++){
			if((itToOccurenceMap = occurenceMap.find(userInput2[counter]))== occurenceMap.end()){
				return false;
			}
		}
	}else{
		for(int counter = 0;counter < sizeOfArray2;counter++){
			if((itToOccurenceMap = occurenceMap.find(userInput2[counter]))!=occurenceMap.end()){
				occurenceMap.insert(pair<int,int>(userInput2[counter],itToOccurenceMap->second+1));
			}else{
				occurenceMap.insert(pair<int,int>(userInput2[counter],1));
			}
		}
		for(int counter =0;counter < sizeOfArray1;counter++){
			if((itToOccurenceMap = occurenceMap.find(userInput1[counter])) == occurenceMap.end()){
				return false;
			}
		}
	}
	return true;
}



bool FindWhetherArrayIsSubsetOfAnotherMerging(int userInput1[],int sizeOfArray1,int userInput2[],int sizeOfArray2){
	if(userInput1 == NULL || sizeOfArray1 == 0|| userInput2 == NULL || sizeOfArray2 == 0){
		return true;
	}
	sort(userInput1,userInput1+sizeOfArray1);
	sort(userInput2,userInput2+sizeOfArray2);

	int arrayCrawler1=0,arrayCrawler2=0;
	if(sizeOfArray1 > sizeOfArray2){
		while(arrayCrawler1 < sizeOfArray1 && arrayCrawler2 < sizeOfArray2){
			if(userInput1[arrayCrawler1] > userInput2[arrayCrawler2]){
				arrayCrawler1++;
			}
			if(userInput1[arrayCrawler1] == userInput2[arrayCrawler2]){
				arrayCrawler1++;
				arrayCrawler2++;
			}
			if(userInput2[arrayCrawler2] > userInput1[arrayCrawler1]){
				return false;
			}
		}
		return arrayCrawler2 == sizeOfArray2?true:false;
	}else{
		while(arrayCrawler1 < sizeOfArray1 && arrayCrawler2 < sizeOfArray2){
			if(userInput2[arrayCrawler2] > userInput1[arrayCrawler1]){
				arrayCrawler2++;
			}
			if(userInput1[arrayCrawler1] == userInput2[arrayCrawler2]){
				arrayCrawler1++;
				arrayCrawler2++;
			}
			if(userInput1[arrayCrawler1] > userInput2[arrayCrawler2]){
				return false;
			}
		}
		return arrayCrawler1 == sizeOfArray1?true:false;
	}

}


#endif /* FINDWHETHERARRAYISSUBSETOFANOTHER_H_ */

