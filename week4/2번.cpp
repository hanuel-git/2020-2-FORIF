#include<iostream>
#include<algorithm>
using namespace std;

int n;
int adj[26][26] = { -1, };
int house_name=0;
int house_num[314] = { 0, };
int move_p[4][2] = { {0, -1}, {1,0}, {0,1}, {-1, 0} };

void dfs(int y, int x, int house_name);
void search();

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf_s("%1d", &adj[i][j]);
	}

	search();

	cout << house_name << endl;
	
	sort(house_num + 1, house_num + house_name + 1);
	if (house_name != 0)
	{
		for (int j = 1; j <= house_name; j++)
			cout << house_num[j] << endl;
	}
	return 0;
}

void dfs(int y, int x, int house_name)
{
	adj[y][x] = -1;
	house_num[house_name]++;

	int dx;
	int dy;
	int near_house;
	for (int k = 0; k < 4; k++)
	{
		dx = x + move_p[k][0];
		dy = y + move_p[k][1];
		near_house = adj[dy][dx];
		if (0 <= dx && dx < n
			&& 0 <= dy && dy < n
			&& near_house == 1)
			dfs(dy, dx, house_name);
	}
	return;
}

void search()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adj[i][j] == 1)
				dfs(i, j, ++house_name);
		}
	}
	return;
}