#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;
class clsCurrenciesListScreen:protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}

public:
	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency>vCurrency = clsCurrency::GetCurrenciesList();
		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";
		
		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout <<setw(8)<<left<<""<<"| "<<left<<setw(30) << " Country";
		cout <<"| " << left << setw(8) << "Code";
		cout <<"| " << left << setw(45) << "Name";
		cout <<"| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vCurrency.size() == 0)
			cout << "\t\t\t\tNo Currency Available In the System!";
		else

		for (clsCurrency C1 : vCurrency)
		{
			_PrintCurrencyRecordLine(C1);
			cout << endl;
		}
	}
};

