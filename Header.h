#include<stdio.h>
#include<stdlib.h>

typedef struct obj {
	int data;
	struct obj* next;
}obj;

obj* push(obj* top) {
	int data;
	scanf_s("%d", &data);
	obj* ptr = (obj*)malloc(sizeof(obj));
	ptr->data = data;
	ptr->next = top;
	return ptr;
}


void show_me_stack (obj* top) { 
	printf("Stack : \n");
	obj* ptr = top;
	while (ptr != NULL) {
		printf("	%d \n", ptr->data);
		ptr = ptr->next;
	}
	printf("----------------------------- ");
}

obj* create_stack(obj *buffer , int size) {
	
	for (int i = 0; i < size; i++) {
		buffer = push(buffer);
	}
	return buffer;
}


void task1() {
	int size;
	obj* buffer = NULL;
	    printf("Enter the stack size : ");
		scanf_s("%d", &size);
		printf("Enter the values : ");
		buffer =  create_stack(buffer, size);
		show_me_stack(buffer);


		
}