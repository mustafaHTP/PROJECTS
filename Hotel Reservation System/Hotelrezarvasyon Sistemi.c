/*
 * HOTEL REZERVASYON S�STEM�
 *
 * odalar.txt dosyasinda oda numaralari ve dolu veya bo� olduklari tutulur.
 *
 *
 * rezervasyon.txt dosyasinda m��terinin sirasiyla epostasi, ismi ,soyismi ,telefon numarasi ,rezervasyon yapaca�i tarih,
 * kalaca�� g�n sayisi, oda t�r�, ki�i sayisi, oda numarasi ve varsa kredi karti numarasi tutulur.
 *
 *
 *
 * Emegi ge�enler
 * 
 * Mustafa Hatipo�lu
 * Ahmet Hacio�lu
 * Dilara Karaduman
 * Selen Nazli Ba�a
 *
 */


#include <stdio.h>
#include <stdlib.h>   //system cls i�in
#include <locale.h>
#include <string.h>
#include <conio.h>   //getch fonksiyonu i�in
#include <ctype.h>



char std[10]="Standart";   //musteri.odaturu'ne kopyalamak i�in bazi global de�i�kenler belirlendi
char ort[10]="Orta";
char lx[10]="Lux";

char kisi1[2]="1";    //musteri.kisisayisi'na kopyalamak i�in bazi global de�iskenler belirlendi
char kisi2[2]="2";
char kisi4[2]="4";


char eposta[50]; //M��teri yapaca�i i�lemlerde �nce epostasini girmelidir bu y�zden global bir de�i�ken tanimliyoruz
int mgunsayisi;   //Tutar fonksiyonuna g�ndermek i�in int de�i�ken tanimlandi

typedef struct musteribilgileri {  //M�steri ile ilgili b�t�n bilgiler bu struct ta tutulur

	char mail[50];
	char isim[30];
	char soyisim[30];
	char telefon[11];
	char gun[3];
	char ay[3];
	char yil[5];
	char gunsayisi[4];
	char odatur[2];
	char kisisayisi[2];
	char odano[4];
	int tutar;
    char kredikartno[17];

	}musteri;

void musteribilgisi (){   //Musteri sirasiyla e postasini, ismini, soyismini ve telefon numarasini alir ve struct ta kaydeder

	FILE *h = fopen("rezervasyon.txt","a+");
	struct musteribilgileri musteri;

	char telkontrol[50]; //M��terinin telefon numarasini ge�i�i bir s�re tutar
	int a=0; //D�ng�y� kontrol i�in
	char epostakontrol='@'; //Girilen epostada '@' karakterini kontrol i�in tanimlandi
	int b=0;  //Eposta d�ng�s� kontrol� i�in


	while(b<1){ //M��teri istenilen �artlarda eposta girmedi�i s�rece d�ng�ye girecek

	printf("\nLutfen e-posta adresini giriniz: ");  //M��teriden eposta adresini alir ve struct a yazar
	scanf("%s",musteri.mail);




    for(int i=0;i<strlen(musteri.mail);i++){

		    if(musteri.mail[i]==epostakontrol)
	           b++;
		}

    if(b==0){
       system("cls");
       printf("\nL�tfen ge�erli bir eposta giriniz...\n");
	       }


         }

    for(int j=0;j<strlen(musteri.mail);j++){	//Eposta adresi b�y�k harflerle girilirse onlari k���k harf yapar
		 musteri.mail[j]=tolower(musteri.mail[j]);
		}


	system("cls");
	fwrite(musteri.mail,sizeof(char),strlen(musteri.mail),h); //�nce yazilacak diziyi sonra yazilacak her �genin boyutu, string in uzunlu�u  ve hangi stream e yazilacagi belirtilir
    fputc('\t',h);   //Her dosyaya yazma isleminden sonra "\t" konur


	printf("\nL�tfen ismini giriniz(UYARI: iki isminiz varsa lutfen birlesik yaziniz):");
	scanf("%s",musteri.isim);
	musteri.isim[0]=toupper(musteri.isim[0]); //M�sterinin isminin ilk harfini b�y�k yapar
	system("cls");

	fwrite(musteri.isim,sizeof(char),strlen(musteri.isim),h);
    fputc('\t',h);

	printf("\nLutfen soyisminizi giriniz: ");
	scanf("%s",musteri.soyisim); //M�sterinin soyisminin ilk harfini b�y�k yapar
	musteri.soyisim[0]=toupper(musteri.soyisim[0]);
	system("cls");

	fwrite(musteri.soyisim,sizeof(char),strlen(musteri.soyisim),h);
    fputc('\t',h);

	while(a<1){  //Musteri ge�erli bir telefon numarasi girmedigi s�rece d�ng�ye girecek

	printf("\nLutfen cep telefon numaranizi giriniz: ");
	scanf("%s",telkontrol);

	if(strlen(telkontrol)<12 && strlen(telkontrol)>10){
		a++;
		strcpy(musteri.telefon,telkontrol);

		}

	else
	    {
		system("cls");
		printf("\nL�tfen Ge�erli bir telefon numaras� giriniz...\n");

			}

	 }

	fwrite(musteri.telefon,sizeof(char),strlen(musteri.telefon),h);
    fputc('\t',h);

	fclose(h);  //acilan streami kapatir
	system("cls"); //konsol ekranini temizler
	}


