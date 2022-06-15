#include "MedalTable.h"

int MedalTable::findCountry(const char *country) const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(medalRows[i].getCountry(), country) == 0)
		{
			return i;
		}
	}
    return -1;
}

MedalTable::MedalTable()
{
	medalRows = nullptr;
	size = 0;
}

MedalTable::MedalTable(const MedalTable &mt)
{
	size = mt.size;
	medalRows = new MedalRow[size];
	for (int i = 0; i < size; i++)
	{
		medalRows[i] = mt.medalRows[i];
	}
}

MedalTable::MedalTable(MedalTable &&mt)
{
	size = mt.size;
	medalRows = mt.medalRows;
	mt.medalRows = nullptr;
	mt.size = 0;
}

MedalTable::~MedalTable()
{
	delete[]medalRows;
}

MedalTable &MedalTable::operator=(const MedalTable &mt)
{
	if (!(this == &mt))
	{
		if (size != mt.size)
		{
			delete[]medalRows;
			medalRows = new MedalRow[size];
		}
		size = mt.size;
		for (int i = 0; i < size; i++)
		{
			medalRows[i] = mt.medalRows[i];
		}
	}
	return *this;
}

MedalTable &MedalTable::operator=(MedalTable &&mt)
{
	size = mt.size;
	medalRows = mt.medalRows;
	mt.medalRows = nullptr;
	mt.size = 0;
	return *this;
}

MedalRow &MedalTable::operator[](const char *country)
{
	int idx{ findCountry(country) };

	if (idx == -1)
	{
		idx = size++;
		addRow();
		medalRows[idx].setCountry(country);
	}
	return medalRows[idx];
}

const MedalRow &MedalTable::operator[](const char *country) const
{
	int idx{ findCountry(country) };
	assert(idx != -1 and "Country not found on const table");
	return medalRows[idx];
}

void MedalTable::print() const
{
	for (int i = 0; i < size; i++)
	{
		medalRows[i].print();
	}
}

const int MedalTable::operator()(const char *country)
{
	int idx{ findCountry(country) };
	assert(idx != -1 and "Country not found on const table");

	int tmp = (medalRows[idx][MedalRow::GOLD] > medalRows[idx][MedalRow::SILVER]) ? 
		medalRows[idx][MedalRow::GOLD] : medalRows[idx][MedalRow::SILVER];
	tmp = (tmp > medalRows[idx][MedalRow::BRONZE]) ? tmp : medalRows[idx][MedalRow::BRONZE];

	int index = 0;
	for (int i = index; i < 3; i++)
	{
		if (tmp == medalRows[idx][i])
		{
			index = i;
			break;
		}
	}
	return index;
}

void MedalTable::addRow()
{
	MedalRow *tmp = new MedalRow[size];
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = medalRows[i];
	}
	delete[]medalRows;
	medalRows = new MedalRow[size];
	for (int i = 0; i < size - 1; i++)
	{
		medalRows[i] = tmp[i];
	}
	delete[]tmp;
}

std::ostream &operator<<(std::ostream &out, MedalTable &mt)
{
	for (int i = 0; i < mt.size; i++)
	{
		out << mt.medalRows[i];
	}
	return out;
}
