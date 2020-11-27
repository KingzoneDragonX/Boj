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
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

char mz[1100][1100];
int vis[1100][1100][2];

void bfs(int y, int x)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ {y,x},0 });    //0은 벽안부숨, 1은 부숨

    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<pair<int, int>, int> cur = q.front();
            q.pop();


            if (cur.first.first == n - 1 && cur.first.second == m - 1)
            {
                cout << cnt + 1 << "\n";
                return;
            }

            for (int i = 0;i < 4;i++)
            {
                int ny = cur.first.first + dy[i];
                int nx = cur.first.second + dx[i];
                int s = cur.second;

                if (ny < 0 || ny>=n || nx < 0 || nx>=m)
                    continue;

                if (vis[ny][nx][s])
                    continue;

                if (s == 1 && mz[ny][nx] == '1')
                    continue;

                if (s == 1 && mz[ny][nx] == '0')
                {
                    q.push({ {ny,nx},1 });
                    vis[ny][nx][1] = 1;
                }

                if (s == 0)
                {
                    if (mz[ny][nx] == '0')
                    {
                        q.push({ {ny,nx}, 0 });
                        vis[ny][nx][0] = 1;
                    }

                    else
                    {
                        q.push({ {ny,nx}, 1 });
                        vis[ny][nx][1] = 1;
                    }
                }


            }

        }
        cnt++;
    }

    cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n >> m;
    for (i = 0;i < n;i++)
    {
        string s; cin >> s;
        for (j = 0;j < m;j++)
            mz[i][j] = s[j];
    }

    bfs(0, 0);

    return 0;
}

