
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

//20191107###############################################################################################
//排序子序列*************************************************
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> array(n+1, 0);
		int count = 0;
		int i = 0;
		for (i = 0; i<n; i++)
		{
			cin >> array[i];
		}
		i = 0; 
		while (i<n)
		{
			if (array[i]<array[i + 1])
			{
				while (array[i]<array[i + 1] && i<n)
				{
					i++;
				}
				count++;
				i++;
			}
			else if(array[i]>array[i+1])
			{
				while(array[i]>array[i+1]&&i<n)
				{
					i++;
				}
				count++;
				i++;
			}
			else
			{
				i++;
			}
		}
		cout<<count<<endl;
	}
}

#if 0
//翻转字符串***************************************************************
int main()
{
	string str;
	while(getline(cin,str))
	{
		reverse(str.begin(),str.end());
		int start=0;;
		int end=0;
		while(str[start]!='\0')
		{
			while (str[start] != ' '&&str[start] != '\0')
			{
				start++;
			}
			reverse(str.begin()+end,str.begin()+start);
			while(str[start]==' ')
			{
				start++;
			}
			end=start;
		}
		cout<<str<<endl;
	}
}
//20191106############################################################################################################
//组队竞速*******************************************
int main()
{
	int n = 0;

	while (cin >> n)
	{
		vector<int> v(3 * n, 0);
		int sum = 0;
		for (int i = 0; i<3 * n; i++)
		{
			cin >> v[i];

		}
		sort(v.begin(), v.end());
		for (int i = v.size() - 2; i > 0; i -= 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
}

//删除str1中str2的所有字母
int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		for (int i = 0; i<str2.size(); i++)
		{
			int tmp = str1.find(str2[i]);
			while (tmp != string::npos)
			{
				str1.erase(tmp, 1);
				tmp = str1.find(str2[i]);
			}
		}
		cout << str1 << endl;
	}
}
//组队竞速***********************************************
int main()
{
	int n=0;
	
	while(cin>>n)
	{
		vector<int> v(3*n,0);
		int sum=0;
		for(int i=0;i<3*n;i++)
		{
			cin>>v[i];

		}
		sort(v.begin(),v.end());
		for (int i = v.size() - 2; i > 0; i -= 2)
		{
			sum+=v[i];
		}
		cout<<sum<<endl;
	}
}

