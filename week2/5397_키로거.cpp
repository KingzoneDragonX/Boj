#include <iostream>
#include <string>
#include <list>             //linked list를 만듦

using namespace std;


int main()
{
    int i, j;

    int num; cin >> num;

    while (num--)
    {
        list<char> pray;
        string s1;
        cin >> s1;

        auto iter = pray.begin();


        for (char ch : s1)
        {
            if (ch == '-')
            {
                if (iter != pray.begin())
                    pray.erase(prev(iter));
            }

            else if (ch == '<')
            {
                if (iter != pray.begin())
                    iter = prev(iter);
            }

            else if (ch == '>')
            {
                if (iter != pray.end())
                    iter = next(iter);
            }

            else
                pray.insert(iter, ch);

        }

        for (char ch : pray)
            cout << ch;
        printf("\n");
    }
    

    return 0;
}
