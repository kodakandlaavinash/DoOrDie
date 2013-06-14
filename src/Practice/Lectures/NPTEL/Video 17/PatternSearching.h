/*
 * PatternSearching.h
 *
 *  Created on: Jun 5, 2013
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

#ifndef PATTERNSEARCHING_H_
#define PATTERNSEARCHING_H_

vector<int> FindPatternsNaiveMethodIterative(char *text,char *pattern){
	if(text == NULL  || pattern == NULL){
		return 0;
	}
	int patternCrawler,textCrawler;
	int patternLength = strlen(pattern),textLength = strlen(text);
	bool patternFound;
	vector<int> positionOfOccurenceOfPattern;
	for(textCrawler = 0;textCrawler < textLength-patternLength;textCrawler++){
		patternFound = true;
		for(patternCrawler=0;patternCrawler < patternLength;patternCrawler++){
			if(text[textCrawler] != pattern[patternCrawler]){
				patternFound = false;
				break;
			}
		}
		if(patternFound){
			positionOfOccurenceOfPattern.push_back(textCrawler);
		}
	}
	return positionOfOccurenceOfPattern;
}

vector<int> FindOccurenceOfPatternRecursive(char *text,char *pattern,vector<int> positionsOfOccurence,int textPosition,int &textLength,int &patternLength){
	if(textPosition == textLength - patternLength){
		return positionsOfOccurence;
	}
	int textCrawler,patternCrawler;
	bool patternFound = true;
	for(patternCrawler = 0;patternCrawler< 0;patternCrawler++){
		if(pattern[patternCrawler] != text[textPosition + patternCrawler]){
			patternFound = false;
			break;
		}
	}
	if(patternFound){
		positionsOfOccurence.push_back(textPosition);
	}
	return FindOccurenceOfPatternRecursive(text,pattern,positionsOfOccurence,textPosition+1,textLength,patternLength);
}

int *InitializeFailureFunctionON2(char *pattern,int patternLength){
	if(pattern == null){
		return null;
	}
}

int *InitializeFailureFunctionON(char *pattern,int patternLength){
	if(pattern == null){
		return null;
	}

	int *failureTable = (int *)calloc(patternLength,sizeof(int));
	int lastMatchIndex = 0;
	failureTable[0] = 0;
	for(int crawler = 1;crawler < patternLength;crawler++){
		if(pattern[crawler] == pattern[lastMatchIndex]){
			failureTable[crawler] = failureTable[crawler-1] + 1;
			lastMatchIndex += 1;
		}else{
			failureTable[crawler] = 0;
			lastMatchIndex = 0;
		}
	}
	return failureTable;
}

vector<int> KMPPatternMatching(char *text,char *pattern){
	if(text == null || pattern == null){
		return NULL;
	}
	int *failureTable = InitializeFailureFunction(pattern);

	char *textCrawler = text,*patternCrawler;
	char currentTextChar,currentPatternChar;
	int patternLength = strlen(pattern);
	int counter = 0;
	vector<int> occurencesList;
	int successfullyMatched;
	for(textCrawler = text;textCrawler != '\0';){
		currentTextChar = *textCrawler;
		successfullyMatched = 0;
		for(patternCrawler = pattern;patternCrawler != '\0';patternCrawler++){
			currentPatternChar = *patternCrawler;
			if(currentTextChar != currentPatternChar){
				break;
			}else{
				successfullyMatched += 1;
			}
		}
		if(patternCrawler == '\0'){
			occurencesList.push_back(counter);
			counter += patternLength;
		}else{
			textCrawler += failureTable[patternLength - successfullyMatched];
			counter  += failureTable[patternLength - successfullyMatched];
		}
	}
	return occurencesList;
}
#endif /* PATTERNSEARCHING_H_ */
