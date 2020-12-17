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

int num[10][10];
vector <pair<int, int>> zero;


bool check1(int x, int y,int i)
{
    for (int a = 0;a < 9;a++)
    {
        if (num[x][a] == i)
            return false;
    }

    return true;
}

bool check2(int x, int y, int i)
{
    for (int a = 0; a < 9;a++)
    {
        if (num[a][y] == i)
            return false;
    }
    
    return true;
}

bool check3(int x, int y, int i)
{
    int a = x / 3;
    int b = y / 3;

    a *= 3;
    b *= 3;

    for (int c = 0;c < 3;c++)
        for (int d = 0;d < 3;d++)
            if (num[a + c][b + d] == i)
                return false;

    return true;

}

void dfs(int dep)
{
    if (dep == zero.size())
    {
        for (int i = 0;i < 9;i++)
        {
            for (int j = 0;j < 9;j++)
                cout << num[i][j] << " ";
            cout << "\n";
        }
        exit(0);                //함수 강제종료 함수
    }

    for (int i = 1; i <= 9; i++)
    {
        int x = zero[dep].first;
        int y = zero[dep].second;

        if (check1(x,y,i) && check2(x,y,i) && check3(x,y,i))
        {
            num[x][y] = i;
            dfs(dep + 1);
            num[x][y] = 0;
        }
    }

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    for(i=0;i<9;i++)
        for (j = 0;j < 9;j++)
        {
            int x; cin >> x;
            num[i][j] = x;
            if (x == 0)
                zero.push_back({ i,j });
        }

    dfs(0);

    return 0;
}

