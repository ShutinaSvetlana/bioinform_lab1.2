// BioinfLab1.2.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string Task(string str, int n)
{
	int count = 0; //���-�� ���������� ����� � ������
	int max_count = 0; //���� ���-�� ���������� � ������
	string result;
	char str2[80];
	for (int i = 0; i < strlen(str.c_str()) - n + 1; i++)
	{
		strncpy_s(str2, str.c_str() + i, n);
		for (int j = i; j < strlen(str.c_str()) - n + 1; j++)
		{
			//���������� ������� ������ � j-�� ������� � �����
			if (!strncmp(str.c_str() + j, str2, n))
				count++;
		}
		if (count > max_count)
		{   
			//������� ������-���������
			result = "";
			max_count = count;
			//���������� ����� ��������
			result += str2;			
			count = 0;
		}
		else
			if (count == max_count)
			{   
				//��������� k-mer
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
	string result; //���������
	string str; //������
	string n1; //���-�� ����
	int n; //���-�� ����

	ifstream input("input.txt"); // ������� ���� ��� ������	

	getline(input,str); //������� ������ �� �����
	input >> n1; //������� ���-��	
	n = atoi(n1.c_str()); //������� � int

	input.close(); // ��������� ����

	result = Task(str, n); //����� 

	ofstream output; //������� ���� ��� ������
	output.open("output.txt"); //������� ���� ��� ������	
	output << result;
	output.close(); // ��������� ����

	return 0;
}


