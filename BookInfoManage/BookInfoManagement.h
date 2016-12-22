#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"

const int Num_book = 100;		//最大书籍类别总数
static Book book[Num_book];		//书对象数组
static int No_book = 1;			//序号从1开始
static int Total_book = 0;      //当前书籍总数

class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //文件操作流实现读出功能
	Fileoperate OutFile_book; //文件操作流实现写入功能

public:
	void BookInfoManage();     //信息管理
	void InBookFile();		  //读出文件
	void OutBookFile();		  //写入文件
	void AllBookShow();		  //信息展示
	int SwitchFunction (int); //操作选项
	void AfterBorrow(string bookid);
	void ReturnBook(string bookid);
	BookInfoManagement() { InBookFile(); }
	string GetBookIdByIndex(int index);
	string GetBookNameByIndex(int index);
	int GetBookAmount(string bid);
};

