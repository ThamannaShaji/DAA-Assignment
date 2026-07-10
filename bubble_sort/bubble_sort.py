import random
import time
import matplotlib.pyplot as plt

def bubble_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        swapped = False

        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break


sizes = [100, 200, 500, 1000, 2000, 3000]

times = []

print("Array Size\tExecution Time (seconds)")

for size in sizes:

    arr = random.sample(range(size * 10), size)

    start = time.perf_counter()

    bubble_sort(arr)

    end = time.perf_counter()

    elapsed = end - start

    times.append(elapsed)

    print(f"{size}\t\t{elapsed:.6f}")


plt.figure(figsize=(8, 5))
plt.plot(sizes, times, marker='o', linewidth=2)

plt.title("Bubble Sort Time Complexity")
plt.xlabel("Array Size")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)

plt.show()