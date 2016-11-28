#include "Book.h"

void Book::SetInfo(string id, string name, string author, string publisher, string pubdate, int num)
{
	mBookId = id;
	mBookName = name;
	mBookAuthor = author;
	mBookPub = publisher;
	mBookPubDate = pubdate;
	mRemainAmount = num;
}

void Book::Show()
{
	cout << "序号:" << index << endl
		<< "书号：" << mBookId << "	"
		<< "书名：" << mBookName << "	"
		<< "作者：" << mBookAuthor << "	"
		<< "出版社：" << mBookPub << "	"
		<< "出版日期：" << mBookPubDate << "	"
		<< "剩余数量：" << mRemainAmount << endl << endl;
}
