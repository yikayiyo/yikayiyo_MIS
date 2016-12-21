#include "Student.h"

void Student::SetInfo(string id, string name, string age, string cls, string major, string phone,int num)
{
	mStuId = id;
	mStuName = name;
	mStuAge = age;
	mStuClass = cls;
	mStuMajor = major;
	mStuPhone = phone;
	mStuBorrow = num;
}

void Student::Show()
{
	cout << "序号:" << index << endl
		<< "学号：" << mStuId << "	"
		<< "姓名：" << mStuName << "	"
		<< "年龄：" << mStuAge << "	"
		<< "班级：" << mStuClass << "	"
		<< "专业：" << mStuMajor << "	"
		<< "电话：" << mStuPhone << "	"
		<<"当前借阅数："<<mStuBorrow<<"	"
		<<endl << endl;
}
