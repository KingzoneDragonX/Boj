#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라 ,  stack 
#include <algorithm>        //sort 함수사용
#include <utility>
#include <queue>            // queue        queue에는 front와 back이 있다.

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
   
    int n,k; cin >> n >> k;


    int cnt[5100];
    

    for (i = 0;i < n;i++)
        cnt[i] = 0;

    
    int here=0;
    int a;
    int b;

    cout << "<";
    for (i = 0;i < n;i++)
    {
        a = 0;
        b = k;

        while (b)
        {
            if (here >= n)
                here -= n;

            if (cnt[here] != 1)
                b--;
                
            here++;
        }

        here--;
        //cout << b << " " << here << "\n";
        cnt[here] = 1;
        if (i != n - 1)
            cout << here + 1 << ", ";

        else
            cout << here + 1;

        here++;
    }
    cout << ">";
    
    return 0;
}