//删除str1中str2的所有字母
int main()
{
	string str1;
	string str2;
	while (getline(cin,str1))
	{
		getline(cin, str2);
		for (int i = 0; i<str2.size(); i++)
		{
			int tmp = str1.find(str2[i]);
			while (tmp != string::npos)
			{
				str1.erase(tmp, 1);
				tmp = str1.find(str2[i]);
			}
		}
		cout << str1 << endl;
	}
}
//用两个栈实现队列*******************************************************************
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if(stack2.empty()){//注意：必须要等stack2为空时，才能继续入栈，不然就会导致栈顶元素出不来
			while(stack1.empty()!=1)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int t=stack2.top();
		stack2.pop();
		return t;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
/**从尾到头打印链表，用栈来实现
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include<stack>
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> s;
		vector<int> array;
		ListNode* p=head;
		while(p!=NULL)
		{
			s.push(p->val);
			p=p->next;
		}
		while(s.empty()!=1)
		{
			array.push_back(s.top());
			s.pop();
		}
		return array;
	}
};

//20191105####################################################################################
//左旋转字符串，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int size=str.size();
		reverse(str.begin(),str.end());
		reverse(str.begin(),str.end()-n);
		reverse(str.begin()+size-n,str.end());
		return str;
	}
};
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if(n<0) return NULL;
		if(n==0) return str;
		string strTemp="";

		strTemp=str.substr(0,n);
		str.erase(0,n);
		str+=strTemp;
		return str;

	}
};
//数值的整数次方，给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
double Power(double base, int exponent) {
	int tp = 0;
	double tmp = 0;
	int flag = 1;
	if (exponent < 0)
	{
		tp = -exponent;
	}
	else
	{
		tp = exponent;
	}
	double result=0;
	if (exponent == 0)
	{
		return 1;
	}
	if(base==0)
	{
		return 0;
	}
	if (tp == 1)
	{
		return base;
	}
	tmp = Power(base, tp / 2);
	if (tp & 1 == 0)
	{
		result=tmp*tmp;
	}
	else
	{
		result=base*tmp*tmp;
		flag = -flag;
	}
	if (exponent < 0)
	{
		double sum = 0;
		sum = flag*1.0 / result;
		return sum;
	}
	else
	{
		return result;
	}
}
int main()
{
	int x = 2;
	int y = -3;
	double num = Power(x, y);
	printf("%d\n", num);
	system("pause");
	return 0;
}

//20191102##################################################################################################
//将字符串转化为数字*******************************************************************
class Solution {
public:
	int StrToInt(string str) {
		const int length = str.length();
		int isNegtive = 1, overValue = 0;
		int digit = 0, value = 0;

		if (length == 0) return 0;
		else {
			int idx = 0;
			if (str[0] == '-') { isNegtive = -1; idx = 1; }
			else if (str[0] == '+') { idx = 1; }

			for (; idx<length; idx++) {
				digit = str[idx] - '0';
				// overValue表示本轮循环是否会越界
				overValue = isNegtive*value - INT_MAX / 10
					+ (((isNegtive + 1) / 2 + digit > 8) ? 1 : 0);

				if (digit<0 || digit>9) return 0;
				else if (overValue > 0) return 0;

				value = value * 10 + isNegtive*digit;
			}
			return value;
		}
	}
};

//数组中重复的数字，在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，请找出数组中任意一个重复的数字。 
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	void swap(int *n,int *m)
	{
		int tmp=0;
		tmp=*n;
		*n=*m;
		*m=tmp;
	}
	bool duplicate(int numbers[], int length, int* duplication) {
		for(int i=0;i<length;)
		{
			if(numbers[i]==i)
			{
				i++;
			}
			else
			{
				if(numbers[i]==numbers[numbers[i]])
				{
					*duplication=numbers[i];
					return true;
				}
				swap(&numbers[i],&numbers[numbers[i]]);
				i++;
			}
		}
		return false;
	}
};

//20191101################################################################################################
//找到单链表的入环节点***************************************************
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* p = pHead;
		ListNode* q = pHead;
		if(pHead == NULL||pHead->next==NULL||pHead->next->next==NULL)
			return NULL;
		while(q->next != NULL && q->next->next != NULL){
			p = p->next;
			q = q->next->next;
			if(p == q){
				break;
			}
		}
		q = pHead;
		while(p != q){
			p = p->next;
			q = q->next;
		}
		return p;

	}
};
//找到两个链表的第一个公共节点****************************************************
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//通过右对齐的方式来查找，从同一起点一起走，直到走到同一地址
class Solution {
public:
	ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		ListNode* longlist=pHead1;
		ListNode* shortlist=pHead2;
		int lenA=0;
		int lenB=0;
		for(ListNode* cur=pHead1;cur;cur=cur->next)
		{
			lenA++;
		}
		for(ListNode* cur=pHead2;cur;cur=cur->next)
		{
			lenB++;
		}
		if(lenA<lenB)
		{
			longlist=pHead2;
			shortlist=pHead1;
			swap(lenA,lenB);
		}
		int gap=lenA-lenB;
		for(int i=0;i<gap;i++)
		{
			longlist=longlist->next;
		}
		for(;longlist&&shortlist;longlist=longlist->next,shortlist=shortlist->next)
		{
			if(longlist==shortlist)
			{
				return longlist;
			}
		}
		return nullptr;
	}
};

//20191031###########################################################################################################################
//调整数组中所有奇数位于偶数的前面初始版本
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int start=0;
		int end=array.size()-1;
		while(start<end)
		{
			if(array[start]%2==0&&array[end]%2!=0)
			{
				swap(array[start],array[end]);
				start++;
				end--;
			}
			if(array[start]%2!=0)
			{
				start++;
			}
			if(array[end]%2==0)
			{
				end--;
			}
		}
	}
};
//调整数组中所有奇数位于偶数的前面进阶版本，并保证奇数和奇数，偶数和偶数之间的相对位置不变（基于快排的思想）
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int j=0;
		int tmp=0;
		for(int i=0;i<array.size();i++)
		{
			if(array[i]%2==1)
			{
				tmp=array[i];
				j=i-1;
				while(j>=0&&array[j]%2==0)
				{
					array[j+1]=array[j];
					j--;
				}
				array[j+1]=tmp;
			}
		}
	}
};


//反转一个单链表
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr)
			return nullptr;
		if(pHead->next == nullptr)
			return pHead;
		ListNode* pre=pHead;
		ListNode* cur=pHead->next;
		ListNode* next=pHead->next;
		pre->next=NULL;
		while(next)
		{
			next=next->next;
			cur->next=pre;
			pre=cur;
			cur=next;
		}
		pHead=pre;
		return pHead;
		//方法二：
		/*
		ListNode* pre=pHead;
		ListNode* oldh=pHead;
		ListNode* next=pHead->next;
		while(next)
		{
		oldh->next=next->next;
		next->next=pre;
		pre=next;
		next=oldh->next;
		}
		pHead=pre;
		return pHead;*/
	}
};
//20191029########################################################################################################################
//数组中只出现一次的数字，一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int sum=0;
		int pos=0;
		for(int i=0;i<data.size();i++)
		{
			sum^=data[i];
		}
		for(int i=0;i<32;i++)
		{
			if(sum>>i&1)
			{
				pos=i;
				break;
			}
		}
		vector<int> d1;
		vector<int> d2;
		for(int i=0;i<data.size();i++)
		{
			if(data[i]>>pos&1)
			{
				d1.push_back(data[i]);
			}
			else
			{
				d2.push_back(data[i]);
			}
		}
		for(int i=0;i<d1.size();i++)
		{
			*num1^=d1[i];
		}
		for(int i=0;i<d2.size();i++)
		{
			*num2^=d2[i];
		}
	}
};
//翻转单词顺序列，“student. a am I”正确的句子应该是“I am a student.”
string ReverseSentence(string str) {
	reverse(str.begin(), str.end());
	size_t fast = 0; size_t last = fast;
	int length = str.size()-1;
	while(last <= str.size())
	{
		while (str[last] != ' '&&str[last] != '\0')
		{
			last++;
		}
		if (str[last] == '\0')
		{
			last = last - 1;
			reverse((str.begin() + fast), (str.end() - length + last));
			break;
		}
		else
		{
			reverse((str.begin() + fast), (str.end() - length + last - 1));
		}
		while (str[last] == ' ')
		{
			last++;
		}
		fast = last;
	}
	return str;
}
int main()
{
	string str = "student. a am I";
	ReverseSentence(str);
	system("pause");
	return 0;
}

