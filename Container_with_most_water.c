#include <stdio.h>

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int *height, int heightSize) {
    if (height == NULL || heightSize <= 1) {
        return 0;
    }

    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);

        if (max_water < h * width) {
            max_water = h * width;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}

int main(void) {
    int n;
    printf("enter the number of pileres in container:");
    scanf("%d", &n);
    int height[n];
    for(int i = 0; i < n; i++) {
        printf("enter the height of piler %d:", i + 1);
        scanf("%d", &height[i]);
    }
    int heightSize = sizeof(height) / sizeof(height[0]);
    int result = maxArea(height, heightSize);

    printf("%d\n", result);
    return 0;
}