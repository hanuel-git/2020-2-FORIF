#include<iostream>
#include<vector>
using namespace std;

int N, M;
int adj[10][10];
int island_num = 1;
int move_p[4][2] = { {0, -1}, {1,0}, {0,1}, {-1, 0} };
vector<pair<int, int>> Pos[10];

// 1. ���� ����(�̸�) ���̱�
void dfs(int(*ptr)[10], int y, int x, int island_num)
{
	ptr[y][x] = island_num;
	
	int dx;
	int dy;
	int near;
	for (int k = 0; k < 4; k++)
	{
		dx = x + move_p[k][0];
		dy = y + move_p[k][1];
		near = ptr[dy][dx];
		if (0 <= dx && dx < M && 0 <= dy && dy < N && near == 1)
			dfs(ptr, dy, dx, island_num);
	}
	return;
}

void labeling(int(*ptr)[10])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ptr[i][j] == 1)
				dfs(ptr, i, j, ++island_num);
		}
	}
}

void Store_pos(int(*ptr)[10], int num)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ptr[i][j] == num)
			{
				Pos[num].push_back(make_pair(i, j));
			}
		}
	}
}

// 2. �ٸ� ���ϱ�
typedef struct Bridge
{
	int land_A;
	int land_B;
	int distance;
} Bridge;
Bridge b[15];

void find_distance(int(*ptr)[10], int land_A, int land_B) // land_A�� land_B ������ �Ÿ� ���ϱ�
{
	
}

void get_distance(int(*ptr)[10])
{
	for (int i = 1; i < island_num; i++)
	{
		for (int j = i + 1; j < island_num; j++)
		{
			find_distance(ptr, i, j); 
		}
	}
}

 // 3. �ּ� �Ÿ� ���ϱ�(MST)



int main()
{
	// ������ ����ũ�� N�� ����ũ�� M �Է¹ޱ�
	cin >> N >> M;
	// ������ ���� �Է¹ޱ�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> adj[i][j];
		}
	}
	int(*ptr)[10] = adj;

	// 1. ���� ����(�̸�) ���̱�
	labeling(ptr); 
	for (int i = 0; i < N; i++) // �� ��ȣ 1���� �����ϵ���
	{
		for (int j = 0; j < M; j++)
		{
			if (ptr[i][j] != 0)
				ptr[i][j]--;
		}
	}
	for (int k = 1; k < island_num; k++) // ������ ��ǥ ����
	{
		Store_pos(ptr, k);
	}

	// 2. �ٸ� ���ϱ�
	get_distance(ptr);

	// 3. �ּ� �Ÿ� ���ϱ�

}