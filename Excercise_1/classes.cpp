#include <iostream>
#include <cstring>
#include "classes.h"
using namespace std;

////////////////////////////////
Base::Base()
{
    cout << "A base has been made." << endl;
}

Base::~Base() 
{
    cout << "A base has been destroyed." << endl;
}


/////////////////////////////
Book::Book(const char* t, const char* n, int i) 
        : title(t), author(n), isbn(i) {}  

Book::~Book()
{
    delete[] Book::author;
    delete[] Book::title;
}

void Book::show()
{
    cout << "///// BOOK'S INFO /////" << endl;
    cout << "TITLE: " << Book::title << endl;
    cout << "AUTHOR: " << Book::author << endl;
    cout << "ISBN: " << Book::isbn << endl << endl;
}


//////////////////////////////
Shelf::Shelf(int nmax)
{
    Shelf::nmax = nmax;
    Shelf::sum = 0;
    Shelf::books = new Book*[nmax];
    for (int i = 0 ; i < Shelf::nmax ; i++)
    {
        Shelf::books[i] = NULL;
    }
    cout << "A shelf has been made." << endl;
}

Shelf::~Shelf()
{
    cout << "A shelf has been destroyed." << endl;
    delete[] books;
}

bool Shelf::place_book(Book &book)
{
    if (Shelf::sum == Shelf::nmax)
    {
        cout << "The shelf is full." << endl;
        return false;
    }
    for (int i = 0 ; i < Shelf::nmax ; i++)
    {
        if (Shelf::books[i] == NULL)
        {
            Shelf::books[i] = &book;
            book.show();
            Shelf::sum++;
            break;
        }
    }
    return true;
}

bool Shelf::take_book()
{
    if (Shelf::sum == 0)
    {
        cout << "The shelf is empty." << endl; 
        return false;
    }
    bool flag = false;
    while (flag == false)
    {
        int pos = rand() % Shelf::nmax;     // taking random book 
        if (Shelf::books[pos] != NULL)
        {
            Shelf::books[pos] = NULL;
            Shelf::sum--;
            flag = true;
        }
    }
    return true;
}

void Shelf::print()
{
    for (int i = 0 ; i < Shelf::nmax ; i++)
    {
        if (Shelf::books[i] != NULL)
        {
            Shelf::books[i]->show();
        }
    }
}

//////////////////////////////
Closet::Closet(int nmax) : s1(nmax), s2(nmax)
{ 
    Closet::sum = 0;
    Closet::nmax = nmax;
    cout << "A closet has been made." << endl;
}

Closet::~Closet()
{
    cout << "A closet has been destroyed." << endl;
}

bool Closet::place_book(int pos, Book& book)
{
    if (Closet::sum == 2 * Closet::nmax)
    {
        cout << "The closet is full." << endl;
        return false;
    }
    if (pos == 1)
    {
        cout << "Placing book in top closet shelf." << endl;
        if (s1.place_book(book) == true)
        {
            Closet::sum++;
        }
    }
    else
    {
        cout << "Placing book in bottom closet shelf." << endl;
        if (s2.place_book(book) == true)
        {
            Closet::sum++;
        }
    }
    return true;
}

bool Closet::take_book(int pos)
{
    if (Closet::sum == 0)
    {
        cout << "The closet is empty." << endl;
        return false;
    }
    if (pos == 1)
    {
        cout << "Taking book from the top closet shelf." << endl;
        if (s1.take_book() == true)
        {
            Closet::sum--;
        }
    }
    else
    {
        cout << "Taking book from the bottom closet shelf." << endl;
        if (s2.take_book() == true)
        {
            Closet::sum--;
        }
    }
    return true;
}

void Closet::print()
{
    s1.print();
    s2.print();
}


////////////////////////////////
Bookcase::Bookcase(int nmax)
        : s1(nmax), s2(nmax), s3(nmax), c1(nmax), b()
{
    Bookcase::nmax = nmax;
    Bookcase::sum = 0;
    cout << "A bookcase has been made." << endl;
}

Bookcase::~Bookcase()
{
    cout << "A bookcase has been destroyed." << endl;
}

bool Bookcase::place_book(int pos, Book& book)
{
    if (Bookcase::sum == 5 * Bookcase::nmax)
    {
        cout << "The bookcase is full." << endl;
        return false;
    }
    if (pos == 1)
    {
        cout << "Placing book in top bookcase shelf." << endl;
        if (s1.place_book(book) == true)
        {
            Bookcase::sum++;
        }
    }
    else if (pos == 2)
    {
        cout << "Placing book in middle bookcase shelf." << endl;
        if (s2.place_book(book) == true)
        {
            Bookcase::sum++;
        }
    }
    else if (pos == 3)
    {
        cout << "Placing book in bottom bookcase shelf." << endl;
        if (s3.place_book(book) == true)
        {
            Bookcase::sum++;
        }
    }
    else
    {
        int new_pos = pos - 3;
        if (c1.place_book(new_pos, book) == true)
        {
            Bookcase::sum++;
        }
    }
    return true;
}

bool Bookcase::take_book(int pos)
{
    if (Bookcase::sum == 0)
    {
        cout << "The bookcase is empty." << endl;
        return false;
    }
    if (pos == 1)
    {
        cout << "Taking book from the top bookcase shelf." << endl;
        if (s1.take_book() == true)
        {
            Bookcase::sum--;
        }
    }
    else if (pos == 2)
    {
        cout << "Taking book from the middle bookcase shelf." << endl;
        if (s2.take_book() == true)
        {
            Bookcase::sum--;
        }
    }
    else if (pos == 3)
    {
        cout << "Taking book from the bottom bookcase shelf." << endl;
        if (s3.take_book() == true)
        {
            Bookcase::sum--;
        }
    }
    else
    {
        int new_pos = pos - 3;
        if (c1.take_book(new_pos) == true)
        {
            Bookcase::sum--;
        }
    }
    return true;
}

void Bookcase::print()
{
    c1.print();
    s1.print();
    s2.print();
    s3.print();
}