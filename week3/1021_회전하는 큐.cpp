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
    int end; cin >> end;

    deque<int> num;
    queue<int> del;

    for (i = 0;i < end;i++)
    {
        int a; cin >> a;
        del.push(a);
    }

    for (i = 1;i <= n;i++)
        num.push_back(i);

    int cnt = 0;
    int mem = 0;
    int arr[55];
   
    while (end)
    {
        if (num.front() == del.front())
        {
            end--;
            num.pop_front();
            del.pop();
           // cout << "cnt : " << cnt << "\n";
        }

        else
        {
            for (i = 0;i < num.size();i++)
            {
                int x = num[i];
                if (x == del.front())
                    mem = i;
                //cout << mem << " " << x << " " << del.front() << "\n";
            }



            if (mem <= num.size()/2)
            {
                while (1)
                {
                    if (num.front() == del.front())
                        break;
                    else
                    {
                        int x = num.front();
                        num.push_back(x);
                        num.pop_front();
                        cnt++;
                    }

                }
            }

            else
            {
                while (1)
                {
                    if (num.front() == del.front())
                        break;
                    else
                    {
                        int x = num.back();
                        num.push_front(x);
                        num.pop_back();
                        cnt++;
                    }
                }
            }
        }
    }


    cout << cnt << "\n";
    
    return 0;
}

