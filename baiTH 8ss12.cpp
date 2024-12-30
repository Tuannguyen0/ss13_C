#include <stdio.h>

int ucln(int a, int b);

int main() {
    int num1, num2;

    printf("Nhap so nguyen thu nhat: ");
    if (scanf("%d", &num1) != 1) {
        printf("Loi: Vui long nhap so nguyen.\n");
        return 1;
    }

    printf("Nhap so nguyen thu hai: ");
    if (scanf("%d", &num2) != 1) {
        printf("Loi: Vui long nhap so nguyen.\n");
        return 1;
    }

    int result = ucln(num1, num2);

    if (result != -1) {
        printf("Uoc chung lon nhat cua %d va %d la: %d\n", num1, num2, result);
    }

    return 0;
}
