#pragma once

#include"MedalRow.h"

class MedalTable
{
	MedalRow *medalRows;
	int size;
	int findCountry(const char *country)const;
	void addRow();
public:
	MedalTable();
	MedalTable(const MedalTable &mt);
	MedalTable(MedalTable &&mt);
	~MedalTable();
	MedalTable &operator=(const MedalTable &mt);
	MedalTable &operator=(MedalTable &&mt);
	MedalRow &operator[](const char *country);
	const MedalRow &operator[](const char *country)const;
	void print()const;
	friend std::ostream &operator<<(std::ostream &out, MedalTable &mt);
	const int operator()(const char *country);
};