//20191028#######################################################################################################
//和为S的两个数字*******************************************************************
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> vv;
		int start = 0;
		int end = array.size() - 1;
		while (start < end)
		{
			if (array[start] + array[end] > sum)
			{
				end--;
			}
			else if (array[start] + array[end] < sum)
			{
				start++;
			}
			else
			{
				vv.push_back(array[start]);
				vv.push_back(array[end]);
				break;
			}
		}
		return vv;
	}
};

//和为S的两个数字傻瓜做法，还错了****
	int main()
	{
		vector<int> array;
		array.push_back(1);
		array.push_back(3);
		array.push_back(5);
		array.push_back(6);
		array.push_back(7);
		array.push_back(8);
		array.push_back(10);
		array.push_back(11);
		int sum = 14;


	int mid = array.size() / 2 - 1;
	int end = mid + 1;
	int start = mid - 1;
	vector<int> vv;
	vector<int> v;
	while (end < array.size())
	{
		if (array[mid] + array[end] < sum)
		{
			end++;
		}
		else if (array[mid] + array[end] == sum)
		{
			vv.push_back(array[mid]);
			vv.push_back(array[end]);
			break;
		}
		else
		{
			break;
		}
	}
	while (start >= 0 && end < array.size())
	{
		if (array[start] + array[end] > sum)
		{
			start--;
		}
		else if (array[start] + array[end] < sum)
		{
			end++;
		}
		else
		{
			vv.push_back(array[start]);
			vv.push_back(array[end]);
			start--;
			end++;
		}
	}
	int min = vv[0];
	int max = vv[0];
	int pos1 = 0;
	int pos2 = 0;
	int i = 0;
	for (; i<vv.size(); i++)
	{
		if (vv[i]<min)
		{
			min = vv[i];
			pos1 = i;
		}
		if (vv[i]>max)
		{
			max = vv[i];
			pos2 = i;
		}
	}
	cout << vv[pos1] << vv[pos2] << endl;

	system("pause");
	return 0;
}
#endif


