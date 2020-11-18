#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라
#include <algorithm>        //sort 함수사용
#include <utility>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
   
    int n; cin >> n;

    vector<int> pray;

    for (i = 0;i < n;i++)
    {
        string s; cin >> s;
        if (s == "push")
        {
            int b; cin >> b;
            pray.push_back(b);
        }

        else if (s == "top")
        {
            if (pray.empty() == 1)
                cout << -1 << "\n";
            else
                cout << pray.back() << "\n";
        }

        else if (s == "pop")
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
    }



    return 0;
}
