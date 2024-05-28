#include <iostream>
using namespace std;

int num = 0, ex_count = 0, answer_count = 0;
int arr[500000];
void heapify(int len, int target) {
	int smallest = target;
	int left_node = target * 2 + 1;
	int right_node = target * 2 + 2;
	// 현재 노드, 왼쪽 자식, 오른쪽 자식

	if (left_node < len && arr[left_node] < arr[smallest])
		smallest = left_node;
	// 왼쪽 자식이 더 크면 왼쪽으로 바꿈
	if (right_node < len && arr[right_node] < arr[smallest])
		smallest = right_node;
	
	if (smallest != target) {
		swap(arr[target], arr[smallest]);
		answer_count++;

		if (answer_count == ex_count) {
			cout << arr[target] << " " << arr[smallest];
			exit(0);
		}

		heapify(len, smallest);
	} // 대소 관계에 의해 교환을 해야 한다면 swap
}

void heap_sort() {
	for (int i = num / 2 - 1; i >= 0; i--)
		heapify(num, i);
	// 마지막 노드의 부모부터 위로 올라가며 heapify
	
	for (int i = num - 1; i >= 1; i--) {
		swap(arr[0], arr[i]);
		answer_count++;
		
		if (answer_count == ex_count) {
			if (arr[0] < arr[i])
				cout << arr[0] << " " << arr[i];
			else
				cout << arr[i] << " " << arr[0];

			exit(0);
		}

		heapify(i, 0);
	// 최대값 -> 마지막 노드로 이동시킨다.
	// 이후 루트노드부터 다시 heapify
	}
}

int main()
{
	cin >> num >> ex_count;
	for (int i = 0; i < num; i++)
		cin >> arr[i];

	heap_sort();
	cout << -1;
	return 0;
}
