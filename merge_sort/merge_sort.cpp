#include <iostream>
using namespace std;

int arr[100], n;

void merge(int low, int mid, int high) {
    int temp[100];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
             temp[k++] = arr[i++];
        else
             temp[k++] = arr[j++];
    }






      while (i <= mid)
          temp[k++] = arr[i++];
      while (j <= high)
          temp[k++] = arr[j++];
      for (i = low, k = 0; i <= high; i++, k++)
          arr[i] = temp[k];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
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
      mergeSort(0, n - 1);
      cout << "After sorting : ";
      display();
      return 0;
}
