#pragma once

#include<iostream>
#include<cassert>
#include<ostream>

class MedalRow
{
	char country[4];
	int medals[3];
public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };

	MedalRow(const char *countryP, const int *medalsP);
	MedalRow();
	MedalRow &setCountry(const char *countryP);
	const char *getCountry()const;
	int &operator[](int idx);
	int operator[](int idx)const;
	void print()const;
	friend std::ostream &operator<<(std::ostream &out, MedalRow &mr);
};