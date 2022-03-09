#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define MAX 10002

int V, E, Answer; // V : 정점의 개수 , E : 간선의 개수, Answer : 최소신장트리의 가중치 합
int Dist[MAX]; // 업데이트된 정점간의 길이 저장용
bool Select[MAX]; // 선택여부 표시
vector<pair<int, int>> Cost[MAX]; // 연결된 정점과 가중치 저장용


void Prim()
{
    Dist[1] = 0; // 시작점 : 1번정점
    Select[1] = true; // 1번정점 선택
    for (int i = 0; i < Cost[1].size(); i++)
    {
        int Next = Cost[1][i].first; // 1번정점과 연결된 정점
        int Distance = Cost[1][i].second; // 1번정점과 연결된 거리(가중치)
        Dist[Next] = Distance; // 정점간의 길이 업데이트
    }

    for (int i = 1; i <= V - 1; i++)
    {
        int Min_Cost = 1000000;
        int Min_Idx = -1;
        for (int j = 1; j <= V; j++)  // 가장 짧은 간선으로 연결되어 있는 정점 탐색
        {
            if (Select[j] == true) continue; // 이미 선택된 정점일 경우 다음 정점으로 이동
            if (Min_Cost > Dist[j])
            {
                Min_Cost = Dist[j];
                Min_Idx = j;
            }
        }
        Select[Min_Idx] = true; // 정점 선택
        Answer = Answer + Min_Cost; 

        for (int j = 0; j < Cost[Min_Idx].size(); j++) // 정점들의 거리 업데이트
        {
            int Next = Cost[Min_Idx][j].first;
            int Distance = Cost[Min_Idx][j].second;

            if (Select[Next] == true) continue;
            if (Dist[Next] > Distance) Dist[Next] = Distance;
        }
    }
    cout << Answer << endl;
}

int main()
{
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Cost[A].push_back(make_pair(B, C));
        Cost[B].push_back(make_pair(A, C));
    }

    Prim();
    return 0;
}
