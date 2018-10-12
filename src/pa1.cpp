// Ryan McKenzie

#include "pa1.h"

#include <vector>  // vector
#include <algorithm>  // swap (until c++11)
#include <utility>  // swap (since c++11)


using namespace std;


// T(n) = 2T(n/2) + n
// O(n*log(n))
int Prog1::countInOrderPairs(vector<int>& A)
{
	return mergeSort(A, 0, A.size() - 1);
}


// T(n) = 2T(n/2)
// O(n*log(n))
int Prog1::smallestElementPos(vector<int>& A)
{
	return findMin(A, 0, A.size() - 1);
}


int Prog1::groupSort(vector<int>& A)
{
	int size = A.size();
	int i = 0;
	while (i < size) {
		if (A[i] % 2) {
			swap(A[i], A[size - 1]);
			--size;
		} else {
			++i;
		}
	}
	return i - 1;
}


int Prog1::mergeSort(vector<int>& A, int i, int j)
{
	int pairs = 0;

	if (i < j) {
		int mid = i + (j - i) / 2;

		pairs = mergeSort(A, i, mid);
		pairs += mergeSort(A, mid + 1, j);

		pairs += merge(A, i, mid, j);
	}

	return pairs;
}


int Prog1::merge(vector<int>& A, int i, int mid, int j)
{
	vector<int> tmp(j - i + 1);
	int left = i;
	int right = mid + 1;
	int it = 0;
	int pairs = 0;

	while (left <= mid && right <= j) {
		if (A[left] >= A[right]) {
			tmp[it++] = A[left++];
		} else {
			tmp[it++] = A[right++];
			pairs += mid + 1 - left;
		}
	}

	while (left <= mid) {
		tmp[it++] = A[left++];
	}

	while (right <= j) {
		tmp[it++] = A[right++];
	}

	for (int k = 0; k < j - i + 1; ++k) {
		A[i + k] = tmp[k];
	}

	return pairs;
}


int Prog1::findMin(vector<int>& A, int left, int right)
{
	if (right - left + 1 < 3) {
		return (A[left] <= A[right]) ? left : right;
	} else {
		int minLeft = findMin(A, left, (right + left) / 2);
		int minRight = findMin(A, ((right + left) / 2) + 1, right);
		return (A[minLeft] <= A[minRight]) ? minLeft : minRight;
	}
}