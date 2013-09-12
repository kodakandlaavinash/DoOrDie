/*
 * 	ELPHANT.h
 *	http://www.codechef.com/problems/ELPHANT
 *  Created on: Sep 10, 2013
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

#ifndef ELPHANT_H_
#define ELPHANT_H_

/**
 * Tested
 */
int TotalNumberOfCameras(vector<int> mapOfElephantAndItsPosition,int segmentLength){
	if(mapOfElephantAndItsPosition.size() == 0){
		return 0;
	}
	sort(mapOfElephantAndItsPosition.begin(),mapOfElephantAndItsPosition.end());
	int lastCameraPosition = mapOfElephantAndItsPosition[0];
	int totalCameras = 1;
	for(unsigned int counter =0;counter < mapOfElephantAndItsPosition.size();counter++){
		if(mapOfElephantAndItsPosition[counter] > lastCameraPosition+segmentLength){
			totalCameras += 1;
			lastCameraPosition = mapOfElephantAndItsPosition[counter];
		}
	}
	return totalCameras;
}

int main(){
	int noOfElephants,segmentLength,noOfActs;
	scanf("%d",&noOfElephants);
	scanf("%d",&segmentLength);
	scanf("%d",&noOfActs);
	//initial positions
	vector<int> mapOfElephantsAndPositions(noOfElephants);
	int position;
	for(int counter = 0;counter < noOfElephants;counter++){
		scanf("%d",&position);
		mapOfElephantsAndPositions[counter] = position;
	}
	int changedElephant,elephantMovedIndex;
	while(noOfActs--){
		scanf("%d%d",&changedElephant,&elephantMovedIndex);
		mapOfElephantsAndPositions[changedElephant] = elephantMovedIndex;
		printf("%d\n",TotalNumberOfCameras(mapOfElephantsAndPositions,segmentLength));
	}
}

#endif /* ELPHANT_H_ */
