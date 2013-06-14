/*
 * UnorderedDictionary.h
 *
 *  Created on: May 27, 2013
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

#ifndef UNORDEREDDICTIONARY_H_
#define UNORDEREDDICTIONARY_H_

class UnorderedDictionary {
private:
	int size = 1000;
	int dictionary[size];
	int tail = 0;
public:
	UnorderedDictionary();
	void addKeyToDictionary(int key);
	void deleteKeyFromDictionary(int key);
	int searchKeyFromDictionary(int key);
	bool doesKeyExistsInDictionary(int key);
	virtual ~UnorderedDictionary();
};

#endif /* UNORDEREDDICTIONARY_H_ */
