#include <stdio.h>
#include <stdlib.h>
struct frame {
    int fslno;
    char finfo[20];
} arr[10];
int n;

void sort() {
    struct frame temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].fslno > arr[j + 1].fslno) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main() {
    printf("\nEnter number of frames: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i].fslno = rand() % 50;
        printf("Enter content for sequence %d: ", arr[i].fslno);
        scanf("%s", arr[i].finfo);
    }
    sort();
    printf("\nFrames in sequence:\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\n", arr[i].fslno, arr[i].finfo);
}
