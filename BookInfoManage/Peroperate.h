#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include"BookInfoManagement.h"
#include"StudentInfoManagement.h"


class Peroperate
{
private:
	Interface face;
	BookInfoManagement bm;
	StudentInfoManagement sm;
	Fileoperate Infile_borrow;
	Fileoperate Infile_reserve;
	Fileoperate OutFile_borrow;
	Fileoperate OutFile_reserve;
	Peroperate() {};
public:
	static Peroperate & GetInstance()
	{
		static Peroperate instance;   //局部静态变量  
		return instance;
	}
	void PersonalOperate(string sid);
	void InBorrowFile();
	void InReserveFile();
	void OutBorrowFile();
	void OutReserveFile();
	void ShowMyBorrow(string sid);
	int ShowMyCurBorrow(string sid);
	bool isEnough(string stuid, string bookid);					//判断书籍是否可借阅
	bool isReserved(string stuid, string bookid);
	void UpdateReserve(string stuid, string bookid);
	void ShowMyReserve(string sid);
	int SwitchFunction(string sid,int i);
	int GetReserveAmount(string bookid);
};
