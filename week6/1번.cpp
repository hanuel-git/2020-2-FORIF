#include<iostream>
#include<vector>
using namespace std;

int V, E;

class Edge 
{
public:
	int node1;
	int node2;
	int cost;

	Edge(int n1, int n2, int c)
		: node1(n1), node2(n2), cost(c)
	{ }
};

void Sort(vector<Edge> &edge_list, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (edge_list[j - 1].cost > edge_list[j].cost)
				swap(edge_list[j - 1], edge_list[j]);
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
	cin >> V >> E;
	vector<int> parent(V + 1, 0);
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	vector<Edge> edge_list;
	for (int i = 0; i < E; i++)
	{
		int n1, n2, c;
		cin >> n1 >> n2 >> c;
		edge_list.push_back(Edge(n1, n2, c));
	}

	int edge_list_size = edge_list.size();
	Sort(edge_list, edge_list_size);

	int ans=0;

	for (int i = 0; i < E; i++)
	{
		int a = edge_list[i].node1;
		int b = edge_list[i].node2;

		if (Find(parent, a) == Find(parent, b))
			continue;
		else
		{
			ans += edge_list[i].cost;
			Union(parent, a, b);
		}
	}

	cout << ans;

	return 0;
}