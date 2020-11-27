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

int ice[310][310];
bool vis[310][310];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int cnt = 0;
int year = 1;

struct cmp {
    bool operator() (int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;

        else
            return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;
    for (i = 0;i < n;i++)
    {
        int x; cin >> x;
        if (x == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }

        else
            pq.push(x);

    }
    
    return 0;
}

