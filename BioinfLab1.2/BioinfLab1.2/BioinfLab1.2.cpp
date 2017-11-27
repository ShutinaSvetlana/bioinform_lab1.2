// BioinfLab1.2.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string Task(string str, int n)
{
	int count = 0; //кол-во повторений слова в строке
	int max_count = 0; //макс кол-во посторений в строке
	string result;
	char str2[80];
	for (int i = 0; i < strlen(str.c_str()) - n + 1; i++)
	{
		strncpy_s(str2, str.c_str() + i, n);
		for (int j = i; j < strlen(str.c_str()) - n + 1; j++)
		{
			//сравниваем символы строки с j-ой позиции и слова
			if (!strncmp(str.c_str() + j, str2, n))
				count++;
		}
		if (count > max_count)
		{   
			//очищаем строку-результат
			result = "";
			max_count = count;
			//записываем новое значение
			result += str2;			
			count = 0;
		}
		else
			if (count == max_count)
			{   
				//добавляем k-mer
				result += " ";
				result += str2;
				count = 0;
			}
			else
				count = 0;
	}
	return result;
}

int main()
{
	string result; //результат
	string str; //строка
	string n1; //кол-во букв
	int n; //кол-во букв

	ifstream input("input.txt"); // открыли файл для чтения	

	getline(input,str); //считали строку из файла
	input >> n1; //считали кол-во	
	n = atoi(n1.c_str()); //перевод в int

	input.close(); // закрываем файл

	result = Task(str, n); //поиск 

	ofstream output; //создаем файл для записи
	output.open("output.txt"); //открыли файл для записи	
	output << result;
	output.close(); // закрываем файл

	return 0;
}


