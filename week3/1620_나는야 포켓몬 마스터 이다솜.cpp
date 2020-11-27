#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라 ,  stack 
#include <algorithm>        //sort 함수사용
#include <utility>
#include <queue>            // queue        queue에는 front와 back이 있다.
#include <set>
#include <map>


using namespace std;

map<string, int> mp;
map<string, string> mp2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    int n, m; cin >> n >> m;

    for (i = 1;i <= n;i++)
    {
        string s; cin >> s;
        mp[s] = i;
        mp2[to_string(i)] = s;
    }

    for (i = 0;i < m;i++)
    {
        string s; cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
           cout << mp2[s] << "\n";

        else
            cout << mp[s] << "\n";
    }   
    
    return 0;
}

