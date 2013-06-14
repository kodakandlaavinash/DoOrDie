/*
 * Trie.h
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

#ifndef TRIE_H_
#define TRIE_H_

struct trieNode;


struct trieNode{
	bool truthValue[26] = {false};
	trieNode *alphabets[26] = {NULL};
};

trieNode *BuildTrieForUserInputStrings(vector<string> userInput){
	if(userInput.size() == 0){
		return null;
	}
	trieNode *root = null;
	string userInputAtomString;
	int index;
	trieNode *trieCrawler;
	for(int crawler =0;crawler < userInput.size();crawler++){
		userInputAtomString = userInput[crawler];
		for(int stringCrawler = 0;stringCrawler < userInputAtomString.length();stringCrawler){
			if('a' >= userInputAtomString[stringCrawler] && userInputAtomString[stringCrawler] <= 'z'){
				index = userInputAtomString[stringCrawler] - 'a';
			}else{
				if('A' >= userInputAtomString[stringCrawler] && userInputAtomString[stringCrawler] <= 'Z'){
					index = userInputAtomString[stringCrawler] - 'z';
				}else{
					return NULL;
				}
			}

			if(trieCrawler->truthValue[index] != true){
				trieCrawler = trieCrawler->alphabets[index];
			}else{

			}
		}
	}

}

#endif /* TRIE_H_ */
