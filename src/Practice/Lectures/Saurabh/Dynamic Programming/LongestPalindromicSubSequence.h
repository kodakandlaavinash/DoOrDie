/*
 * LongestPalindromicSubSequence.h
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

#ifndef LONGESTPALINDROMICSUBSEQUENCE_H_
#define LONGESTPALINDROMICSUBSEQUENCE_H_

int LongestPalindromicSubsequence(int userInput[],int startCrawler,int endCrawler){
	if(startCrawler > endCrawler){
		return 0;
	}
	if(abs(startCrawler - endCrawler) == 0){
		return 1;
	}
	if(abs(startCrawler-endCrawler) == 1){
		if(userInput[startCrawler] == userInput[endCrawler]){
			return 2;
		}
		return 0;
	}
	if(userInput[startCrawler] == userInput[endCrawler]){
		return 2 + LongestPalindromicSubsequence(userInput,startCrawler+1,endCrawler-1);
	}else{
		return max(LongestPalindromicSubsequence(userInput,startCrawler+1,endCrawler),LongestPalindromicSubsequence(userInput,startCrawler,endCrawler-1));
	}
}

int LongestPalindromicSubsequenceMemoziation(int userInput[],int startCrawler,int endCrawler){
	if(userInput == NULL || startCrawler > endCrawler){
		return 0;
	}
	if(abs(startCrawler - endCrawler) == 1){
		return 1;
	}
	if(abs(startCrawler - endCrawler) == 2){
		if(userInput[startCrawler] == userInput[endCrawler]){
			return 2;
		}
		return 0;
	}

	if(userInput[startCrawler] == userInput[endCrawler]){

	}else{

	}

}

int LongestPalindromicSubSequenceO2N(int userInput[],int sizeOfArray){
	if(userInput == NULL || sizeOfArray == 0){
		return 0;
	}
	vector<int> currentSubSet;
	int maxPalindromicLength = INT_MIN;
	for(int subSetCounter = 0;subSetCounter < pow(2,sizeOfArray);subSetCounter++){
		bitset<sizeOfArray> bitRepSubSet(subSetCounter);
		currentSubSet.clear();
		for(int bitCounter = 0;bitCounter < sizeOfArray;bitCounter++){
			if(bitRepSubSet[bitCounter]){
				currentSubSet.push_back(userInput[bitCounter]);
			}
		}
		//Elliminating zero size
		if(currentSubSet.size() > 0){
			int frontCrawler = 0,backCrawler = currentSubSet.size();
			int palindromeLength = 0;
			bool isPalindrome = true;
			while(frontCrawler < backCrawler){
				if(userInput[frontCrawler] != userInput[backCrawler]){
					isPalindrome = false;
				}
				palindromeLength += 1;
			}
			if(isPalindrome){
				if(maxPalindromicLength < palindromeLength){
					maxPalindromicLength = palindromeLength;
				}
			}
		}
	}
	return maxPalindromicLength;
}
#endif /* LONGESTPALINDROMICSUBSEQUENCE_H_ */
