#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1 

void insert(int HT[], int m, int key) {
    int index = key % m; 
    int start = index; 
    
    
    while (HT[index] != EMPTY) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash Table is full, cannot insert key %d\n", key);
            return;
        }
    }
    HT[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}


void display(int HT[], int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (HT[i] == EMPTY)
            printf("HT[%02d] : EMPTY\n", i);
        else
            printf("HT[%02d] : %d\n", i, HT[i]);
    }
}

int main() {
    int m, n;
    
    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);
    
    int HT[m];
    for (int i = 0; i < m; i++) HT[i] = EMPTY;
    
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    
    printf("Enter %d employee keys (4-digit integers):\n", n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(HT, m, key);
    }
    
    display(HT, m);
    return 0;
}
