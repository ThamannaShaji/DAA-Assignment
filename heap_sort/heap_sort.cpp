#include <iostream>
using namespace std;

int arr[100], n;

void heapify(int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {







              temp = arr[i];
              arr[i] = arr[largest];
              arr[largest] = temp;
              heapify(size, largest);
      }
}

void heapSort() {
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(i, 0);
    }
}

void display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

      cout << "Before sorting: ";
      display();
      heapSort();
      cout << "After sorting : ";
      display();
      return 0;
}
