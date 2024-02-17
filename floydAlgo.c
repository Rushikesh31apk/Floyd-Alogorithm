#include<stdio.h>

int a[10][10], d[10][10], n, i, j;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void path(int a[10][10], int n) {
    int k, i, j;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void display(int t[10][10], int size) {
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%5d\t", t[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter Weighted matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("\nfrom %d to %d weight :", i + 1, j + 1);
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    printf("\nShow A0 matrix:\n");
    display(a, n);
    path(d, n);
    printf("\nShow shortest path all vertices:\n");
    display(d, n);
    return 0;
}

