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
bool vis[20][20];

int cnt = 0;

bool check(int y, int x)
{
    int i;
    int sum = y + x;
    int sub = y - x;
    for (i = 0;i < n;i++)
    {
        if (vis[y][i] == 1)
            return false; // bool함수의 경우 return 0으로 해도 알아들음

        if (vis[i][x] == 1)
            return false;
    }

    for (i = 0;i <= sum;i++)
    {
        if (sum - i < n && i < n)
        {
            if (vis[i][sum - i] == 1)
                return false;
        }
    }

    for (i = 0;i < n;i++)
    {
        int b = i;
        int a = i + sub;
        if (a < 0 || a>=n)
            continue;
        else
        {
            if (vis[a][b] == 1)
                return false;
        }
    }

    return true;


}

void dfs(int a)
{
    if (a == n)
    {
        cnt++;
        return;
    }

    for (int i = 0;i < n;i++)
    {
        if (check(a, i))
        {
            vis[a][i] = 1;
            dfs(a + 1);
            vis[a][i] = 0;
        }
    }

    
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n;


    dfs(0);
   
    cout << cnt << "\n";

    return 0;
}

