#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep()

void main() {
    int packets[5], i, clk, b_size, o_rate, p_sz_rm = 0, p_time;

    for (i = 0; i < 5; ++i)
        packets[i] = rand() % 9 + 1;  // Packet sizes 1 to 9

    printf("Enter output rate: ");
    scanf("%d", &o_rate);
    printf("Enter bucket size: ");
    scanf("%d", &b_size);

    for (i = 0; i < 5; ++i) {
        if ((packets[i] + p_sz_rm) > b_size) {
            printf("\nPacket size %d exceeds bucket capacity\n", packets[i]);
        } else {
            p_sz_rm += packets[i];
            printf("\nIncoming packet: %d\nTransmission left: %d\n", packets[i], p_sz_rm);
            p_time = rand() % 10;
            printf("Next packet in %d seconds\n", p_time);

            for (clk = 0; clk < p_time && p_sz_rm > 0; ++clk) {
                sleep(1);
                if (p_sz_rm) {
                    printf("Transmitting... ");
                    p_sz_rm -= (p_sz_rm < o_rate) ? p_sz_rm : o_rate;
                    printf("Bytes remaining: %d\n", p_sz_rm);
                }
            }
        }
    }
}
