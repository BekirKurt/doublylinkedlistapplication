#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "datastructurestask3.h"

// Bekir Kurt
// doubly linked list uygulamalari

int main()
{
    char name[20],surname[20],bolum[20];
    int ogrenci_no , sinif;

    int kontrol = 0;

    while(kontrol =! 0){
        printf("\n*********Ana Menu*********\n");
        printf("\nYapilacak islemi seciniz :\n");
        printf("\n1-Dugum ekleme\n2-Dugumu silme\n3-Ogrenci Arama\n4-Cift Bagli Listeyi Yok Etme\n5-Listeyi Gosterme\n6-Yeni Dugum Olustur\n7-Cikis");

        printf("\n\n\nIslemi seciniz :");
        scanf("\n%d",&kontrol);

        if(kontrol == 7){
            break;
        }
        switch(kontrol){
            case 1:
                printf("Adiniz :");
                scanf("%s",name);
                printf("Soydiniz :");
                scanf("%s",surname);
                printf("Bolumunuz :");
                scanf("%s",bolum);
                printf("Ogrenci no :");
                scanf("%d",&ogrenci_no);
                printf("Sinifiniz :");
                scanf("%d",&sinif);

                addnode(name , surname , bolum , ogrenci_no , sinif);
                break;
            case 2:
                printf("Silinecek ogrencinin ogrenci numarasini giriniz :");
                scanf("%d",&ogrenci_no);

                delete_node(ogrenci_no);
                break;

            case 3:
                search();
                break;

            case 4:
                destroy_list();
                break;

            case 5:
                printf("Ogrenci Bilgileri :\n");
                print_list();
                break;

            case 6:
                printf("Adiniz :");
                scanf("%s",name);
                printf("Soydiniz :");
                scanf("%s",surname);
                printf("Bolumunuz :");
                scanf("%s",bolum);
                printf("Ogrenci no :");
                scanf("%d",&ogrenci_no);
                printf("Sinifiniz :");
                scanf("%d",&sinif);

                create_node(name , surname , bolum , ogrenci_no , sinif);
                break;

            default:
                printf("Gecersiz islem girdiniz.");
                break;
        }
        printf("\n\nIslemler kaydedildi ana menu tekrar baslatiliyor...");
        sleep(2);
        system("cls");
        printf("Ogrenci Bilgi Listesi :\n");
        print_list();
   }
    return 0;
}
