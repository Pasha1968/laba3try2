// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// За выбор файла в строке может отломать пальчики, сделать нормально через окошечко
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include<string>
#include <time.h>
#include "Block.h"
using namespace std;
// структура с именем файлика
void MakeOpenFileStruct(LPOPENFILENAME OFN, TCHAR* FileName, bool isRead)
{
	OFN->lStructSize = sizeof(OPENFILENAME);
	OFN->hwndOwner = NULL;
	OFN->lpstrFilter = __TEXT("All Files\0*.*\0Text Files\0*.txt\0\0");
	OFN->lpstrCustomFilter = NULL;
	OFN->nFilterIndex = 1;
	*FileName = 0;
	OFN->lpstrFile = FileName;
	OFN->nMaxFile = MAX_PATH;
	OFN->lpstrFileTitle = NULL;
	OFN->lpstrInitialDir = NULL;
	OFN->lpstrTitle = __TEXT("Открыть файл...");
	OFN->Flags = (isRead ? (OFN_FILEMUSTEXIST) : (OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT)) | OFN_EXPLORER | OFN_NOCHANGEDIR;//если выбирается файл для считывания, то флажки OFN_FILEMUSTEXIST| OFN_EXPLORER | OFN_NOCHANGEDIR если для записи OFN_CREATEPROMPT|OFN_OVERWRITEPROMPT| OFN_EXPLORER | OFN_NOCHANGEDIR
	OFN->lpstrDefExt = __TEXT("txt");
}
//ключ должен быть 16 символов 0-9;a-f
bool CheckTextKey(string& Key)
{
	if (Key.size() != 16)
		return false;
	for (unsigned int i = 0; i < 16; ++i) 
	{
		if (!(((Key[i] >= '0') & (Key[i] < 58)) || ((Key[i] > 64) & (Key[i] < 71)) || ((Key[i] > 96) & (Key[i] < 103))))
			return false;
		else cin.putback(Key[15 - i]);
	}
	return true;
}
Block_64b Readkey(unsigned int KNumber)//
{
	// нам надо 16 16ричных значений
	string  TextKey;
	Block_64b value;
	while (1)
	{
		if (KNumber < 4)
			cout << "Введите " << KNumber << " шестнадцатеричный ключ:\n";
		else
			cout << "Введите начальный шестнадцатеричный вектор, состоящий из 16 символов:\n";
		cin >> TextKey;
		if (CheckTextKey(TextKey))//вызов проверочки
		{
			cin >> hex >> value.Full_Block;//записали в 16ричной
			return value;
		}
		else
			cout << "Неправильно, проверьте написание\n ";
	}

}

void FileWork(LPOPENFILENAME inpFile, LPOPENFILENAME outpFile)
{
	while (true)
		if (!GetOpenFileName(inpFile))
		{
			std::cout << "\nФайл не выбран!.";
		}
		else break;
	while (true)
		if (!GetSaveFileName(outpFile))
		{
			std::cout << "\nФайл не выбран! Выберите файл для записи результата.";
		}
		else break;
}

int main()
{
    setlocale(LC_ALL, "Russian");// консолька+ русский
    // сделать роботу с файлами
    // нужны: выбранные файлы,ключики, вектор?, проверка времени
    // ну и выборы алгоритмов, методов работы
    std::cout << "Hello World!\n";
}