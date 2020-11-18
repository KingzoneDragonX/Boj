#include <iostream>
#include <string>
#include <cmath>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라 ,  stack 
#include <algorithm>        //sort 함수사용
#include <utility>
#include <queue>            // queue        queue에는 front와 back이 있다.

using namespace std;

int cnt[8100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
   
    float n; cin >> n;
    for (i = 0;i < 8000;i++)
        cnt[i] = 0;

    for (i = 0;i < n;i++)
    {
        int a; cin >> a;
        cnt[a + 4000]++;
    }

    int sum = 0;
    for (i = 0;i < 8001;i++)
    {
        if (cnt[i] != 0)
            sum += cnt[i] * (i - 4000);
    }
    cout << round(sum / n) << "\n";
    
    int count = 0;
    for (i = 0;i < 8001;i++)
    {
        if (cnt[i] != 0)
        {
            for (j = 0;j < cnt[i];j++)
            {
                count++;
                if (count >= (n+1)/2)
                    break;
            }
        }

        if (count >= (n+ 1)/2)
            break;
    }
    cout << i - 4000 << "\n";

    int max = -1;
    count = 0;
    for (i = 0;i < 8001;i++)
    {
        if (cnt[i] != 0)
        {
            if (cnt[i] > max)
            {
                max = cnt[i];
                count = 0;
            }

            else if (cnt[i] == max)
                count = 1;
        }
    }

    if (count == 0)
    {
        for (i = 0;i < 8001;i++)
        {
            if (cnt[i] == max)
            {
                cout << i - 4000 << "\n";
                break;
            }
        }
    }

    else
    {
        for (i = 0;i < 8001;i++)
        {
            if (cnt[i] == max)
            {
                if (count == 0)
                    break;
                
                else
                    count = 0;
            }
        }

        cout << i-4000 << "\n";        
    }

    int min = 8000;
    max = 0;
    for (i = 0;i < 8001;i++)
    {
        if (cnt[i] != 0)
        {
            if (i <= min)
                min = i;

            if (i >= max)
                max = i;
        }
    }
    cout << max - min << "\n";

    return 0;
}
