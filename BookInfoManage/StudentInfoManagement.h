#pragma once
#include "Student.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>



class StudentInfoManagement
{
private:
	Interface Face_student;
	Fileoperate Infile_student;  //文件操作流实现写入功能
	Fileoperate OutFile_student; //文件操作流实现读出功能
public:
	void StuInfoManage();     //信息管理
	void InStuFile();		  //写入文件
	void OutStuFile();		  //读出文件
	void AllStuShow();		  //信息展示
	int SwitchFunction(int); //操作选项
};