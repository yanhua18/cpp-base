#include<iostream>
using namespace std;


bool verifyPostorder(int* postorder, int postorderLen) {
	if (postorderLen == 0)
		return false;
	int root = postorder[postorderLen - 1];
	int i = 0;
	while (postorder[i]<root)
		++i;
	for (int j = i; j<postorderLen - 1; j++)
	{
		if (postorder[i] <= root)
			return false;
	}
	bool left = true;
	if (i>0)
	{
		int leftarr[i];
		for (int n = 0; n<i; ++n)
		{
			leftarr[n] = postorder[n];
		}
		left = verifyPostorder(leftarr, i);
	}
	bool right = true;
	if (i<postorderLen - 1)
	{
		int rightarr[postorderLen - 1 - i];
		for (int n = 0, m = i; m<postorderLen - 1; ++n, ++m)
		{
			rightarr[n] = postorder[m];
		}
		right = verifyPostorder(rightarr, postorderLen - i - 1);
	}
	return (left&&right);
}

int main()
{
	int arr[5] = { 1, 3, 2, 6, 5 };
	verifyPostorder(arr, 5);
}


















