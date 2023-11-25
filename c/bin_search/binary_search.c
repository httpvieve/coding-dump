#include <stdio.h>
#include <stdlib.h>

int search (int *arr, int size, int key) {
        int low = 0;
        int high = size - 1;
        int mid;
        while (low <= high) {
                mid = (low + high) / 2;
                if (key == arr[mid]) return mid;
                else if (key < arr[mid]) high = mid - 1;
                else low = mid + 1;
        }
        return -1;
}

int main () {
        
        return 0;
}