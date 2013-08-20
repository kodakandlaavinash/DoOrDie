/*
 * DifferenceBetweenOddAndEvenSumLevel.h
 *
 *  Created on: Aug 20, 2013
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

#ifndef DIFFERENCEBETWEENODDANDEVENSUMLEVEL_H_
#define DIFFERENCEBETWEENODDANDEVENSUMLEVEL_H_

int DifferenceBetweenOddAndEvenSumTopToBottom(tNode *ptr,int level,int &sumAtOddLevel,int &sumAtEvenLevel){
	if(ptr == NULL){
		return INT_MIN;
	}
	if(level%2 == 1){
		sumAtOddLevel += ptr->value;
	}else{
		sumAtEvenLevel += ptr->value;
	}
	//No need to catch the result
	DifferenceBetweenOddAndEvenSum(ptr->left,level+1,sumAtOddLevel,sumAtEvenLevel);
	DifferenceBetweenOddAndEvenSum(ptr->right,level+1,sumAtOddLevel,sumAtEvenLevel);
	return abs(sumAtEvenLevel - sumAtOddLevel);
}

int DifferenceBetweenOddAndEvenSumLevelWithAuxSpace(tNode *ptr){
	if(ptr == NULL){
		return INT_MIN;
	}
	queue<int> oddAuxSpace,evenAuxSpace;
	oddAuxSpace.push(ptr);
	bool isOddLevel = true;
	int oddSum = 0,evenSum = 0;
	tNode *currentNode;
	while(!oddAuxSpace.empty() || !evenAuxSpace.empty()){
		if(isOddLevel){
			while(!oddAuxSpace.empty()){
				currentNode = oddAuxSpace.front();
				oddAuxSpace.pop();
				oddSum += currentNode->value;
				if(currentNode->left != NULL){
					evenAuxSpace.push(currentNode->left);
				}
				if(currentNode->right != NULL){
					evenAuxSpace.push(currentNode->right);
				}
			}
		}else{
			while(!evenAuxSpace.empty()){
				currentNode = evenAuxSpace.front();
				evenAuxSpace.pop();
				evenSum += currentNode->value;
				if(currentNode->left != NULL){
					oddAuxSpace.push(currentNode->left);
				}
				if(currentNode->right != NULL){
					evenAuxSpace.push(currentNode->left);
				}
			}
		}
	}
	return abs(oddSum - evenSum);
}

#endif /* DIFFERENCEBETWEENODDANDEVENSUMLEVEL_H_ */
