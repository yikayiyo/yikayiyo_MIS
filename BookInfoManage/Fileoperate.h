#pragma once
#include<fstream>
#include<string>
#include "Book.h"

const char book_filename[] = "Bookdata.txt";

class Fileoperate
{
public:
	int Filecinbook();
	int Filecout(Book);
	void Closefile();
	void open_in_bookfile();
	void open_out_bookfile();
	Book Getbook() { return book; }
private:
	fstream file;
	Book book;
	int Judge();
};