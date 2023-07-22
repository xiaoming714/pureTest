#include <iostream>
#include <vector>

using namespace std;

int func(vector<vector<int>> &vec)
{
    int res = 0;
    for (int i = 0; i < vec[0].size(); i++)
    {
        int temp = 0;
        for (int j = vec.size() - 1; j >= 0; j--)
        {
            if (vec[j][i])
            {
                temp += vec[j][i];
                // cout << vec[i][j];
            }
            else
            {
                temp = 0;
            }
        }
        res += temp;
    }
    return res;
}

int main()
{
    vector<vector<int>> vec = {{0, 3, 3}, {1, 0, 4}, {2, 5, 0}};

    // for (int i = 0; i < vec.size(); ++i)
    // {
    //     for (int j = 0; j < vec.size(); ++j)
    //     {
    //         cout << vec[i][j];
    //     }
    //     cout << endl;
    // }
    cout << func(vec);
    return 0;
}