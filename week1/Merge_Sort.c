#include<stdio.h>

// ���İ���
void Merge(int* ptr, int l, int m, int r)
{
	// l : �迭�� ���ʳ�
    // r : �迭�� �����ʳ�
    // m : �迭�� ���
	
	int i = l; // ���� �迭 �ε���
	int j = m + 1; // ���� �迭 �ε���

	int temp[8]; // �Ͻ������� ���� ������ �迭
	int k = l; // �迭 temp�� �ε��� 

	while (i <= m && j <= r) // �� �迭�� ���� �� �迭�� ���� �����ϱ� ������ �ݺ�
	{
		// �� �迭�� �� �� �� ���� ���� �� �迭�� ����
		if (ptr[i] <= ptr[j]) 
			temp[k++] = ptr[i++];
		else temp[k++] = ptr[j++];
	}

	// ���� �迭�� ������ ���� ���� ��� �ϰ� ����
	while (i <= m)
		temp[k++] = ptr[i++];
	// ���� �迭�� ������ ���� ���� ��� �ϰ� ����
	while (j <= r)
		temp[k++] = ptr[j++];

	// temp �迭�� ������ �����迭(ptr)�� ����
	for (int a = l; a <= r; a++)
		ptr[a] = temp[a];
}

// �պ�����
void Merge_Sort(int* ptr, int l, int r)
{
	int m;
	if (l < r)
	{
		m = (l + r) / 2; //�迭 �ΰ��� ����

		Merge_Sort(ptr, l, m); // ���� �迭 ����
		Merge_Sort(ptr, m + 1, r); // ���� �迭 ����
		Merge(ptr, l, m, r); // �ΰ� �迭 ����

	}
}

int main(Void)
{
	int arr[] = { 21, 10, 12, 20, 25, 13, 15, 22 };
	int count = sizeof(arr) / sizeof(int);

	// ���� �� �迭 ���
	printf("���� �� �迭 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	// ���� ���� 
	Merge_Sort(arr, 0, count-1);

	// ���� �� �迭 ���
	printf("���� �� �迭 : ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}