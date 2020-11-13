#include <iostream>
using namespace std;

char str[1100000];

int main()
{
    int i, j;
    
    

    i = 0;
   
    while (1)
    {
        str[i] = getchar();
        
        if ((str[i] > 96 && str[i] < 123) || str[i] >64 && str[i] < 91)
            i++;
        else
            break;
    }

    int cnt[30];
    for (j = 0;j < 26;j++)
        cnt[j] = 0;

    int k;
    for (j = 0;j < i;j++)
    {
        for (k = 0;k < 26;k++)
        {
            if (str[j] > 96 && str[j] < 123)
            {
                if ((str[j] - 'a') == k )
                    cnt[k]++;
                
            }
            else
            {
                if ((str[j] - 'A') == k )
                    cnt[k]++;
            }
        }
    }
    
    int max = -1;
    int tmp = 0;
    int r;
    for (k = 0;k < 26;k++)
    {
        if (cnt[k] == max)
            tmp = 1;
        

        if (cnt[k] > max)
        {
            r = k;
            tmp = 0;
            max = cnt[k];
        }
    }

    if (tmp == 1)
        printf("?\n");
    else
        printf("%c\n", r + 'A');

    return 0;
}
