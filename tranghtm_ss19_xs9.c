#include <stdio.h>
#include <string.h>

typedef  struct {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
}SinhVien;

void show( SinhVien menu[], int n);
void add( SinhVien menu[], int *n);
void update( SinhVien menu[], int n);
void del( SinhVien menu[], int *n);
void sort( SinhVien menu[], int n);
void search( SinhVien menu[], int n);

int main(){
	SinhVien menu[100] = {
        { 1, "han", 30, "0123456789" },	
        { 2, "lee", 40 , "0123456789" },	
        { 3, "kim", 35, "0123456789"  },
        { 4, "park", 60 , "0123456789" },
        { 5, "choi", 55 , "0123456789" },
    };
    
    int choice, n = 5;
    
    do {
    	printf("\n\n---------Menu-----------");
    	printf("\n1. Hien thi danh sach sv ");
    	printf("\n2. Them sv ");
    	printf("\n3. Sua sv ");
    	printf("\n4. Xoa sv ");
    	printf("\n5. Tim kiem  ");
    	printf("\n6. Sap xep ");
    	printf("\n7. Thoat ");
    	printf("\nLua chon cua ban:  ");
    	scanf("%d", &choice);
    	fflush(stdin);
    	
    	switch( choice){
    		case 1:{
    			show(menu, n);
				break;
			}
			case 2:{
				add(menu, &n);
				break;
			}
			case 3:{
				update(menu, n);
				break;
			}
			case 4:{
				del(menu, &n);
				break;
			}
			case 5:{
				search(menu, n);
				break;
			}
			case 6:{
				sort(menu, n); 
				break;
			}
			case 7:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long chon dung(1-7)!");
				break;
			}
		}
	}while( choice != 7 );

	return 0;
}

void show( SinhVien sv[], int n){
	printf("\nPhan tu trong mang: ");
	for ( int i = 0; i< n; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}	
}

void add( SinhVien sv[], int *n){
	int index;
	printf("\nVi tri them(1 - %d): ", *n+1);
	scanf("%d", &index);
	
	while ( index < 1 || index > (*n)+1 ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri them(1 - %d): ", (*n)+1);
		scanf("%d", &index);
	}
	fflush(stdin);
	
	// chuyen ptu
	for ( int i = *n; i>= index ; i--){
		sv[i].id = sv[i-1].id +1;
		strcpy( sv[i].name, sv[i-1].name);
		sv[i].age = sv[i-1].age;
		strcpy( sv[i].phoneNumber, sv[i-1].phoneNumber);
	}
	
	// nhap  va them
	sv[index-1].id = index ;
	printf("\nNhap ten sv: ");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int len = strlen(sv[index-1].name);
	sv[index-1].name[len-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("\nNhap sdt: ");
	fgets( sv[index-1].phoneNumber, sizeof( sv[index-1].phoneNumber), stdin);
	
	(*n)++;
	printf("\nKet qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}

void update( SinhVien sv[], int n){
	int index;
	printf("\nVi tri sua(1 - %d): ", n);
	scanf("%d", &index);
	
	while ( index < 1 || index > n ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri sua(1 - %d): ", n);
		scanf("%d", &index);
	}
	fflush(stdin);
	// nhap  va sua
	sv[index-1].id = index ;
	printf("\nNhap ten sv: ");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int len = strlen(sv[index-1].name);
	sv[index-1].name[len-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%f", &sv[index-1].age);
	fflush(stdin);
	
	printf("\nNhap sdt: ");
	fgets( sv[index-1].phoneNumber, sizeof( sv[index-1].phoneNumber), stdin);
	
	printf("\nKet qua: \n");
	for ( int i = 0; i< n; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}

void del( SinhVien sv[], int *n){
	int index;
	printf("\nVi tri xoa(1 - %d): ", *n);
	scanf("%d", &index);
	
	while ( index < 1 || index > *n ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri them(1 - %d): ", *n );
		scanf("%d", &index);
	}
	fflush(stdin);
	
	// chuyen ptu
	for ( int i = index-1 ; i < (*n)-1  ; i++){
		sv[i].id = sv[i+1].id ;
		strcpy( sv[i].name, sv[i+1].name);
		sv[i].age = sv[i+1].age;
		strcpy( sv[i].phoneNumber, sv[i+1].phoneNumber);
	}
	
	(*n)--;
	printf("\nKet qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}

void sort( SinhVien sv[], int n){
	for( int i = 0; i< n; i++){
		for ( int j = 0; j< n-1-i; j++){
			if ( strcmp(sv[j].name, sv[j+1].name ) > 0 ){
				SinhVien temp = sv[j];
                sv[j] = sv[j+1];
                sv[j+1] = temp;
			}
		}
	}
	printf("\nKet qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
}

void search( SinhVien sv[], int n){
	char input[50];
	int count = 0;
	
	printf("\nNhap ten can tim: ");
	fgets( input, 50, stdin);
	int len = strlen(input);
	input[len-1] = '\0';
	
	for ( int i = 0; i< n; i++){
		if ( strcmp(sv[i].name, input) == 0 ){
			count = 1;
			printf("\nSV can tim: ");
			printf("\n\nID: %d", sv[i].id);
			printf("\nTen: %s", sv[i].name);
			printf("\nTuoi: %d", sv[i].age);
			printf("\nSdt: %s ", sv[i].phoneNumber);
			break;
		}
	}

	if ( count == 0 ) printf("\n Khong tim thay sv!");
}

