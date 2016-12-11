#include "Reserve.h"

void Reserve::SetInfo(string s1, string s2, string s3, string s4, string s5)
{
	mBookId = s1;
	mBookName = s2;
	mStuId = s3;
	mStuName = s4;
	mReserveDate = s5;
}

void Reserve::Show()
{
	cout << "序号:" << index << endl
		<< "书号：" << mBookId << "	"
		<< "书名：" << mBookName << "	"
		<< "学号：" << mStuId << "	"
		<< "姓名：" << mStuName << "	"
		<<"预约时间："<<mReserveDate
		<<endl << endl;
}
