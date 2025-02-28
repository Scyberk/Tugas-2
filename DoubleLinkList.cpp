#include <stdio.h>
#include <stdlib.h>

struct Data{
	int number;
	struct Data *next;
	struct Data *prev;
};

struct Data *head = NULL;

struct Data *createNode(int number){
	struct Data *newNode = (struct Data*)malloc(sizeof(struct Data));
	newNode->number = number;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void insertNode(int number){
	struct Data *node = createNode(number);
	
	// kalo masukkin head
	if(head == NULL || number < head->number){
		node->next = head; //isi head menjadi data ke 2 (node -> next)
		
		if(head != NULL){
			head->prev = node; //kalo ada head, karena lebih kecil, jadi posisinya di sblm head
		}
		
		head = node; // head dipindah jadi data baru
		return;
	}
	
	struct Data *curr = head;
	
	// cari perlu masuk dimana
	while (curr -> next != NULL && number > curr->next->number){
		curr = curr -> next; // kalo masih lebih besar, geser ke kanan
	}
	node->next = curr->next; //kalo udah ketemu next data baru disambungin sama next dari curr (kanannya data baru), 
	//dan curr jadi di kiri data baru
	
	if(curr -> next != NULL){ //kalo di kanan data baru ada data
		curr -> next -> prev = node; // prev dari data kanan data baru disambungin sama data baru
	}
	
	curr->next = node; //kanannya curr jadi data baru
	node->prev = curr; // kirinya data baru jadi curr
}

void deleteNode(int number){
	
	if(head == NULL){
		return;
	}
	
	struct Data *curr = head;
	
	// kalo delete head
	if(head -> number == number){
		head = head -> next; // head dipindah dulu ke kanan
		
		if(head != NULL){
			head -> prev = NULL; //kiri head baru dicopot 
		}
		free(curr); //free head lama
		return;
	}
	
	// search posisi yang mau di delete
	while (curr != NULL && curr->number != number){
		curr = curr->next; //kalo bukan geser ke kanan
	}
	
	if(curr == NULL){
		return;
	}
	
	struct Data *currNext = curr ->next; //currNext = kanan data hapus
	struct Data *currPrev = curr ->prev; // kiri data hapus
	
	if(curr -> next != NULL){ 
		currNext->prev = curr->prev; // Kanan data hapus ditempel sama kiri data hapus
		
	}
	if(curr -> prev != NULL){
		currPrev->next = curr->next; //Kiri data hapus ditempel sama kanan data hapus
	}
	free(curr); // delete datanya
}

void printLinkedList(){
	if (head == NULL){
		printf("linked list is empty");
	}
	
	struct Data *curr = head;
	while (curr != NULL){
		printf("%d ", curr -> number);
		curr = curr -> next;
	}
}

int main (){
	
	insertNode(5);
	insertNode(1);
	insertNode(3);
	printLinkedList();
	
	printf("\n\n After Delete \n\n");
	deleteNode(3);
	printLinkedList();
	
	return 0;
}
