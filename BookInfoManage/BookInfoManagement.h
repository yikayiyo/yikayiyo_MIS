#pragma once
#include "Book.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class BookInfoManagement
{
private:
	Interface Face_book;
	Fileoperate Infile_book;  //文件操作流实现写入功能
	Fileoperate OutFile_book; //文件操作流实现读出功能
public:
	void BookInfoManage();     //信息管理
	void InBookFile();		  //写入文件
	void OutBookFile();		  //读出文件
	void AllBookShow();		  //信息展示
	int SwitchFunction (int); //操作选项
};