#include <iostream>
using namespace std;

int main()
{
    int i, j,k;

    int n;
    scanf("%d\n", &n);

    int a = n;
    char str[110];
    
    int cnt[30];

    for (j = 0;j < n;j++)
    {
        i = 0;
        while (1)
        {
            str[i] = getchar();

            if (str[i] >= 'a' && str[i] <= 'z')
                i++;

            else
                break;
        }

        for (k = 0;k < 30;k++)
            cnt[k] = 0;

        for (k = 0;k < i;k++)
        {
            int b = str[k] - 'a';
            if (cnt[b] == 0)
            {
                cnt[b] = 1;
                while (1)
                {
                    if (str[k + 1] == str[k])
                        k++;
                    else
                        break;
                }
            }

            else if(cnt[b] == 1)
                cnt[b] = -1;
        }


        for (k = 0;k < 26;k++)
        {
            if (cnt[k] == -1)
            {
                a--;
                break;
            }
        }
    }
    
    printf("%d\n", a);

    return 0;
}
