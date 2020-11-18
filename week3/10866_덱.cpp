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

    deque<int> pray;            //double ended queue

    for (i = 0;i < n;i++)
    {
        string s; cin >> s;
        if (s == "push_front")
        {
            int b; cin >> b;
            pray.push_front(b);
        }

        if (s == "push_back")
        {
            int b; cin >> b;
            pray.push_back(b);
        }

        else if (s == "pop_front")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";

            else
            {
                cout << pray.front() << "\n";
                pray.pop_front();
            }
        }

        else if (s == "pop_back")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";

            else
            {
                cout << pray.back() << "\n";
                pray.pop_back();
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
