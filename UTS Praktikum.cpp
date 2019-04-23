/*
Nama : Muhamad Farid Ridho Rambe
NPM : 140810180033
Tanggal Buat : 23/04/2019
Deskripsi : Case 1
*/
#include <iostream>
using namespace std;

struct element{
	int noDaftar;
	string namaTim;
	string asalDaerah;
	int gol;
	element* next;
};

typedef element* pointer;
typedef pointer list;

void createList(list& first){
	first=NULL;
}

void createElement(pointer& pBaru){
	pBaru = new element;
	cout<<"Masukkan Nomor Daftar : ";cin>>pBaru->noDaftar;
	cout<<"Masukkan Nama Tim : ";cin>>pBaru->namaTim;
	cout<<"Masukkan Asal Daerah : ";cin>>pBaru->asalDaerah;
	cout<<"Masukkan Jumlah Gol : ";cin>>pBaru->gol;
	pBaru->next = NULL;
}

void insertFirst(list& first,pointer pBaru){
	if(first==NULL){
		first=pBaru;
	}
	else{
		pBaru->next=first;
		first=pBaru;
	}
}

void traversal(list first){
	pointer pBaru;
	if(first==NULL){
		cout<<"List Kosong"<<endl;
	}
	else{
		pBaru=first;
		do{
			cout<<"Nomor Daftar : "<<pBaru->noDaftar<<endl;
			cout<<"Nama Tim     : "<<pBaru->namaTim<<endl;
			cout<<"Asal Daerah  : "<<pBaru->asalDaerah<<endl;
			cout<<"Gol          : "<<pBaru->gol<<endl;
			cout<<endl;
			pBaru=pBaru->next;
		}while(pBaru!=NULL);
	}
}

void swap(pointer& a,pointer& b){
	int tempGol = a->gol;
	a->gol = b->gol;
	b->gol = tempGol;
	int tempNoDaftar = a->noDaftar;
	a->noDaftar = b->noDaftar;
	b->noDaftar = tempNoDaftar;
	string tempNamaTim = a->namaTim;
	a->namaTim = b->namaTim;
	b->namaTim = tempNamaTim;
	string tempAsalDaerah = a->asalDaerah;
	a->asalDaerah = b->asalDaerah;
	b->asalDaerah = tempAsalDaerah;
}

void sorting(list& first){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (first == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = first;

        while(ptr1->next!=lptr){
            if (ptr1->gol<ptr1->next->gol){
                swap(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

int main(){
	pointer p;
	list q;
	int n;
	cout<<"Masukkan Banyak Data  : ";cin>>n;
	createList(q);
	cout<<"\tMasukkan Tim "<<endl<<endl;
	for(int i=0;i<n;i++){
		createElement(p);
		insertFirst(q,p);
		cout<<endl;
	}
	
	cout<<"\t Klasemen Awal";
	
	cout<<endl;
	traversal(q);
	
	cout<<"\tKlasemen Akhir"<<endl;
	sorting(q);
	traversal(q);
}
