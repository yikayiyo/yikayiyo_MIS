#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //读入文件
	Fileoperate OutFile_book; //读出文件
public:
	void BookInfoMange();
	void InBookFile();
	void OutBookFile();
	void AllBookShow();
	int SwitchFunction (int);
};