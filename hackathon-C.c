#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int amount;
	int arr[100]={0};
	long long max, min;
	int choose;
	int sum;
	int newpos, newvalue;
	int deleted;
	int check;
	int find;
	int position;
	int cnt;
	int i,j;
	do{
		
		printf("\nnhap lua chon cua ban:");
		
		printf("\n1:nhap so phan tu va gia tri cho mang");
		
		printf("\n2:in cac gia tri phan tu trong mang");
		
		printf("\n3:tim so lon nhat, nho nhat");
		
		printf("\n4:in ra tong tat ca cac phan tu");
		
		printf("\n5:them phan tu vao cuoi mang, phan tu moi cho nguoi dung nhap vao");
		
		printf("\n6:xoa phan tu tai mot vi tri cu the");
		
		printf("\n7:sap xep mang theo thu tu giam dan");
		
		printf("\n8:lay du lieu tu nguoi dung kiem tra phan tu co trong mang hay khong");
		
		printf("\n9:in ra toan bo so nguyen to");
		
		printf("\n10:sap xep mang theo thu tu tang dan");
		
		printf("\n11:thoat");
		
		printf("\n");
		
		scanf("%d", &choose);
		
		switch(choose){
			
			case 1:
				printf("nhap vao so phan tu co trong mang:");
				scanf("%d", &amount);
				printf("nhap cac phan tu trong mang(%d phan tu): \n", amount);
				for( i = 0; i < amount; i++){
					scanf("%d", &arr[i]);
				}
			break;
			
			case 2:
				for( i = 0; i < amount; i++){
					printf("\narr[%d]=%d ",i , arr[i]);
				}
			break;
			
			case 3:
				max=-pow(10,9);
				min=pow(10,9);
				for( i=0;i<amount; i++){
					if(arr[i]>max){
						max=arr[i];
					}
					if(arr[i]<min){
						min=arr[i];	
					}	
				}
				printf("gia tri lon nhat = %d", max);
				printf("\n");
				printf("gia tri nho nhat = %d", min);
			break;
			
			case 4:
				for( i=0;i<amount;i++){
					sum+=arr[i];
				}
				printf("tong cac phan tu = %d", sum);
			break;
			
			case 5:
				printf("chon vi tri ban muon them vao:");
				scanf("%d", &newpos);
				printf("nhap gia tri ban muon them vao:");
				scanf("%d", &newvalue);
				if(newpos>amount){
				arr[newpos-1]=newvalue;
				printf("mang moi sau khi chen so %d vao la: \n", newvalue);
				for( i=0;i<newpos;i++){
					printf("%d ", arr[i]);
					}	
				}else{
				for(i=amount;i>=newpos;i--){
					arr[i]=arr[i-1];
				}
				arr[newpos-1]=newvalue;
				printf("mang moi sau khi chen so %d vao la: \n", newvalue);
				for(i=0;i<amount+1;i++){
					printf("%d ", arr[i]);
				}
			}
			break;
			
			case 6:
				printf("chon vi tri ban muon xoa:");
				scanf("%d", &deleted);
				--deleted;
				if(deleted>amount){
					printf("vi tri khong hop le !");
				}else{
				for(i=deleted;i<amount;i++){
					arr[i]=arr[i+1];
				}
				printf("mang sau khi xoa di phan tu tai vi tri thu %d \n", deleted+1);
				for( i=0;i<amount-1;i++){
					printf("%d ", arr[i]);
				}
			}
			break;
			
			case 7:
				printf("mang sau khi truoc sap xep la: \n");
				for( i=0;i<amount; i++){
					printf("%d ", arr[i]);
				}
				for( i=0;i<amount;i++){
					for(int j=0;j<amount-1-i;j++){
						if(arr[j]<arr[j+1]){
							int temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				printf("\nmang sau khi da sap xep la: \n");
				for( i=0;i<amount; i++){
					printf("%d ", arr[i]);
				}
			break;
			
			case 8:
				for( i=0;i< amount;i++){
					printf("%d ", arr[i]);
				}
				printf("moi ban nhap vao mot so bat ky:");
				scanf("%d", &check);
				for(i=0;i<amount;i++){
					if(arr[i]==check){
						find++;
						position=i;
					}
				}
				if(find){
					printf("tim thay phan tu %d tai vi tri %d", check, position+1);
				}else{
					printf("khong tim thay phan tu %d", check);
				}
			break;
			
			case 9:
				for(i=0;i<=amount;i++){
					cnt=0;
					for(j=1;j<=arr[amount];j++){
						if(arr[i]%j==0){
							cnt++;	
						}
					}
					if(cnt==2){
						printf("\n%d la so nguyen to", arr[i]);
					}
				}
			break;
			
			case 10:
				for( i=0;i<amount;i++){
					int minpos=i;
					for( j=i+1;j<amount;j++){
						if(arr[j]<arr[minpos]){
							minpos=j;
						}
						if(minpos!=i){
							int temp=arr[i];
							arr[i]=arr[minpos];
							arr[minpos]=temp;
						}
					}
				}
				for(i=0;i<amount; i++){
					printf("%d ", arr[i]);
				}
			break;
			
			case 11:
				printf("thoat chuong trinh !!");
			break;
			
		}
	}while(choose!=11);
	exit(0);
}