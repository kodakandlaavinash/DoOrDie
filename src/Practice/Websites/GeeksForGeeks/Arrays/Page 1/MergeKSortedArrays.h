/*
 * MergeKSortedArrays.h
 *
 *  Created on: Aug 22, 2013
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

#ifndef MERGEKSORTEDARRAYS_H_
#define MERGEKSORTEDARRAYS_H_

vector<int> MergeKSortedArraysNaive(vector<vector<int>> sortedArrays){
	if(sortedArrays.size() == 0){
		return;
	}
	vector<int> mergedArray;
	for(int arrayCounter = 0;arrayCounter < sortedArrays.size();arrayCounter++){
		for(int individualVectorCounter = 0;individualVectorCounter < sortedArrays[arrayCounter].size();individualVectorCounter++){
			mergedArray.push_back(sortedArrays[arrayCounter][individualVectorCounter]);
		}
	}
	sort(mergedArray.begin(),mergedArray.end());
	return mergedArray;
}

vector<int> MergeKSortedArrayON(vector<vector<int>> sortedArrays){
	if(sortedArrays.size() == 0){
		return;
	}
	vector<int> mergedArray;
	vector<int> countersForIndividualArrays;
	for(int counter = 0;counter <sortedArrays.size();counter++){
		countersForIndividualArrays.push_back(0);
	}
	int totalNoOfElements = 0;
	for(int counter =0;counter < sortedArrays.size();counter++){
		totalNoOfElements += sortedArrays[counter].size();
	}
	int minElement,minElementVector;
	for(int counter = 0;counter < totalNoOfElements;counter++){
		minElement = INT_MAX;
		for(int flagCounter =0;flagCounter < countersForIndividualArrays.size();flagCounter++){
			if(countersForIndividualArrays[flagCounter] < sortedArrays[counter].size()){
				continue;
			}
			if(minElement > sortedArrays[counter][countersForIndividualArrays[flagCounter]]){
				minElement = sortedArrays[counter][countersForIndividualArrays[flagCounter]];
				minElementVector = flagCounter;
			}
		}
		mergedArray.push_back(minElement);
		countersForIndividualArrays[minElementVector]++;
	}
}

vector<int> MergeKSortedArraysBinarySearchTres(vector<vector<int>> sortedArrays){

}

#endif /* MERGEKSORTEDARRAYS_H_ */
