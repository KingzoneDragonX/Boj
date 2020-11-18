#include <iostream>
#include <string>
#include <cmath>
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
    
    int m = n;
    int size = 1;
    while (1)
    {
        if (m < 10)
            break;
        m /= 10;
        size++;
    }

    vector<int> num(size);
    for (i = 0;i < size;i++)
    {
        num[i] = n % 10;
        n /= 10;
    }

    sort(num.begin(), num.end());

    for (i = size-1;i >=0;i--)
        cout << num[i];

    return 0;
}
