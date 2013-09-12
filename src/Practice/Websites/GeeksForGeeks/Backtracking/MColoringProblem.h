/*
 * MColoringProblem.h
 *
 *  Created on: Sep 5, 2013
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

#ifndef MCOLORINGPROBLEM_H_
#define MCOLORINGPROBLEM_H_

#define MAX_VERTICES_M_COLORING_PROBLEM 10

bool MColoringProblemByGeneratingAllConfigs(int userInputGraph[MAX_VERTICES_M_COLORING_PROBLEM][MAX_VERTICES_M_COLORING_PROBLEM],int totalNoOfVertices,int mColors,int currentVertex,int colours[]){
	if(userInputGraph == NULL || totalNoOfVertices == 0){
		return true;
	}
	if(currentVertex == totalNoOfVertices){
		for(int outerCounter=0;outerCounter < totalNoOfVertices;outerCounter++){
			for(int innerCounter =0;innerCounter < totalNoOfVertices;innerCounter++){
				if(userInputGraph[outerCounter][innerCounter] == 1){
					if(colours[outerCounter] == colours[innerCounter]){
						return false;
					}
				}
			}
		}
		return true;
	}
	for(int colorCounter = 0;colorCounter < mColors;colorCounter++){
		colours[currentVertex] = colorCounter;
		if(MColoringProblemByGeneratingAllConfigs(userInputGraph,totalNoOfVertices,mColors,currentVertex+1,colours)){
			return true;
		}
	}
	return false;
}

bool IsAValidConfiguration(int userInputGraph[MAX_VERTICES_M_COLORING_PROBLEM][],int totalNoOfVertices,int currentVertex,int color){
	if(userInputGraph == NULL || totalNoOfVertices == 0){
		return true;
	}
	for(int vertexCounter = 0;vertexCounter < totalNoOfVertices;vertexCounter++){
		if(userInputGraph[currentVertex][vertexCounter] == 1){
			if(color[vertexCounter] == color){
				return false;
			}
		}
	}
	return true;
}

bool MColoringProblem(int userInputGraph[MAX_VERTICES_M_COLORING_PROBLEM][],int totalNoOfVertices,int currentVertex,int mColors,int colors){
	if(userInputGraph == NULL || totalNoOfVertices == 0){
		return true;
	}
	if(currentVertex == totalNoOfVertices-1){
		return true;
	}
	for(int colorCounter = 1;colorCounter <= mColors;colorCounter++){
		if(IsAValidConfiguration(userInputGraph,totalNoOfVertices,currentVertex,colorCounter)){
			colors[currentVertex] = colorCounter;
			if(MColoringProblem(userInputGraph,totalNoOfVertices,currentVertex+1,mColors,colors)){
				return true;
			}
			colorCounter[currentVertex] = 0;
		}
	}
	return false;
}

#endif /* MCOLORINGPROBLEM_H_ */
