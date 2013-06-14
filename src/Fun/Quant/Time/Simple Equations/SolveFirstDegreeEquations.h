/*
 * SolveFirstDegreeEquations.h
 *
 *  Created on: June 14, 2013
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

#ifndef SOLVEFIRSTDEGREEEQUATIONS_H_
#define SOLVEFIRSTDEGREEEQUATIONS_H_

struct firstDegreeEquation{
	int coefficientOfX;
	int coefficientOfY;
	int constant;
};

struct firstDegreeEquationThreeUnknowns{
	int coefficientOfX;
	int coefficientOfY;
	int coefficientOfZ;
	int constant;
};

int *FindRootsForTheFirstDegreeEquationOfTwoUnknowns(firstDegreeEquation *firstEquation,firstDegreeEquation *secondEquation){
	if(firstEquation == NULL || secondEquation == NULL){
		return NULL;
	}

	// elliminate the first variable
	int lcmOfCoefficients;
	int multiplyFirstEquation;
	int multiplySecondEquation;
	lcmOfCoefficients = FindLCMOfTwoNumbers(firstEquation->coefficientOfX < 0?-1*firstEquation->coefficientOfX:firstEquation->coefficientOfX,secondEquation->coefficientOfX < 0 ? -1 * secondEquation->coefficientOfX:secondEquation->coefficientOfX);
	if(firstEquation->coefficientOfX * secondEquation->coefficientOfX < 0){
		//They have different signs
		multiplyFirstEquation = (lcmOfCoefficients)/firstEquation->coefficientOfX;
		multiplySecondEquation = -1 * (lcmOfCoefficients)/secondEquation->coefficientOfX;
	}else{
		//They have same signs
		multiplyFirstEquation = (lcmOfCoefficients)/firstEquation->coefficientOfX;
		multiplySecondEquation = (lcmOfCoefficients)/secondEquation->coefficientOfX;
	}

	//Multiplying the equations
	firstEquation->coefficientOfX *= multiplyFirstEquation;
	firstEquation->coefficientOfY *= multiplyFirstEquation;
	firstEquation->constant *= multiplyFirstEquation;

	secondEquation->coefficientOfX *= multiplySecondEquation;
	secondEquation->coefficientOfY *= multiplySecondEquation;
	secondEquation->constant *= multiplySecondEquation;

	if(firstEquation->coefficientOfX != secondEquation->coefficientOfX){
		printf("Oops something went wrong");
		return;
	}

	firstDegreeEquation *resultingEquation = (firstDegreeEquation *)malloc(sizeof(firstDegreeEquation));
	resultingEquation->coefficientOfX = firstEquation->coefficientOfX - secondEquation->coefficientOfX;
	resultingEquation->coefficientOfY = firstEquation->coefficientOfY - secondEquation->coefficientOfY;
	resultingEquation->constant = firstEquation->constant - secondEquation->constant;

	int rootXY[2];
	rootXY[1] = (resultingEquation->constant)/(resultingEquation->coefficientOfY);
	rootXY[0] = (firstEquation->constant - firstEquation->coefficientOfY * rootXY[1])/firstEquation->coefficientOfX;

	return rootXY;
}

int *SolveFirstDegreeEquationWithTwoUnknownsMatrix(firstDegreeEquation *firstEquation,firstDegreeEquation *secondEquation){
	if(firstEquation == NULL || secondEquation == NULL){
		return NULL;
	}

	int matrixOfCoefficients[2][2];
	int constantMatrix[2][1];

	/**
	 * Coefficient Matrix
	 */
	matrixOfCoefficients[0][0] = firstEquation->coefficientOfX;
	matrixOfCoefficients[0][1] = firstEquation->coefficientOfY;
	matrixOfCoefficients[1][0] = secondEquation->coefficientOfX;
	matrixOfCoefficients[1][1] = secondEquation->coefficientOfY;

	/**
	 * Constant Matrix
	 */
	constantMatrix[0][0] = firstEquation->constant;
	constantMatrix[1][0] = secondEquation->constant;

	int lcmOfXCoefficients = FindLCMOfTwoNumbers(matrixOfCoefficients[0][0] < 0? -1 * matrixOfCoefficients[0][0] : matrixOfCoefficients[0][0],matrixOfCoefficients[1][0] < 0?-1*matrixOfCoefficients[1][0]:matrixOfCoefficients[1][0]);
	int multiplyFirstRow,multiplySecondRow;
	multiplyFirstRow = lcmOfXCoefficients/matrixOfCoefficients[0][0];
	multiplySecondRow = lcmOfXCoefficients/matrixOfCoefficients[1][0];
	if(matrixOfCoefficients[0][0] * matrixOfCoefficients[1][0] < 0){
		//They have different signs
		multiplySecondRow *= -1;
	}

	matrixOfCoefficients[0][0] *= multiplyFirstRow;
	matrixOfCoefficients[0][1] *= multiplyFirstRow;
	matrixOfCoefficients[1][0] *= multiplySecondRow;
	matrixOfCoefficients[1][1] *= multiplySecondRow;

	constantMatrix[0] *= multiplyFirstRow;
	constantMatrix[1] *= multiplySecondRow;

}