int gunvetarih(){

	FILE *h = fopen("rezervasyon.txt","a+");



	struct musteribilgileri musteri;
	//M�steriden alinan tarih bilgileri ve ka� g�n kalacagi bu degiskenlerde tutulur
	int month1;
	int length;
	int day;
	int year;
	int b=0; //D�ng� kontrol i�in


	while(b<1){   //Istenilen sartlarda giris yapilmadigi surece dongu devam edecek

	printf("\nLutfen hangi tarihler icin rezervasyon yapacaginizi belirtiniz: "); //
	printf("\nG�n: ");
	scanf("%s",musteri.gun);



	printf("\nAy: ");
	scanf("%s",musteri.ay);



	printf("\nY�l: ");
	scanf("%s",musteri.yil);


	printf("\nLutfen kac gun kalacaginizi soyleyiniz: ");
	scanf("%s",musteri.gunsayisi);




	printf("\nLutfen hangi tarihler icin rezervasyon yapacaginizi tekrar belirtiniz: ");
	printf("\nG�n: ");
	scanf("%d",&day);

	printf("\nAy: ");
	scanf("%d",&month1);

	printf("\nY�l: ");
	scanf("%d",&year);

	printf("\nLutfen kac gun kalacaginizi tekrar soyleyiniz: ");
	scanf("%d",&length);

	if(day<31 && day>0 && month1>0 && month1<13 && year>2018 && year<2021 ){ //Tarihin istenilen sartlarda girilmesi i�in
	   b++;
	       }
  else{
      system("cls");
      printf("\nL�tfen g�n/ay/y�l do�ru e�le�ecek sekilde giriniz...\n");
       }

         }

	//Dosyaya yazma i�lemleri

	fwrite(musteri.gun,sizeof(char),strlen(musteri.gun),h);
    fputc('\t',h);
	fwrite(musteri.ay,sizeof(char),strlen(musteri.ay),h);
	fputc('\t',h);
	fwrite(musteri.yil,sizeof(char),strlen(musteri.yil),h);
    fputc('\t',h);
    fwrite(musteri.gunsayisi,sizeof(char),strlen(musteri.gunsayisi),h);
	fputc('\t',h);

	mgunsayisi=length; //Kalacagi g�n sayisini global degiskene atanir ve bu degisken tutar fonksiyonunda kullanilacak
	fclose(h);
	system("cls");
	return month1; //Girilen ay a g�re fiyat belirlenecek bu y�zden ay return edilir ve donem fonksiyonuna g�nderilir

	}


