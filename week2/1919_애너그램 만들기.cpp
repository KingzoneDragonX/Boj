#include <iostream>
#include <string>
using namespace std;


int main()
{
    int i, j;

    string s1, s2;

    cin >> s1 >> s2;            // 이 방식으로 string을 받을 시 cin, cout만 사용이 가능하다. 공백문자를 기준으로 짤라서 받는다.

   // cout << s1 << "\n" << s2;

    /*
        (string에 대하여)
        1. string의 길이
          -> s1.size()

        2. string끼리 붙이기
          -> s1+s2 가능

          +)예제
            for(i=0;i<5;i++)
             s1 += char(i+'0')
     */

    int cnt = 0;
    
    int cnt1[30];
    int cnt2[30];

    for (i = 0;i < 26;i++)
    {
        cnt1[i] = 0;
        cnt2[i] = 0;
    }

    for (i = 0;i < s1.size();i++)
        cnt1[s1[i] - 'a']++;

    for (i = 0;i < s2.size();i++)
        cnt2[s2[i] - 'a']++;

    for (i = 0;i < 26;i++)
    {
        if (cnt1[i] != cnt2[i])
        {
            if (cnt1[i] > cnt2[i])
                cnt += cnt1[i] - cnt2[i];

            else
                cnt += cnt2[i] - cnt1[i];
        }
    }

    printf("%d\n", cnt);
    return 0;
}
