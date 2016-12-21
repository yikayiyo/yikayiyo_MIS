#pragma once
#ifndef BOOK_H
#define BOOK_H


#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	int index;
	string mBookId;//书号
	string mBookName;//书名
	string mBookAuthor;//作者
	string mBookPub;//出版社
	string mBookPubDate;//出版日期
	int mRemainAmount;//库存

public:
	void SetIndex(int i) { index = i; }                       //设置下标
	void SetInfo(string, string, string, string, string, int);//修改函数
	void SetBookId() { cin >> mBookId; }                      //修改书号
	void SetBookName() { cin >> mBookName; }                  //修改书名
	void SetBookAuthor() { cin >> mBookAuthor; }              //修改作者
	void SetBookPub() { cin >> mBookPub; }                    //修改出版社
	void SetBookPubDate() { cin >> mBookPubDate; }            //修改出版日期
	void SetBookAmount() { cin >> mRemainAmount; }            //修改数量
	void SetBookAmount1(string stuId) { mRemainAmount ++; }
	void SetBookAmount2(string stuId) { mRemainAmount --; }
	void Show();

	string GetBookId() { return mBookId; }                   //获取书号
	string GetBookName() { return mBookName; }				 //获取书名
	string GetBookAuthor() { return mBookAuthor; }			 //获取作者
	string GetBookPub() { return mBookPub; }				 //获取出版社 
	string GetBookPubDate() { return mBookPubDate; }         //获取出版日期
	int GetBookAmount() { return mRemainAmount; }            //获取数量
};
#endif // !BOOK_H
