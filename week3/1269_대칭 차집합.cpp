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


int ice[310][310];
bool vis[310][310];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int cnt = 0;
int year = 1;

struct cmp {
    bool operator() (long long a, long long b)
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    int n, m;
    int a, b; cin >> a >> b;

    map<int,int> mpa;
    map<int,int> mpb;

    for (i = 0;i < a;i++)
    {
        int x; cin >> x;
        mpa[i] = x;
    }

    for (i = 0;i < b;i++)
    {
        int x; cin >> x;
        mpb[x] = i;
    }

    int sum = a+b;
    
    for(i=0;i<a;i++)
        if (mpb.find(mpa[i]) != mpb.end())
        {
            sum--;
            sum--;
        }

    
    cout << sum << "\n";

    return 0;
}

