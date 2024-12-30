#include <stdio.h>
#include <stdlib.h>

int** tao_ma_tran(int so_hang, int so_cot) {
   

    if (so_hang <= 0 || so_cot <= 0) {
        printf("So hang va so cot phai la so nguyen duong.\n");
        return NULL;
    }

    
    int** ma_tran = (int**)malloc(so_hang * sizeof(int*));
    if (ma_tran == NULL) {
        perror("Loi cap phat bo nho.");
        exit(1);
    }

    
    for (int i = 0; i < so_hang; i++) {
        ma_tran[i] = (int*)malloc(so_cot * sizeof(int));
        if (ma_tran[i] == NULL) {
            perror("Loi cap phat bo nho.");
            for (int j = 0; j < i; j++) {
                free(ma_tran[j]);
            }
            free(ma_tran);
            exit(1);
        }
    }

   
    for (int i = 0; i < so_hang; i++) {
        for (int j = 0; j < so_cot; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            if (scanf("%d", &ma_tran[i][j]) != 1) {
                printf("Loi: Gia tri nhap vao khong phai la so nguyen.\n");
                for (int k = 0; k <= i; k++) {
                    free(ma_tran[k]);
                }
                free(ma_tran);
                return NULL;
            }
        }
    }

    return ma_tran;
}

void in_ma_tran(int** ma_tran, int so_hang, int so_cot) {
    if (ma_tran == NULL) return;

    for (int i = 0; i < so_hang; i++) {
        for (int j = 0; j < so_cot; j++) {
            printf("%d ", ma_tran[i][j]);
        }
        printf("\n");
    }
}

void giai_phong_ma_tran(int** ma_tran, int so_hang) {
    if (ma_tran == NULL) return;

    for (int i = 0; i < so_hang; i++) {
        free(ma_tran[i]);
    }
    free(ma_tran);
}

int main() {
    int so_hang, so_cot;

    printf("Nhap so hang cua ma tran: ");
    if (scanf("%d", &so_hang) != 1 || so_hang <= 0) {
        printf("So hang khong hop le.\n");
        return 1;
    }

    printf("Nhap so cot cua ma tran: ");
    if (scanf("%d", &so_cot) != 1 || so_cot <= 0) {
        printf("So cot khong hop le.\n");
        return 1;
    }

    int** ma_tran = tao_ma_tran(so_hang, so_cot);

    if (ma_tran != NULL) {
        printf("\nMa tran vua tao:\n");
        in_ma_tran(ma_tran, so_hang, so_cot);
        giai_phong_ma_tran(ma_tran, so_hang);
    }

    return 0;
}