#if 0
//最小的k个数************************************************************************
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int length = input.size();
		vector<int> vv;
		if(length<=0||k<=0||k>length)
		{
			return vv;
		}
		sort(input.begin(),input.end());
		int i=0;
		while(i<k)
		{
			vv.push_back(input[i]);
			i++;
		}
		return vv;
	}
};
//20191027######################################################################################################################
//斐波那契数列求第n个值
int Fibonacci(int n) {
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	int n1 = 1;
	int n2 = 1;
	int n3 = 0;
	int i = 3;
	while (i<=n)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		i++;
	}
	return n3;
}
int main()
{
	int temp = Fibonacci(6);
		cout << temp << endl;
	system("pause");
	return 0;
}

//二进制中1的个数
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for(int i=0;i<32;i++)
		{
			if(n>>i&1)
			{
				count++;
			}
		}
		return count;
	}
};
#endif
#if 0

//20191026###################################################################################################################

//将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
void replaceSpace(char *str, int length) {
	int i;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	int num = 2 * count + length;
	int j = num - 2;
	str[num-1] = '\0';
	for (i = length - 2; i >= 0,j>=0; i--)
	{
		if (str[i] == ' ')
		{
			str[j] = '0';
			j--;
			str[j] = '2';
			j--;
			str[j] = '%';
			j--;
		}
		else
		{
			str[j] = str[i];
			j--;
		}
	}
}
int main()
{
	char arr[] = "ab cdef g";
	int num = sizeof(arr) / sizeof(arr[0]);
	replaceSpace(arr, num);
	system("pause");

	return 0;
}


//二维数组中的查找，在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	bool Find(int target, vector<vector<int> > array) {
		int i = 0;
		int j = array[0].size() - 1;
		while (i<array.size() && j >= 0)
		{
			if (array[i][j]>target)
			{
				j--;
			}
			else if (array[i][j]<target)
			{
				i++;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};



//删除字符串后面重复的字母************************************************************
int  main()
{
	string s1;
	while (cin >> s1)
	{
		for (int i = 0; i<s1.size(); i++)
		{
			for (int j = i+1; j<s1.size();)
			{
				if (s1[i] == s1[j])
				{
					s1.erase(j, 1);
				}
				else
				{
					j++;
				}
			}
		}
		cout << s1 << endl;
	}

}
//
//int  main()
//{
//	string s1;
//	while (cin >> s1)
//	{
//		for (int i = 0; i<s1.size();)
//		{
//			if (s1.find(s1[i]) != string::npos)
//			{
//				s1.erase(s1.find(s1[i]), 1);                                                                                                                                                                               
//			}
//			else
//			{
//				i++;
//			}
//		}
//		cout << s1 << endl;
//	}
//}
#endif
































#if 0

20191021###############################################################################################################
二叉树的层序遍历*************************************************************************
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ret;
		if (root == nullptr)
		{
			return ret;
		}
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int levelsize = q.size();
			for (int i = 0; i<levelsize; i++)
			{
				TreeNode* pcur = q.front();
				level.push_back(pcur->val);
				if (pcur->left)
				{
					q.push(pcur->left);
				}
				if (pcur->right)
				{
					q.push(pcur->right);
				}
				q.pop();
			}
			ret.push_back(level);
		}
		return ret;
	}
};
//数组中第k个最大元素**********************************************************
class Solution {//大堆来解决
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> p(nums.begin(), nums.end());
		for (int i = 0; i<k - 1; i++)
		{
			p.pop();
		}
		return p.top();
	}
};
class Solution {//降序排序来解决
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k - 1];
	}
};
//第一个只出现一次的字符***************************************************
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int arr[256] = { 0 };
		for (int i = 0; i<str.size(); i++)
		{
			arr[str[i]]++;
		}
		for (int i = 0; i<str.size(); i++)
		{
			if (arr[str[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
//整数中1出现的次数********************************************************
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int temp = 0;
		int com = 0;
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			temp = i;
			while (temp)
			{
				com = temp % 10;
				temp = temp / 10;
				if (com == 1)
				{
					count++;
				}
			}
		}
		return count;
	}
};

//20191020###################################################################################################################
//连续子数组的最大和************************************************************************
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = array[0];
		int sum = 0;
		for (int i = 0; i<array.size(); i++)
		{
			sum += array[i];
			if (sum<array[i])
			{
				sum = array[i];
			}
			if (sum>max)
			{
				max = sum;
			}
		}
		return max;
	}
};

