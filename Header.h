#include<stdio.h>
#include<stdlib.h>

typedef struct obj {
	int data;
	struct obj* next;
}obj;

void menu() {
	puts("");
	printf("1. Task 1\n");
	printf("2. Task 2\n");
	printf("3. Exit\n");
	printf("4. Сlear the console\n");
	printf("Make a choice : ");


}

int cheсk_int() {
	int g;
	while (1) {
		if (scanf_s("%d", &g) != 1 || getchar() != '\n' || g > 100000000) {
			printf("\nIncorrect input : ");
			while (getchar() != '\n');
		}
		else break;
	}
	return g;
}

obj* push(obj* top) {
	int data;
	data = cheсk_int();
	
	obj* ptr = (obj*)malloc(sizeof(obj));
	if (ptr == NULL) {
		printf("Error memory allocation");
			exit(0);
			__assume(ptr != NULL);
	}
	ptr->data = data;
	ptr->next = top;
	return ptr;
}

obj* push2(int data, obj* next) {

	
	obj* ptr = (obj*)malloc(sizeof(obj));
	if (ptr == NULL) {
		printf("Error memory allocation");
		exit(0);
		__assume(ptr != NULL);
	}
	ptr->data = data;
	ptr->next = next;
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

obj* push_sorted_desc(obj* top) {
	int data;
	data = cheсk_int();

	if (top != NULL && data > top->data) {
		printf("Error: %d > %d. Values must be in descending order!\n", data, top->data);
		return top; 
	}

	return push2(data, top);
}

obj* create_stack_desc(obj* buffer, int size) {
	for (int i = 0; i < size; ) {
		printf("Enter value %d: ", i + 1);
		obj* new_top = push_sorted_desc(buffer);
		if (new_top != buffer) { 
			buffer = new_top;
			i++;
		}
	}
	return buffer;
}

obj* create_stack_from_two(obj* buffer1, obj* buffer2) {


	obj* new_stack = NULL ;

	while (buffer1 != NULL && buffer2 != NULL) {
		if (buffer1->data < buffer2->data) {
			new_stack = push2(buffer1->data, new_stack);

			buffer1 = buffer1->next;

		}
		else {
			new_stack = push2(buffer2->data, new_stack);
			buffer2 = buffer2->next;


		}
	}

	while (buffer1 != NULL) {
		new_stack = push2(buffer1->data, new_stack);
		buffer1 = buffer1->next;
	}


	while (buffer2 != NULL) {
		new_stack = push2(buffer2->data, new_stack);
		buffer2 = buffer2->next;
	}


	return new_stack;

}

int find_element(obj* buffer, int size) {
	int max = 0 ;

	obj* ptr = buffer;
	while(ptr != NULL) {
		if (ptr->data % 2 == 0 && ptr->data > max) {
			max = ptr->data;
		}
		ptr = ptr->next;
	}
	return max;
}

void free_stack(obj* top) {
	while (top != NULL) {
		obj* temp = top;
		top = top->next;
		free(temp);
	}
}

void task1() {
	int size, max_el;
	obj* buffer = NULL;
	    printf("Enter the stack size : ");
		size = cheсk_int();
		printf("Enter the values : ");
		buffer =  create_stack(buffer, size);
		show_me_stack(buffer);
		max_el = find_element(buffer, size);
		printf("\nMax even element : %d", max_el);

		
}

void task2() {

	int size1, size2;
	obj* buffer1 = NULL, * buffer2 = NULL, * new_buffer = NULL;

	printf("Enter the size of the 1st stack: ");
	size1 = cheсk_int();

	printf("Enter values for 1st stack (descending order):\n");
	buffer1 = create_stack_desc(buffer1, size1);

	printf("Enter the size of the 2nd stack: ");
	size2 = cheсk_int();

	printf("Enter values for 2nd stack (descending order):\n");
	buffer2 = create_stack_desc(buffer2, size2);

	new_buffer = create_stack_from_two(buffer1, buffer2);
	printf("Merged stack (ascending order):\n");
	show_me_stack(new_buffer);

	free_stack(buffer1);
	free_stack(buffer2);
	free_stack(new_buffer);
}