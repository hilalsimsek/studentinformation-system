#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 10 // S�n�f mevcudunun maksimum boyutu

int main(int argc, char *argv[]){
	
	setlocale(LC_ALL, "Turkish");
	char students[MAX_SIZE][50]; // ��renci adlar�n� saklamak i�in dizi
	char studentSurname[MAX_SIZE][50];// ��renci soyadlar�n� saklamak i�in dizi
	int vize1[MAX_SIZE]; // ��renci vize1 notlar�n� saklamak i�in dizi
	int vize2[MAX_SIZE]; // ��renci vize2 notlar�n� saklamak i�in dizi
	int final[MAX_SIZE]; // ��renci final notlar�n� saklamak i�in dizi
	int num_students = 0; // Kaydedilen ��renci say�s�
	
	
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
	
	// harf notuna g�re kal�p ge�ti�ini hesaplayan fonksiyon
	void is_pass(char* grade){
	if(grade=="FF")
	{
	printf("\tKALDI\n");
	}
	else if(grade=="FD")
	{
	printf("\t�ARTLI GE�T�\n");
	}
	else
	{
	printf("\tGE�T�\n");
	}
}
	
	// ortalama hesaplama fonksiyonu
	double calc_avarage(int vize1[], int vize2[],int final[],int i){
		 double average =(vize1[i] * 0.2 + vize2[i] * 0.3 + final[i] * 0.5);
		 return average;
	}
	
	// en y�ksek notu bulma
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
	
	//en d���k ortalamay� bulma
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
		return min_average; // en k���k ortalamay� d�nd�r
}
	
	//S�n�f ortalamas�n� bulan fonksiyon
	double get_class_average(int vize1[], int vize2[],int final[], int num_students) {
		double total_average = 0.0;
		int i;
		for ( i = 0; i < num_students; i++) {
			total_average += calc_avarage(vize1, vize2, final, i);
			}
		return total_average / num_students;
		}

	//Ortalama �st� ki�i say�s� ve Ba�ar� y�zdesini bulan fonksiyon
	//Ortalama hesaplanmas� ve kar��la�t�rma i�in en az iki ki�i girilmesi gerekir
	void calc_success_rate(int vize1[], int vize2[], int final[], int num_students) {
	  int above_average_count = 0; // Ortalama �st� notu alan ��renci say�s�n� saklamak i�in saya�
	  int i;
	  for (i = 0; i < num_students; i++) {
	    // ��rencinin ortalamas�n� hesapla
	    double average = calc_avarage(vize1, vize2, final, i);
	    int averaged =round_average(average); // Ortalamay� yuvarlama
	   
	    // ��rencinin ortalamas� ortalaman�n �st�ndeyse saya� de�erini art�r
	    if (average > 60) {
	      above_average_count++;
	    }
	  }
	  
	  // Ortalama �st� notu alan ��renci say�s�n� y�zde olarak ba�ar� oran� olarak hesapla
	  double success_rate = above_average_count / num_students * 100;
	  
	  printf("Ortalama �st� notu alan ��renci say�s�: %d  -  ", above_average_count);
	  printf("Ba�ar� oran�: %.2f%%\n", success_rate);
}
	
	//Standart sapma hesaplayan fonksiyon
	double calc_standard_deviation(int vize1[], int vize2[], int final[], int num_students) {
		double mean = 0;
		double sum = 0;
		
		// Ortalama hesaplama
		int i;
		for (i = 0; i < num_students; i++) {
	    // ��rencinin ortalamas�n� hesapla
		    double average = calc_avarage(vize1, vize2, final, i);
		    int averaged =round_average(average); // Ortalamay� yuvarlama
			mean += averaged;
		}
		mean /= num_students;
		
		// Standart sapma hesaplama
		int j;
		for (j = 0; j < num_students; j++) {
			double average = calc_avarage(vize1, vize2, final, j);
		    int averaged =round_average(average); // Ortalamay� yuvarlama
			sum += (averaged - mean) * (averaged - mean);
		}
		sum /= num_students;
		
		return sqrt(sum);
		}
	
	//men�y� ekrana yzan fonksiyon
	void write_menu(){
		printf("\n");
		printf("1. Kay�t ekle\n");
		printf("2. Kay�tlar� listele\n");
		printf("3. S�n�f ba�ar� notlar�n� hesapla\n");
		printf("4. Kay�tlar� ba�ar� notuna g�re s�rala\n");
		printf("5. �statistiki bilgiler\n");
		printf("6. Programdan ��k\n");
	}
	

	int choice; // se�ilecek se�enek
	do {
		write_menu();// Men� ekran�n� g�ster
		printf("\n");	
		printf("Bir se�enek se�in: ");
		scanf("%d", &choice);
	
		switch (choice) {
		    case 1: {
		    	printf("\n");
		    	// ��renci kayd� ekleme fonksiyonu
		        if (num_students < MAX_SIZE) 
				{
		        	printf("---Kay�t Ekle---\n");
		        	printf("��renci ad�: ");
		            scanf("%s", students[num_students]);
		            printf("��renci Soyad�: ");
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
		            printf("S�n�f mevcudu dolu!\n");
		            num_students++;
		        }
		        
		        break;
		    }
		    case 2: 
			{

			// S�n�f ba�ar� notlar�n� hesaplama 
			if (num_students == 0) 
			{
				// Kullan�c� ba�ka tu�a t�klarsa diye bu kod eklendi
				printf("\n");
				printf("Kay�t bulunamad�. ��renci ekleme i�lemi yap�n�z.\n");
			} 
			else 
			{
				// ��renci kay�tlar�n� listeleme
		        printf("\n");
		        printf("---Kay�tlar� listele---\n");
		        printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
		        int i;
		        for (i = 0; i < num_students; i++) 
				{
		        	double average = calc_avarage(vize1,vize2, final,i);// ��renci ortalamas�
					int averaged =round_average(average); // Ortalamay� yuvarlama
					char* grade =get_grade(average); // harf notu hesaplama
					
					// ekrana yazd�rma
		  	     
		            printf("%s\t%c.\t%d\t%d\t%d\t%d\t%s", students[i],studentSurname[i][0],vize1[i], vize2[i], final[i],averaged,grade);
					is_pass(grade);
		        }	
		    } 
		        
		    break;
		    }
		    
		   case 3: 
		   {
			// S�n�f ba�ar� notlar�n� hesaplama 
			if (num_students == 0) 
			{
				// Kullan�c� ba�ka tu�a t�klarsa diye bu kod eklendi
				printf("\n");
				printf("Kay�t bulunamad�. ��renci ekleme i�lemi yap�n�z.\n");
			} 
			else 
			{
				printf("\n");
				printf("---S�n�f ba�ar� notlar�n� hesapla---\n");
				printf("Ad\tSoyad\tNotu\n");
				int i;
				for (i = 0; i < num_students; i++) 
				{
					double average = calc_avarage(vize1,vize2, final,i); // ��renci ortalamas�
					int averages = round_average(average) ;// Ortalamay� yuvarlama
				
				    printf("%s\t%c.\t%d\n", students[i],studentSurname[i][0],averages);
				}
		   } 
		break;
		}
		
			case 4: {
				// ��renci kay�tlar�n� ba�ar� notlar�na g�re s�ralama
				if (num_students == 0)
				{
					printf("\n");
					printf("Kay�t bulunamad�. ��renci ekleme i�lemi yap�n�z.\n");
				} 
				else 
				{
					// ��renci kay�tlar�n� ba�ar� notlar�na g�re s�ralama
					printf("\n");
					printf("---Kay�tlar� ba�ar� notuna g�re S�rala---\n");
					int i ,j;
					for ( i = 0; i < num_students; i++) {
						for ( j = i + 1; j < num_students; j++) {
							// ��renci ortalamas�n� hesaplama
							double average1 = calc_avarage(vize1,vize2,final,i);
							double average2 = calc_avarage(vize1,vize2,final,j);
							
							// Ortalamay� yuvarlama
							average1 = round_average(average1);
							average2 = round_average(average2);
					
					            // ��renci kayd�n� ba�ar� notlar�na g�re s�ralama
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
			    // S�ralanm�� ��renci kay�tlar�n� listeleme
				printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
			    for (i = 0; i < num_students; i++) {
			        // ekrana yazd�rma
			        double average = calc_avarage(vize1,vize2, final,i); // ��renci ortalamas�
					int averages = round_average(average) ;// Ortalamay� yuvarlama
					char* grade =get_grade(averages); // harf notu hesaplama
		            printf("%s\t%c.\t%d\t%d\t%d\t%d\t%s", students[i],studentSurname[i][0],vize1[i], vize2[i], final[i],averages,grade);
					is_pass(grade);
			    }
			}
		break;
		}
		case 5: 
		{
			// �statistiki bilgiler
			if (num_students == 0) 
			{
				printf("Kay�t bulunamad�. ��renci ekleme i�lemi yap�n�z.\n");
			}
			 else
			  	{
			
				    // ��renci ortalamas�na g�re en b�y�k ortalamay� bulma
				    int highest_average=find_highest_average(vize1, vize2,final, num_students);
				    printf("En y�ksek not : %d\n",highest_average);
				    
				    // ��renci ortalamas�na g�re en k���k ortalamay� bulma
				    int min_average=get_min_average(vize1, vize2,final, num_students);
				    printf("En d���k not : %d\n",min_average);
				    
				    //S�n�f ortalamas�n� bulma
				    int class_average=get_class_average(vize1, vize2,final, num_students);
				    printf("S�n�f ortalamas� : %d\n",class_average);
				    
					//Ba�ar� oran� ve ba�ar�l� ki�i say�s�
					calc_success_rate(vize1, vize2,final, num_students);
					
					//Standart sapma
					double standart_dev=calc_standard_deviation(vize1, vize2,final, num_students);
					printf("Standart Sapma : %.2f\n",standart_dev);
				}
			break;
			}
		

		case 6:{
				// Programdan ��kma
				printf("Programdan ��k�l�yor...\n");
				break;
			}
				
		default: {
				printf("Ge�ersiz se�enek. L�tfen tekrar deneyin.\n");
				break;
			}
		}
	}while (choice != 6);

return 0;
}
