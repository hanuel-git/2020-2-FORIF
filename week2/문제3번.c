#include<stdio.h>

int main()
{
	int num;

	printf("How many number do you want to input? ");
	scanf_s("%d", &num);

	int arr[100];

	for (int i = 0; i < num; i++)
	{
		printf("Input %d st num : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	//  selection sort
	int temp;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	int j; // 타겟(기준)
	int k; // 인덱스
	int h_index;

	for (j = arr[0]; ; j--)
	{
		int count = 0;
		for (k = 0; k < num; k++)
		{
			if (arr[k] >= j)
				count++;
		}

		if (count >= j)
		{
			h_index = j;
			break;
		}
	}

	printf("H-index는 %d 입니다. ", h_index);

	return 0;
}
