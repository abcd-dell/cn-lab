#include <stdio.h>

int a[10][10], n;

void adj(int root) {
    printf("Adjacent nodes of %d: ", root);
    for (int j = 1; j <= n; j++)
        if (a[root][j] || a[j][root]) printf("%d ", j);
    printf("\nNon-adjacent nodes of %d: ", root);
    for (int i = 1; i <= n; i++)
        if (!a[root][i] && !a[i][root] && i != root) printf("%d ", i);
    printf("\n");
}

int main() {
    int root;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("Enter root node: ");
    scanf("%d", &root);
    adj(root);
    return 0;
}
