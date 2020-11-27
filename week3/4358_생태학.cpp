#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라 ,  stack 
#include <algorithm>        //sort 함수사용
#include <utility>
#include <queue>            // queue        queue에는 front와 back이 있다.
#include <set>
#include <map>
#include <cstring>
#include <cmath>


using namespace std;


int ice[310][310];
bool vis[310][310];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int cnt = 0;
int year = 1;

struct cmp {
    bool operator() (long long a, long long b)
    {
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;

    
    map<string, int> tree;
    map<int, float> per;

    float cnt = 0;
    while (1)
    {
        string s; getline(cin, s);           //공백이 있는 문자열 받기용 험수
        if (s[0] == NULL)   
            break;
 
        //cout << s << "\n";
        if (tree.find(s) != tree.end())
        {
            tree[s]++;
            
        }

        else
            tree[s] = 1;

        cnt++;
    }
     
    //cout << cnt;
    i = 0;
    for (auto iter : tree)
    {
        float p = iter.second;
        p = p * 100 / cnt;
        per[i] = p;
        cout << fixed;                        // 소수점 아래 몇자리를 고정하겠다는 뜻. 만약 이 문장 없이 precision만 쓴다면 전체 자릿수를 조절하는 거임.
        cout.precision(4);
        cout << iter.first << " " << per[i] << "\n";
        i++;
    }

    return 0;
}

