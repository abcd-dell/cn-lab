#include <stdio.h>
#include <string.h>

void encrypt(char *msg, int key) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] += key;
    }
}

void decrypt(char *msg, int key) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] -= key;
    }
}

int main() {
    char msg[] = "Hello"; // Changed 'String' to 'char[]' and corrected assignment syntax
    int key = 4;

    encrypt(msg, key);
    printf("Encrypted message: %s\n", msg);

    decrypt(msg, key);
    printf("Decrypted message: %s\n", msg);

    return 0;
}
