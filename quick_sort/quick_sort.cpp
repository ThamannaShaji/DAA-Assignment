#include <iostream>
using namespace std;

int arr[100], n;

int partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1, temp;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;






      return i + 1;
}

void quickSort(int low, int high) {
    if (low < high) {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
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
      quickSort(0, n - 1);
      cout << "After sorting : ";
      display();
      return 0;
}
