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
    cin >> m;


    for (j = 0;j < m;j++)
    {
        cin >> n;
        priority_queue<long long, vector<long long>, cmp> pq;
        if (n == 1)
        {
            long long x; cin >> x;
            cout << "1" << "\n";
        }
        else
        {
            for (i = 0;i < n;i++)
            {
                long long x; cin >> x;
                pq.push(x);
            }

            long long mul = 1;
            for (i = 0;i < n - 1;i++)
            {
                long long x = pq.top();
                pq.pop();
                long long y = pq.top();
                pq.pop();
                long long z = x * y;
                pq.push(z);
                z %= 1000000007;

                mul *= z;
                mul %= 1000000007;
            }

            cout << mul % 1000000007 << "\n";
        }
    }


    return 0;
}