firstDegreeEquationThreeUnknowns *ElliminateOneVariable(firstDegreeEquationThreeUnknowns *firstEquation,firstDegreeEquationThreeUnknowns *secondEquation,int elliminateVariable){
	if(firstEquation == NULL || secondEquation == NULL){
		return NULL;
	}
	if(elliminateVariable != 1||elliminateVariable != 2||elliminateVariable != 3){
		return NULL;
	}


}


int *SolveFirstDegreeEquationsWithThreeUnknows(firstDegreeEquationThreeUnknowns *firstEquation,firstDegreeEquationThreeUnknowns *secondEquation,firstDegreeEquationThreeUnknowns *thirdEquation){
	if(firstEquation == NULL || secondEquation == NULL || thirdEquation == NULL){
		return NULL;
	}

	int lcmHelperVariable,multiplicationFactorForFirstEquation,multiplicationFactorForSecondEquation,multiplicationFactorForThirdEquation;
	lcmHelperVariable = FindLCMOfTwoNumbers(firstEquation->coefficientOfX,secondEquation->coefficientOfX);

	multiplicationFactorForFirstEquation = lcmHelperVariable/firstEquation->coefficientOfX;
	multiplicationFactorForSecondEquation = lcmHelperVariable/secondEquation->coefficientOfX;

	if(firstEquation->coefficientOfX * secondEquation->coefficientOfX < 0){
		multiplicationFactorForSecondEquation *= -1;
	}

	firstEquation->coefficientOfX *= multiplicationFactorForFirstEquation;
	secondEquation->coefficientOfX *= multiplicationFactorForSecondEquation;

	firstEquation->coefficientOfY *= multiplicationFactorForFirstEquation;
	secondEquation->coefficientOfY *= multiplicationFactorForSecondEquation;

	firstEquation->coefficientOfZ*= multiplicationFactorForFirstEquation;
	secondEquation->coefficientOfZ *= multiplicationFactorForSecondEquation;

	firstEquation->constant *= multiplicationFactorForFirstEquation;
	secondEquation->constant *= multiplicationFactorForSecondEquation;

	firstDegreeEquationThreeUnknowns *equationWithXElliminated = (firstDegreeEquationThreeUnknowns *)malloc(sizeof(firstDegreeEquationThreeUnknowns));
	equationWithXElliminated->coefficientOfX = firstEquation->coefficientOfX - secondEquation->coefficientOfX;
	equationWithXElliminated->coefficientOfY = firstEquation->coefficientOfY - secondEquation->coefficientOfY;
	equationWithXElliminated->coefficientOfZ = firstEquation->coefficientOfZ - secondEquation->coefficientOfZ;
	equationWithXElliminated->constant = firstEquation->constant - secondEquation->constant;


}



#endif /* SOLVEFIRSTDEGREEEQUATIONS_H_ */
