#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void crypto(int key);
void decrypt();
string alphabet = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
int main()
{
	setlocale(LC_ALL, "rus");
	int key = 4;
	system("cls");
	while (key != 0)
	{
		cout << "Введите код действия:\n1)Шифрование\n2)Расшифрование\n0)Выход из программы\nКод: ";
		cin >> key;
		if ((key >= 0) && (key <= 2))
		{
			switch (key)
			{
			case 0:
				cout << "\nДо свидания!\n";
				break;
			case 1:
				crypto(key);
				break;
			case 2:
				decrypt();
				break;
			}
		}
		else
		{
			SetConsoleTextAttribute(console, BACKGROUND_RED | BACKGROUND_INTENSITY);
			cout << "Введен неверный код операции!\n\n";
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
	system("pause");
	return 0;
}
void crypto(int key)
{
	system("cls");
	int len_close, len_key;
	string close_text, key_text;
	cout << "Введите текст для шифрования: ";
	cin.ignore();
	getline(cin, close_text);
	cout << "Введите слово-ключ: ";
	getline(cin, key_text);
	len_close = close_text.length();
	len_key = key_text.length();
	transform(close_text.begin(), close_text.end(), close_text.begin(), toupper);
	transform(key_text.begin(), key_text.end(), key_text.begin(), toupper);
	cout << "Введеный закрытый текст: ";
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	for (int i = 0; i < len_close; i++)
	{
		cout << close_text[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "\nВведеный ключ: ";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < len_key; i++)
	{
		cout << key_text[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char* open_text_answer = new char[len_close];
	int count = 0, number, temp;
	if (len_close == len_key)
	{
		while (count != len_close)
		{
			if ((close_text[count] >= 'A') && (close_text[count] <= 'Z'))
			{
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == close_text[count])
					{
						number = i;
					}
				}
				temp = number;
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == key_text[count])
					{
						number = i;
					}
				}
				temp = temp + number;
				if (temp > 25)
				{
					open_text_answer[count] = alphabet[temp - 26];
				}
				else
				{
					open_text_answer[count] = alphabet[temp];
				}
			}
			else
			{
				open_text_answer[count] = close_text[count];
			}
			temp = 0;
			count++;
		}
	}
	else
	{
		while (count != len_close)
		{
			for (int i = 0; i < len_key; i++)
			{
				if (count != len_close)
				{
					open_text_answer[count] = key_text[i];
					count++;
				}
			}
		}
		count = 0;
		while (count != len_close)
		{
			if ((close_text[count] >= 'A') && (close_text[count] <= 'Z'))
			{
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == close_text[count])
					{
						number = i;
					}
				}
				temp = number;
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == open_text_answer[count])
					{
						number = i;
					}
				}
				temp = temp + number;
				if (temp > 25)
				{
					open_text_answer[count] = alphabet[temp - 26];
				}
				else
				{
					open_text_answer[count] = alphabet[temp];
				}
			}
			else
			{
				open_text_answer[count] = close_text[count];
			}
			temp = 0;
			count++;
		}
	}
	cout << "\nЗашифрованное сообщение: ";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for (int i = 0; i < len_close; i++)
	{
		cout << open_text_answer[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl<<endl;
	delete[] open_text_answer;
}
void decrypt()
{
	system("cls");
	int len_open, len_key;
	string open_text, key_text;
	cout << "Введите текст для расшифрования: ";
	cin.ignore();
	getline(cin, open_text);
	cout << "Введите слово-ключ: ";
	getline(cin, key_text);
	len_open = open_text.length();
	len_key = key_text.length();
	transform(open_text.begin(), open_text.end(), open_text.begin(), toupper);
	transform(key_text.begin(), key_text.end(), key_text.begin(), toupper);
	cout << "Введеный открытый текст: ";
	SetConsoleTextAttribute(console, FOREGROUND_RED);
	for (int i = 0; i < len_open; i++)
	{
		cout << open_text[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "\nВведеный ключ: ";
	SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < len_key; i++)
	{
		cout << key_text[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char* close_text_answer = new char[len_open];
	int count = 0, number, temp;
	if (len_open == len_key)
	{
		while (count != len_open)
		{
			if ((open_text[count] >= 'A') && (open_text[count] <= 'Z'))
			{
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == open_text[count])
					{
						number = i;
					}
				}
				temp = number;
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == key_text[count])
					{
						number = i;
					}
				}
				temp = temp - number;
				if (temp < 0)
				{
					close_text_answer[count] = alphabet[temp + 26];
				}
				else
				{
					close_text_answer[count] = alphabet[temp];
				}
			}
			else
			{
				close_text_answer[count] = open_text[count];
			}
			temp = 0;
			count++;
		}
	}
	else
	{
		while (count != len_open)
		{
			for (int i = 0; i < len_key; i++)
			{
				if (count != len_open)
				{
					close_text_answer[count] = key_text[i];
					count++;
				}
			}
		}
		count = 0;
		while (count != len_open)
		{
			if ((open_text[count] >= 'A') && (open_text[count] <= 'Z'))
			{
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == open_text[count])
					{
						number = i;
					}
				}
				temp = number;
				for (int i = 0; i < 26; i++)
				{
					if (alphabet[i] == close_text_answer[count])
					{
						number = i;
					}
				}
				temp = temp - number;
				if (temp < 0)
				{
					close_text_answer[count] = alphabet[temp + 26];
				}
				else
				{
					close_text_answer[count] = alphabet[temp];
				}
			}
			else
			{
				close_text_answer[count] = open_text[count];
			}
			temp = 0;
			count++;
		}
	}
	cout << "\nЗашифрованное сообщение: ";
	SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	for (int i = 0; i < len_open; i++)
	{
		cout << close_text_answer[i];
	}
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << endl<<endl;
	delete[] close_text_answer;
}
