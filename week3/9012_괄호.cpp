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
    

    for (i = 0;i < n;i++)
    {
        vector<char> vps;
        int con = 0;
        string str; cin >> str;

        for (char ch : str)
        {
            if (ch == '(')
            {
                vps.push_back(ch);
                //cout << vps.back() << "\n";
            }

            else if(ch == ')')
            {
                if (vps.empty())
                {
                    cout << "NO" << "\n";
                    con = 1;
                    break;
                }

                else
                {
                    if (vps.back() == '(')
                        vps.pop_back();

                }
            }
        }
        if (con == 0)
        {
            if (vps.empty())
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    
    return 0;
}

