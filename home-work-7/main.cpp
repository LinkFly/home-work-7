// home-work-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "mylib.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <string>
#include <fstream>
#include <memory>

using namespace std;

//// Tasks 1, 5
void task1_and_5()
{
	cout << "====== Task1 ======\n";
	constexpr size_t arSize = 10;
	float ar[arSize];
	ns_arrays::init_array(ar, arSize);
	ns_arrays::print_array(ar, arSize);
	unsigned negc, posc;
	ns_arrays::neg_pos_count(ar, arSize, negc, posc);
	cout << "negative: " << negc << ", positive: " << posc << endl;
	cout << endl;
}

//// Task2
#define RANGE(num, below) (num >= 0 && num < below)

void task2() {
	cout << "====== Task2 ======\n";
	int num, below = 20;
	cout << "Enter number: ";
	cin >> num;
	
	cout << "Range for " << num << " from 0 below " << below << ": \n\t"
		 << (RANGE(num, below) ? "true" : "false") << endl
		 << endl;
}

//// Task3
#define AR_SIZE 4
#define SwapINT(a, b) {\
	auto tmp = a;\
	a = b;\
	b = tmp;\
}

void bubbleSort(int ar[], size_t arSize, function<bool(int a, int b)> comp) {
	if (arSize < 2)
		return;
	int left = ar[0];
	for (size_t i = 0; i < AR_SIZE - 1; i++)
	{
		for (size_t j = i + 1; j < AR_SIZE; j++)
		{
			if (!comp(ar[i], ar[j]))
				SwapINT(ar[i], ar[j])
		}
	}
}

void task3() {
	cout << "====== Task3 ======\n";
	int ar[AR_SIZE];
	cout << "Initialize array:\n";
	for (size_t i = 0; i < AR_SIZE; i++)
	{
		cout << "\tnumber " << i << ": ";
		cin >> ar[i];
	}

	bubbleSort(ar, AR_SIZE, [](int a, int b) { return a < b; });

	cout << "Sorted array: ";
	for (int i : ar)
	{
		cout << i << " ";
	}

	cout << endl;
}

//// Task4
void task4() {
	cout << "====== Task4 ======\n";
	#pragma pack(push, 1)
	struct Employee
	{
		string firstName;
		string lastName;
		uint8_t age;
		char code[2];
	};
	#pragma pack(pop)

	auto pEmployee = make_shared<Employee>();
	pEmployee->firstName = "Mike";
	pEmployee->lastName = "Binsky";
	pEmployee->age = 33;
	pEmployee->code[0] = 'A';
	pEmployee->code[1] = 'B';

	auto fnPrintKeyVal = [](const string& key, const string& val) {
		cout << '\t' << left << setw(15) << key << val << endl;
	};
	cout << "Employee (code: " << pEmployee->code[0] << pEmployee->code[1] 
		<< ", size: " << sizeof(*pEmployee)
		<< "):\n";
	fnPrintKeyVal("firstName: ", pEmployee->firstName);
	fnPrintKeyVal("lastName: ", pEmployee->lastName);
	fnPrintKeyVal("age: ", to_string(static_cast<int>(pEmployee->age)));

	// Save employee
	string file = "employee_"
		+ to_string(pEmployee->code[0]) + to_string(pEmployee->code[1])
		+ ".txt";
	ofstream fout(file);
	if (!fout) {
		cerr << "Failed open file: " << file;
		exit(-1);
	}
	fout
		<< "code\t" << pEmployee->code[0] << pEmployee->code[1] << endl
		<< "firstName\t" << pEmployee->firstName << endl
		<< "lastName\t" << pEmployee->lastName << endl
		<< "age\t" << static_cast<int>(pEmployee->age) << endl
		<< endl;
	fout.close();

	cout << endl;
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	task1_and_5();
	task2();
	task3();
	task4();
}
