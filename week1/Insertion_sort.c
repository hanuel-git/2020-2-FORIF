#include<stdio.h>

// 삽입정렬
void insertion_sort(int* ptr, int count)
{
	for (int i = 1; i < count; i++)
	{
		// basket : 주된 비교 자료(기준) 저장용
		int basket = ptr[i];

		for (int j = i - 1; j >= 0; j--) // 기준 바로 왼쪽 자료부터 기준과 비교시작
		{
			if (ptr[j] > basket) // 비교자료가 기준보다 클 경우
			{
				ptr[j + 1] = ptr[j]; // 비교자료를 오른쪽으로 한칸 민다

				if (j == 0) // 끝에 도달했을때 (기준이 제일 작은 수일때)
				{
					ptr[j] = basket;
					break;
				}
			}
			else // 비교자료가 기준보다 작을 경우
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
	
	// 정렬 전 배열 출력
	printf("정렬 전 배열 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 삽입정렬 
	insertion_sort(arr, count);

	// 정렬 후 배열 출력
	printf("정렬 후 배열 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}