#pragma once
#include<string>
#include<iostream>
using namespace std;
class Borrow
{
private:
	int index;
	string mBookId;
	string mBookName;
	string mStuId;
	string mStuName;
	string mBorrowDate;
	int isReturn;

public:
	void SetIndex(int i) { index = i; }
	void SetInfo(string, string, string, string, string, int);
	void Show();

	void SetBookId() { cin >> mBookId; }  
	void SetBookName() { cin >> mBookName; }
	void SetStuId() { cin >> mStuId; }
	void SetStuName() { cin >> mStuName; }
	void SetBorrowDate() { cin >> mBorrowDate; }
	void SetIsReturn() { isReturn=1; }

	string GetBookId() { return mBookId; }                   
	string GetBookName() { return mBookName; }
	string GetStuId() { return mStuId; }                   
	string GetStuName() { return mStuName; }
	string GetBorrowDate() { return mBorrowDate; }
	int GetIsReturn() { return isReturn; }
};