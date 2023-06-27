#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 10 // Sýnýf mevcudunun maksimum boyutu

int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Turkish");
	char students[MAX_SIZE][50]; // Öðrenci adlarýný saklamak için dizi
	char studentSurname[MAX_SIZE][50];// Öðrenci soyadlarýný saklamak için dizi
	int vize1[MAX_SIZE]; // Öðrenci vize1 notlarýný saklamak için dizi
	int vize2[MAX_SIZE]; // Öðrenci vize2 notlarýný saklamak için dizi
	int final[MAX_SIZE]; // Öðrenci final notlarýný saklamak için dizi
	int num_students = 0; // Kaydedilen öðrenci sayýsý
	
	
	// harf notu hesaplama fonksiyonu
	char* get_grade(double average) {
	if (average >= 90) 
	{
		return "AA";
	} 
	else if (average >= 85) 
	{
		return "BA";
	} 
	else if (average >= 80)
	{
		return "BB";
	} 
	else if (average >= 75) 
	{
	return "CB";
	} 
	else if (average >= 70)
	{
	return "CC";
	} 
	else if (average >= 65) 
	{
	return "DC";
	} 
	else if (average >= 60) 
	{
	return "DD";
	} 
	else if (average >= 50) 
	{
	return "FD";
	} 
	else
	{
	return "FF";
	}	
}
	
	// ortalama yuvarlama fonksiyonu
	double round_average(double average) {
		return average - (int)average > 0.5 ? (int)average + 1 : (int)average;
	}
	
	// harf notuna göre kalýp geçtiðini hesaplayan fonksiyon
	void is_pass(char* grade){
	if(grade=="FF")
	{
	printf("\tKALDI\n");
	}
	else if(grade=="FD")
	{
	printf("\tÞARTLI GEÇTÝ\n");
	}
	else
	{
	printf("\tGEÇTÝ\n");
	}
}
	
	// ortalama hesaplama fonksiyonu
	double calc_avarage(int vize1[], int vize2[],int final[],int i){
		 double average =(vize1[i] * 0.2 + vize2[i] * 0.3 + final[i] * 0.5);
		 return average;
	}
	
	// en yüksek notu bulma
	double find_highest_average(int vize1[], int vize2[],int final[], int num_students){
		int average= calc_avarage(vize1, vize2, final, 0); // ortalama hesapla
		double highest_average =  round_average(average) ; // ortalama yuvarla
		int i;
		for(i=1; i<num_students; i++)
		{ 
			int average= calc_avarage(vize1, vize2, final, i); // ortalama hesapla
			double current_average = round_average(average) ; // ortalama yuvarla
			if(current_average > highest_average)
			{ 
				highest_average = current_average; 
			}
		}
	return highest_average;
	}
	
	//en düþük ortalamayý bulma
	double get_min_average(int vize1[], int vize2[],int final[], int num_students) {
		int average= calc_avarage(vize1, vize2, final, 0); // ortalama hesapla
		double min_average =  round_average(average) ; // ortalama yuvarla
		int i;
		for (i = 1; i < num_students; i++) { 
			int average= calc_avarage(vize1, vize2, final, i); // ortalama hesapla
			double current_average = round_average(average) ; // ortalama yuvarla
			if(current_average < min_average)
			{ 
				min_average = current_average; 
			}
		}
		return min_average; // en küçük ortalamayý döndür
}
	
	//Sýnýf ortalamasýný bulan fonksiyon
	double get_class_average(int vize1[], int vize2[],int final[], int num_students) {
		double total_average = 0.0;
		int i;
		for ( i = 0; i < num_students; i++) {
			total_average += calc_avarage(vize1, vize2, final, i);
			}
		return total_average / num_students;
		}

	//Ortalama üstü kiþi sayýsý ve Baþarý yüzdesini bulan fonksiyon
	//Ortalama hesaplanmasý ve karþýlaþtýrma için en az iki kiþi girilmesi gerekir
	void calc_success_rate(int vize1[], int vize2[], int final[], int num_students) {
	  int above_average_count = 0; // Ortalama üstü notu alan öðrenci sayýsýný saklamak için sayaç
	  int i;
	  for (i = 0; i < num_students; i++) {
	    // Öðrencinin ortalamasýný hesapla
	    double average = calc_avarage(vize1, vize2, final, i);
	    int averaged =round_average(average); // Ortalamayý yuvarlama
	   
	    // Öðrencinin ortalamasý ortalamanýn üstündeyse sayaç deðerini artýr
	    if (average > 60) {
	      above_average_count++;
	    }
	  }
	  
	  // Ortalama üstü notu alan öðrenci sayýsýný yüzde olarak baþarý oraný olarak hesapla
	  double success_rate = above_average_count / num_students * 100;
	  
	  printf("Ortalama üstü notu alan öðrenci sayýsý: %d  -  ", above_average_count);
	  printf("Baþarý oraný: %.2f%%\n", success_rate);
}
	
	//Standart sapma hesaplayan fonksiyon
	double calc_standard_deviation(int vize1[], int vize2[], int final[], int num_students) {
		double mean = 0;
		double sum = 0;
		
		// Ortalama hesaplama
		int i;
		for (i = 0; i < num_students; i++) {
	    // Öðrencinin ortalamasýný hesapla
		    double average = calc_avarage(vize1, vize2, final, i);
		    int averaged =round_average(average); // Ortalamayý yuvarlama
			mean += averaged;
		}
		mean /= num_students;
		
		// Standart sapma hesaplama
		int j;
		for (j = 0; j < num_students; j++) {
			double average = calc_avarage(vize1, vize2, final, j);
		    int averaged =round_average(average); // Ortalamayý yuvarlama
			sum += (averaged - mean) * (averaged - mean);
		}
		sum /= num_students;
		
		return sqrt(sum);
		}
	
	//menüyü ekrana yzan fonksiyon
	void write_menu(){
		printf("\n");
		printf("1. Kayýt ekle\n");
		printf("2. Kayýtlarý listele\n");
		printf("3. Sýnýf baþarý notlarýný hesapla\n");
		printf("4. Kayýtlarý baþarý notuna göre sýrala\n");
		printf("5. Ýstatistiki bilgiler\n");
		printf("6. Programdan çýk\n");
	}
	

	int choice; // seçilecek seçenek
	do {
		write_menu();// Menü ekranýný göster
		printf("\n");	
		printf("Bir seçenek seçin: ");
		scanf("%d", &choice);
	
		switch (choice) {
		    case 1: {
		    	printf("\n");
		    	// Öðrenci kaydý ekleme fonksiyonu
		        if (num_students < MAX_SIZE) 
				{
		        	printf("---Kayýt Ekle---\n");
		        	printf("Öðrenci adý: ");
		            scanf("%s", students[num_students]);
		            printf("Öðrenci Soyadý: ");
		            scanf("%s", studentSurname[num_students]);
		            printf("Vize1 notu: ");
		            scanf("%d", &vize1[num_students]);
		            printf("Vize2 notu: ");
		            scanf("%d", &vize2[num_students]);
		            printf("Final notu: ");
		            scanf("%d", &final[num_students]);
		            num_students++;
		        } 
				else 
				{
					printf("\n");
		            printf("Sýnýf mevcudu dolu!\n");
		            num_students++;
		        }
		        
		        break;
		    }
		    case 2: 
			{

			// Sýnýf baþarý notlarýný hesaplama 
			if (num_students == 0) 
			{
				// Kullanýcý baþka tuþa týklarsa diye bu kod eklendi
				printf("\n");
				printf("Kayýt bulunamadý. Öðrenci ekleme iþlemi yapýnýz.\n");
			} 
			else 
			{
				// Öðrenci kayýtlarýný listeleme
		        printf("\n");
		        printf("---Kayýtlarý listele---\n");
		        printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
		        int i;
		        for (i = 0; i < num_students; i++) 
				{
		        	double average = calc_avarage(vize1,vize2, final,i);// Öðrenci ortalamasý
					int averaged =round_average(average); // Ortalamayý yuvarlama
					char* grade =get_grade(average); // harf notu hesaplama
					
					// ekrana yazdýrma
		  	     
		            printf("%s\t%c.\t%d\t%d\t%d\t%d\t%s", students[i],studentSurname[i][0],vize1[i], vize2[i], final[i],averaged,grade);
					is_pass(grade);
		        }	
		    } 
		        
		    break;
		    }
		    
		   case 3: 
		   {
			// Sýnýf baþarý notlarýný hesaplama 
			if (num_students == 0) 
			{
				// Kullanýcý baþka tuþa týklarsa diye bu kod eklendi
				printf("\n");
				printf("Kayýt bulunamadý. Öðrenci ekleme iþlemi yapýnýz.\n");
			} 
			else 
			{
				printf("\n");
				printf("---Sýnýf baþarý notlarýný hesapla---\n");
				printf("Ad\tSoyad\tNotu\n");
				int i;
				for (i = 0; i < num_students; i++) 
				{
					double average = calc_avarage(vize1,vize2, final,i); // Öðrenci ortalamasý
					int averages = round_average(average) ;// Ortalamayý yuvarlama
				
				    printf("%s\t%c.\t%d\n", students[i],studentSurname[i][0],averages);
				}
		   } 
		break;
		}
		
			case 4: {
				// Öðrenci kayýtlarýný baþarý notlarýna göre sýralama
				if (num_students == 0)
				{
					printf("\n");
					printf("Kayýt bulunamadý. Öðrenci ekleme iþlemi yapýnýz.\n");
				} 
				else 
				{
					// Öðrenci kayýtlarýný baþarý notlarýna göre sýralama
					printf("\n");
					printf("---Kayýtlarý baþarý notuna göre Sýrala---\n");
					int i ,j;
					for ( i = 0; i < num_students; i++) {
						for ( j = i + 1; j < num_students; j++) {
							// Öðrenci ortalamasýný hesaplama
							double average1 = calc_avarage(vize1,vize2,final,i);
							double average2 = calc_avarage(vize1,vize2,final,j);
							
							// Ortalamayý yuvarlama
							average1 = round_average(average1);
							average2 = round_average(average2);
					
					            // Öðrenci kaydýný baþarý notlarýna göre sýralama
					            if (average1 < average2) {
					                char temp_name[50];
					                strcpy(temp_name, students[i]);
					                strcpy(students[i], students[j]);
					                strcpy(students[j], temp_name);
					                char temp_surname[50];
					                strcpy(temp_surname, studentSurname[i]);
					                strcpy(students[i], studentSurname[j]);
					                strcpy(students[j], temp_surname);
					                int temp_vize1 = vize1[i];
					                vize1[i] = vize1[j];
					                vize1[j] = temp_vize1;
					                int temp_vize2 = vize2[i];
					                vize2[i] = vize2[j];
					                vize2[j] = temp_vize2;
					                int temp_final = final[i];
					                final[i] = final[j];
					                final[j] = temp_final;
				        }
			        }
			    }
			    // Sýralanmýþ öðrenci kayýtlarýný listeleme
				printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
			    for (i = 0; i < num_students; i++) {
			        // ekrana yazdýrma
			        double average = calc_avarage(vize1,vize2, final,i); // Öðrenci ortalamasý
					int averages = round_average(average) ;// Ortalamayý yuvarlama
					char* grade =get_grade(averages); // harf notu hesaplama
		            printf("%s\t%c.\t%d\t%d\t%d\t%d\t%s", students[i],studentSurname[i][0],vize1[i], vize2[i], final[i],averages,grade);
					is_pass(grade);
			    }
			}
		break;
		}
		case 5: 
		{
			// Ýstatistiki bilgiler
			if (num_students == 0) 
			{
				printf("Kayýt bulunamadý. Öðrenci ekleme iþlemi yapýnýz.\n");
			}
			 else
			  	{
			
				    // Öðrenci ortalamasýna göre en büyük ortalamayý bulma
				    int highest_average=find_highest_average(vize1, vize2,final, num_students);
				    printf("En yüksek not : %d\n",highest_average);
				    
				    // öðrenci ortalamasýna göre en küçük ortalamayý bulma
				    int min_average=get_min_average(vize1, vize2,final, num_students);
				    printf("En düþük not : %d\n",min_average);
				    
				    //Sýnýf ortalamasýný bulma
				    int class_average=get_class_average(vize1, vize2,final, num_students);
				    printf("Sýnýf ortalamasý : %d\n",class_average);
				    
					//Baþarý oraný ve baþarýlý kiþi sayýsý
					calc_success_rate(vize1, vize2,final, num_students);
					
					//Standart sapma
					double standart_dev=calc_standard_deviation(vize1, vize2,final, num_students);
					printf("Standart Sapma : %.2f\n",standart_dev);
				}
			break;
			}
		

		case 6:{
				// Programdan çýkma
				printf("Programdan çýkýlýyor...\n");
				break;
			}
				
		default: {
				printf("Geçersiz seçenek. Lütfen tekrar deneyin.\n");
				break;
			}
		}
	}while (choice != 6);

return 0;
}
