/*
 * WhetherTwoStringsAreAnagramsToEachOther.h
 * http://www.careercup.com/question?id=5136177443110912
 *  Created on: Aug 19, 2013
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

#ifndef WHETHERTWOSTRINGSAREANAGRAMSTOEACHOTHER_H_
#define WHETHERTWOSTRINGSAREANAGRAMSTOEACHOTHER_H_

bool AreTwoStringsAnagramsToEachOtherON(char *userInput1,char *userInput2){
	if(userInput1 == NULL && userInput2 == NULL){
		return true;
	}
	if(userInput1 == NULL || userInput2 == NULL){
		return false;
	}

	hash_map<char,int> frequencyMap;
	hash_map<char,int>::iterator itToFrequencyMap;
	char *crawlerForFirstString = userInput1,*crawlerForSecondString = userInput2;
	char temp = userInput1;
	while(temp != '\0'){
		if((itToFrequencyMap = frequencyMap.find(temp)) != frequencyMap.end()){
			frequencyMap.insert(pair<char,int>(itToFrequencyMap->first,itToFrequencyMap->second+1));
		}else{
			frequencyMap.insert(pair<char,int>(itToFrequencyMap->first,1));
		}
		temp = ++crawlerForFirstString;
	}

	temp = userInput2;

	while(temp != '\0'){
		if(itToFrequencyMap = frequencyMap.find(temp) != frequencyMap.end()){
			if(itToFrequencyMap->second == 1){
				frequencyMap.erase(itToFrequencyMap->first);
			}
			frequencyMap[itToFrequencyMap->first] = itToFrequencyMap->second -1;
		}
		return false;
	}
	return true;
}

bool CheckWhetherTwoStringsAreAnagramsONLOGN(char *userInput1,char *userInput2){
	if(userInput1 == NULL && userInput2 == NULL){
		return true;
	}
	if(userInput1 == NULL || userInput2 == NULL){
		return false;
	}
	if(strlen(userInput1) != strlen(userInput2)){
		return false;
	}
	sort(userInput1,strlen(userInput1));
	sort(userInput2,strlen(userInput2));

	for(int counter = 0;counter < strlen(userInput1);counter++){
		if(userInput1[counter] != userInput2[counter]){
			return false;
		}
	}
	return true;
}



#endif /* WHETHERTWOSTRINGSAREANAGRAMSTOEACHOTHER_H_ */
