#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;

    for (int i = 0; i < moves.size(); i++)
    {
        int index = moves[i] - 1;
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][index] != 0)
            {
                int temp = 0;
                if (!basket.empty())
                    temp = basket.top();
                basket.push(board[j][index]);
                board[j][index] = 0;
                if (temp == basket.top())
                {
                    basket.pop();
                    basket.pop();
                    answer += 2;
                }
                break;
            }
        }
    }
    return answer;
}