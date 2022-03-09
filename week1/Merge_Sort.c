#include<stdio.h>

// 정렬과정
void Merge(int* ptr, int l, int m, int r)
{
	// l : 배열의 왼쪽끝
    // r : 배열의 오른쪽끝
    // m : 배열의 가운데
	
	int i = l; // 앞쪽 배열 인덱스
	int j = m + 1; // 뒷쪽 배열 인덱스

	int temp[8]; // 일시적으로 값을 저장할 배열
	int k = l; // 배열 temp의 인덱스 

	while (i <= m && j <= r) // 두 배열이 전부 각 배열의 끝에 도달하기 전까지 반복
	{
		// 두 배열의 값 비교 후 작은 값을 새 배열에 저장
		if (ptr[i] <= ptr[j]) 
			temp[k++] = ptr[i++];
		else temp[k++] = ptr[j++];
	}

	// 앞쪽 배열의 값들이 남아 있을 경우 일괄 복사
	while (i <= m)
		temp[k++] = ptr[i++];
	// 뒷쪽 배열의 값들이 남아 있을 경우 일괄 복사
	while (j <= r)
		temp[k++] = ptr[j++];

	// temp 배열의 값들을 기존배열(ptr)에 저장
	for (int a = l; a <= r; a++)
		ptr[a] = temp[a];
}

// 합병정렬
void Merge_Sort(int* ptr, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2; //배열 두개로 분할

		Merge_Sort(ptr, l, m); // 앞쪽 배열 정렬
		Merge_Sort(ptr, m + 1, r); // 뒤쪽 배열 정렬
		Merge(ptr, l, m, r); // 두개 배열 결합

	}
}

int main(Void)
{
	int arr[] = { 21, 10, 12, 20, 25, 13, 15, 22 };
	int count = sizeof(arr) / sizeof(int);

	// 정렬 전 배열 출력
	printf("정렬 전 배열 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 병합 정렬 
	Merge_Sort(arr, 0, count-1);

	// 정렬 후 배열 출력
	printf("정렬 후 배열 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}