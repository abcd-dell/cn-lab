#include <stdio.h>
#include <string.h>

void computeCRC(const char *frame, const char *poly, char *result) {
    int frameLen = strlen(frame), polyLen = strlen(poly);
    char trans[128];

    // Step 1: Copy frame and pad with zeros
    strcpy(trans, frame);
    memset(trans + frameLen, '0', polyLen - 1);
    trans[frameLen + polyLen - 1] = '\0';

    // Step 2: Perform XOR division
    for (int i = 0; i < frameLen; i++) {
        if (trans[i] == '1') {
            for (int j = 0; j < polyLen; j++) {
                trans[i + j] = (trans[i + j] == poly[j]) ? '0' : '1';
            }
        }
    }

    // Step 3: Extract the CRC remainder
    strncpy(result, trans + frameLen, polyLen - 1);
    result[polyLen - 1] = '\0';
}

int main() {
    char frame[128], crcResult[32];
    const char *crc12 = "1100000001111"; // CRC-12 polynomial
    const char *crc16 = "11000000000000101"; // CRC-16 polynomial
    const char *crcCCITT = "10001000000100001"; // CRC-CCITT polynomial

    printf("Enter the frame: ");
    scanf("%s", frame);

    // CRC-12
    computeCRC(frame, crc12, crcResult);
    printf("CRC-12 Result: %s\n", crcResult);

    // CRC-16
    computeCRC(frame, crc16, crcResult);
    printf("CRC-16 Result: %s\n", crcResult);

    // CRC-CCITT
    computeCRC(frame, crcCCITT, crcResult);
    printf("CRC-CCITT Result: %s\n", crcResult);

    return 0;
}
