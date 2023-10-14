#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct sinhvien{
	char hoten[30];
	char gt[5];
	int age;
	float dT, dL, dH;
	float dtb;
};

typedef struct sinhvien SV;

void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);


int main()
{
	int key;
	char fileName[] = "DSSV.txt";
	int n;
	bool daNhap = false;
	
	do{
		printf("\nNhap vao so luong sinh vien: "); scanf("%d", &n);
	}while(n <= 0);
	
	SV a[n];
	
	while(true){
		system("cls");
		printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Sap xep sinh vien theo DTB   **\n");
        printf("**      4. Xep loai sinh vien           **\n");
        printf("**      5. Xuat DS sinh vien            **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");
        
        scanf("%d", &key);
        switch(key){
        	case 1: 
        		printf("\nBan da chon nhap danh sach sinh vien");
        		nhapN(a, n);
        		daNhap = true;
        		printf("\nBam phim bat ki de ket thuc!!!");
        		break;
        	case 2: 
        		if(daNhap){
        			printf("\nBan chon in ra danh sach sinh vien!");
        			xuatN(a, n);
        		}else{
        			printf("\nNhap danh sach sinh vien truoc!");
        		}
        		printf("\nBam phim bat ki de tiep tuc!!!");
        		getch();
        		break;
        	case 3: 
        		if(daNhap){
        			printf("\nBan chon sap xep sinh vien!");
        			sapxep(a, n);
        		}else{
        			printf("\nNhap danh sach sinh vien truoc!");
        		}
        		printf("\nBam phim bat ki de tiep tuc!!!");
        		getch();
        		
        		break;
        	case 4: 
        		if(daNhap){
        			printf("\nBan chon xep laoi sinh vien!");
        			xeploaiN(a, n);
        		}else{
        			printf("\nNhap danh sach sinh vien truoc!");
        		}
        		printf("\nBam phim bat ki de tiep tuc!!!");
        		getch();
        		break;
        	case 5: 
        		if(daNhap){
        			printf("\nBan chon xuat file sinh vien!");
        			xuatFile(a, n, fileName);
        		}else{
        			printf("\nNhap danh sach sinh vien truoc!");
        		}
        		printf("\nBam phim bat ki de ket thuc!!!");
        		getch();
        		break;
        	case 0:
        		printf("\nBan chon thoat chuong trinh!");
        		getch();
        		return 0;
        	default:
        		printf("\nLua chon khong hop le!!!");
        		break;
        }

	}

}

void tinhDTB(SV &sv){
	sv.dtb = (sv.dT + sv.dL + sv.dT) / 3;
}

void nhap(SV &sv){
	printf("\nNhap ten sinh vien: "); fflush(stdin); gets(sv.hoten);
	printf("\nNhap gioi tinh sinh vien: "); fflush(stdin); gets(sv.gt);
	printf("\nNhap tuoi sinh vien: "); scanf("%d", &sv.age);
	printf("\nNhap diem 3 mon toan, ly, hoa: "); scanf("%f%f%f", &sv.dT, &sv.dL, &sv.dH);
	tinhDTB(sv);
}

void nhapN(SV a[], int n){
	 printf("\n____________________________________\n");
	for(int i = 0; i < n; i++){
		printf("\nNhap sinh vien thu %d: ", i + 1); nhap(a[i]);
	}
	 printf("\n____________________________________\n");
}

void xuat(SV sv){
	printf("\nHo ten sinh vien: %s", sv.hoten);
	printf("\nTuoi sinh vien: %d", sv.age);
	printf("\nGioi tinh cua sinh vien: %s", sv.gt);
	printf("\nDiem 3 mon cua sinh vien: %.2f - %.2f - %.2f", sv.dT, sv.dL, sv.dH);
	 printf("\nDiem trung binh sinh vien: %.2f", sv.dtb);
}

void xuatN(SV a[], int n){
	printf("\n____________________________________\n");
	for(int i = 0; i < n; i++){
		printf("\nSinh vien thu %d", i + 1); xuat(a[i]);
	}
	printf("\n____________________________________\n");

}

void  sapxep(SV a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j].dtb < a[i].dtb){
				SV temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
}

void xeploai(SV sv){
	if(sv.dtb >= 8.0) printf("\nGioi");
	else if(sv.dtb >= 6.5) printf("\nKha");
	else if(sv.dtb >= 4.0) printf("\nTrung Binh");
	else printf("\nYeu");
}

void xeploaiN(SV a[], int n){
	printf("\n____________________________________\n");
	for(int i = 0; i < n; i++){
		xeploai(a[i]);
	}
	printf("\n____________________________________\n");
}

void xuatFile(SV a[], int n, char fileName[]){
	FILE *fptr;
	fptr = fopen(fileName, "w");
	fprintf(fptr, "%20s%5s%5s%10s%10s%10s%10s\n", "Ho Ten","GT", "Tuoi", "DT", "DL", "DH", "DTB");	
	for(int i = 0; i < n; i ++){
		 fprintf(fptr, "%20s%5s%5d%10f%10f%10f%10f\n", a[i].hoten,a[i].gt, a[i].age, a[i].dT, a[i].dL, a[i].dH, a[i].dtb);
	}
	fclose(fptr);
}

