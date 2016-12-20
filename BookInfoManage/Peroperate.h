#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include"BookInfoManagement.h"


class Peroperate
{
private:
	Interface face;
	BookInfoManagement bm;
	Fileoperate Infile_borrow;
	Fileoperate Infile_reserve;
	Fileoperate OutFile_borrow;
	Fileoperate OutFile_reserve;

public:
	void PersonalOperate(string sid);
	void InBorrowFile();
	void InReserveFile();
	void OutBorrowFile();
	void OutReserveFile();
	void ShowMyBorrow(string sid);
	int ShowMyCurBorrow(string sid);
	void ShowMyReserve(string sid);
	int SwitchFunction(string sid,int i);
};