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

int tree[70][70]; 


void dfs(int x, int y, int size)
{
    if (size == 0)
        return;

    int cnt = 0;
    int z = tree[x][y];
    for(int i=x;i<x+size;i++)
        for (int j = y;j < y + size;j++)
        {
            if (tree[i][j] == z)
                cnt++;
        }

    if (cnt == size * size)
    {
        cout << z;
    }

    else
    {
        cout << "(";
        size /= 2;
        dfs(x, y, size);
        dfs(x , y+size, size);
        dfs(x+size, y, size);
        dfs(x + size, y + size, size);

        cout << ")";
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
        string s; cin >> s;
        for (j = 0;j < n;j++)
        {
            char ch = s[j];
            tree[i][j] = ch - 48;
        }
    }

    dfs(0, 0, n);

    return 0;
}

