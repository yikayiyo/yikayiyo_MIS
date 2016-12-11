#pragma once
#include<string>
#include "iostream"
using namespace std;
class Reserve
{
private:
	int index;
	string mBookId;
	string mBookName;
	string mStuId;
	string mStuName;
	string mReserveDate;

public:
	void SetIndex(int i) { index = i; }
	void SetInfo(string, string, string, string, string);
	void Show();

	void SetBookId() { cin >> mBookId; }
	void SetBookName() { cin >> mBookName; }
	void SetStuId() { cin >> mStuId; }
	void SetStuName() { cin >> mStuName; }
	void SetReservedate() { cin >> mReserveDate; }

	string GetBookId() { return mBookId; }
	string GetBookName() { return mBookName; }
	string GetStuId() { return mStuId; }
	string GetStuName() { return mStuName; }
	string GetReserveDate() { return mReserveDate; }
};

