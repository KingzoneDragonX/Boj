#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라
#include <algorithm>        //sort 함수사용
#include <utility>

using namespace std;

string arr[21000];

bool cmp(const string& a, const string& b)                     //비교함수로 bool을 return 하는데 이는 true, false만 return한다. bool은 true, false만을 가지는 자료형이다라고 할 수 있다.
{                                                                              // cmp로 받은 인자에서 &는 자료의 크기가 크면 시간이 오래 걸리기 때문에 포이터처럼 주소를 넘겨준다.(call-by-reference) cpp 문법인 참조자를 이용해서 c의 포인터 역할을 대체할 수 있다. 그리고 이 주소가 바뀌는 것을 방지하기 위해 const를 붙여준다.
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
    int n; cin >> n;

    for (i = 0;i < n;i++)
        cin >> arr[i];

    sort(arr, arr + n, cmp);                        // 비교함수를 추가해주면서 sort의 기준을 바꿔준다.
   
    for (i = 0;i < n;i++)
    {   
        if (arr[i] != arr[i + 1])
            cout << arr[i] << "\n";
    }
    return 0;
}
