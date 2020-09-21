#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	while (1)
	{
		vector<int> v;
		int temp = 0;
		while (1)
		{
			cin >> temp;
			v.push_back(temp);
			if (getchar() == '\n')
				break;
		}
		
		sort(v.begin(), v.end());
		int size = v.size();
		for (int i = 0; i<size - 2; ++i)
		{
			if (v[i]>0)
				break;
			if (i>0 && v[i] == v[i - 1])
				continue;
			int start = i + 1;
			int end = size - 1;
			while (start<end)
			{
				if (v[start] + v[end] == -v[i])
				{
					if (start == i + 1 || end == size - 1)
					{
						cout << v[i] <<" "<< v[start] <<" "<< v[end] << endl;
						start++, end--;
					}
					else if (v[start] == v[start - 1])
					{
						start++;
					}
					else if (v[end] == v[end + 1])
					{
						end--;
					}
					else
					{
						cout << v[i] << " " << v[start] << " " << v[end] << endl;
						start++, end--;
					}
				}
				else if (v[start] + v[end]<-v[i])
				{
					start++;
				}
				else
					end--;
			}
		}
	}
}












