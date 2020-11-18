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

    int n; cin >> n;

    queue<int> num;

    for (i = 1;i <= n;i++)
        num.push(i);

    for (i = 0;i < 2 * (n - 1) - 1;i++)
    {
        if (i % 2 == 0)
             num.pop();
        

        else
        {
            int a = num.front();
            num.pop();
            num.push(a);
        }
    }

    cout << num.front();

    return 0;
}

