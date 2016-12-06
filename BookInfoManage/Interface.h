#pragma once
#include<string>
#include<iostream>
using namespace std;
class Interface 
{
public:

	int AdminMainFace();					//管理员主界面

	void BookLoadFace();					//图书管理主界面
	void BookSubLoadFace();					//图书管理子界面
	void BookSubLoadFace2();				//图书管理子界面2
	void StuLoadFace();						//学生管理主界面
	void StuSubLoadFace();					//学生管理子界面
	void StuSubLoadFace2();					//学生管理子界面2
	
	char ReadFromFileFace();				//提示导入文件界面
	char AfterReadFromFileFace();			//导入之后提示显示界面
	char WriteIntoFileFace();				//提示保存文件界面
	int OperateFace();						//操作输入界面
	int OperateFace2();						//操作输入界面2

	int AddFace();							//添加界面
	int DelFace();							//删除界面

	int BookSetFace();						//图书信息修改界面
	int BookSearchFace();					//图书信息搜索界面
	int StuSetFace();						//学生信息修改界面
	int StuSearchFace();					//学生信息搜索界面

	void AfterSearchFace();					//搜索结果显示界面
};
