#include <stdio.h>
#include <string.h>

void main() {
    int i = 0, j = 6, n, pos;
    char a[20], b[50], ch;

    printf("Enter string: ");
    scanf("%s", a);
    n = strlen(a);

    do {
        printf("Enter position (<= %d): ", n);
        scanf("%d", &pos);
    } while (pos > n);

    printf("Enter the character: ");
    ch = getche();

    // Initialize frame with "dle stx"
    strcpy(b, "dlestx");

    while (i < n) {
        if (i == pos - 1) {
            strcat(b, "dle");
            b[j++] = ch;
            strcat(b + j, "dle");
            j += 3;
        }
        if (a[i] == 'd' && a[i + 1] == 'l' && a[i + 2] == 'e') {
            strcat(b + j, "dle");
            j += 3;
        }
        b[j++] = a[i++];
    }

    strcat(b + j, "dleetx");
    printf("\nFrame after stuffing: %s\n", b);
}