int donem (int mevsim) {

	int Y,S,K,I;

	K=1;    //Mevsime g�re fiyat �arpilir
	S=2;
	I=3;
	Y=4;
	        //gun ve tarih fonksiyonunun return ettigi degere g�re donem fonksiyonuda �arpilacak olan fiyati return eder
	if(mevsim==12 || mevsim==1 || mevsim==2) //kis donemine gore fiyatlandirilir
		return K;
	else if(mevsim==3 || mevsim==4 || mevsim==5) //ilkbahar donemine gore fiyatlandirilir
		return I;
	else if(mevsim==6 || mevsim==7 || mevsim==8) //yaz donemine gore fiyatlandirilir
		return Y;
	else if(mevsim==9 || mevsim==10 || mevsim==11) //sonbahar donemine gore fiyatlandirilir
		return S;
	else
		return -1;
	}


int odaturu(){

	FILE *h = fopen("rezervasyon.txt","a+");
	struct musteribilgileri musteri;

	int a=0; //Donguyu kontrol i�in
	int roomtype;  //Oda tipini tutar ve bu deger return edilir

	while(a<1){

	printf("\nRezervasyon yapmak istediginiz oda t�r�n� se�iniz:");
	printf("\n1-Standart");
    printf("\n2-Orta");
	printf("\n3-Lux\n");

	scanf("%d",&roomtype);

		 if(roomtype==1){   //Kullanicidan alinan degere gore oda turu belirlenir
	        strcpy(musteri.odatur,std);  //global degiskenler kopyalanir
            a++;
            system("cls"); }
	else if(roomtype==2){
			strcpy(musteri.odatur,ort);
            a++;
            system("cls"); }
	else if(roomtype==3){
			strcpy(musteri.odatur,lx);
            a++;
            system("cls"); }
	else{
	    system("cls");
        printf("\nL�tfen 1-3 aras� bir say� giriniz !\n");
	     }
		  }


	fwrite(musteri.odatur,sizeof(char),strlen(musteri.odatur),h);
	putc('\t',h);

	fclose(h);



	return roomtype; //Oda tipi tutar fonksiyonununa gonderilecek

	}

int kackisilik(){

	FILE *h = fopen("rezervasyon.txt","a+");

	struct musteribilgileri musteri;

	int i=0;
	int kisisayi;

	while(i<1){ //Kullanici 1-2-4 haricinde sayi girdigi surece dongu devam edecek
	printf("\nKa� ki�ilik rezervasyon yapmak istiyorsunuz(1/2/4)?");
	scanf("%d",&kisisayi);


		if(kisisayi==1){ //Kullanicidan alinan kisi sayisina gore atama yapilir
	       strcpy(musteri.kisisayisi,kisi1);  //global degisken kopyalanir
           i++;
                       }

   else if(kisisayi==2){
	       strcpy(musteri.kisisayisi,kisi2);
           i++;
				       }

   else if(kisisayi==4){
	       strcpy(musteri.kisisayisi,kisi4);
	       i++;
				       }
   else  {
          system("cls");
          printf("\nL�tfen 1/2/4 se�eneklerinden birini se�iniz\n");
          }

	         }
	system("cls");
	fwrite(musteri.kisisayisi,sizeof(char),strlen(musteri.kisisayisi),h);
	putc('\t',h);

	fclose(h);
	return kisisayi; //Kisi sayisini tutar fonksiyonuna gonderilir



          }



						//En �nemli FONKSIYON
