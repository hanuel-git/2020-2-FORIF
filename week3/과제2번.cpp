#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    int pro_size = progresses.size();

    for (int i = 0; i < pro_size; i++)
    {
        int t = 0;
        while (1)
        {
            if ((progresses[i] + t * speeds[i]) >= 100)
                break;
            t++;
        }
        time.push_back(t);
    }

    int time_size = time.size();
    int left = 0;
    int right = 1;
    int ans = 0;

    while (1)
    {
        if (time[left] >= time[right])
        {
            right++;
        }
        else
        {
            ans = right - left;
            answer.push_back(ans);
            left = right;
            right++;
        }

        if (right >= time_size)
        {
            ans = right - left;
            answer.push_back(ans);
            break;
        }
    }

    return answer;
}