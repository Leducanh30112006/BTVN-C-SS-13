#include <stdio.h>

void nhapMaTran(int n, int m, int maTran[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}
void inMaTran(int n, int m, int maTran[n][m]) {
    printf("Ma tran da nhap:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}

void inPhanTuGoc(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu o goc:\n");
    printf("%d ", maTran[0][0]);
    printf("%d ", maTran[0][m-1]);
    printf("%d ", maTran[n-1][0]);
    printf("%d ", maTran[n-1][m-1]);
    printf("\n");
}

void inDuongBien(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu nam tren duong bien:\n");
    for (int j = 0; j < m; j++) {
        printf("%d ", maTran[0][j]);
    }
    for (int j = 0; j < m; j++) {
        printf("%d ", maTran[n-1][j]);
    }
    for (int i = 1; i < n-1; i++) {
        printf("%d ", maTran[i][0]);
    }
    for (int i = 1; i < n-1; i++) {
        printf("%d ", maTran[i][m-1]);
    }
    printf("\n");
}

void inDuongCheo(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu nam tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == m - 1) {
                printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
}

int kiemTraSoNguyenTo(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void inSoNguyenTo(int n, int m, int maTran[n][m]) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (kiemTraSoNguyenTo(maTran[i][j])) {
                printf("%d ", maTran[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m, choice;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    int maTran[n][m];

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMaTran(n, m, maTran);
                break;
            case 2:
                inMaTran(n, m, maTran);
                break;
            case 3:
                inPhanTuGoc(n, m, maTran);
                break;
            case 4:
                inDuongBien(n, m, maTran);
                break;
            case 5:
                inDuongCheo(n, m, maTran);
                break;
            case 6:
                inSoNguyenTo(n, m, maTran);
                break;
            case 7:
                return 0;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

