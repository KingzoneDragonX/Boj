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

int l, r, c;
char mz[35][35][35];
bool vis[35][35][35];

int dz[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0};
int dx[] = { 1,-1,0,0,0,0};

int cnt = 0;
int con = 1;

struct trp {
    int z, y, x;
};

int bfs(int z, int y, int x)
{
    cnt = 0;
    con = 1;

    queue<trp> q;
    q.push({ z, y, x });
    vis[z][y][x] = 1;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            trp cur = q.front();
            q.pop();

            for (int i = 0;i < 6;i++)
            {
                int nz = cur.z + dz[i];
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (mz[nz][ny][nx] == 'E')
                    return cnt;

                if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c)
                    continue;
                if (vis[nz][ny][nx])
                    continue;
                if (mz[nz][ny][nx] != '.')
                    continue;

                q.push({ nz,ny,nx });
                vis[nz][ny][nx] = 1;
                //cnt++;
            }
            //cout << cur.z << cur.y << cur.x << " " << cnt << "\n";
        }
        cnt++;
    }

    con = 0;
    return 0;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j, k;

    while (1)
    {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
            break;

        int x, y, z;
        x = 0;
        y = 0;
        z = 0;

        memset(vis, 0, sizeof(vis));
        memset(mz, 0, sizeof(mz));

        for (i = 0;i < l;i++)
        {
          
            for (j = 0;j < r;j++)
            {
                string s; cin >> s;
                for (k = 0;k < c;k++)
                {
                    mz[i][j][k] = s[k];
                    if (mz[i][j][k] == 'S')
                    {
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }

      

        int ret = bfs(x, y, z);


        if (con == 0)
            cout << "Trapped!" << "\n";

        else
            cout << "Escaped" << " " <<"in" << " " << ret+1 << " " << "minute(s)." << "\n";

    }
    

    

    return 0;
}

