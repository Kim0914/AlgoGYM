#include <iostream>
using namespace std;

int num = 0, limit = 0;
void heapify(int arr[], int len, int target) {
	int largest = target;
	int left = 2 * target + 1;
	int right = 2 * target + 2;

	if (left < len && arr[left] > arr[largest])
		largest = left;
	// 현재 노드 기준, 왼쪽 자식이 부모보다 크면 교체

	if (right < len && arr[right] > arr[largest])
		largest = right;
	// 현재 노드 기준, 오른쪽 자식이 부모보다 크면 교체
	// ex) 2 3 4 -> 3 2 4 -> 4 3 2 와 같이 교환되는 과정

	if (largest != target) {
	// 가장 큰 노드(부모)가 들어왔던 target과 다르면?
	// 자식과 교환이 발생했다는 말이므로, 실제 값을 교환해야 한다.
		swap(arr[target], arr[largest]);
	// 교환 이후, 교환된 값에 대해 반복해서 heapify 진행
		heapify(arr, len, largest);
	// ex) 위에서 4 3 2로 교환되었다면, largest 였던 2에 대해서 heapify 진행
	// 그 이유는, 2보다 더 큰 값이 아래에 있을 수도 있기 때문
	}

	// Leaf node이거나, 정렬이 끝난 node라면 재귀가 끝남
}

void heap_sort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--)
		heapify(arr, len, i);
	// 배열 최대 힙으로 만들어주기

	for (int i = len - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		// 힙의 최대값(Root)와 마지막 칸 노드 교환
		heapify(arr, i, 0);
		// 힙의 크기를 줄여서 최대 값을 제외하고 다시 힙 구성
		// 원래는 len을 집어넣지만, 마지막 칸에 최대값이 갔으니
		// 길이를 하나 줄여 i가 최대길이 -> 나머지 칸에 대해 정렬 진행
		// i의 길이 중 최대값 -> 다시 마지막칸으로 이동
	}
}

int main()
{
	int arr[10] = { 3, 2, 5, 7, 9, 10, 1, 6, 4, 8 };
	heap_sort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	return 0;
}
