#include "Borrow.h"

void Borrow::SetInfo(string s1, string s2, string s3, string s4, string s5, int i)
{
	mBookId = s1;
	mBookName = s2;
	mStuId = s3;
	mStuName = s4;
	mBorrowDate = s5;
	isReturn = i;
}

void Borrow::Show()
{
	cout << "序号:" << index << endl
		<< "书号：" << mBookId << "	"
		<< "书名：" << mBookName << "	"
		<< "学号：" << mStuId << "	"
		<< "姓名：" << mStuName << "	"
		<< "借书日期：" << mBorrowDate << "	"
		<< "是否归还：" << isReturn << endl << endl;
}
