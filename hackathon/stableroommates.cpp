#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<string>
using namespace std;

class StableRoommates
{
    void deleteFromTable(string x, string y);
    void deleteFrom(int st, int en, string x);
public:
    //Vertex stores all the names, Table stores the preference table, and Rank store the rank of person b in a's Preference List
    set<string> Vertex;
    map<string, vector<string> > Table;
    map< pair <string, string>, long long> Rank;
    set<pair<string, string>> mates;
    map<pair<string, string>, bool> Exist;
};

inline void StableRoommates::deleteFromTable(string x, string y)
{
    Table[x][Rank[make_pair(x, y)] - 1] = "";
    Exist[make_pair(x, y)] = false;
}
void StableRoommates::deleteFrom(int st, int end, string y) {
    for (int i = st; i < end; i++)
    {
        if (Table[y][i] != "")   //if has not been deleted
        {
            string z = Table[y][i];
            if (Exist[make_pair(z, y)]) deleteFromTable(z, y);
            deleteFromTable(y, z);
        }
    }
}

map<int, string> dict;
int N;
vector<int>* V;

int main()
{

    string Table_keys[] = { "���ٿ�", "������", "����", "��â��" ,"�̼���",
    "�赿��", "����","������", "�ΰ�ȯ", "�Ѱ���", "�����", "�ӱԹ�",
    "����ȣ", "��α�","������","������", "�質��", "�缺��", "�̼���",
    "�輭��", "����ä", "���ϴ�" };


    StableRoommates S;
    S.Table["���ٿ�"] = vector <string>{ "������", "�̼���", "����", "�̼���", "�Ѱ���", "�缺��", "������", "����", "�ӱԹ�", "��â��", "���ϴ�", "��α�", "�����", "������", "������", "�ΰ�ȯ", "����ȣ", "�輭��", "�赿��", "�質��", "����ä" };
    S.Table["������"] = vector <string>{ "�赿��", "�̼���", "�ӱԹ�", "������", "�̼���", "������", "����ȣ", "�����", "�缺��", "��â��", "������", "�質��", "�輭��", "���ϴ�", "����", "�Ѱ���", "���ٿ�", "����ä", "��α�", "�ΰ�ȯ", "����" };
    S.Table["����"] = vector <string>{ "�̼���", "����", "������", "�缺��", "���ٿ�", "��α�", "�̼���", "��â��", "�����", "������", "�Ѱ���", "�ӱԹ�", "������", "�輭��", "�ΰ�ȯ", "������", "���ϴ�", "�質��", "�赿��", "����ȣ", "����ä" };
    S.Table["��â��"] = vector <string>{ "�缺��", "�̼���", "����", "�ӱԹ�", "������", "�̼���", "������", "�ΰ�ȯ", "���ٿ�", "���ϴ�", "�Ѱ���", "����", "������", "�����", "��α�", "�赿��", "������", "����ȣ", "�質��", "����ä", "�輭��" };
    S.Table["�̼���"] = vector <string>{ "����", "����", "�̼���", "������", "��α�", "�缺��", "���ٿ�", "��â��", "�Ѱ���", "�ӱԹ�", "�����", "������", "������", "������", "�ΰ�ȯ", "���ϴ�", "�質��", "�輭��", "�赿��", "����ȣ", "����ä" };
    S.Table["�赿��"] = vector <string>{ "������", "������", "������", "�ӱԹ�", "�̼���", "����ȣ", "����ä", "�����", "�質��", "�缺��", "��â��", "�̼���", "���ϴ�", "�Ѱ���", "���ٿ�", "������", "����", "����", "��α�", "�ΰ�ȯ", "�輭��" };
    S.Table["����"] = vector <string>{ "������", "�̼���", "���ٿ�", "����", "�̼���", "��â��", "�缺��", "�����", "�Ѱ���", "��α�", "�ΰ�ȯ", "������", "�ӱԹ�", "������", "���ϴ�", "������", "����ȣ", "�赿��", "�質��", "�輭��", "����ä" };
    S.Table["������"] = vector <string>{ "�����", "������", "������", "�赿��", "�̼���", "���ٿ�", "����", "�̼���", "����ȣ", "������", "��â��", "�Ѱ���", "�缺��", "�質��", "����ä", "����", "���ϴ�", "�ӱԹ�", "�輭��", "�ΰ�ȯ", "��α�" };
    S.Table["�ΰ�ȯ"] = vector <string>{ "��α�", "���ϴ�", "����", "������", "��â��", "�̼���", "�̼���", "����ȣ", "�質��", "�Ѱ���", "�����", "�缺��", "�ӱԹ�", "���ٿ�", "����", "������", "�輭��", "������", "����ä", "�赿��", "������" };
    S.Table["�Ѱ���"] = vector <string>{ "�̼���", "������", "���ٿ�", "�̼���", "����", "�����", "������", "��â��", "�ΰ�ȯ", "�缺��", "��α�", "�ӱԹ�", "����", "������", "���ϴ�", "�赿��", "������", "����ȣ", "�輭��", "�質��", "����ä" };
    S.Table["�����"] = vector <string>{ "������", "������", "����", "������", "�̼���", "�赿��", "�̼���", "�Ѱ���", "����ȣ", "������", "�質��", "���ٿ�", "��â��", "����", "�ΰ�ȯ", "�缺��", "����ä", "�ӱԹ�", "��α�", "���ϴ�", "�輭��" };
    S.Table["�ӱԹ�"] = vector <string>{ "�缺��", "�̼���", "��â��", "������", "�赿��", "�̼���", "���ٿ�", "���ϴ�", "����", "������", "������", "��α�", "�Ѱ���", "����", "����ȣ", "������", "�ΰ�ȯ", "�����", "�質��", "����ä", "�輭��" };
    S.Table["����ȣ"] = vector <string>{ "�質��", "����ä", "���ϴ�", "��α�", "�赿��", "������", "������", "������", "�̼���", "�ΰ�ȯ", "�����", "�輭��", "�ӱԹ�", "�̼���", "������", "�缺��", "���ٿ�", "����", "��â��", "�Ѱ���", "����" };
    S.Table["��α�"] = vector <string>{ "�ΰ�ȯ", "�̼���", "���ϴ�", "�質��", "����", "�̼���", "����ȣ", "������", "�缺��", "����", "�輭��", "���ٿ�", "��â��", "�Ѱ���", "�ӱԹ�", "�����", "������", "������", "����ä", "������", "�赿��" };
    S.Table["������"] = vector <string>{ "����", "���ٿ�", "�̼���", "�̼���", "�Ѱ���", "��â��", "�����", "������", "�缺��", "����", "�ΰ�ȯ", "��α�", "�ӱԹ�", "���ϴ�", "������", "������", "����ȣ", "�赿��", "�輭��", "�質��", "����ä" };
    S.Table["������"] = vector <string>{ "�赿��", "������", "������", "�質��", "�����", "�̼���", "����ȣ", "�̼���", "����ä", "�ӱԹ�", "�缺��", "����", "���ٿ�", "�輭��", "���ϴ�", "��â��", "����", "������", "�Ѱ���", "��α�", "�ΰ�ȯ" };
    S.Table["�質��"] = vector <string>{ "����ȣ", "��α�", "����ä", "������", "�赿��", "�ΰ�ȯ", "�����", "�輭��", "������", "���ϴ�", "������", "�̼���", "�̼���", "�ӱԹ�", "�缺��", "����", "����", "��â��", "������", "�Ѱ���", "���ٿ�" };
    S.Table["�缺��"] = vector <string>{ "�ӱԹ�", "��â��", "�̼���", "�̼���", "����", "���ٿ�", "������", "����", "��α�", "������", "������", "���ϴ�", "�ΰ�ȯ", "������", "�Ѱ���", "�����", "�赿��", "�質��", "����ȣ", "����ä", "�輭��" };
    S.Table["�̼���"] = vector <string>{ "�̼���", "�Ѱ���", "�ӱԹ�", "���ٿ�", "������", "�缺��", "������", "����", "��â��", "���ϴ�", "������", "�赿��", "��α�", "������", "�����", "����", "�ΰ�ȯ", "����ȣ", "�質��", "�輭��", "����ä" };
    S.Table["�輭��"] = vector <string>{ "��α�", "���ϴ�", "�質��", "������", "����ȣ", "�̼���", "������", "����ä", "����", "������", "�ΰ�ȯ", "�̼���", "�����", "���ٿ�", "����", "������", "�Ѱ���", "�缺��", "�赿��", "��â��", "�ӱԹ�" };
    S.Table["����ä"] = vector <string>{ "����ȣ", "���ϴ�", "�質��", "�赿��", "������", "������", "�輭��", "������", "�����", "�ӱԹ�", "��α�", "�ΰ�ȯ", "�̼���", "��â��", "�缺��", "�̼���", "���ٿ�", "������", "����", "����", "�Ѱ���" };
    S.Table["���ϴ�"] = vector <string>{ "�̼���", "��α�", "����ä", "�ΰ�ȯ", "����ȣ", "�ӱԹ�", "���ٿ�", "��â��", "�輭��", "������", "�缺��", "�̼���", "�質��", "������", "������", "����", "�Ѱ���", "������", "�赿��", "����", "�����" };

    for (int i = 0; i < 22; i++) {
        S.Vertex.insert(Table_keys[i]);
    }

    dict[0] = "���ٿ�";
    dict[1] = "������";
    dict[2] = "����";
    dict[3] = "��â��";
    dict[4] = "�̼���";
    dict[5] = "�赿��";
    dict[6] = "����";
    dict[7] = "������";
    dict[8] = "�ΰ�ȯ";
    dict[9] = "�Ѱ���";
    dict[10] = "�����";
    dict[11] = "�ӱԹ�";
    dict[12] = "����ȣ";
    dict[13] = "��α�";
    dict[14] = "������";
    dict[15] = "������";
    dict[16] = "�質��";
    dict[17] = "�缺��";
    dict[18] = "�̼���";
    dict[19] = "�輭��";
    dict[20] = "����ä";
    dict[21] = "���ϴ�";

    //Step 1
    N = dict.size();
    V = new vector<int>[N];

    map<string, bool> received; 
    map<string, string> proposer;

    stack<string> fr;

    for (int i = N - 1; i >= 0; i--) //initialize
        fr.push(Table_keys[i]);


    while (!fr.empty())
    {
        string s_top = fr.top();
        //cout << "s_top: " << s_top << endl;
        string receiver = S.Table[s_top][0];
        bool flag = false;

        fr.pop();

        if (received[receiver] == false)
        {//��ȣ�� ��ġ�� ���� ��
            received[receiver] = true;
            proposer[receiver] = s_top;
        }
        else
        {//��ȣ�� ��ĥ ��, �������� ���� ��뿡�Լ� �� ���� ��ȣ�� ���� ����� ����
            int count = 0;
            string to_be_deleted = "";
            string store_string = "";


            for (auto iter = S.Table[receiver].begin(); iter != S.Table[receiver].end();)
            {
                if (count != 2)
                {//�� ���� ��ȣ�� ���� ����� �� ã��
                    if (*iter == proposer[receiver] || *iter == s_top)
                    {
                        count++;
                        //cout << "receiver: " << receiver << " and count : " << count << endl;

                        //cout << *iter << endl;

                        if (count == 1)//receiver�� ��ȣ �� �� ���� ��ȣ�Ǵ� ���
                            store_string = *iter;

                        if (count == 2)//receiver�� ��ȣ �� �� ���� ��ȣ�Ǵ� ���
                            to_be_deleted = *iter;

                    }
                    ++iter;
                    if (iter == S.Table[receiver].end())
                        --iter;
                }
                else
                {
                    proposer[receiver] = store_string;
                    fr.push(to_be_deleted);

                    for (auto iter = S.Table[to_be_deleted].begin(); iter != S.Table[to_be_deleted].end(); iter++)
                    {
                        if (*iter == receiver)
                        {
                            S.Table[to_be_deleted].erase(iter);
                            break;
                        }
                    }

                    for (auto iter = S.Table[receiver].begin(); iter != S.Table[receiver].end(); iter++)
                    {
                        if (*iter == to_be_deleted)
                        {
                            S.Table[receiver].erase(iter);
                            break;
                        }
                    }

                    flag = true;
                }
                if (flag == true)
                    break;
            }
        }
    }


    //Step2

    for (auto x : S.Vertex) {
        string y = S.Table[x][0];
        int hi = find(S.Table[y].begin(), S.Table[y].end(), x) - S.Table[y].begin();
        vector<string>::iterator iter = S.Table[y].begin();
        for (int i = hi + 1; i < S.Table[y].size(); i++) {
            S.Table[S.Table[y][i]].erase(remove(S.Table[S.Table[y][i]].begin(),
                S.Table[S.Table[y][i]].end(), y), S.Table[S.Table[y][i]].end());

        }
        S.Table[y].erase(iter + hi + 1, iter + S.Table[y].size());


    }

    //Step 3
    vector <string> finalP;
    vector <string> finalQ;
    for (auto x1 = S.Vertex.begin(); x1 != S.Vertex.end(); x1++) {
        string x = *x1;
        if (S.Table[x].size() < 2)
            continue;
        while (1) {
            vector<string>::iterator iter = find(finalP.begin(), finalP.end(), x);
            if (iter != finalP.end()) {
                S.Table[finalQ.back()].erase(remove(S.Table[finalQ.back()].begin(), S.Table[finalQ.back()].end(), x), S.Table[finalQ.back()].end());
                S.Table[x].erase(remove(S.Table[x].begin(), S.Table[x].end(), finalQ.back()), S.Table[x].end());
                finalQ.pop_back();
                while (!finalQ.empty()) {
                    S.Table[finalQ.back()].erase(remove(S.Table[finalQ.back()].begin(), S.Table[finalQ.back()].end(), finalP.back()), S.Table[finalQ.back()].end());
                    S.Table[finalP.back()].erase(remove(S.Table[finalP.back()].begin(), S.Table[finalP.back()].end(), finalQ.back()), S.Table[finalP.back()].end());
                    finalP.pop_back();
                    finalQ.pop_back();
                }
                break;
            }
            string q = S.Table[x][1];
            finalQ.push_back(q);
            finalP.push_back(x);
            x = S.Table[q][S.Table[q].size() - 1];
        }
    }



    //Print
    vector <string> final;
    cout << "**Forif ���� ����Ʈ**" << endl << endl;
    for (auto x = S.Vertex.begin(); x != S.Vertex.end(); x++) {
        if (find(final.begin(), final.end(), *x) != final.end())
            continue;
        cout << *x << " ��  ";
        for (int i = 0; i < S.Table[*x].size(); i++) {
            cout << S.Table[*x][i];
            final.push_back(S.Table[*x][i]);
        }
        cout << endl;
    }
    cout << endl << "*End*" << endl;

    return 0;
}

