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

char stu[7][7];
bool use[30];
vector<pair<int, int>> ans;

int cnt;
int cnt_s;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool check()
{
    queue<pair<int, int>> q;
    pair<int, int> cur;

    cur.first = ans[0].first;
    cur.second = ans[0].second;

    q.push({ cur.first, cur.second });

    bool flag[7] = { 0 };
    int count = 1;
    flag[0] = 1;
    
    while (!q.empty())
    {
        cur.first = q.front().first;
        cur.second = q.front().second;

        q.pop();
        for (int t = 1; t < 7;t++)
        {
            if (flag[t])
                continue;

            for (int i = 0;i < 4;i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                if (nx == ans[t].first && ny == ans[t].second)
                {
                    q.push({ nx,ny });
                    flag[t] = 1;
                    count++;
                }
            }
        }
    }
    
    if (count == 7)
        return true;
    else
    {
        //cout << "boom" << "\n";
        return false;

    }
}


void dfs(int dep, int ds, int ld)
{
    if (ds + ld == 7)
    {
        if (ds >= 4)
        {
            if (check())
                cnt++;
        }
        return;
    }

   

    for (int i = dep;i < 25;i++)
    {
        if (!use[i])
        {
            int r = i / 5;
            int c = i % 5;

            use[i] = 1;
            ans.push_back({ r, c });

            if (stu[r][c] == 'S')
                dfs(i + 1, ds + 1, ld);
            else
                dfs(i + 1, ds, ld + 1);

            use[i] = 0;
            ans.pop_back();
        }
    }


}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    for (i = 0;i < 5;i++)
    {
        string s; cin >> s;
        for (j = 0;j < 5;j++)
            stu[i][j] = s[j];
    }

    dfs(0, 0, 0);

    cout << cnt << "\n";

    return 0;
}

