// Prinafsika
// 21081010278

/*
--- TEST ---
case :
1. food-elec-chem   *DONE
2. chem-elec-food   *DONE
3. food-food-chem   (NOT PASSED)    *DONE
4. chem-chem-food   (NOT PASSED)    *DONE
5. elec-food-food   *DONE
6. food-food-elec   *DONE
7. elec-chem-chem   *DONE
8. chem-chem-elec   *DONE
9. elec-chem-food   (NOT PASSED)    *DONE
10. food-chem-elec  (NOT PASSED)    *DONE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create();
void display();
void delete();
void sort();
void send();

int berat_max = 30; // limit container
int berat_now = 0;
int kirim = 0;
int total_container = 0;

struct node* phead = NULL;
struct node{
    int id;
    char food[30];
    char chem[30];
    char elec[30];
    int berat;
    struct node* next;
}; typedef struct node node;

int main(){
    int pilih;
    menu:
    printf("1. Add\n");
    printf("2. Display\n");
    printf("3. Delete\n");
    printf("4. Sort\n");
    printf("5. Send\n");
    printf("0. Exit\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    system("clear");

    if (pilih == 1){
        create();
        goto menu;
    } 
    else if (pilih == 2){
        display();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
        
    } 
    else if (pilih == 3){
        delete();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    } 
    else if (pilih == 4){
        sort();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 5){
        send();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 0){
        system("clear");
        printf("good bye!");
        return 0;
    } 
    else {
        printf("Pilihan tidak ada\n");
        goto menu;
    }
}

void create(){
    int pilih;
    struct node* pwalker = phead;
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Total berat\t: %d TONs\n", berat_max);
    printf("Berat\t\t: %d TONs\n\n", berat_now);
    if (berat_now >= berat_max){
        printf("Container penuh!\n\n");
        return;
    }
    printf("Masukan ID (Unik) : ");
    scanf("%d", &pnew->id);
    while (pwalker != NULL){
        if (pnew->id == pwalker->id){
            printf("ID sudah ada!\n\n");
            return;
        }
        pwalker = pwalker->next;
    }
    printf("Masukan Jenis \n");
    printf("1. Makanan\n");
    printf("2. Bahan Kimia\n");
    printf("3. Barang Elektronik\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    switch (pilih){
        case 1:
            strcpy(pnew->food, "Makanan");
            break;
        case 2:
            strcpy(pnew->chem, "Bahan Kimia");
            break;
        case 3:
            strcpy(pnew->elec, "Elektronik");
            break;
        default:
            printf("Pilihan tidak ada\n");
            break;
    }
    printf("Masukan Berat : ");
    scanf("%d", &pnew->berat);
    if (berat_now + pnew->berat > berat_max){
        printf("Berat melebihi kapasitas!\n\n");
        return;
    }
    berat_now += pnew->berat;
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
    }
    else{
        struct node* ppre = phead;
        while (ppre->next != NULL){
            ppre = ppre->next;
        }
        ppre->next = pnew;
    }
    total_container += 1;
    kirim = 0;
    system("clear");
}

void display(){
    if (phead == NULL){
        printf("Data kosong!\n");
    }
    else{
        int count = 0;
        struct node* pwalker = phead;
        while (pwalker != NULL){
            count++;
            printf("Container ke-%d\n", count);
            printf("ID\t: %d\t\tJenis\t: %s%s%s\t\t\tBerat\t: %d\n", pwalker->id, pwalker->food, pwalker->chem, pwalker->elec, pwalker->berat);
            pwalker = pwalker->next;
        }
    }
}

void delete(){
    int pos ,i;

    if (phead == NULL){
        printf("Data kosong!\n");
    }
    else if (phead != NULL){
        struct node* pwalker = phead;
        int count = 0;
        while (pwalker != NULL){
            printf("No. %d \tID : %d\n", count, pwalker->id);
            pwalker = pwalker->next;
            count++;
        }
        printf("\nMasukan posisi yang ingin dihapus : ");
        scanf("%d", &pos);
        
        if (pos == 0){
            struct node* ppre = phead;
            phead = phead->next;
            berat_now -= ppre->berat;
            free(ppre);
            system("clear");
            printf("Data berhasil dihapus!\n");
        }
        else{
            struct node* pcur = phead;
            struct node* ppre = phead;
            for (i=0; i<pos; i++){
                pcur = ppre;
                ppre = ppre->next;
            }
            pcur->next = ppre->next;
            berat_now -= ppre->berat;
            free(ppre);
            system("clear");
            printf("Data berhasil dihapus!\n");
        }
        total_container -= 1;
    }
    kirim = 0;
}

void sort(){
    int temp;
    struct node* pwalker = phead, *index = NULL;
    if (phead == NULL){
        printf("Data kosong!\n");
        return;
    }
    else {
        while (pwalker != NULL){
            index = pwalker->next;
            while (index != NULL){
                if (pwalker->berat < index->berat){
                    temp = pwalker->berat;
                    pwalker->berat = index->berat;
                    index->berat = temp;
                }
                index = index->next;
            }
            pwalker = pwalker->next;
        }
        printf ("Data berhasil diurutkan!\n\n");
        kirim = 1;
        display();
    }
}

void send(){
    int pilih;
    if (kirim == 0 || phead == NULL){
        printf("Data kosong / belum diurutkan!\n");
        return;
    }
    else if (total_container == 1){
        printf("Data hanya 1 container!\n\n");
        printf("Apakah anda yakin ingin mengirim?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        switch (pilih){
            case 1:
                system("clear");
                printf("--------------------------------------------\n");
                printf("STATUS\t: Kereta berhasil dikirim!\n");
                printf("Berat\t: %d TONs\n", berat_now);
                printf("--------------------------------------------\n");
                while (phead != NULL){
                    struct node* ppre = phead;
                    phead = phead->next;
                    berat_now -= ppre->berat;
                    free(ppre);
                }
                total_container = 0;
            break;
            case 2:
                printf("Kereta tidak dikirim!\n");
                return;
            break;
            default:
                printf("Pilihan tidak ada!\n");
                return;
            break;
        }
    }
    else{
        struct node* pwalker = phead;
        printf("[WARN!] Sorting membandingkan makanan tidak boleh dekat dengan Bahan Kimia!\n\n");
        while (pwalker->next != NULL){
            if (strcmp(pwalker->food, "Makanan") == 0 && strcmp(pwalker->next->chem, "Bahan Kimia") == 0){
                printf("Makanan tidak boleh dekat dengan Bahan Kimia!\n");
                printf("Apakah anda yakin ingin mengirim?\n");
                printf("1. Ya\n");
                printf("2. Tidak\n");
                printf("Pilih : ");
                scanf("%d", &pilih);
                switch (pilih){
                    case 1:
                        system("clear");
                        goto send;
                    break;
                    case 2:
                        printf("Kereta tidak dikirim!\n");
                        return;
                    break;
                    default:
                        printf("Pilihan tidak ada!\n");
                        return;
                    break;
                }
            }
            else if (strcmp(pwalker->chem, "Bahan Kimia") == 0 && strcmp(pwalker->next->food, "Makanan") == 0){
                printf("Makanan tidak boleh dekat dengan Bahan Kimia!\n");
                printf("Apakah anda yakin ingin mengirim?\n");
                printf("1. Ya\n");
                printf("2. Tidak\n");
                printf("Pilih : ");
                scanf("%d", &pilih);
                switch (pilih){
                    case 1:
                        system("clear");
                        goto send;
                    break;
                    case 2:
                        printf("Kereta tidak dikirim!\n");
                        return;
                    break;
                    default:
                        printf("Pilihan tidak ada!\n");
                        return;
                    break;
                }
            }
            pwalker = pwalker->next;
        }
        send:
        printf("--------------------------------------------\n");
        printf("STATUS\t: Kereta berhasil dikirim!\n");
        printf("Berat\t: %d TONs\n", berat_now);
        printf("--------------------------------------------\n");
        while (phead != NULL){
            struct node* ppre = phead;
            phead = phead->next;
            free(ppre);
        }
        printf("\nData berhasil di kosongkan!\n");
        phead = NULL;
        berat_now = 0;
    }
}
