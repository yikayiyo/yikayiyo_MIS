#pragma once
#ifndef STUDENT_H
#define STUDENT_H


#include<iostream>
#include<string>
#include "Book.h"
using namespace std;
class Student
{
private:
	int index;
	string mStuId;							//学号
	string mStuName;						//姓名
	string mStuAge;							//年龄
	string mStuClass;						//班级
	string mStuMajor;
	string mStuPhone;
	//Book temp;							//借书还书预约信息读取，+接口
	//string SysMessage="";						//系统消息
		 
public:
	void SetIndex(int i) { index = i; }                       //设置下标
	void SetInfo(string, string, string, string, string,string);//修改函数

	void SetStuId() { cin >> mStuId; }
	void SetStuName() { cin >> mStuName; }
	void SetStuAge() { cin >> mStuAge; };
	void SetStuClass() { cin >> mStuClass; }
	void SetStuMajor() { cin >> mStuMajor; }
	void SetStuPhone() { cin >> mStuPhone; }
	void Show();

	string GetStuId() {	return mStuId;}
	string GetStuName() { return mStuName; }
	string GetStuAge() { return mStuAge; }
	string GetStuClass() { return mStuClass; }
	string GetStuMajor() { return mStuMajor; }
	string GetStuPhone()	{ return mStuPhone;}

	//借书、还书、预约-----涉及文件操作Fileoperate、Book、界面设计、程序逻辑设计
};
#endif // !STUDENT_H
