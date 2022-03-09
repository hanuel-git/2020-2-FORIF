#include<iostream>
#include<vector>
using namespace std;

int N, M;
int adj[10][10];
int island_num = 1;
int move_p[4][2] = { {0, -1}, {1,0}, {0,1}, {-1, 0} };
vector<pair<int, int>> Pos[10];

// 1. 섬에 숫자(이름) 붙이기
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

// 2. 다리 구하기
typedef struct Bridge
{
	int land_A;
	int land_B;
	int distance;
} Bridge;
Bridge b[15];

void find_distance(int(*ptr)[10], int land_A, int land_B) // land_A와 land_B 사이의 거리 구하기
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

 // 3. 최소 거리 구하기(MST)



int main()
{
	// 지도의 세로크기 N과 가로크기 M 입력받기
	cin >> N >> M;
	// 지도의 정보 입력받기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> adj[i][j];
		}
	}
	int(*ptr)[10] = adj;

	// 1. 섬에 숫자(이름) 붙이기
	labeling(ptr); 
	for (int i = 0; i < N; i++) // 섬 번호 1부터 시작하도록
	{
		for (int j = 0; j < M; j++)
		{
			if (ptr[i][j] != 0)
				ptr[i][j]--;
		}
	}
	for (int k = 1; k < island_num; k++) // 섬별로 좌표 저장
	{
		Store_pos(ptr, k);
	}

	// 2. 다리 구하기
	get_distance(ptr);

	// 3. 최소 거리 구하기

}