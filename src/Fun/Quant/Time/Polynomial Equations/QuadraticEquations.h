/*
 * QuadraticEquations.h
 *
 *  Created on: Jun 10, 2013
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

#ifndef QUADRATICEQUATIONS_H_
#define QUADRATICEQUATIONS_H_

struct quadraticEquation{
	int x2CoEfficient;
	int xCoEfficient;
	int constant;
};

struct complexRoots{
	int realPart;
	int imaginaryPart;
};

int sumOfRootsOfQuadraticEquation(quadraticEquation *userInput){
	return -1 * (userInput->xCoEfficient)/(userInput->x2CoEfficient);
}

int productOfRootsOfQuadraticEquation(quadraticEquation *userInput){
	return (userInput->constant)/(userInput->x2CoEfficient);
}

quadraticEquation *ConstructQuadraticEquationBasedOnRoots(int firstRoot,int secondRoot){
	quadraticEquation *newEquation = (quadraticEquation *)malloc(sizeof(quadraticEquation));
	newEquation->x2CoEfficient = 1;
	newEquation->xCoEfficient = -1 * (firstRoot + secondRoot);
	newEquation->constant = (firstRoot*secondRoot);
	return newEquation;
}

complexRoots *FindRootsOfQuadraticEquation(quadraticEquation *userInput){
	double discriminent = (pow(userInput->xCoEfficient,2) - (4 * userInput->x2CoEfficient * userInput->constant));
	complexRoots rootsOfQuadraticEquation[2];
	if(discriminent == 0){
		rootsOfQuadraticEquation[0].realPart = ((- userInput->xCoEfficient)/(2*userInput->xCoEfficient));
		rootsOfQuadraticEquation[0].imaginaryPart = 0;
		rootsOfQuadraticEquation[1].realPart = rootsOfQuadraticEquation[0].realPart;
		rootsOfQuadraticEquation[1].imaginaryPart = 0;
	}else{
		if(discriminent > 0){
			rootsOfQuadraticEquation[0].realPart = ((-1 * userInput->xCoEfficient) + sqrt(discriminent))/(2 * userInput->x2CoEfficient);
			rootsOfQuadraticEquation[0].imaginaryPart = 0;
			rootsOfQuadraticEquation[1].realPart = ((-1 * userInput->xCoEfficient) - sqrt(discriminent))/(2 * userInput->x2CoEfficient);
			rootsOfQuadraticEquation[1].imaginaryPart = 0;
		}else{
			rootsOfQuadraticEquation[0].realPart = ((-1 * userInput->xCoEfficient)/(2*userInput->x2CoEfficient));
			rootsOfQuadraticEquation[0].imaginaryPart = sqrt(-1 * discriminent)/(2*userInput->x2CoEfficient);
			rootsOfQuadraticEquation[1].realPart = ((-1 * userInput->xCoEfficient)/(2*userInput->x2CoEfficient));
			rootsOfQuadraticEquation[1].imaginaryPart = -1 * rootsOfQuadraticEquation[0].imaginaryPart;
		}
	}
	return rootsOfQuadraticEquation;
}

/**
 * 0 - roots are equal
 * 1 - real and distinct
 * 2 - complex roots
 */
int FindNatureOfRootsOfQuadraticEquation(quadraticEquation *userInput){
	double discriminent;
	discriminent = ((pow(userInput->xCoEfficient,2)) - (4 * userInput->x2CoEfficient * userInput->constant));
	if(discriminent == 0){
		return 0;
	}else{
		if(discriminent > 0){
			return 1;
		}else{
			return 2;
		}
	}
}

int *FindMaxMinValueOfQuadraticEquation(quadraticEquation *userInput){
	double discriminent;
	discriminent = ((pow(userInput->xCoEfficient,2)) - (4 * userInput->x2CoEfficient * userInput->constant));
	discriminent *= -1;
	int minMax[2];
	if(userInput->x2CoEfficient > 0){
		minMax[0] = discriminent/(4 * userInput->x2CoEfficient);
		minMax[1] = INT_MAX;
	}else{
		minMax[0] = INT_MIN;
		minMax[1] = discriminent/(4 * userInput->x2CoEfficient);
	}
	return minMax;
}

quadraticEquation *GetNewQuadraticEquatioByIncreaseInRootsByK(quadraticEquation *userInput,int k){
	if(k == 0){
		return userInput;
	}
	if(k < 0){
		return GetNewQuadraticEquationByDecreaseInRootsByK(userInput,-1*k);
	}
	quadraticEquation *newEquation = (quadraticEquation)malloc(sizeof(quadraticEquation));
	newEquation->x2CoEfficient = userInput->x2CoEfficient;
	newEquation->xCoEfficient = (userInput->xCoEfficient-(2*userInput->x2CoEfficient*k));
	newEquation->constant = ((userInput->x2CoEfficient * pow(k,2)) - (userInput->xCoEfficient * k) + userInput->constant);

	return newEquation;
}

quadraticEquation *GetNewQuadraticEquationByDecreaseInRootsByK(quadraticEquation *userInput,int k){
	if(k == 0){
		return userInput;
	}
	if(k < 0){
		return GetNewQuadraticEquatioByIncreaseInRootsByK(userInput, -1 * k);
	}
	quadraticEquation *newEquation = (quadraticEquation)malloc(sizeof(quadraticEquation));
	newEquation->x2CoEfficient = userInput->x2CoEfficient;
	newEquation->xCoEfficient = (userInput->xCoEfficient + (2*userInput->x2CoEfficient*k));
	newEquation->constant = ((userInput->x2CoEfficient * pow(k,2))+ (userInput->xCoEfficient * k) + userInput->constant);
	return newEquation;
}

quadraticEquation *GetNewQuadraticEquationByKTimesRoots(quadraticEquation *userInput,int k){
	if(k==0){
		return NULL;
	}
	if(k == 1){
		return userInput;
	}
	if(k>0 && k<1){
		return GetNewQuadraticEquationBy1ByKTimesRoots(userInput,1/k);
	}
	quadraticEquation *newEquation = (quadraticEquation)malloc(sizeof(quadraticEquation));
	newEquation->x2CoEfficient = (userInput->x2CoEfficient / (pow(k,2)));
	newEquation->xCoEfficient = (userInput->xCoEfficient/k);
	newEquation->constant = userInput->constant;
	return newEquation;
}

quadraticEquation *GetNewQuadraticEquationBy1ByKTimesRoots(quadraticEquation *userInput,int k){
	if(k == 0){
		return NULL;
	}
	if(k == 1){
		return userInput;
	}
	if(k > 0 && k < 1){
		return GetNewQuadraticEquationByKTimesRoots(userInput,1/k);
	}
	quadraticEquation *newEquation = (quadraticEquation)malloc(sizeof(quadraticEquation));
	newEquation->x2CoEfficient = (pow(k,2) * userInput->x2CoEfficient);
	newEquation->xCoEfficient = (k * userInput->xCoEfficient);
	newEquation->constant = userInput->constant;
	return newEquation;
}



#endif /* QUADRATICEQUATIONS_H_ */
