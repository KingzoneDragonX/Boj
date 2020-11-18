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
   
    int n,max;
    cin >> n >> max;

    int stu[6][2];
    for (i = 0;i < 6;i++)
    {
        stu[i][0] = 0;
        stu[i][1] = 0;
    }
    
    for (i = 0;i < n;i++)
    {
        int a, b; cin >> a >> b;
        stu[b - 1][a]++;
    }

    int cnt = 0;
    for (i = 0;i < 6;i++)
    {
        for (j = 0;j < 2;j++)
        {
            if(stu[i][j]%max == 0)
                cnt += stu[i][j] / max;
            else
                cnt += stu[i][j] / max + 1;
        }

    }

    cout << cnt << "\n";

    return 0;
}
