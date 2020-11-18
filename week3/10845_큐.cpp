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

    queue<int> pray;

    for (i = 0;i < n;i++)
    {
        string s; cin >> s;
        if (s == "push")
        {
            int b; cin >> b;
            pray.push(b);
        }

        else if (s == "pop")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";

            else
            {
                cout << pray.front() << "\n";
                pray.pop();
            }
        }

        else if (s == "size")
            cout << pray.size() << "\n";

        else if (s == "empty")
            cout << pray.empty() << "\n";

        else if(s == "front")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";

            else
                cout << pray.front() << "\n";
        }

        else if (s == "back")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";

            else
                cout << pray.back() << "\n";
        }
    }



    return 0;
}
