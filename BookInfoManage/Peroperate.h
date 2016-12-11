#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"

class Peroperate
{
private:
	Interface face;
	Fileoperate Infile_borrow;
	Fileoperate Infile_reserve;
	Fileoperate OutFile_borrow;
	Fileoperate OutFile_reserve;

public:
	void InBorrowFile();
	void InReserveFile();
	void OutBorrowFile();
	void OutReserveFile();
	void ShowMyBorrow(string sid);
	void ShowMyReserve(string sid);
	int SwitchFunction(string sid,int i);
};