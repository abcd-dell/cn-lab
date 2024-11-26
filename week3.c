#include <stdio.h>

int main() {
    int w, f, frames[50];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("Enter number of frames to transmit: ");
    scanf("%d", &f);

    printf("Enter %d frames: ", f);
    for (int i = 0; i < f; i++)
        scanf("%d", &frames[i]);

    printf("\nWith sliding window protocol:\n");
    printf("Sender sends %d frames, then waits for acknowledgment.\n\n", w);

    for (int i = 0; i < f; i++) {
        printf("%d ", frames[i]);
        if ((i + 1) % w == 0 || i == f - 1) {
            printf("\nAcknowledgment received.\n\n");
        }
    }

    return 0;
}
