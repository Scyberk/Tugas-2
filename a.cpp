#include <stdio.h>

// Function to find the smallest position of a query in a sorted array
int find_position(int *arr, int n, int query) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == query) {
            result = mid + 1; // Store the 1-based position
            right = mid - 1;  // Continue searching on the left for the smallest position
        } else if (arr[mid] < query) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int queries[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &queries[i]);
    }

    for (int i = 0; i < m; i++) {
        int position = find_position(arr, n, queries[i]);
        printf("%d\n", position);
    }

    return 0;
}

