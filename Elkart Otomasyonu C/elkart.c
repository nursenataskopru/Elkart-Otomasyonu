#include <stdio.h>
#include <stdlib.h>
// Nursena Taskopru
typedef struct kisi
{
    char ad[15];
    int id;
    int durum;
    int para;


} Bilgiler;
typedef struct GenelBilgi
{
    Bilgiler bilgi;
//ic ice struct icin yapi
} genelbilgiler;

genelbilgiler *sahis;
// sahis struct pointeri islemler bu pointerla yapiliyor
int kacSahis=0,t=0;
int yukleme_miktari;
int menu()
{
    //menuyu rahatca cagirabilmek icin bu fonksiyonu actim
    int sayi;
    printf("\n-----ELKART OTOMASYONU-----\n");
    printf("1-Kisi Ekleme \n");
    printf("2-Para Yukleme \n");
    printf("3-Kisi Listeleme \n");
    printf("4-Kisi Silme \n");
    printf("5-Ogrencilik Durumu Guncelleme \n");
    printf("6-Yetiskin Listesi \n");
    printf("7-Ogrenci Listesi \n");
    printf("8-Programi Kapat\n");
    printf("---Lutfen ilk olarak kisi ekleme islemini yapiniz---");
    printf("\nSecim yap: ");
    scanf( "%d", &sayi );
    printf("\n----------------------------\n");
    return sayi;
}

genelbilgiler *kisi_ekleme()
{
    printf("\n-----Kisi Ekleme-----\n");
    printf("\nEkleyeceginiz kisi sayisi: ");
    scanf("%d",&kacSahis);
    sahis = (genelbilgiler*) realloc (sahis, (kacSahis+t)*sizeof(genelbilgiler));
    int i;
    //reallocla kayit olacak kisi kadar yer actim, t program devam ederken tekrar kisi eklemek istedigimizde sorun cıkmamasi icin var.
    for ( i = t ; i < kacSahis+t ; i++ )
    {
        printf("\nAd: ");
        scanf("%s",(( sahis + i )->bilgi.ad));
        printf("\nID: ");
        scanf("%d",&(( sahis + i )->bilgi.id));
        // struct pointeri gezebilmek icin for dongusunde
y:
        printf("\nOgrenci misin? Evet -> 1 / Hayir -> 0: ");
        scanf("%d",&(( sahis + i )->bilgi.durum));
        if(( sahis + i )->bilgi.durum<0 || ( sahis + i )->bilgi.durum>1)
        {
            printf("\nDurum bilgisini yanlis girdiniz [0 veya 1 girmelisiniz]");
            goto y;
        }

        printf("\nBakiyeniz: ");
        scanf("%d",&(( sahis + i )->bilgi.para));
        printf("\n----Bilgiler basarili bir sekilde kaydedildi----\n");

    }
    t += kacSahis;
    kacSahis = 0;

}

