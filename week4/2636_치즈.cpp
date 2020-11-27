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
    int z, y, x;
};

int n, m, k;
int chs[110][110];
bool vis[110][110];

//int dz[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int cnt = 0;
int con = 0;

void blank(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({ y,x });
    vis[y][x] = 1;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        chs[cur.first][cur.second] = 2;
        for (int i = 0;i < 4;i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (vis[ny][nx])
                continue;
            if (chs[ny][nx] != 0)
                continue;

            q.push({ ny,nx });
            vis[ny][nx] = 1;

        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n >> m;

    for (i = 0;i < n;i++)
        for (j = 0;j < m;j++)
        {
            int x; cin >> x;
            chs[i][j] = x;
        }


    int cnt_chs = 0;
    int tmp = 0;
    while (1)
    {
        memset(vis, 0, sizeof(vis));

        for (j = 0;j < m - 1;j++)
            if (chs[0][j] == 0 && !vis[0][j])
                blank(0, j);


        for (j = 0;j < m - 1;j++)
            if (chs[n - 1][j] == 0 && !vis[n - 1][j])
                blank(n - 1, j);

        for (i = 0;i < n - 1;i++)
            if (chs[i][0] == 0 && !vis[i][0])
                blank(i, 0);

        for (i = 0;i < n - 1;i++)
            if (chs[i][m - 1] == 0 && !vis[i][m - 1])
                blank(i, m - 1);

        k = 0;
        queue<pair<int, int>> q;

        memset(vis, 0, sizeof(vis));

        for (i = 1;i < n;i++)
            for (j = 1;j < m;j++)
                if (chs[i][j] == 1)
                {
                    cnt_chs++;
                    if (!vis[i][j])
                    {
                        q.push({ i,j });
                        k = 1;
                    }
                }

        if (k == 0)
            break;

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();

            for (int b = 0;b < 4;b++)
            {
                int ny = cur.first + dy[b];
                int nx = cur.second + dx[b];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                    continue;
                if (vis[ny][nx])
                    continue;

                if (chs[ny][nx] == 2)
                    chs[cur.first][cur.second] = 0;

                if (chs[ny][nx] == 1)
                {
                    q.push({ ny,nx });
                    vis[ny][nx] = 1;
                }
            }

        }
        cnt++;

        for (i = 0;i < n;i++)
            for (j = 0;j < m;j++)
                if (chs[i][j] != 1)
                    chs[i][j] = 0;

        /*
        for (i = 0;i < n;i++)
        {
            for (j = 0;j < m;j++)
                cout << chs[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
        */
        tmp = cnt_chs;
        cnt_chs = 0;
    }

    cout << cnt << "\n" << tmp << "\n";

    return 0;
}
