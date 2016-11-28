#pragma once
#include<string>
#include<iostream>
using namespace std;
class Interface 
{
public:
	void BookLoadface();//主界面
	void BookSubloadface();//子界面
	void BookSubloadface2();//子界面2
	char BookInputcharface();//提示导入文件界面
	int BookOperateface();//操作输入界面
	int BookOperateface2();//操作输入界面2
	int BookAddface();//添加界面
	int BookDelface();//删除界面
	int BookSetface();//修改界面
	int BookSearchface();//搜索界面
	void BookAfterSearchface();//搜索结果显示界面

};
