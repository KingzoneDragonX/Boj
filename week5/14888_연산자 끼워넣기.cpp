#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라 ,  stack 
#include <algorithm>        //sort 함수사용
#include <utility>
#include <queue>            // queue        queue에는 front와 back이 있다.
#include <set>
#include <map>
#include <cstring>


using namespace std;

int n, m;

int num[15];
int sym[5];
int ans[15];

int cnt;
int big = -1000000000;
int sml = 1000000000;

void dfs(int dep, int ret)
{
    if (dep == n-1)
    {
        if (ret > big)
            big = ret;

        if (ret < sml)
            sml = ret;

        return;
    }
    
    for (int i = 0;i < 4;i++)
    {
        if (sym[i] > 0)
        {
            if (i == 0)
            {
                ret += num[dep + 1];
                sym[i]--;

                dfs(dep + 1, ret);

                sym[i]++;
                ret -= num[dep + 1];
            }

            else if (i == 1)
            {
                ret -= num[dep + 1];
                sym[i]--;

                dfs(dep + 1, ret);

                sym[i]++;
                ret += num[dep + 1];
            }

            else if (i == 2)
            {
                ret *= num[dep + 1];
                sym[i]--;

                dfs(dep + 1, ret);

                sym[i]++;
                ret /= num[dep + 1];
            }

            else if (i == 3)
            {
                int r = ret % num[dep + 1];
                ret /= num[dep + 1];
                sym[i]--;

                dfs(dep + 1, ret);

                sym[i]++;
                ret /= num[dep + 1];
                ret += r;
            }

        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n;
    for (i = 0;i < n;i++)
    {
        int x; cin >> x;
        num[i] = x;
    }

    for (i = 0;i < 4;i++)
    {
        int x; cin >> x;
        sym[i] = x;
    }

    dfs(0, num[0]);

    cout << big << "\n" << sml << "\n";

    return 0;
}

