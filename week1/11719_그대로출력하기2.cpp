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

        if (str[i] == EOF)
            break;

        else
            printf("%c", str[i]);
    }

   

    return 0;
}
