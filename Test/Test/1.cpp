#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);

	}
}

#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	vector<int> person;
	vector<int> risk;
	
	int val;
	while (1)
	{
		cin >> val;
		if (getchar() != '\n')
		{
			person.push_back(val);
		}
		else
		{
			break;
		}
	}
	person.push_back(val);

	while (cin>>val)
	{
		//cin >> val;
		if (getchar() != '\n')
		{
			risk.push_back(val);
		}
		else
		{
			break;
		}
	}
	risk.push_back(val);
	
	

	sort(person.begin(), person.end());
	sort(risk.begin(), risk.end());
	int num = person.size();
	for (int i = 0; i<person.size(); i++)
	{
		if (person[i]>risk[risk.size() - 1])
		{
			num--;
		}
	}
	cout << num << endl;
	return 0;
}
#endif