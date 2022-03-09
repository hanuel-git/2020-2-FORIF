#include<stdio.h>
#include<math.h>
int main()
{
    int num, i, j, arr[100];
    printf("How many numbers you want to input ? ");
    scanf_s("%d", &num);


    printf("Start input %d numbers\n", num);
    for (int i = 0; i < num; i++)
    {
        scanf_s("%d", &arr[i]);
    }

    int target, ans = 0;
    printf("What is a target ? ");
    scanf_s("%d", &target);

    for (i = 0; i <= num - 1; i++)
    {
        for (j = i; j <= num - 1; j++)
        {
            if (arr[i] + arr[j] <= target)
            {
                if (i != j) ans += pow(2, j - i - 1);
                else ans += 1;
            }
        }
    }
    printf("%d", ans);
    return 0;

}