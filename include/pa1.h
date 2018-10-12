/*
* *File: pa1.h
*
*/


#ifndef _PA1_H
#define _PA1_H


#include <iostream>
#include <vector>


using namespace std;


class Prog1
{
public:
	static int countInOrderPairs(vector<int>& A);
	static int smallestElementPos(vector<int>& A);
	static int groupSort(vector<int>& A);

private:
	static int mergeSort(vector<int>& A, int i, int j);
	static int merge(vector<int>& A, int i, int mid, int j);
	static int findMin(vector<int>& A, int left, int right);
};


#endif