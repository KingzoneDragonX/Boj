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
struct trp {
    int y,x,lim;
};

int n, m, k;
int mon[220][220];
bool vis[220][220][35];

//int dz[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1};
int dx[] = { 1,-1,0,0};
int ay[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int ax[] = { 2, -2, 2, -2, 1, -1, 1, -1};

int cnt = 0;
int con = 0;

int bfs(int y, int x, int lim)
{
    queue<trp> q;
    q.push({ y, x, lim });
    vis[y][x][lim] = 1;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            trp cur = q.front();
            q.pop();
            //mon[cur.y][cur.x] = 2;

            if (cur.y == n - 1 && cur.x == m - 1)
            {
                return cnt;
                break;
            }

            if (cur.lim < k)
            {
                for (int i = 0;i < 8;i++)
                {
                    int ny = cur.y + ay[i];
                    int nx = cur.x + ax[i];
                    int nl = cur.lim;

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;
                    if (vis[ny][nx][nl+1])
                        continue;
                    if (mon[ny][nx] != 0)
                        continue;

                    
                    q.push({ ny,nx,nl + 1 });
                    vis[ny][nx][nl + 1] = 1;
                    
                }

                for (int i = 0;i < 4;i++)
                {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];
                    int nl = cur.lim;

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;
                    if (vis[ny][nx][nl])
                        continue;
                    if (mon[ny][nx] != 0)
                        continue;

                    
                    q.push({ ny,nx,nl });
                    vis[ny][nx][nl] = 1;
                    
                }
            }

            else
            {
                for (int i = 0;i < 4;i++)
                {
                    int ny = cur.y + dy[i];
                    int nx = cur.x + dx[i];
                    int nl = cur.lim;

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                        continue;
                    if (vis[ny][nx][nl])
                        continue;
                    if (mon[ny][nx] != 0)
                        continue;

                    
                    q.push({ ny,nx,nl });
                    vis[ny][nx][nl] = 1;
                   
                }
            }
        }
        cnt++;

    }

    con = 1;
    return 0;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> k;
    cin >>m >> n;
    
    for(i=0;i<n;i++)
        for (j = 0;j < m;j++)
        {
            int x; cin >> x;
            mon[i][j] = x;
        }

    int ret = bfs(0, 0, 0);

    if (con == 1)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}

