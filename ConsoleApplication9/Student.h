#pragma once
#define STUDENT_H
struct birthday
{
	int day;
	int month;
	int year;
};
struct student
{
	char name[20];
	char fam[30];
	char gender;
	birthday birthday;
};