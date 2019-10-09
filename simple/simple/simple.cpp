#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include <vector>

using namespace std;
const double eps = 1e-20;
enum{ mxn = 50, mxm = 50 };//mxn��δ֪���ĸ����������ɳڱ�����mxm Լ������
class Simplex
{
public:
	int n, m, t;
	double c[mxn];
	double a[mxm][mxn];
	int idx[mxn], idy[mxn];
	int st[mxn], top = 0;

	Simplex(int _m, int _n)
	{
		this->m = _m;
		this->n = _n;
		int i;
		for (i = 1; i <= n; i++)
		{
			idx[i] = i;//������ 
		}
		for (i = 1; i <= m; i++)
			//��Ӻ���ɳڱ���
		{
			idy[i] = i + n;//�ǻ����� 
		}
	}
	void set_objective(double ci[mxn])
	{
		for (int i = 1; i <= n; i++)
		{
			a[0][i] = -ci[i - 1];//��0����ΪĿ�꺯��
		}
	}
	void set_co_matrix(double co_matrix[mxm][mxn])
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = co_matrix[i - 1][j - 1];
			}
		}
	}
	void set_bi_matrix(double b_matrix[mxm])
	{
		for (int i = 1; i <= m; i++)
		{
			a[i][0] = b_matrix[i - 1];//��0����Ϊb����
		}
		a[0][0] = 0;
	}
	int init_simplex()
	{
		while (1)
		{

			int i, x = 0, y = 0;
			for (i = 1; i <= m; i++)
			{
				if (a[i][0] < -eps && ((!x) || (rand() & 1)))
					//�����ĳ��b[i] ����Լ��С��0��
				{
					x = i;
				}
			}
			if (!x)
				break;//û��С��0��
			for (i = 1; i <= n; i++)
			{
				if (a[x][i] < -eps && ((!y) || (rand() & 1)))
					//�Ӹո���һ��biС��0������,�ҵ�����һ��С��0��
				{
					y = i;
				}
			}
			if (!y)
			{
				printf("Infeasible\n");
				return 0;
			}
			Pivot(x, y);//�ѵ�x�еĵ�y�е�Ԫ����Ϊ��Ԫ ���и�˹��Ԫ
		}
		return 1;
	}
	void Pivot(int x, int y)
	{//��idy����idx
		swap(idy[x], idx[y]);
		double tmp = a[x][y];
		a[x][y] = 1 / a[x][y];
		int i, j;
		top = 0;
		for (i = 0; i <= n; i++)
		{
			if (y != i)
				a[x][i] /= tmp;
		}

		for (i = 0; i <= n; i++)
		{
			if ((y != i) && fabs(a[x][i]) > eps)
			{
				st[++top] = i;
			}
		}
		for (i = 0; i <= m; i++)
		{
			if ((i == x) || (fabs(a[i][y]) < eps))
			{
				continue;
			}
			for (j = 1; j <= top; j++)
			{
				a[i][st[j]] -= a[x][st[j]] * a[i][y];
			}
			a[i][y] = -a[i][y] / tmp;
		}
		return;
	}
	int run()
	{
		int init = init_simplex();
		if (init == 0)
		{
			return init;//�޽�
		}
		int i, j;
		while (1){
			int x = 0, y = 0;
			double mn = 1e15;
			for (i = 1; i <= n; i++)
			{
				if (a[0][i] > eps)
				{
					y = i;
					break;
				}
			}
			if (!y)
				break;
			for (i = 1; i <= m; i++)
			{
				if (a[i][y] > eps && (a[i][0] / a[i][y] < mn))
				{
					mn = a[i][0] / a[i][y];
					x = i;
				}
			}
			if (!x)
			{
				printf("Unbounded\n");
				return -1;//�޽�
			}
			Pivot(x, y);
		}
		return 1;//�н�
	}
	pair<vector<double>, double> getans()
	{
		vector<double> x;
		double z;
		int i;
		z = a[0][0];
		for (i = 1; i <= n; i++)
		{
			a[0][i] = 0;
		}
		for (i = 1; i <= m; i++)
		{
			if (idy[i] <= n)a[0][idy[i]] = a[i][0];
		}
		for (i = 1; i <= n; i++)
		{
			x.push_back(a[0][i]);
		}
		return pair< vector<double>, double>(x, z);
	}
};
double b_matrix[mxm] = { 0 };
double co_matrix[mxm][mxn] = { 0 };
double c_matrix[mxn] = { 0 };
int main()
{
	int m, n;
	m = 14;//С����Լ���ĸ���
	n = 6;//��ʵ�����ĸ���,�������ɳڱ���
	float st[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &(st[i]));
	}
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			//������
		{
			b_matrix[i] = -st[i];
			co_matrix[i][i / 2] = -1;
		}
		else
		{
			b_matrix[i] = st[i];
			co_matrix[i][i / 2] = 1;
		}
	}
	co_matrix[10][0] = 1, co_matrix[10][1] = -1, co_matrix[10][5] = 1, b_matrix[10] = 0;
	co_matrix[11][1] = 1, co_matrix[11][2] = -1, co_matrix[11][5] = 1, b_matrix[11] = 0;
	co_matrix[12][2] = 1, co_matrix[12][3] = -1, co_matrix[12][5] = 1, b_matrix[12] = 0;
	co_matrix[13][3] = 1, co_matrix[13][4] = -1, co_matrix[13][5] = 1, b_matrix[13] = 0;
	c_matrix[5] = -1;
	Simplex simplex(m, n);
	simplex.set_objective(c_matrix);
	simplex.set_co_matrix(co_matrix);
	simplex.set_bi_matrix(b_matrix);
	simplex.run();
	pair<vector<double>, double> rst = simplex.getans();
	printf("%0.2f\n", rst.second + 0.00005);
	for (int i = 0; i < rst.first.size() - 1; i++)
	{
		printf("%0.2f", float(rst.first[i] + 0.000005));
		if (i != (rst.first.size() - 2))
		{
			printf(" ");
		}
	}
	system("pause");
	return 0;
}

