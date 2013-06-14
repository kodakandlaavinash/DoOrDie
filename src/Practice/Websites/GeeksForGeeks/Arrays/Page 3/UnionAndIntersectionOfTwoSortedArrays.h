/*
 * UnionAndIntersectionOfTwoSortedArrays.h
 *
 *  Created on: May 15, 2013
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

#ifndef UNIONANDINTERSECTIONOFTWOSORTEDARRAYS_H_
#define UNIONANDINTERSECTIONOFTWOSORTEDARRAYS_H_

vector<int> *UnionIntersectionOfTwoSortedArrays(int sortedArray1[],int sizeOfArray1,int sortedArray2[],int sizeOfArray2){
	if(sizeOfArray1 == 0 && sizeOfArray2 == 0){
		return NULL;
	}
	vector<int> unionAndIntersection[2];
	vector<int> unionOfSortedArrays;

	if(sizeOfArray1 == 0||sizeOfArray2 == 0){
		if(sizeOfArray1 != 0){
			for(int crawler =0;crawler < sizeOfArray1;crawler++){
				unionOfSortedArrays.push_back(sortedArray1[crawler]);
			}
		}else{
			for(int crawler =0;crawler < sizeOfArray1;crawler++){
				unionOfSortedArrays.push_back(sortedArray1[crawler]);
			}
		}
		unionAndIntersection[0] = unionOfSortedArrays;
		return unionAndIntersection;
	}

	vector<int> intersectionOfSortedArrays;

	int crawlerSortedArray1=0,crawlerSortedArray2=0;
	while(crawlerSortedArray1 < sizeOfArray1 && crawlerSortedArray2 < sizeOfArray2){
		if(sortedArray1[crawlerSortedArray1] == sortedArray2[crawlerSortedArray2]){
			intersectionOfSortedArrays.push_back(sortedArray1[crawlerSortedArray1]);
			unionOfSortedArrays.push_back(sortedArray1[crawlerSortedArray1]);
			crawlerSortedArray1++;
			crawlerSortedArray2++;
		}else{
			if(sortedArray1[crawlerSortedArray1] > sortedArray2[crawlerSortedArray2]){
				unionOfSortedArrays.push_back(sortedArray2[crawlerSortedArray2]);
				crawlerSortedArray2++;
			}else{
				unionOfSortedArrays.push_back(sortedArray1[crawlerSortedArray1]);
				crawlerSortedArray1++;
			}
		}
	}

	unionAndIntersection[0] = unionOfSortedArrays;
	unionAndIntersection[1] = intersectionOfSortedArrays;
}

vector<int> *UnionIntersectionOfSortedArraysHashMap(int sortedArray1[],int sizeOfArray1,int sortedArray2[],int sizeOfArray2){
	if(sizeOfArray1 == 0 && sizeOfArray2 == 0){
		return NULL;
	}
	vector<int> unionAndIntersection[2];
	hash_map<int,int> frequencyMap;
	hash_map<int,int>::iterator itToFrequencyMap;
	int crawler;
	for(crawler =0 ;crawler < sizeOfArray1;crawler++){
		if((itToFrequencyMap = frequencyMap.find(sortedArray1[crawler])) != frequencyMap.end()){
			frequencyMap[sortedArray1[crawler]]++;
		}else{
			frequencyMap.insert(pair<int,int>(sortedArray1[crawler],1));
		}
	}

	for(crawler =0 ;crawler < sizeOfArray2;crawler++){
		if((itToFrequencyMap = frequencyMap.find(sortedArray2[crawler])) != frequencyMap.end()){
			frequencyMap[sortedArray2[crawler]]++;
		}else{
			frequencyMap.insert(pair<int,int>(sortedArray2[crawler],1));
		}
	}

	for(itToFrequencyMap = frequencyMap.begin();itToFrequencyMap != frequencyMap.end();itToFrequencyMap++){
		if(itToFrequencyMap->second > 1 ){
			unionAndIntersection[0].push_back(itToFrequencyMap->first);
			unionAndIntersection[1].push_back(itToFrequencyMap->first);
		}else{
			unionAndIntersection[0].push_back(itToFrequencyMap->first);
		}
	}

	return unionAndIntersection;
}


vector<int> *UnionAndIntersectionONLOGN(int sortedArray1[],int sizeOfSortedArray1,int sortedArray2[],int sizeOfSortedArray2){

}

#endif /* UNIONANDINTERSECTIONOFTWOSORTEDARRAYS_H_ */
