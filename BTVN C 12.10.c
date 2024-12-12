#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu ( Khi lua chon menu cha thi hien thi menu con )\n");
        printf("      a. Giam dan\n");
        printf("      b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("      a. Tim kiem tuyen tinh\n");
        printf("      b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        if (choice == 8) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri cho phan tu %d: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printf("Cac phan tu trong mang la:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 3: {
                int viTri, giaTri;
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                if (viTri < 0 || viTri > n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d", &giaTri);
                if (n >= 100) {
                    printf("Mang da day, khong the them phan tu!\n");
                    break;
                }
                for (int i = n; i > viTri; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[viTri] = giaTri;
                n++;
                break;
            }
            case 4: {
                int viTri, giaTri;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &viTri);
                if (viTri < 0 || viTri >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                printf("Nhap gia tri moi: ");
                scanf("%d", &giaTri);
                arr[viTri] = giaTri;
                break;
            }
            case 5: {
                int viTri;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                if (viTri < 0 || viTri >= n) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = viTri; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            }
            case 6: {
                char subChoice;
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Chon: ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[i] < arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                } else if (subChoice == 'b') {
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[i] > arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;
            }
            case 7: {
                char subChoice;
                int giaTri, viTri;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Chon: ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    viTri = -1;
                    for (int i = 0; i < n; i++) {
                        if (arr[i] == giaTri) {
                            viTri = i;
                            break;
                        }
                    }
                } else if (subChoice == 'b') {
                    int left = 0, right = n - 1;
                    viTri = -1;
                    while (left <= right) {
                        int mid = (left + right) / 2;
                        if (arr[mid] == giaTri) {
                            viTri = mid;
                            break;
                        } else if (arr[mid] < giaTri) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                } else {
                    printf("Lua chon khong hop le!\n");
                    break;
                }
                if (viTri != -1) {
                    printf("Gia tri %d duoc tim thay o vi tri %d\n", giaTri, viTri);
                } else {
                    printf("Gia tri %d khong duoc tim thay\n", giaTri);
                }
                break;
            }
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    return 0;
}

