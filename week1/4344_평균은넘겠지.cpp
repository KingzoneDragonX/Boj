#include <iostream>
using namespace std;

int main()
{
    int i, j;

    int n;
    scanf("%d", &n);

    int sco[1100];

    float sum;
    int cnt;

    for (i = 0;i < n;i++)
    {
        cnt = 0;
        sum = 0;
        float stu;

        scanf("%f", &stu);
        for (j = 0;j < stu;j++)
            scanf("%d", &sco[j]);

        for (j = 0;j < stu;j++)
            sum += sco[j];

        sum /= stu;

        // printf("%fa\n", sum);
        for (j = 0;j < stu;j++)
        {
            if (sco[j] > sum)
                cnt++;
        }

        float a;
        a = cnt * 100 / stu;
        printf("%.3f%c\n", a, 37);
    }

    return 0;
}
