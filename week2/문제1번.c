#include<stdio.h>

int main()
{
	int num;
	printf("How many intervals you want to input ? ");
	scanf_s("%d", &num);
	int arr[100][2];

	for (int i = 0; i < num; i++)
	{
		printf("Input %d st interval : ", i + 1);
		scanf_s("%d,%d", &arr[i][0], &arr[i][1]);
	}

	for (int j = 0; j < num; j++)
	{
		if (arr[j + 1][0] <= arr[j][1] && arr[j][1] <= arr[j + 1][1])
		{
			arr[j + 1][0] = arr[j][0];
			arr[j][0] = 0;
			arr[j][1] = 0;
		}
	}

	for (int k = 0; k < num; k++)
	{
		if (arr[k][0] != 0)
			printf("[ %d, %d ]", arr[k][0], arr[k][1]);
	}

	return 0;
}