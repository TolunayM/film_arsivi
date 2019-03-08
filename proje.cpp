#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct film {                                                 //menu_s = menuden seçenek için.
	char *name;
	char *director;
	char *star;
	char *s_writer;
	char *r_date;
	
}bilgi;
int filmEkleme(); // burasý fonksiyonlarýn olduðu kýsým
int filmListele();
int filmArama();
int filmGuncelle();
int filmSil(); // buraya kadar tanýmladýðýmýz fonksiyonlar var int olarak tanýmlama sebebimiz devc void yaptýðýmýzda sýkýntý çýkartmýþtý.
int main(){
	system("cls"); // her seçim ve iþlem sonucunda ekraný temizlemek için.
	int menu_s; 
	printf("Ozel Film Arsivinize Hos Geldiniz.\n Lutfen Menuden Bir Secim Yapin \n");
	printf(" 1-->Film Ekle\n 2-->Filmleri Listele\n 3-->Filmleri Guncelle\n 4-->Film Sil\n 5-->Film Ara\n Cikmak icin 0\'a basin \n");
	scanf("%d",&menu_s);
	
	if (menu_s == 0){ //menumuzu dýþarda tanýmladýk ve if yardýmý ile yapýcaðýmýz iþleme önceden tanýmlayýp kodlarýný yazdýðýmýz fonksiyonlarý return ile ulaþtýk.
		char secim_cikis;
		printf("Cikis yapmayi sectiniz. Hoscakalin..");
		return 0;
		
		
	}
	if (menu_s == 1){
	return filmEkleme();
	}
	if (menu_s == 2){
		return filmListele();
	}	
	if (menu_s == 3){
		return filmGuncelle();
	}
	if (menu_s == 4){
		return filmSil();
	}
	if (menu_s == 5){
		return filmArama();
	}
}


	

