#include"MedalTable.h"

int main()
{
	MedalTable mt1;
	std::cout << "Medals table #1:\n";
	mt1["UKR"][MedalRow::GOLD] = 14;
	mt1["UKR"][MedalRow::SILVER] = 5;
	mt1["HUN"][MedalRow::BRONZE] = 9;
	mt1["HUN"][MedalRow::GOLD] = 7;
	mt1["POL"][MedalRow::GOLD] = 1;
	mt1["POL"][MedalRow::SILVER] = 2;
	mt1["RUS"][MedalRow::SILVER] = 10;
	mt1["RUS"][MedalRow::GOLD] = 20;
	mt1.print();

	std::cout << "\nMedals table #2:\n";
	const MedalTable mt2{ std::move(mt1) };
	mt2.print();

	std::cout << "\nMedals table #3:\n";
	MedalTable mt3 = mt2;
	mt3["RUS"][MedalRow::BRONZE] = 7;
	std::cout << mt3;
	
	switch (mt3("HUN"))
	{
	case 0:
		std::cout << "\nGOLD\n";
		break;
	case 1:
		std::cout << "\nSILVER\n";
		break;
	case 2:
		std::cout << "\nBRONZE\n";
		break;
	default:
		break;
	}

	return 0;
}