#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define MAX 10002

int V, E, Answer; // V : ������ ���� , E : ������ ����, Answer : �ּҽ���Ʈ���� ����ġ ��
int Dist[MAX]; // ������Ʈ�� �������� ���� �����
bool Select[MAX]; // ���ÿ��� ǥ��
vector<pair<int, int>> Cost[MAX]; // ����� ������ ����ġ �����


void Prim()
{
    Dist[1] = 0; // ������ : 1������
    Select[1] = true; // 1������ ����
    for (int i = 0; i < Cost[1].size(); i++)
    {
        int Next = Cost[1][i].first; // 1�������� ����� ����
        int Distance = Cost[1][i].second; // 1�������� ����� �Ÿ�(����ġ)
        Dist[Next] = Distance; // �������� ���� ������Ʈ
    }

    for (int i = 1; i <= V - 1; i++)
    {
        int Min_Cost = 1000000;
        int Min_Idx = -1;
        for (int j = 1; j <= V; j++)  // ���� ª�� �������� ����Ǿ� �ִ� ���� Ž��
        {
            if (Select[j] == true) continue; // �̹� ���õ� ������ ��� ���� �������� �̵�
            if (Min_Cost > Dist[j])
            {
                Min_Cost = Dist[j];
                Min_Idx = j;
            }
        }
        Select[Min_Idx] = true; // ���� ����
        Answer = Answer + Min_Cost; 

        for (int j = 0; j < Cost[Min_Idx].size(); j++) // �������� �Ÿ� ������Ʈ
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
