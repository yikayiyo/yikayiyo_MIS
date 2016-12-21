#pragma once
#include "Student.h"
#include "Fileoperate.h"
#include "Interface.h"
#include <algorithm>

const int Num_stu = 100; //最大学生总数
static Student student[Num_stu];	  //学生象数组
static int No_stu = 1;		  //序号从1开始
static int Total_stu = 0;       //当前学生总数

class StudentInfoManagement
{
private:
	Interface Face_student;
	Fileoperate Infile_student;						//文件操作流实现读出功能
	Fileoperate OutFile_student;					//文件操作流实现写入功能
public:
	void StuInfoManage();							//信息管理
	void InStuFile();								//读出文件
	void OutStuFile();								//写入文件
	void AllStuShow();								//信息展示
	int SwitchFunction(int);						//操作选项
	StudentInfoManagement() { InStuFile(); }
	string GetNameById(string sid);
	int GetNumById(string id);
	void AfterReturn(string id);
	void AfterBorrow(string id);
};