void para_yukleme()
{
    printf("\n-----Para Yukleme-----\n");
    if(sahis==NULL)
    {
        printf("----Kayitli kullanici yok. Lutfen once kisi ekleyiniz----");
        menu();
    }
    for ( int i = 0 ; i < kacSahis+t ; i++ )
    {
        printf("\n%d. Kisi-Ad:% s\tId:%d\tOgrenci mi (Evet -> 1 / Hayir -> 0):%d\tPara:%d\n", i+1,(sahis+i)->bilgi.ad,
               (sahis+i)->bilgi.id,
               (sahis+i)->bilgi.durum,
               (sahis+i)->bilgi.para);
    }
    int secim;
    printf("\nKacinci kisiye yukleme yapilacak?:");
    scanf("%d",&secim);
    secim = secim - 1 ;
    //kacinci kisi oldugunu gosterirken for dongusundeki i'yi kullandim, i sifirdan basliyor yani sahis+0 aslinda 1. kisi bu yuzden secim-1 yazdim
    printf("\nYuklemek istediginiz miktari giriniz: ");
    scanf("%d",&yukleme_miktari);
    (sahis+secim)->bilgi.para=((sahis+secim)->bilgi.para)+yukleme_miktari;
    printf("\n----Para basarili bir sekilde yuklendi----\n");
    for ( int i = 0 ; i < kacSahis + t ; i++ )
    {
        printf("\n%d. Kisi-Ad:% s\tId:%d\tOgrenci mi (Evet -> 1 / Hayir -> 0):%d\tPara:%d\n", i+1,(sahis+i)->bilgi.ad,
               (sahis+i)->bilgi.id,
               (sahis+i)->bilgi.durum,
               (sahis+i)->bilgi.para);
    }

}
void kisi_listeleme()
{
    printf("\n-----Kisi Listeleme-----\n");
    if(sahis==NULL)
    {
        printf("\n----Kayitli kisi yok----\n");
    }

    for ( int i = 0 ; i < t ; i++ )
    {
        printf("\n%d. Kisi-Ad:% s\tId:%d\tOgrenci mi (Evet -> 1 / Hayir -> 0):%d\tPara:%d\n", i+1,(sahis+i)->bilgi.ad,
               (sahis+i)->bilgi.id,
               (sahis+i)->bilgi.durum,
               (sahis+i)->bilgi.para);
    }
}
void kisi_silme()
{
    printf("\n-----Kisi Silme-----\n");
    if(sahis==NULL)
    {
        printf("\n----Kayitli kisi yok----\n");
        menu();
    }
    int i;
    for (  i = 0 ; i < kacSahis+t ; i++ )
    {
        printf("\n%d. Kisi-Ad:% s\tId:%d\tOgrenci mi (Evet -> 1 / Hayir -> 0):%d\tPara:%d\n", i+1,(sahis+i)->bilgi.ad,
               (sahis+i)->bilgi.id,
               (sahis+i)->bilgi.durum,
               (sahis+i)->bilgi.para);
    }
    int secim;
    printf("\nHangisini silmek istersiniz :");
    scanf("%d",&secim);
    secim = secim - 1;
    for( i=secim; i< kacSahis+t; i++)
    {
        sahis[i]=sahis[i+1];
    }
    //for dongusu icindeki statement sayesinde birini silmek istedigimizde yer degistirme yapiyoruz en son reallocla silmek istedigimiz kisiyi siliyoruz.
    t--;
    sahis = (genelbilgiler*) realloc (sahis, t*sizeof(genelbilgiler));
    printf("\n----Kisi basariyla silindi----\n");
}

void durum_guncelleme()
{
    printf("\n-----Ogrencilik Durumunu Guncelleme-----\n");
    if(sahis==NULL)
    {
        printf("\n----Kayitli kisi yok----\n");
        menu();
    }
    kisi_listeleme();
    int secim,onay;
    printf("\n Kacinci kisinin durumu guncellenecek?:");
    scanf("%d",&secim);
    secim = secim - 1;
    printf("\nOgrenci misiniz? Evet -> 1 / Hayir -> 0:");
    scanf("%d",&((sahis+secim)->bilgi.durum));
    printf("\n----Durum Guncelleme Basariyla Tamamlandi----\n");
}

void yetiskinler()
{
    //yetiskin listeleme
    printf("\n-----Yetiskinlerin Listesi-----\n");
    if(sahis==NULL)
    {
        printf("\n----Kayitli kisi yok----\n");
        menu();
    }
    for(int i = 0 ; i < kacSahis + t ; i++ )
    {
        if((sahis+i)->bilgi.durum == 0)
        {
            printf("\n %d. Kisi-\t Ad:%s \tId:%d \tPara:%d", i+1, (sahis+i)->bilgi.ad, (sahis+i)->bilgi.id, (sahis+i)->bilgi.para);
        }
    }
}

void ogrenciler()
{
    //ogrenci listeleme
    printf("\n-----Ogrencilerin Listesi-----\n");
    if(sahis==NULL)
    {
        printf("\n----Kayitli kisi yok----\n");
        menu();
    }
    for(int i = 0 ; i < kacSahis +t  ; i++ )
    {
        if((sahis+i)->bilgi.durum == 1)
        {
            printf("\n %d. Kisi-\t Ad:%s \tId:%d \tPara:%d", i+1, (sahis+i)->bilgi.ad, (sahis+i)->bilgi.id, (sahis+i)->bilgi.para);
        }
    }
}

int main()
{
    genelbilgiler *sahis;
    int sayi = menu();
    while(1==1)
    {
        //menuye exit gelene kadar islemlerden sonra geri donebilmesi icin sonsuz dongu var
        switch( sayi )
        {

        case 1:

            sahis=kisi_ekleme();

            break;

        case 2:
            para_yukleme();
            break;

        case 3:
            kisi_listeleme();
            break;

        case 4:
            kisi_silme();
            break;

        case 5:
            durum_guncelleme();
            break;

        case 6:
            yetiskinler();
            break;

        case 7:
            ogrenciler();
            break;
        case 8:
            exit(0);
        }
        sayi = menu();

    }
    return 0;
}
