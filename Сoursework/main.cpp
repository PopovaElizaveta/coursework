﻿#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Contact.h"
#include <Windows.h>
#include "Functions.h"
#include <cstdlib>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Первое меню
M1:	int mode = menu1();
	system("cls");
	
	if(mode == 1)//Работа со списком	КОНТАКТОВ
	{
		string titel = "Contacts.txt";

		ofstream fo;
		fo.open(titel, ostream::app);
		if (!fo.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			fo.close();
			system("pause");
			return 1;
		}
		else
		{
			cout << "Файл успешно открыт или создан!" << endl;
			fo.close();
		}

		//Создание копии файла в векторе
		ifstream fi;
		vector<Contact> vec;
		fi.open(titel);
		Contact temp;
		if (!fi.is_open())
		{
			cout << "Ошибка открытия файла для чтения!" << endl;
			fi.close();
			system("pause");
			return 1;
		}
		else
		{
			while (true)
			{
				fi >> temp;
				if (fi.eof())
				{
					break;
				}
				vec.push_back(temp);
			}
			fi.close();
		}

	M3:	if (vec.size() == 0)
		{
	M2:	mode = menu2();
		system("cls");
			if (mode == 1)
			{
				AddContact(vec);
				goto M3;
			}
			if (mode == 2)
			{
				SaveContacts(vec, titel);
				goto M3;
			}
			if (mode == 3)
			{
				goto M1;
			}
			if (mode == 0) //Завершение работы
			{
				cout << "Звершение работы" << endl;
				system("pause");
				return 0;
			}
		}
		
		mode = menu3();
		system("cls");
		if (mode == 1)
		{
			AddContact(vec);
		}

		if (mode == 2)
		{
			DeleteContact(vec);
		}

		if (mode == 3)
		{
			OutputContacts(vec);
		}

		if (mode == 4)
		{
			SortName(vec);
		}
			

		if (mode == 5)
		{
			SortSurname(vec);
		}
			

		if (mode == 6)
		{
			EditContact(vec);
		}
			

		if (mode == 7)
		{
			DeleteAllContacts(vec);
			goto M2;
		}

		if (mode == 8)
		{
			SaveContacts(vec, titel);
		}
			

		if (mode == 9)
		{
			goto M1;
		}
			

		if (mode == 0) //Завершение работы
		{
			cout << "Звершение работы" << endl;
			system("pause");
			return 0;
		}

		goto M3;
	}


	if (mode == 2)	//Работа со списком СОБЫТЕЙ
	{
		cout << "Работа со списком СОБЫТИЙ" << endl;
		string titel = "Eventss.txt";

		ofstream fo;
		fo.open(titel, ostream::app);
		if (!fo.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
			fo.close();
			system("pause");
			return 1;
		}
		else
		{
			cout << "Файл успешно открыт или создан!" << endl;
			fo.close();
		}

		//Создание копии файла в векторе
		ifstream fi;
		vector<Event> vec;
		fi.open(titel);
		Event temp;
		if (!fi.is_open())
		{
			cout << "Ошибка открытия файла для чтения!" << endl;
			fi.close();
			system("pause");
			return 1;
		}
		else
		{
			while (true)
			{
				fi >> temp;
				if (fi.eof())
				{
					break;
				}
				vec.push_back(temp);
			}
			fi.close();
		}

	M5:	if (vec.size() == 0)
	{
	M4:	mode = menu4();
		system("cls");
		if (mode == 1)
		{
			AddEvent(vec);
			goto M5;
		}
		if (mode == 8)
		{
			SaveEvents(vec, titel);
			goto M5;
		}
		if (mode == 3)
		{
			goto M1;
		}
			
		if (mode == 0) //Завершение работы
		{
			cout << "Звершение работы" << endl;
			system("pause");
			return 0;
		}
	}

		mode = menu5();
		system("cls");
		if (mode == 1)
		{
			AddEvent(vec);
		}
			

		if (mode == 2)
		{
			DeleteEvent(vec);
		}
		

		if (mode == 3)
		{
			OutputEvents(vec);
		}
			

		if (mode == 4)
		{
			SortName(vec);
		}
			

		if (mode == 5)
		{
			SortTad(vec);
		}
			

		if (mode == 6)
		{
			EditEvent(vec);
		}
			

		if (mode == 7)
		{
			DeleteAllEvents(vec);
			goto M4;
		}

		if (mode == 8)
		{
			SaveEvents(vec, titel);
		}
			

		if (mode == 9)
		{
			goto M1;
		}
			

		if (mode == 0) //Завершение работы
		{
			cout << "Звершение работы" << endl;
			system("pause");
			return 0;
		}

		goto M5;
	}


	if (mode == 0) //Завершение работы
	{
		cout << "Звершение работы" << endl;
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}