//找到数组中出现次数超过一半的数字************************************************************************88
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int mid = numbers.size() / 2;
		int count = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == numbers[mid])
			{
				count++;
			}
		}
		if (count>mid)
		{
			return numbers[mid];
		}
		else{
			return 0;
		}
	}
};
//快排*************************************************
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int *arr, int start, int end)
{
	int i = start;
	int j = end;
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	while (i < j)
	{
		if (arr[i] > arr[j])
		{
			Swap(&arr[i], &arr[j]);
			flag = !flag;
		}
		flag ? i++ : j--;
	}
	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}

//20191015*******************************************************************************************************************************************
//260，只出现一次的数字，给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int sum = 0;
		int pos = 0;
		vector<int> num(2, 0);
		for (int i = 0; i<nums.size(); i++)
		{
			sum ^= nums[i];
		}
		for (int i = 0; i<32; i++)
		{
			if (sum >> i & 1)
			{
				pos = i;
			}
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] >> pos & 1)
			{
				num[0] ^= nums[i];
			}
			else
			{
				num[1] ^= nums[i];
			}
		}
		return num;
	}
};

//只出现一次的数字，给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int single=0;
		for(int i=0;i<32;i++)
		{
			int count=0;
			for(int j=0;j<nums.size();j++)
			{
				if(nums[j]>>i&1)
				{
					count++;
				}
			}
			if(count%3!=0)
			{
				single=single|1<<i;
			}
		}
		return single;
	}
};
//傻瓜解法
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int i=0;
		int j=0;
		for(i=0;i<nums.size();i++)
		{
			for(j=0;j<nums.size();j++)
			{
				if(i==j)
				{
					continue;
				}
				if(nums[i]==nums[j])
				{
					break;
				}
			}
			if(j==nums.size())
			{
				break;
			}
		}
		return nums[i];
	}
};



//删除排序数组中重复的项
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int i = 0;
		int j = 1;
		while (j<nums.size())
		{
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
			else
			{
				j++;
			}
		};

		class Solution {
		public:
			int removeDuplicates(vector<int>& nums) {
				if(nums.size()==0)
				{
					return 0;
				}
				int i = 0;
				while (i < nums.size()-1)
				{
					if (nums[i] == nums[i + 1])
					{
						nums.erase(nums.begin() + i + 1);
					}
					if (nums[i] != nums[i + 1])
					{
						i++;
					}
				}
				return nums.size();
			}
		};

		int main()
		{
			int arr[10] = { 1, 1, 3, 4, 5, 6, 6, 7, 7, 9 };
			vector<int> vv(arr, arr + sizeof(arr) / sizeof(int));
			int i = 0;
			while (i < vv.size()-1)
			{
				if (vv[i] == vv[i + 1])
				{
					vv.erase(vv.begin() + i + 1);
				}
				if (vv[i] != vv[i + 1])
				{
					i++;
				}
			}

			system("pause");
			return 0;

		}

//杨辉三角，给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (int i = 1; i <= vv.size(); i++)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		for (int i = 2; i<vv.size(); i++)
		{
			for (int j = 1; j<vv[i].size()-1; j++)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}
		return vv;

	}
};

//只出现一次的数字
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for(size_t i =0 ; i < nums.size(); ++i){
			value ^= nums[i];
		}
		return value;
	}
};


