// Copyright 2021 NNTU-CS

// Вспомогательная функция для бинарного поиска
bool binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < len; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) {
                continue;
            }
            if (arr[i] + arr[j] == value) {
                count++;
                break;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int currentLeft = arr[left];
            while (left < right && arr[left] == currentLeft) {
                left++;
            }
            int currentRight = arr[right];
            while (left < right && arr[right] == currentRight) {
                right--;
            }
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        if (target < arr[i]) {
            continue;
        }
        if (binarySearch(arr, i + 1, len - 1, target)) {
            count++;
        }
    }
    return count;
}
