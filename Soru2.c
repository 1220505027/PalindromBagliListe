#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct List {
    int deger;
    struct List* next;
};

bool Palindrom(struct List* head) {
    int boyut = 0;
    struct List* bag = head;
    while (bag) {
        boyut++;
        bag = bag->next;
    }
    
    int dizi[boyut];
    bag = head;
    for (int i = 0; i < boyut; i++) {
        dizi[i] = bag->deger;
        bag = bag->next;
    }
    
    for (int i = 0, j = boyut - 1; i < j; i++, j--) {
        if (dizi[i] != dizi[j]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    struct List* head = (struct List*)malloc(sizeof(struct List));
    head->deger = 1;
    head->next = (struct List*)malloc(sizeof(struct List));
    head->next->deger = 2;
    head->next->next = (struct List*)malloc(sizeof(struct List));
    head->next->next->deger = 2;
    head->next->next->next = (struct List*)malloc(sizeof(struct List));
    head->next->next->next->deger = 1;
    head->next->next->next->next = NULL;

    bool sonuc = Palindrom(head);
    printf("%s\n", sonuc ? "true" : "false");

    return 0;
}

