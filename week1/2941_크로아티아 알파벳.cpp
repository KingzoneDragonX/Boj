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

        if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '-' || str[i] == '=')
            i++;

        else
            break;
    }

    int cnt = 0;
    for (j = 0;j < i;j++)
    {
        if (str[j] == 'c')
        {
            if (str[j + 1] == '=' || str[j + 1] == '-')
                j++;
        }
        else if (str[j] == 'd')
        {
            if (str[j + 1] == 'z' && str[j + 2] == '=')
                j += 2;
            else if (str[j + 1] == '-')
                j++;
        }

        else if (str[j] == 'l')
        {
            if (str[j + 1] == 'j')
                j++;
        }

        else if (str[j] == 'n')
        {
            if (str[j + 1] == 'j')
                j++;
        }

        else if (str[j] == 's' || str[j] == 'z')
        {
            if (str[j + 1] == '=')
                j++;
        }
        
        cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}
