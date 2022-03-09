#include<stdio.h>

void Selection_Sort(int arr[], int num);
void Scoville(int arr[], int num, int target);

int main()
{
	int num;
	printf("How many 'scoville index' you want to input ? ");
	scanf_s("%d", &num);

	int arr[100];
	for (int i = 0; i < num; i++)
	{
		printf("Input %d st index : ", i+1);
		scanf_s("%d", &arr[i]);
	}

	int target;
	printf("What scoville index do you want ? ");
	scanf_s("%d", &target);

	int count=0;

	Selection_Sort(arr, num);

	Scoville(arr, num, target, &count);

	printf("The return is %d", count);

	return 0;

}

void Selection_Sort(int arr[], int num)
{
	int temp;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void Scoville(int arr[], int num, int target, int*ptr)
{
	if (arr[0] < target)
	{
		arr[0] = arr[0] + 2 * arr[1];
		for (int j = 1; j < num-1; j++)
		{
			arr[j] = arr[j + 1];
			if (j == num - 2)
				arr[j + 1] = 0;
		}
		*ptr += 1;
		Selection_Sort(arr, num - 1);
		Scoville(arr, num - 1, target, ptr);
	}
	else return;
}