//20191005############################################################################################################
//比较含退格的字符串
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int pos;
		while(S.find('#')!=string::npos)
		{
			pos=S.find('#');
			if(pos==0)
			{
				S.erase(pos,1);
			}
			else
			{
				S.erase(pos-1,2); 
			}
		}
		while(T.find('#')!=string::npos)
		{
			pos=T.find('#');
			if(pos==0)
			{
				T.erase(pos,1);
			}
			else
			{
				T.erase(pos-1,2); 
			}
		}
		if(S.compare(T)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//删除字符串中所有相邻重复项：给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
class Solution {
public:
	string removeDuplicates(string S) {
		int i=0;
		for(i=0;i<S.size();)
		{
			if(S[i]==S[i+1])
			{
				S.erase(i,2);
				i=0;
			}
			else
			{
				i++;
			}
		}
		return S;
	}
};

//两个字符串的最大公因子
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		string str3 = str1;
		int i = 0;
		while (str1.compare(str2) != 0)//判断两个字符串是否相等
		{
			if (str1.size()<str2.size())//让两个字符串中比较长的那个为str1
			{
				swap(str1, str2);
			}
			for (i = 0; i<str2.size();)//判断str1的前i个字符是否与str2相等
			{
				if (str1[i] == str2[i])
				{
					i++;
				}
				else
				{
					return "";//不相等就返回
				}
			}
			str3 = str1.substr(i);//相等就截掉前i个字符继续比较
			str1 = str3;
		}
		return str1;//直到两个字符串相等就返回
	}
};
int main()
{
	string str1 = "ABABAB";
	string str2 = "ABAB";
	Solution d;
	string str3=d.gcdOfStrings(str1, str2);
	cout << str3 << endl;
	system("pause");
	return 0;
}


//2019_09_26#######################################################################################################################
//求两个字符串数字相乘得到的结果以字符串输出************************************************
class Solution {
public:
	string multiply(string num1, string num2) {
		string s;
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int count = 1;
		long long cur = 0;    
		int temp = 0;
		int getnum = 1;
		int mul = 0;
		for (end1; end1 >= 0; end1--)
		{
			cur = 0;
			temp = 0;
			count = 1;
			for (end2 = num2.size() - 1; end2 >= 0; end2--)
			{
				cur += ((num1[end1] - '0')*(num2[end2] - '0') + temp)*count;
				if (end2 > 0)
				{
					temp = cur / (10 * count);
					cur = cur % (10 * count);
					count *= 10;
				}
			}
			mul += cur*getnum;
			getnum *= 10;
		}
		s = to_string(mul);
		return s;
	}
};
int main()
{
	Solution d;
	cout << d.multiply("12345","45678") << endl;

	system("pause");
	return 0;
}


//找字符串中第一个只出现一次的字母*************************************************************
int main()
{
	int count[255]={0};
	string s;
	int i = 0;
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();i++)
		{
			count[s[i]]++;
		}
		for(i=0;i<s.size();i++)
		{
			if(count[s[i]]==1)
			{
				cout<<s[i]<<endl;
				break;
			}
		}
		if (i == s.size())
		{
			cout << "-1" << endl;
		}
	}
}

//将字符串中的每一个单词进行逆转***************************************************
class Solution {
public:
	void reverse(int m,int n,string &s )
	{
		while(m<n)
		{
			swap(s[m],s[n]);
			m++;
			n--;
		}
	}
	string reverseWords(string s) {
		int pos=0;
		int temp=0;
		while (s.find(' ', pos)!=string::npos)
		{
			temp=s.find(' ',pos);
			reverse(pos,temp-1,s);
			pos=temp+1;
		}
		temp = pos;
		for (int i = 0; s[pos] != '\0'; i++)
		{
			pos++;
		}
		reverse(temp, pos-1,s);
		return s;
	}
};
int main()
{
	Solution d;
	cout << d.reverseWords("Let's take LeetCode contest") << endl;

	system("pause");
	return 0;
}


