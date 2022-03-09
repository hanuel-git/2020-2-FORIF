#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
int N, M;

class Point
{
public:
	int x;
	int y;
	Point(int xpos, int ypos)
		: x(xpos), y(ypos)
	{ }
};

class Edge
{
public:
	int god1;
	int god2;
	double cost;
	Edge(int g1, int g2, double c)
		: god1(g1), god2(g2), cost(c)
	{ }
};

vector<Point> p;
vector<Edge> e;

double Dis(Point &p1, Point &p2)
{
	double r = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return r;
}

void Sort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (e[j - 1].cost > e[j].cost)
				swap(e[j - 1], e[j]);
		}
	}
}

int Find(vector<int>& parent, int x)
{
	if (parent[x] == x)
		return x;
	else
	{
		return parent[x] = Find(parent, x); // 경로압축
	}
}

void Union(vector<int>& parent, int n1, int n2)
{
	n1 = Find(parent, n1);
	n2 = Find(parent, n2);

	if (n1 < n2)
		parent[n2] = parent[n1];
	else
		parent[n1] = parent[n2];
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int xpos, ypos;
		cin >> xpos >> ypos;
		p.push_back(Point(xpos, ypos));
	}

	for (int i = 1; i <= N-1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double d = Dis(p[i-1], p[j-1]);
			e.push_back(Edge(i, j, d));
		}
	}

	int edge_list_size = e.size();
	Sort(edge_list_size);

	vector<int> parent(N + 1, 0);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	double ans = 0;

	for (int i = 0; i < M; i++)
	{
		int g1, g2;
		cin >> g1 >> g2;
		Union(parent, g1, g2);
	}

	int num = M;

	for (int i = 0; ; i++)
	{

		if (num == N - 1)
			break;

		int a = e[i].god1;
		int b = e[i].god2;

		cout << "오예1" << endl;
		if (Find(parent, a) == Find(parent, b))
			continue;
		else
		{
			ans += e[i].cost;
			Union(parent, a, b);
			num++;
		}
		cout << "오예2" << endl;
	}
	cout << ans << endl;
	return 0;
}