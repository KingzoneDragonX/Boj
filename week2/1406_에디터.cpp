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
   
    list<char> str;
    string s1; cin >> s1;
   
    
    auto iter = str.begin();
    
    for (char ch : s1)
        str.insert(iter, ch);

    int n; cin >> n;

    for (i = 0;i < n;i++)
    {
        char ch; cin >> ch;
        if (ch == 'L')
        {
            if (iter != str.begin())
                iter = prev(iter);
        }

        else if (ch == 'D')
        {
            if (iter != str.end())
                iter = next(iter);
        }

        else if (ch == 'B')
        {
            if (iter != str.begin())
                str.erase(prev(iter));
        }

        else if (ch == 'P')
        {
            char x; cin >> x;
            str.insert(iter, x);
        }
        
    }

    for (char ch : str)
        cout << ch;

    return 0;
}
