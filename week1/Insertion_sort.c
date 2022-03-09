#include<stdio.h>

// ��������
void insertion_sort(int* ptr, int count)
{
	for (int i = 1; i < count; i++)
	{
		// basket : �ֵ� �� �ڷ�(����) �����
		int basket = ptr[i];

		for (int j = i - 1; j >= 0; j--) // ���� �ٷ� ���� �ڷ���� ���ذ� �񱳽���
		{
			if (ptr[j] > basket) // ���ڷᰡ ���غ��� Ŭ ���
			{
				ptr[j + 1] = ptr[j]; // ���ڷḦ ���������� ��ĭ �δ�

				if (j == 0) // ���� ���������� (������ ���� ���� ���϶�)
				{
					ptr[j] = basket;
					break;
				}
			}
			else // ���ڷᰡ ���غ��� ���� ���
			{
				ptr[j + 1] = basket; 
				break;
			}
		}
	}
}


int main(void)
{
	int arr[] = { 4, 3, 2, 10, 12, 1, 5, 6 };
	int count = sizeof(arr) / sizeof(int);
	
	// ���� �� �迭 ���
	printf("���� �� �迭 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// �������� 
	insertion_sort(arr, count);

	// ���� �� �迭 ���
	printf("���� �� �迭 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}