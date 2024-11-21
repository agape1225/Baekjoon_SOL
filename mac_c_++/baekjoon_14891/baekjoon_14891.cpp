#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    int left = 2;
    int right = 6;
    int score[4] = {1, 2, 4, 8};
    int ans = 0;
    vector<string> wheel;
    vector<pair<int, int>> commands;
    int wheel_num, dir;
    int K;

    for (int i = 0; i < 4; i++)
    {
        string tmp;
        cin >> tmp;
        wheel.push_back(tmp);
    }

    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> wheel_num >> dir;

        commands.push_back(make_pair(wheel_num - 1, dir));
    }

    for (auto command : commands)
    {

        int dirs[4] = {0};

        wheel_num = command.first;
        dir = command.second;

        dirs[wheel_num] = dir;
        int wheel_tmp = wheel_num;

     

        // right dir
        while (true)
        {
            if (wheel_tmp == 3)
            {
                break;
            }
            else
            {
                cout << wheel[wheel_tmp][right] << ' ' <<  wheel[wheel_tmp + 1][left] << endl;
                if (wheel[wheel_tmp][right] != wheel[wheel_tmp + 1][left])
                {
                    dirs[wheel_tmp + 1] = dirs[wheel_tmp] * -1;
                    wheel_tmp++;
                }
                else
                {
                    break;
                }
            }
        }

        wheel_tmp = wheel_num;

        while (true)
        {
            if (wheel_tmp == 0)
            {
                break;
            }
            else
            {
                if (wheel[wheel_tmp][left] != wheel[wheel_tmp - 1][right])
                {
                    dirs[wheel_tmp - 1] = dirs[wheel_tmp] * -1;
                    wheel_tmp--;
                }
                else
                {
                    break;
                }
            }
        }

        for(int i = 0; i < 4; i++){
            cout << dirs[i] << ' ';
        }
        cout << endl;

        // 회전 진행
        for (int i = 0; i < 4; i++)
        {
            string new_wheel = wheel[i];
            string current_wheel = wheel[i];
            if (dirs[i] == 1)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (j == 7)
                    {
                        new_wheel[0] = current_wheel[j];
                    }
                    else
                    {
                        new_wheel[j + 1] = current_wheel[j];
                    }
                }

                wheel[i] = new_wheel;
                // cout << current_wheel << " , " << new_wheel << endl;
            }
            else if (dirs[i] == -1)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (j == 0)
                    {
                        new_wheel[7] = current_wheel[j];
                    }
                    else
                    {
                        new_wheel[j - 1] = current_wheel[j];
                    }
                }
                wheel[i] = new_wheel;
                // cout << current_wheel << " , " << new_wheel << endl;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        cout << wheel[i] << endl;
        if(wheel[i][0] == '1'){
            ans += score[i];
        }
    }

    cout << ans;

    return 0;
}