int filmEkleme(){
	
		FILE *filep; //filmin pointerý
		bilgi.name=(char*)malloc(sizeof(char)*50); //malloc ile hafýzada yer ayýrýyoruz
	bilgi.director=(char*)malloc(sizeof(char)*50);
	bilgi.r_date=(char*)malloc(sizeof(char)*50);
	bilgi.star=(char*)malloc(sizeof(char)*50);
	bilgi.s_writer=(char*)malloc(sizeof(char)*50);
	
filep = fopen("yok_boyle_bir_arsiv.txt","a+");
		printf("Birden fazla kelime iceren filmleri lutfen birlesik yazin \n");
		printf(NULL); // boþluk býrakmak için NULL deðer yazdýrdýk
		printf("Filmin Adi->");
		scanf("%s",bilgi.name);
		printf("Filmin Yonetmeni->");
		scanf("%s",bilgi.director);
		printf("Filmin Basrolu->");
		scanf("%s",bilgi.star);
		printf("Filmin Yazari->");
		scanf("%s",bilgi.s_writer);
		printf("Filmin Yayinlanma Tarihi->");
		scanf("%s",bilgi.r_date);
	fprintf(filep,"\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.star,bilgi.s_writer,bilgi.r_date);
	fclose(filep);
	printf("Filmler basari ile kaydedildi. :D\n");
		printf("Menuden secim yapmak icin bir tusa basiniz...");
		getch();
	
	return main();
}
int filmListele(){
	FILE *filep;
	bilgi.name=(char*)malloc(sizeof(char)*50);
	bilgi.director=(char*)malloc(sizeof(char)*50);
	bilgi.r_date=(char*)malloc(sizeof(char)*50);
	bilgi.star=(char*)malloc(sizeof(char)*50);
	bilgi.s_writer=(char*)malloc(sizeof(char)*50);
	filep = fopen("yok_boyle_bir_arsiv.txt","r");
	while(!feof(filep)){
		
		fscanf(filep,"%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.star,bilgi.s_writer,bilgi.r_date);
		printf("***Film Bilgileri***\n Filmin Adi->%s\n Filmin Yonetmeni->%s\n Filmin Basrolu->%s\n Filmin Yazari->%s\n Filmin Yayinlanma Tarihi->%s\n",bilgi.name,bilgi.director,bilgi.star,bilgi.s_writer,bilgi.r_date);
	}		
fclose(filep);
printf("\nMenuden secim yapmak icin bir tusa basiniz...");
getch();
return main();
}

int filmGuncelle(){
	FILE *filep , *filen;
	filep=fopen("yok_boyle_bir_arsiv.txt","a+");
	filen=fopen("algonew.txt","a+");
	char ad[50];
	bilgi.name=(char*)malloc(sizeof(char)*50); 
	bilgi.director=(char*)malloc(sizeof(char)*50);
	bilgi.r_date=(char*)malloc(sizeof(char)*50);
	bilgi.star=(char*)malloc(sizeof(char)*50);
	bilgi.s_writer=(char*)malloc(sizeof(char)*50);
	printf("Guncellemek istediginiz filmin adini giriniz -> \n");
	scanf("%s",&ad);
	while(fscanf(filep,"%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer)!=EOF){
		if(strcmp(bilgi.name,ad)==0){
	printf("Birden fazla kelime iceren filmleri lutfen birlesik yazin \n");
	printf(NULL); //boþluk býrakmak için 
	printf("Filmin Yeni Adi->");
	scanf("%s",bilgi.name);
	printf("Filmin Yeni Yonetmeni->");
	scanf("%s",bilgi.director);
	printf("Filmin Yeni Basrolu->");
	scanf("%s",bilgi.star);
	printf("Filmin Yeni Yazari->");
	scanf("%s",bilgi.s_writer);
	printf("Filmin Yeni Yayinlanma Tarihi->");
	scanf("%s",bilgi.r_date);
	fprintf(filen,"\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.star,bilgi.s_writer,bilgi.r_date);
	printf("Film basariyla guncellendi. :D\n");
			
		
	} else{
		fprintf(filen,"\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer); //dosyaya  yazdýrýyoruz
		
	}
	}
	
	
	fclose(filep); //dosyayý kapýyoruz
	fclose(filen);
	remove("yok_boyle_bir_arsiv.txt");
	rename("algonew.txt","yok_boyle_bir_arsiv.txt");
	printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   	getch();			
	return main();	
	
}	
int filmArama(){
		FILE *filep; 
		int tercih;
		int durum = 0;
	bilgi.name=(char*)malloc(sizeof(char)*50); 
	bilgi.director=(char*)malloc(sizeof(char)*50);
	bilgi.r_date=(char*)malloc(sizeof(char)*50);
	bilgi.star=(char*)malloc(sizeof(char)*50);
	bilgi.s_writer=(char*)malloc(sizeof(char)*50);
		printf("Film arama secenegini sectiniz.\nFilm adina gore aramak icin -> 1\nFilmin yonetmenine gore aramak icin -> 2\nFilmin vizyon tarihine gore aramak icin -> 3\nFilmin basrolune gore aramak icin -> 4\nFilmin senaristine gore aramak icin -> 5\n");
		scanf("%d",&tercih);
		fflush(stdin);
			if(tercih==1){
			
			printf("Bulmak istediginiz filmin ismini giriniz->");
				char ismegore[50];			
				gets(ismegore); //scanf yerine kullanýlan kod
				FILE *filep = fopen("yok_boyle_bir_arsiv.txt","r");
			while(!feof(filep))
{
			
		fscanf(filep,"\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
			if(strcmp(bilgi.name,ismegore)==0){
		printf("\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
		durum = 1;
}
}		if(durum == 0){ // Aranan deðer dosyada yok ise
   				puts("Kayit bulunamadi..");
   			}	fclose(filep);
   				printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   				getch();
   				return main();


}	
			if(tercih == 2){ //hangi alanda arama yapmak istediðimizi seçmek için if ile tercihleri belirttik
			printf("Bulmak istediginiz filmin yonetmen adini giriniz ->");
			char yonetgore[50];
			gets(yonetgore);
			filep=fopen("yok_boyle_bir_arsiv.txt","r");
			while(!feof(filep)){
				
				fscanf(filep,"\n%s %s %s %s %s", bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				if(strcmp(bilgi.director,yonetgore) == 0){
				printf("\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				durum = 1;
}
}
				if(durum == 0){ // Aranan deðer dosyada yok ise
  				puts("Kayit bulunamadi..");
}				fclose(filep);
  				printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   				getch();
   				return main();
  				

}
			
			if(tercih== 3){
			printf("Bulmak istediginiz filmin vizyon tarihini giriniz ->");
			char viztar[50];
			gets(viztar);
			filep=fopen("yok_boyle_bir_arsiv.txt","r");
			while(!feof(filep)){
					
				fscanf(filep,"\n%s %s %s %s %s", bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				if(strcmp(bilgi.r_date,viztar)== 0){
				printf("\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				durum = 1;
}
}
				if(durum == 0){
				puts("Kayit bulunamadi..");
}				fclose(filep);
				printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   				getch(); // seçim menüye dönmek için kullanýcan tuþ beklenmesini saðlayan kod
   				
   				return main();
}


			if(tercih == 4){
			printf("Bulmak istediginiz filmin basrol oyuncusunu giriniz->");
			char leadgor[50];
			gets(leadgor);
			filep=fopen("algorhythm.txt","r");
			while(!feof(filep)){
				fscanf(filep, "\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				if(strcmp(bilgi.star,leadgor)== 0){
				printf("\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				durum = 1;	
}
}
				if(durum == 0){
				puts("Kayit bulunamadi.."); //printf yerine kullandýðýmýz kod
} 			
				fclose(filep);
				printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   				getch();
   				return main();		
}
			if(tercih==5){
			printf("Bulmak istediginiz filmin senaristini giriniz ->");
			char senargor[50];
			gets(senargor);
			filep=fopen("algorhythm.txt","r");
			while(!feof(filep)){
				fscanf(filep, "\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				if(strcmp(bilgi.s_writer,senargor)== 0){
				printf("\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
				durum = 1;
}
}
			if(durum== 0){
			puts("Kayit bulunamadi..");
		}	fclose(filep);
			printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   			getch(); // seçim menüye dönmek için kullanýcan tuþ beklenmesini saðlayan kod
   		
   			return main();
}
}


int filmSil(){
	FILE *filep , *filen;
	char ad[50];
	int secim;
	bilgi.name=(char*)malloc(sizeof(char)*50); //mallocla almazsak baþka türlü yapamýyoruz.
	bilgi.director=(char*)malloc(sizeof(char)*50); //director için alan ayýrýyoruz 
	bilgi.r_date=(char*)malloc(sizeof(char)*50); //release date için yer ayýrýyoruz
	bilgi.star=(char*)malloc(sizeof(char)*50);// ayný þekil
	bilgi.s_writer=(char*)malloc(sizeof(char)*50);
	printf("Silmek istediginiz filmin adini giriniz -> \n");
	scanf("%s",&ad);
	filep=fopen("yok_boyle_bir_arsiv.txt","r");
	filen=fopen("algonew.txt","a+");
	rewind(filep); 
	rewind(filen);
	printf("Devam etmek istiyor musunuz ?\n EVET icin 1\'i Hayir icin 2\'yi tuslayin...\n");
	scanf("%d",&secim);
	if(secim==1){
	
	while(fscanf(filep,"%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer)!=EOF){
		if(strcmp(bilgi.name,ad)==0){
			
		
	} else{
		fprintf(filen,"\n%s %s %s %s %s",bilgi.name,bilgi.director,bilgi.r_date,bilgi.star,bilgi.s_writer);
		
	}
	}
	fclose(filep);
	fclose(filen);
	remove("yok_boyle_bir_arsiv.txt");
	rename("algonew.txt","yok_boyle_bir_arsiv.txt");
	printf("Silme islemi basariyla gerceklestirildi.");
	printf("\nMenuden secim yapmak icin bir tusa basiniz...");
   	getch();		 // seçim menüye dönmek için kullanýcan tuþ beklenmesini saðlayan kod	
	return main();	
}
if(secim==2){
	printf("Silmekten vazgectiniz menuye donmek icin bir tusa basin...");
	getch(); // seçim menüye dönmek için kullanýcan tuþ beklenmesini saðlayan kod
	return main();
}

}

  
     
    






