﻿/*
Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти
максимальный четный элемент стека.

Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
стек – организовать ввод по убыванию. Без сортировок и переворачивания исходных стеков
сформировать третий стек упорядоченный по возрастанию
*/

#include"Header.h"

int main() {
	int a;
	while (1) {	menu();
	scanf_s("%d", &a);
	switch (a) {
	case 1: task1();
		break;
	case 2: task2();
		break;
	case 3: return 0;
	case 4:system("cls");
		break;
	default: printf("Enter values from 1 to 4");
		break;
	}
	
}
}