int odanumarasi (int y,int z){ //y oda turu 1-std 2-orta 3-lux z ka� kisilik

	FILE *h = fopen("rezervasyon.txt","a+");



	struct musteribilgileri musteri;

	int i=0;

	int sinir=-1;   //Oda t�r� ve ki�i sayisina gore oda numarasi belirleneceginden belirli araliklarda oda numarasai belirlenecek



	char odadurumubos[]="0";
	char odadurumudolu[]="1";
	char tab []="\t";
	char escape[]="\n";
    char l[30], l2[30],l3[30]; /* dosyadan satir satir okuyacak */ //guncellenecek satiri l3 dizisine yazdirilacak



	FILE *otelodalari = fopen ("odalar.txt","r");
	FILE *gecici = fopen ("temp.txt","w");


	if(y==1){ //STANDART ODALAR ICIN
		if(z==1){      //standart 1 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){  //dosyayi sonuna kadar okuyacak
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");   //0 ve 1'e ulasmak i�in yani odanin dolu mu bos mu oldugunu anlamak icin

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir<20)){
					char *odano = strtok(NULL,"\n");   //Eger oda bos ise oda numarasi alinir ve musteri odano structa yazilir
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);  //Degisecek olan satira burada kopyalama islemlerini yapiyoruz
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);		//Eger oda bos degilse satirlari yazmaya devam ediyoruz

				      }



					}



                              } //STDD 1 Kisilik

		if(z==2){      //standart 2 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");                 
                    
					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=20 && sinir<40)){ // butun oda numaralari tek bir txt de tutuldugu icin m�sterinin istedigi sartlara g�re belirli araliklarda atama yapacak 
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //STDD 2 Kisilik

		if(z==4){      //standart 4 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=40 && sinir<60)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //STDD 4 Kisilik

											   } //STANDART ODALAR



    if(y==2){  // ORTA ODALAR ICIN

		 if(z==1){      //ORTA 1 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=60 && sinir<70)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //ORTA 1 Kisilik


		 if(z==2){      //ORTA 2 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=70 && sinir<80)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //ORTA 2 Kisilik


		 if(z==4){      //ORTA 4 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=80 && sinir<90)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //ORTA 4 Kisilik






		                             } //ORTA ODALAR


		if(y==3){ //LUX ODALAR ICIN
			if(z==1){      //LUX 1 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=90 && sinir<95)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //LUX 1 Kisilik

		if(z==2){      //LUX 2 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=95 && sinir<98)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //LUX 2 Kisilik

		if(z==4){      //LUX 4 Kisilik


				while(fgets(l, 20, otelodalari) != NULL ){
				    sinir++;
					strcpy(l2, l);

					char *dolumubosmu = strtok(l, "\t");

					if(!strcmp(dolumubosmu,odadurumubos) && i<1 && (sinir>=98 && sinir<100)){
					char *odano = strtok(NULL,"\n");
			        strcpy(musteri.odano,odano);


						strcpy(l3,odadurumudolu);
						strcat(l3,tab);
						strcat(l3,odano);
						strcat(l3,escape);
						fputs(l3,gecici);
						i++;
																 }


				  else{
			          fputs(l2,gecici);

				      }



					}



                              } //STDD 4 Kisilik

											   } //LUX ODALAR




	fwrite(musteri.odano,sizeof(char),strlen(musteri.odano),h);
	fputc('\t',h);




	fclose(h);
	fclose(otelodalari);
	fclose(gecici);

	remove("odalar.txt");  //eski odalar dosyasini kaldiriyoruz
	rename("temp.txt","odalar.txt"); //gecicidosyanin adini odalar ile degistiriyoruz

	return 1;

	} 


void tutar (int odatip,int member,int donemx,int uzunluk){

	struct musteribilgileri musteri;
	FILE *h = fopen("rezervasyon.txt","a+");
	char kredikartkontrol[50];  //Musterinin kredikarti numarasini gecici bir sure tutacak
	int a=0; //Kredi karti yanl�� girildigi s�rece bu deger degismeyecek

	int toplamtutar=0;
	char devammi; // Musteri fiyata g�re devam edip etmeyecegi tercihi bu degiskende tutulacak

	  if(odatip==1)   //odatipine g�re tutara �nce ekleme yapilir
	     toplamtutar+=50;
 else if(odatip==2)
	     toplamtutar+=100;
 else if(odatip==3)
	     toplamtutar+=200;

	  if(member==1)  //Kisi sayisina gore tutar carpilir
	     toplamtutar*=1;
 else if(member==2)
	     toplamtutar*=2;
 else if(member==4)
	     toplamtutar*=4;

	 toplamtutar=toplamtutar*donemx*uzunluk; //Tutar d�neme g�re yani mevsimle ve kalinacak gun sayisini ile carpilir

	   musteri.tutar=toplamtutar;   //struct a tutari yazdiriyoruz
       printf("\nTutar = %d TL",musteri.tutar);
       printf("\nDevam etmek istiyor musunuz ?[E/H]");
       scanf(" %c",&devammi);

       if(devammi=='E' || devammi=='e'){  //Kullanicinin devam etmeyi istemesi halinde kredikartno su alinir

          while(a<1){

          printf("\nL�tfen kredi kart� numaran�z� giriniz:");
		  scanf("%s",kredikartkontrol);

		    if(strlen(kredikartkontrol)<17 && strlen(kredikartkontrol)>15){
				a++;
				strcpy(musteri.kredikartno,kredikartkontrol);
				fwrite(musteri.kredikartno,sizeof(char),strlen(musteri.kredikartno),h);
	            fputc('\n',h);  //En son  dosyaya kredi kart numarasi yazilacagindan alt satira gecmesi i�in \n koyuyoruz
	 	        system("cls");
	 	        printf("\nRezervasyonunuz Ba�ar�yla Tamamlanm��t�r...");
				                             }
		  else
		       {
				system("cls");
				printf("\nL�tfen ge�erli bir kredi karti numarasi giriniz...\n");
				}

	               }


	                                   }

      else
          fputc('\n',h);   //Yeni yapilacak herhangi bir rezervasyonda alt satira ge�mesi i�in dosyaya "\n" bastirilir




	   fclose(h);
	   getch();

	}






void rezervasyontakip (){

	FILE *h = fopen("rezervasyon.txt","r");

	printf("\nLutfen e-posta adresini giriniz: "); //M�steri epostasini burada sorar ve alir
    scanf("%s",eposta);
    system("cls");

    char l[200], l2[200]; //Dosyanin her bir satiri bu dizilerde tutulacak
    int i=0; //Epostaya ait rezervasyonun olup olmadigini dongu icinde belirleyecek
    while(fgets(l,200,h) != NULL ){
        strcpy(l2, l);
        char *email = strtok(l,"\t");
        if(!strcmp(eposta,email)){

            printf("E-Posta: %s\n",email);
            printf("Ad: %s\n",strtok(NULL,"\t"));
            printf("Soyad: %s\n", strtok(NULL,"\t"));
            printf("Telefon: %s\n",strtok(NULL,"\t"));
            printf("Tarih: %s.",strtok(NULL,"\t"));
            printf("%s.",strtok(NULL,"\t"));
            printf("%s\n",strtok(NULL,"\t"));
            printf("Kalinacak g�n say�s�: %s\n",strtok(NULL,"\t"));
            printf("Oda t�r�: %s\n",strtok(NULL,"\t"));
            printf("Kisi say�s�: %s\n",strtok(NULL,"\t"));
            printf("ODA NO: %s\n",strtok(NULL,"\t"));
            printf("Kredi Kart no: %s\n",strtok(NULL,"\n"));

            i++;
        }
    }

    if(i==0)    //Eger eposta rezervasyon.txt dosyasinda yoksa bu if'e girer
       printf("\nBu epostaya ait bir rezervasyon bulunamam��t�r...\n");


    getch();
    fclose(h);

	}

void rezervasyoniptal(char *eposta){


	int rzrvsynciptal=0; //Girilen epostaya ait rezervasyonun olup olmadigini bu degiskenle kontrol edilecek

	//g�ncellenecek satira asagidaki diziler yazdiralacak

	char odadurumubos[]="0";
	char tab []="\t";
	char escape[]="\n";

	int x=0; //Strtok ile 10 defa �agirmak i�in bu degiskeni kullaniyoruz
	FILE *otelodalari = fopen("odalar.txt","r");
	FILE *gecici1 = fopen("temp1.txt","w");  //odalar.txt deki veriyi temp1.txt e yazacagiz


	FILE *h = fopen("rezervasyon.txt","r");
	FILE *gecici2 = fopen("temp2.txt","w"); //rezervasyon.txt deki veriler temp2.txt e yazdirilacak

	char x1[200];char x2[200];char y1[30];char y2[30];  //X dizileri rezervasyon txt de kullanilacak Y dizileri odalar.txt de
	char *odanoiptal;
	char *odanoiptalcontrol; //Dosyadaki oda numarasina ulasmak icin

	while(fgets(x1,200,h)!=NULL){

		strcpy(x2,x1);
		char *epostakntrl=strtok(x1,"\t");

		   if(!strcmp(epostakntrl,eposta)){
			   rzrvsynciptal++;
			   while(x<10){

				   odanoiptal=strtok(NULL,"\t"); //Musterinin oda numarasi alinir
				   x++;
				           }



			   }

		else
		    fputs(x2,gecici2);




		}


	   while(fgets(y1,30,otelodalari)!=NULL){

		    strcpy(y2,y1);
		    odanoiptalcontrol=strtok(y1,"\t");
		    odanoiptalcontrol=strtok(NULL,"\n");

		  //Musterinin oda numarasi ile dosyadaki b�t�n numaralar karsilastirilir ve eslesen satir g�ncellenerek yazilir
		    if(!strcmp(odanoiptalcontrol,odanoiptal)){

				strcpy(y2,odadurumubos);
				strcat(y2,tab);
				strcat(y2,odanoiptal);
				strcat(y2,escape);
			    fputs(y2,gecici1);

				}
		 else
		     fputs(y2,gecici1);



		   }

	if(rzrvsynciptal==0){  //Rezervasyoniptal isleminin basarili olup olmadagina bakilir
	   system("cls");
	   printf("\nBu epostaya ait bir rezervasyon bulunamam��t�r...\n");
					}
	else{
	   system("cls");
	   printf("\nRezervasyonunuz ba�ar�l� bir �ekilde iptal edilmi�tir...\n");
	    }
	fclose(otelodalari);
	fclose(h);
	fclose(gecici1);
	fclose(gecici2);


	remove("rezervasyon.txt");
	remove("odalar.txt");

	rename("temp1.txt","odalar.txt");
	rename("temp2.txt","rezervasyon.txt");

	getch();



}


void rezervasyonguncelle(){     //Once mevcut rezervasyon iptal edilecek sonra yeniden rezervasyon yapilacak

	printf("L�tfen e-posta adresinizi giriniz:");
	scanf("%s",eposta);
	system("cls");

	int rzrvsynciptal=0;
	char odadurumubos[]="0";
	char tab []="\t";
	char escape[]="\n";
	int x=0;



	FILE *h = fopen("rezervasyon.txt","a+");
	FILE *gecici2 = fopen("temp2.txt","w");   //rezervasyon bilgilerini temp2.txt e yazar

	char x1[200];char x2[200];char y1[30];char y2[30];
	char *odanoiptal;
	char *odanoiptalcontrol;

	while(fgets(x1,200,h)!=NULL){

		strcpy(x2,x1);
		char *epostakntrl=strtok(x1,"\t");
		if(!strcmp(epostakntrl,eposta)){
			rzrvsynciptal++;
			while(x<10){
				   odanoiptal=strtok(NULL,"\t");
				   x++;
				           }



			   }

		else
		    fputs(x2,gecici2);


		}

	fclose(h);
	fclose(gecici2);
	remove("rezervasyon.txt");
	rename("temp2.txt","rezervasyon.txt");





    if(rzrvsynciptal==0){
	   printf("\nBu epostaya ait bir rezervasyon bulunamam��t�r...\n");
       }



 else{


	FILE *otelodalari = fopen("odalar.txt","a+");
	FILE *gecici1 = fopen("temp1.txt","w");  //odalar.txt deki veriyi temp1.txt e yazar

	while(fgets(y1,30,otelodalari)!=NULL){

		    strcpy(y2,y1);
		    odanoiptalcontrol=strtok(y1,"\t");
		    odanoiptalcontrol=strtok(NULL,"\n");

		    if(!strcmp(odanoiptalcontrol,odanoiptal)){

				strcpy(y2,odadurumubos);
				strcat(y2,tab);
				strcat(y2,odanoiptal);
				strcat(y2,escape);
			    fputs(y2,gecici1);
				}
		 else{
		     fputs(y2,gecici1);
		 }


		   }

	fclose(otelodalari);
	fclose(gecici1);

	remove("odalar.txt");
	rename("temp1.txt","odalar.txt");





	int donembelirleme;
    int odaturubelirleme;
    int kisisayisibelirleme;
    int mevsimbelirleme;


	 musteribilgisi();
     mevsimbelirleme=gunvetarih();
     donembelirleme=donem(mevsimbelirleme);
     odaturubelirleme=odaturu();
     kisisayisibelirleme=kackisilik();
     odanumarasi(odaturubelirleme,kisisayisibelirleme);
     tutar(odaturubelirleme,kisisayisibelirleme,donembelirleme,mgunsayisi);
     }






	getch();

	}



							////ANA FONKSIYON




int main(){

	setlocale(LC_ALL,"Turkish");

	//Fonksiyonlarin return ettigi degerleri asagidaki degiskenlere atiyoruz

	int tercih;
    int donembelirleme;
    int odaturubelirleme;
    int kisisayisibelirleme;
    int mevsimbelirleme;
    int tercihkonrol=0; //Donguyu kontrol icin

     while(tercihkonrol<1){ //Kullanici istenilem sartlarda sayi girmedigi surece donguye girecek
       printf("\t|-----------------------------------------------------|\n");
       printf("\t|        |   |   |---|   -----   |---  |              |\n");
       printf("\t|        |---|   |   |     |     |---  |              |\n");
       printf("\t|        |   |   |---|     |     |___  |___           |\n");
       printf("\t|                                                     |\n");
       printf("\t|\t\t1-Rezervasyon yap\t\t      |\n");
       printf("\t|\t\t2-Rezervasyon takip\t\t      |\n");
       printf("\t|\t\t3-Rezervasyon iptal\t\t      |\n");
       printf("\t|\t\t4-Rezervasyon g�ncelle\t\t      |\n");
       printf("\t|\t\t5-��k��\t\t\t              |\n");
       printf("\t|-----------------------------------------------------|\n");


       scanf("%d",&tercih);



	   if(tercih==1){   //rezervasyon yapar


		   system("cls");  //tercih yapildiktan sonra terminali temizler
		   tercihkonrol++;
		   musteribilgisi();

		   mevsimbelirleme=gunvetarih();

		   donembelirleme=donem(mevsimbelirleme);

		   odaturubelirleme=odaturu();

		   kisisayisibelirleme=kackisilik();

		   odanumarasi(odaturubelirleme,kisisayisibelirleme);
		   tutar(odaturubelirleme,kisisayisibelirleme,donembelirleme,mgunsayisi);


                      }


		else if(tercih==2){   //rezervasyon takip fonksiyonuna gider

			system("cls");
			tercihkonrol++;
			rezervasyontakip();
			return -1;
			}



	else if(tercih==3){   //rezervasyon iptal fonksiyonuna gider

		    system("cls");
		    tercihkonrol++;
		    printf("Lutfen e-mailinizi giriniz:");
	        scanf("%s",eposta);
			rezervasyoniptal(eposta);
			}


    else if(tercih==4){   //rezervasyon guncelleme fonksiyonuna gider

	        system("cls");
	        tercihkonrol++;
	        rezervasyonguncelle();
	        }


	else if(tercih==5){   //Cikisa gider

		    system("cls");
		    tercihkonrol++;
		    printf("\n�yi G�nler Dileriz");

		    goto exit;
		    }


       else	{
		    system("cls");
		    printf("\nL�tfen 1-5 aras� bir say� giriniz!!!\n");
	        }


	}

  exit:

	getch();   //.exe den acildiginda birden konsolun kapanmamasi icin

	return 0;
 }









