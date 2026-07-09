import random


def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
    return arr


if __name__ == "__main__":
    size = random.randint(5, 15)
    numbers = []
    for i in range(size):
        numbers.append(random.randint(1, 100))

    print("Array size:", size)
    print("Original array:", numbers)
    sorted_numbers = bubble_sort(numbers)
    print("Sorted array:", sorted_numbers)
