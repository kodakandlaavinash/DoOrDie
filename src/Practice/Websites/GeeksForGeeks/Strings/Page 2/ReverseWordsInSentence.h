/*
 * ReverseWordsInSentence.h
 *
 *  Created on: Apr 30, 2013
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

#ifndef REVERSEWORDSINSENTENCE_H_
#define REVERSEWORDSINSENTENCE_H_

void ReverseWordsInSentence(char *userInput){
	if(userInput == NULL){
		return;
	}
}

void ReverseWordsInSentenceUsingTwoStacks(char *userInput){
	if(userInput == NULL){
		return;
	}

	stack<char> firstStack;
	stack<char> secondStack;
	char *crawler;
	char ch = *crawler;
	while(1){
		while(ch != " "|| ch != '\0'){
			firstStack.push(ch);
		}

		if(ch == " "){
			while(!firstStack.empty()){
				secondStack.push(firstStack.top());
				firstStack.pop();
			}
			secondStack.push(" ");
		}else{
			while(!firstStack.empty()){
				secondStack.push(firstStack.top());
				firstStack.pop();
			}
			break;
		}
	}
}

#endif /* REVERSEWORDSINSENTENCE_H_ */
