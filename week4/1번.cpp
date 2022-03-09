#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
#define MAX 1001

int n, m, v;
vector<int> adj[MAX];
vector<bool> visited_a(MAX + 1, false);
vector<bool> visited_b(MAX + 1, false);


void dfs(vector<int> adj[], int root)
{
	stack<int> s;

	s.push(root);
	visited_a[root] = true;
	cout << root << " ";

	while (!s.empty())
	{
		int node = s.top();
		s.pop();
		for (auto x : adj[node])
		{
			if (!visited_a[x])
			{
				cout << x << " ";
				visited_a[x] = true;
				s.push(node);
				s.push(x);
				break;
			}
		}
	}
}

void bfs(vector<int> adj[], int root)
{
	queue<int> q;

	q.push(root);
	visited_b[root] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (auto x : adj[node])
		{
			if (!visited_b[x])
			{
				visited_b[x] = true;
				q.push(x);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(adj, v);
	cout << endl;
	bfs(adj, v);

	return 0;
}