//判断两个字符串是否为变形词*******************************************************888
#include<iostream>
using namespace std;
#include<string>
int Ischangeword(string s1, string s2)
{
	int pos = 0;
	for (size_t i = 0; i<s1.size(); i++)
	{
		pos = s2.find(s1[i]);
		if (pos >= 0 && pos <= s1.size())
		{
			s2[pos] = '0';
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	size_t m, n;
	cin >> m >> n;
	string s1, s2;
	cin >> s1 >> s2;
	if (m == n)
	{
		if (Ischangeword(s1, s2))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	else
	{
		cout << "false" << endl;
	}
}

//2019_09_25#################################################################################################################33
//判断两个字符串是否互为旋转词***********************
int IsRevolve(string s1, string s2)
{
	char ch1 = s1[0];
	size_t pos = s2.find(ch1);
	for (int i = 0; i<s1.size(); i++)
	{
		if (s2[pos] == s1[i])
		{
			pos++;
		}
		else
		{
			return 0;
		}
		if (pos == s1.size())
		{
			pos = 0;
		}
	}
	return 1;
}
int main()
{
	size_t m, n;
	cin>>m>>n;
	string s1,s2;
	cin >> s1 >> s2;
	if(m==n)
	{
		if(IsRevolve(s1,s2))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}

//验证是否是回文字符串（不分大小写）
class Solution {
public:
	bool isletterornumber(char c)
	{
		return c >= 'a'&&c <= 'z' || c >= '0'&&c <= '9';
	}
	bool isPalindrome(string s) {
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
		int start = 0;
		int end = s.size() - 1;
		while (start <= end)
		{
			if (isletterornumber(s[start]))
			{
				if (isletterornumber(s[end]))
				{
					if (s[start] == s[end])
					{
						start++;
						end--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					end--;
				}
			}
			else
			{
				start++;
			}

		}
		return true;
	}
};
//字符串中最后一个单词的长度
int main()
{
	string s;
	while(getline(cin,s))
	{
		size_t pos=s.rfind(' ');
		cout<<s.size()-pos-1<<endl;
	}
}

//找字符串中第一个只出现一次的字符的下标
class Solution {
public:
	int firstUniqChar(string s) {
		int count[128]={0};
		int i=0;
		for(i=0;i<s.size();i++)
		{
			count[s[i]]++;
		}
		for(i=0;i<s.size();i++)
		{
			if(count[s[i]]==1)
			{
				return i;
			}
		}
		return -1;
	}
};

//反转一个字符串****************************************************************
class Solution {
public:
	string reverseString(string s) {
		if (s.empty())
		{
			return s;
		}
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};

int main()
{
	Solution s;
	string s1("abcdefghigk");
	s.reverseString(s1);
	system("pause");
	return 0;
}


//日期类*******************************************************************************
class Date
{
public:
	//构造函数******************************
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!(year > 0) &&
			(month > 0 && month < 13) &&
			(day>0 && day <= GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//拷贝构造函数***************************
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	//赋值重载********************************
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//求增加多少天后的日期************************
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day += days;
		while (temp._day > temp.GetDaysOfMonth(temp._year, temp._month))
		{
			temp._day -= temp.GetDaysOfMonth(temp._year, temp._month);
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._month = 1;
				temp._year += 1;
			}
		}
		return temp;
	}
	//求减少多少天后的日期*********************************************
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._month = 12;
				temp._year--;
			}
			temp._day += temp.GetDaysOfMonth(temp._year, temp._month);
		}
		return temp;
	}
	//输出重载***************************************************
	friend ostream& operator<<(ostream& _cout, const Date&d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
	//两个日期对象相减*****************************************
	int operator-(const Date &d)
	{
		Date max(*this);
		Date min(d);
		if (*this < d)
		{
			swap(max, min);
		}
		int count = 0;
		while (min != max)
		{
			count++;
			min++;
		}
		return count;
	}
	//重载== *****************************************************
	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//重载!= *****************************************************
	bool operator!=(const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}

	//重载<  ******************************************
	bool operator<(const Date &d)
	{
		if ((*this)._year < d._year ||
			((*this)._year == d._year) && ((*this)._month < d._month) ||
			((*this)._year == d._year) && ((*this)._month == d._month) && (*this)._day < d._day)
		{
			return true;
		}
		return false;
	}
	//重载>  **************************************************
	bool operator>(const Date& d)const
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}
	//前置++     ************************************************
	Date & operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//后置++******************************************************
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}
	//前置--************************************
	Date & operator--()
	{
		*this = *this - 1;
		return *this;
	}
	//后置--**********************************************
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	
private:
	int GetDaysOfMonth(int year, int month)
	{
		int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		arr[2] = 28;
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		{
			if (month == 2)
			{
				arr[2] += 1;
			}
		}
		return arr[month];
	}
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 18);
	Date d2(2020, 1, 1);
	cout << d2 - d1 << endl;

	d1 = d1 - 999;
	cout << d1 << endl;
	system("pause");
	return 0;
}
#endif