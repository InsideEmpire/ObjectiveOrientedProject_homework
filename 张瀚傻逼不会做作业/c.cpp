#include <stdio.h>

double calculate_average(int arr[], int n);

int main() {
    int n;
    scanf("%d", &n);
    int * array = new int[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &array[i]);
    }
    double average = calculate_average(array, n);
    printf("数组元素的平均值是: %f\\n", average);
    return 0;
}

double calculate_average(int arr[], int n) {
    if (n <= 0) {
        printf("数组长度必须大于0\\n");
        return -1;
    }
    
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}