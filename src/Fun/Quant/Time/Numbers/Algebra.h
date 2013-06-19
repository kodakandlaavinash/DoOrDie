/*
 * Algebra.h
 *
 *  Created on: Jun 19, 2013
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

struct term{
	hash_map<char,int> atoms;
	int coefficient;
};

#define null NULL
#define PRINT_NEW_LINE printf("\n")
//int main(){
//	return -1;
//}

#ifndef ALGEBRA_H_
#define ALGEBRA_H_

vector<term> SimplifyTheAlgebraicEquation(vector<term> algebraicEquation){
	if(algebraicEquation.size() == 0){
		return null;
	}
	set<int> indexesAlreadyVisited;
	vector<term> simplifiedEquation;
	hash_map<char,int> outerEquationAtoms;
	hash_map<char,int> innerEquationAtoms;
	hash_map<char,int>::iterator *itToOuterEquationAtoms;
	hash_map<char,int>::iterator *itToInnerEquationAtoms;
	bool areEqual;
	int outerCounter,innerCounter;
	int coefficientCounter;
	for(outerCounter=0;outerCounter < algebraicEquation.size();outerCounter++){
		coefficientCounter = algebraicEquation[outerCounter].coefficient;
		outerEquationAtoms = algebraicEquation[outerCounter].atoms;
		itToOuterEquationAtoms = outerEquationAtoms.begin();
		areEqual = true;
		for(innerCounter=0;innerCounter < algebraicEquation.size();innerCounter++){
			if(innerCounter == outerCounter){
				continue;
			}
			if(indexesAlreadyVisited.find(innerCounter) != indexesAlreadyVisited.end()){
				continue;
			}
			innerEquationAtoms = algebraicEquation[innerCounter].atoms;

			for(itToInnerEquationAtoms = innerEquationAtoms.begin();itToInnerEquationAtoms != innerEquationAtoms.end();itToInnerEquationAtoms++){
				if((itToOuterEquationAtoms = outerEquationAtoms.find((*itToInnerEquationAtoms)->first)) == outerEquationAtoms.end()){
					areEqual = false;
					break;
				}
				if((*itToOuterEquationAtoms)->first != (*itToInnerEquationAtoms)->first || (*itToOuterEquationAtoms)->second != (*itToInnerEquationAtoms)->second){
					areEqual = false;
					break;
				}
				coefficientCounter += algebraicEquation[innerCounter].coefficient;
			}
			if(areEqual){
				// Already we are checking whether the term is already visited or not
				// So every time we get a new term
				// There is no need to check whether you
				term *newTerm = (term *)malloc(sizeof(term));
				newTerm->atoms = outerEquationAtoms;
				newTerm->coefficient = coefficientCounter;
				indexesAlreadyVisited.insert(innerCounter);

				simplifiedEquation.push_back(newTerm);
			}
		}
	}

	return simplifiedEquation;
}

vector<term> AdditionOfAlgebraicEquation(vector<term> firstAlgebraicEquation,vector<term> secondAlgebraicEquation){
	if(firstAlgebraicEquation.size() == 0 && secondAlgebraicEquation.size() == 0){
		return NULL;
	}
	if(firstAlgebraicEquation.size() == 0||secondAlgebraicEquation.size() == 0){
		if(firstAlgebraicEquation.size() == 0){
			return secondAlgebraicEquation;
		}else{
			return firstAlgebraicEquation;
		}
	}
	firstAlgebraicEquation = SimplifyTheAlgebraicEquation(firstAlgebraicEquation);
	secondAlgebraicEquation = SimplifyTheAlgebraicEquation(secondAlgebraicEquation);

	vector<term> additionResult;
	hash_map<char,int> firstEquationTerms,secondEquationTerms;
	hash_map<char,int> *itToFirstEquation;
	hash_map<char,int> *itToSecondEquation;
	int coefficientCounter = 0;
	bool areEqual = true;
	bool isFound = false;
	for(int counter = 0;counter < firstAlgebraicEquation.size();counter++){
		firstEquationTerms = firstAlgebraicEquation[counter].atoms;
		coefficientCounter = firstAlgebraicEquation[counter].coefficient;
		areEqual = false;
		isFound = false;
		for(int innerCounter =0;innerCounter < secondAlgebraicEquation.size();innerCounter++){
			secondEquationTerms = secondAlgebraicEquation[innerCounter].atoms;
			for(itToSecondEquation = secondEquationTerms.begin();itToSecondEquation != secondEquationTerms.end();itToSecondEquation++){
				if((*itToFirstEquation)->first == (*itToSecondEquation)->first || (*itToFirstEquation)->second == (*itToSecondEquation)->second){
					coefficientCounter += secondAlgebraicEquation[innerCounter].coefficient;
					areEqual = true;
					break;
				}
			}
			if(areEqual){
				break;
			}
		}
		term *newTerm = (term *)malloc(sizeof(term));
		newTerm->atoms = firstEquationTerms;
		if(areEqual){
			newTerm->coefficient = coefficientCounter;
		}else{
			newTerm->coefficient = firstAlgebraicEquation[0].coefficient;
		}
		additionResult.push_back(newTerm);
	}
	return additionResult;
}

vector<term> SubstractionOfAlgebraicEquation(vector<term> firstAlgebraicEquation,vector<term> secondAlgebraicEquation){
	if(firstAlgebraicEquation.size() == 0 && secondAlgebraicEquation.size() == 0){
		return NULL;
	}
	if(firstAlgebraicEquation.size() == 0||secondAlgebraicEquation.size() == 0){
		if(firstAlgebraicEquation.size() == 0){
			for(int counter = 0;counter < secondAlgebraicEquation.size();secondAlgebraicEquation++){
				secondAlgebraicEquation[counter].coefficient *= -1;
			}
			return secondAlgebraicEquation;
		}else{
			return firstAlgebraicEquation;
		}
	}
	firstAlgebraicEquation = SimplifyTheAlgebraicEquation(firstAlgebraicEquation);
	secondAlgebraicEquation = SimplifyTheAlgebraicEquation(secondAlgebraicEquation);

	vector<term> subtractionResult;
	hash_map<char,int> firstEquationTerms,secondEquationTerms;
	hash_map<char,int> *itToFirstEquation;
	hash_map<char,int> *itToSecondEquation;
	int coefficientCounter = 0;
	bool areEqual = true;
	bool isFound = false;
	for(int counter = 0;counter < firstAlgebraicEquation.size();counter++){
		firstEquationTerms = firstAlgebraicEquation[counter].atoms;
		coefficientCounter = firstAlgebraicEquation[counter].coefficient;
		areEqual = false;
		isFound = false;
		for(int innerCounter =0;innerCounter < secondAlgebraicEquation.size();innerCounter++){
			secondEquationTerms = secondAlgebraicEquation[innerCounter].atoms;
			for(itToSecondEquation = secondEquationTerms.begin();itToSecondEquation != secondEquationTerms.end();itToSecondEquation++){
				if((*itToFirstEquation)->first == (*itToSecondEquation)->first || (*itToFirstEquation)->second == (*itToSecondEquation)->second){
					coefficientCounter -= algebraicEquation[innerCounter].coefficient;
					areEqual = true;
					break;
				}
			}
			if(areEqual){
				break;
			}
		}
		term *newTerm = (term *)malloc(sizeof(term));
		newTerm->atoms = firstEquationTerms;
		if(areEqual){
			newTerm->coefficient = coefficientCounter;
		}else{
			newTerm->coefficient = firstAlgebraicEquation[0].coefficient;
		}
		subtractionResult.push_back(newTerm);
	}

	return subtractionResult;
}

vector<term> MultiplicationOfAlgebraicEquation(vector<term> firstAlgebraicEquation,vector<term> secondAlgebraicEquation){
	if(firstAlgebraicEquation.size() == 0 || secondAlgebraicEquation.size() == 0){
		return null;
	}

	firstAlgebraicEquation = SimplifyTheAlgebraicEquation(firstAlgebraicEquation);
	secondAlgebraicEquation = SimplifyTheAlgebraicEquation(secondAlgebraicEquation);

	vector<term> multiplicationResult;
	hash_map<char,int> firstEquationTerms;
	hash_map<char,int> secondEquationTerms;
	hash_map<char,int>::iterator *itToFirstEquationTerms;
	hash_map<char,int>::iterator *itToSecondEquationTerms;

	for(int firstEquationCounter =0;firstEquationCounter < firstAlgebraicEquation.size();firstEquationCounter++){
		firstAlgebraicEquation = firstAlgebraicEquation[firstEquationCounter].atoms;
		itToFirstEquationTerms = firstAlgebraicEquation.begin();
		for(int secondEquationCounter =0;secondEquationCounter < secondAlgebraicEquation.size();secondEquationCounter++){
			secondEquationTerms = secondAlgebraicEquation[secondEquationCounter].atoms;
			term *newTerm = (term *)malloc(sizeof(term));
			hash_map<char,int> multiplicationTermAtoms;
			for(itToSecondEquationTerms = secondEquationTerms.begin();itToSecondEquationTerms != secondEquationTerms.end();itToSecondEquationTerms++){
				if((itToFirstEquationTerms = firstEquationTerms.find((*itToSecondEquationTerms)->first))!= firstAlgebraicEquation.end()){
					multiplicationTermAtoms.insert(pair<char,int>((*itToFirstEquationTerms)->first,((*itToFirstEquationTerms)->second + (*itToSecondEquationTerms)->second)));
				}else{
					multiplicationTermAtoms.insert(pair<char,int>((*itToFirstEquationTerms)->first,(*itToFirstEquationTerms)->second));
				}
			}

			newTerm->atoms = multiplicationTermAtoms;
			newTerm->coefficient = firstAlgebraicEquation[firstEquationCounter].coefficient * secondAlgebraicEquation[secondEquationCounter].coefficient;
			multiplicationResult.push_back(newTerm);
		}
	}
	multiplicationResult = SimplifyTheAlgebraicEquation(multiplicationResult);
	return multiplicationResult;
}
#endif

