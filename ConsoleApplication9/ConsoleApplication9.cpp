#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Student.h"
#include <ctime>
using namespace std;
bool AgeVerification(int day, int month, int year);


int main()
{
	time_t now = time(0);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    student students[30];
	tm ltm;
	localtime_s(&ltm, &now);
	cout << "Текущая дата: ";
	cout << ltm.tm_mday << '.' << ltm.tm_mon + 1 << '.' << ltm.tm_year + 1900 << endl;
	int counter = 0, records = 0;
	char flag = 'y';
	do {
		cout << "Студент " << records + 1 << endl;
		cout << "Введите имя студента" << endl;
		cin >> students[records].name;
		cout << "Введите фамилию студента" << endl;
		cin >> students[records].fam;
		cout << "Введите ваш пол (f/m)" <<endl;
		cin >> students[records].gender;
		cout << "Введите дату рождения"<<endl<<"День"<<endl;
		cin >> students[records].birthday.day;
		cout << "Месяц" << endl;
		cin >> students[records].birthday.month;
		cout << "Год" << endl;
		cin >> students[records].birthday.year;
		cout << "Продолжить ввод? (y/n)";
		cin >> flag;
		records++;
	} while (flag == 'y');
	
	for (counter = 0; counter < records; counter++){ 
	  if(students[counter].gender == 'm'){
		if (AgeVerification(students[counter].birthday.day, students[counter].birthday.month, students[counter].birthday.year)) {
			cout << setw(16) << "Фамилия" << setw(10) <<
				"Имя" << setw(10) << "Дата рождения" << endl;
			cout << setw(16) << students[counter].fam << setw(10) <<
				students[counter].name << setw(10) <<
				students[counter].birthday.day << "." << students[counter].birthday.month << "." << students[counter].birthday.year << endl;
		}
	  }
	}
}
bool AgeVerification(int bday, int bmonth, int byear) {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	int year = 1900 + ltm.tm_year, month = 1 + ltm.tm_mon, day = ltm.tm_mday;
	if (bmonth < month) {
		return year - byear >= 18 ? true : false;
	}
	else if (bmonth > month) {
		return year - byear >= 19 ? true : false;
	}
	else {
		if (bday <= day) {
			return year - byear >= 18 ? true : false;
		}
		else {
			return year - byear >= 19 ? true : false;
		}
	}
}