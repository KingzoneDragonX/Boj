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

int m, n, h;
int tmt[110][110][110];
int visited[110][110][110];
int dy[] = { 0,0,1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
int cnt = 0;
int w = 0;

struct trp {
    int a, b, c ;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j, k;
    cin >> m >> n >> h;

    int zero = 0;
    for(i=0;i<h;i++)
        for(j=0;j<n;j++)
            for (k = 0;k < m;k++)
            {
                cin >> tmt[k][j][i];
                if (tmt[k][j][i] == 0)
                    zero = 1;
            }

    if (zero == 0)
    {
        cout << "0" << "\n";
        return 0;
    }

    else
    {
        queue <trp> q;
        for (i = 0;i < h;i++)
            for (j = 0;j < n;j++)
                for (k = 0;k < m;k++)
                {
                    if (tmt[k][j][i] == 1) {
                        q.push({ k,j,i });
                        visited[k][j][i] = 1;
                    }
                }
 
        cnt = 0;
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                trp cur = q.front();
                q.pop();

                for (int i = 0;i < 6;i++)
                {
                    int nx = cur.a + dx[i];
                    int ny = cur.b + dy[i];
                    int nz = cur.c + dz[i];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                        continue;
                    if (tmt[nx][ny][nz] != 0)
                        continue;
                    if (visited[nx][ny][nz])
                        continue;

                    visited[nx][ny][nz] = 1;
                    q.push({ nx,ny,nz });

                    tmt[nx][ny][nz] = 1;
                }

            }
            cnt++;

        }
    }

    zero = 0;
    for(i=0;i<h;i++)
        for (j = 0;j < n;j++)
        {
            for (k = 0;k < m;k++)
            {
                if (tmt[k][j][i] == 0)
                    zero = 1;
            }
        }

    if (zero == 1)
        cout << "-1" << "\n";

    else
        cout << cnt - 1 << '\n';

    return 0;
}

