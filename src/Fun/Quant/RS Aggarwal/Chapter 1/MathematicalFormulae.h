/*
 * MathematicalFormulae.h
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

#ifndef MATHEMATICALFORMULAE_H_
#define MATHEMATICALFORMULAE_H_

int APlusBWholeSquare(int a,int b){
	return ((a^2)+ (2*a*b)+(b^2));
}

int AMinusBWholeSquare(int a,int b){
	return ((a^2)-(2*a*b)+(b^2));
}

int ACubePlusBCube(int a,int b){
	return ((a+b)*((a^2)-(a*b)+(b^2)));
}

int ACubeMinusBCube(int a,int b){
	return ((a-b)*((a^2)+(a*b)+(b^2)));
}

int APlusBPlusCWholeCube(int a,int b,int c){
	return((a+b+c)*((a^2)+(b^2)+(c^2)+2((a*b)+(b*c)+(c*a))));
}

int APlusBWholeSquarePlusAMinusBWholeSquare(int a,int b){
	return (2*((a^2)+(b^2)));
}

int APlusBWholeSquareMinusAMinusBWholeSquare(int a,int b){
	return 4 * a * b;
}

int ACubePlusBCubePlusCCubeMinus3ABC(int a,int b,int c){
	return ((a+b+c)*((a^2)+(b^2)+(c^2)-(a*b)-(b*c)-(c*a)));
}
#endif /* MATHEMATICALFORMULAE_H_ */
