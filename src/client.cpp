/*
**File: client.cpp
**test programming assignment #1 for CPSC 4100
**Author: Yingwu Zhu
**Last Modification: 10/05/2018
**/
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include "pa1.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Format : " << argv[0] << " [input file]" << endl;
		return 0;
	}
	ifstream fin(argv[1]);
	int cases, n, k;
	fin >> cases;
	vector<int> A;
	for (int i = 1; i <= cases; i++) {
		fin >> n;
		A.resize(n);
		for (int j = 0; j < n; j++)
			fin >> A[j];
		vector<int> B = A;
		int x = 0;
		for (int j = 0; j < B.size(); j++)
			for (int k = j + 1; k < B.size(); k++)
				x += (B[j] < B[k]);
		assert(Prog1::countInOrderPairs(A) == x);
		x = Prog1::smallestElementPos(B);
		for (int j = 0; j < B.size(); j++)
			assert((j < x && B[j] > B[x]) || (j >= x && B[x] <= B[j]));
		x = Prog1::groupSort(B);
		for (int j = 0; j < B.size(); j++)
			assert((j <= x && !(B[j] & 1)) || (j > x && (B[j] & 1)));
	}
	fin.close();
	return 0;
}