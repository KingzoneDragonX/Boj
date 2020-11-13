#include <iostream>
using namespace std;

int main()
{
    int i, j;
    
    char str[110];

    i = 0;
    while (1)
    {
        str[i] = getchar();
        
        if (str[i] > 96 && str[i] < 123)
            i++;
        else
            break;
    }

    
    int cnt[30];
    int k,m;
    int tmp = 0;
    for (j = 0;j < 30;j++)
        cnt[j] = -1;

    for (j = 0;j < i;j++)
    {
        for (k = 0;k < 26;k++)
        {
            if (str[j] == 'a' + k)
            {
                cnt[k] = j;
                tmp = 1;
                break;
            }
        }

        if (tmp == 1)
        {
            tmp = 0;
            for (m = j + 1;m < i;m++)
                if (str[m] == str[j])
                    str[m] = 'A';
        }
    }
    
    for (k = 0;k < 26;k++)
        printf("%d ", cnt[k]);

    return 0;
}
