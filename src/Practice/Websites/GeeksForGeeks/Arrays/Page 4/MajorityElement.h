/*
 * MajorityElement.h
 *
 *  Created on: Apr 24, 2013
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

#include "../../Trees/TreesDS.h"
using namespace std;
using namespace __gnu_cxx;

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef MAJORITYELEMENT_H_
#define MAJORITYELEMENT_H_

/**
 * Tested
 */
int MajorityElementON2(int inputArray[], int sizeOfArray) {
	int innerCrawler, outerCrawler;
	int maxOccuringElement;
	int counterToKey;
	int maxCount = INT_MIN;
	for (outerCrawler = 0; outerCrawler < sizeOfArray; outerCrawler++) {
		counterToKey = 0;
		for (innerCrawler = 0; innerCrawler < sizeOfArray; innerCrawler++) {
			if (inputArray[innerCrawler] == inputArray[outerCrawler]) {
				counterToKey++;
			}
		}
		if (maxCount < counterToKey) {
			maxCount = counterToKey;
			maxOccuringElement = inputArray[outerCrawler];
		}
	}
	return maxOccuringElement;
}

/**
 * Tested
 */
int MajorityElementONLOGN(int inputArray[], int sizeOfArray) {
	sort(inputArray, inputArray + sizeOfArray);
	int maxOccuringElement;
	int maxCount = INT_MIN, counter = 1;

	for (int arrayCrawler = 0; arrayCrawler < sizeOfArray - 1;) {
		counter = 1;
		while (inputArray[arrayCrawler] == inputArray[arrayCrawler + 1] && arrayCrawler < sizeOfArray - 1) {
			arrayCrawler++;
			counter++;
		}
		if (maxCount < counter) {
			maxCount = counter;
			maxOccuringElement = inputArray[arrayCrawler];
		}
		arrayCrawler++;
	}
	return maxOccuringElement;
}

/**
 * Tested
 */
int MajorityElementON(int inputArray[], int sizeOfArray) {
	hash_map<int, int> frequencyMap;
	hash_map<int, int>::iterator itToFrequencyMap;
	int numberOfOccurence;
	int maxOccuringElement;
	int maxCount = INT_MIN;
	for (int crawler = 0; crawler < sizeOfArray; crawler++) {
		if ((itToFrequencyMap = frequencyMap.find(inputArray[crawler]))!= frequencyMap.end()) {
			numberOfOccurence = itToFrequencyMap->second;
			frequencyMap[inputArray[crawler]] = ++numberOfOccurence;
		} else {
			frequencyMap[inputArray[crawler]] = 1;
			numberOfOccurence = 1;
		}
		if (numberOfOccurence > maxCount) {
			maxCount = numberOfOccurence;
			maxOccuringElement = inputArray[crawler];
		}
	}
	return maxOccuringElement;
}

/**
 * Majority Elements according to geeksforgeeks
 * Majority element is an element which occurs more than
 * n/2 times in an array
 *
 */
/**
 * Tested
 */
int MajorityElementsMooreVotingAlgo(int inputArray[], int sizeOfArray) {
	if (sizeOfArray == 0) {
		return INT_MIN;
	}
	int max_element = inputArray[0], counter = 1;
	int crawler;
	for (crawler = 1; crawler < sizeOfArray; crawler++) {
		if (counter == 0) {
			max_element = inputArray[crawler];
			counter = 1;
		} else {
			if (inputArray[crawler] == max_element) {
				counter++;
			} else {
				counter--;
			}
		}
	}
	int counterOfMaxElements = 0;
	for (crawler = 0; crawler < sizeOfArray; crawler++) {
		if (inputArray[crawler] == max_element) {
			counterOfMaxElements++;
		}
	}
	if (counterOfMaxElements > sizeOfArray / 2) {
		return max_element;
	}
	return INT_MIN;
}

/**
 * Tested
 */
augumentedTNode *GetElementToInsertInBST(augumentedTNode *ptr, int elementValue) {
	if (ptr == NULL) {
		return NULL;
	}
	if (ptr->value == elementValue) {
		return ptr;
	}
	if (ptr->value > elementValue) {
		if (ptr->left == NULL) {
			return ptr;
		}
		return GetElementToInsertInBST(ptr->left, elementValue);
	} else {
		if (ptr->right == NULL) {
			return ptr;
		}
		return GetElementToInsertInBST(ptr->right, elementValue);
	}

}

/**
 * Tested
 */
int MajorityElementBST(int userInput[], int sizeOfArray) {
	if (sizeOfArray == 0) {
		return INT_MIN;
	}
	augumentedTNode *root = (augumentedTNode *) malloc(sizeof(augumentedTNode));
	root->value = userInput[0];
	root->helperVar = 1;
	root->left = NULL;
	root->right = NULL;
	augumentedTNode *newNode;
	for (int crawler = 1; crawler < sizeOfArray; crawler++) {
		newNode = GetElementToInsertInBST(root, userInput[crawler]);
		if (newNode->value == userInput[crawler]) {
			newNode->helperVar++;
			if (newNode->helperVar > sizeOfArray / 2) {
				return newNode->value;
			}
		} else {
			if (newNode->value < userInput[crawler]) {
				newNode->right = (augumentedTNode *) malloc(sizeof(augumentedTNode));
				newNode->right->value = userInput[crawler];
				newNode->right->left = NULL;
				newNode->right->right = NULL;
				newNode->right->helperVar = 1;
			} else {
				newNode->left = (augumentedTNode *) malloc(sizeof(augumentedTNode));
				newNode->left->value = userInput[crawler];
				newNode->left->left = NULL;
				newNode->left->right = NULL;
				newNode->left->helperVar = 1;
			}
		}
	}
	return INT_MIN;

}
#endif /* MAJORITYELEMENT_H_ */
