#include <iostream>
#include <string>
#include <list>             //linked list를 만듦
#include <vector>           //많이 쓴다 카더라
#include <algorithm>        //sort 함수사용
#include <utility>

using namespace std;

int cnt[11000];
pair<int, int> arr[110000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j;
    int n; cin >> n;

    for (i = 0;i < n;i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + n);
    
    for (i = 0;i < n;i++)
        cout << arr[i].first << " " << arr[i].second << "\n";

    return 0;
}
