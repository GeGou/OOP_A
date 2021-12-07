#include <iostream>
#include <cstring>
#include "classes.h"
using namespace std;

// generator for random titles/names
char* rand_str(int length)
{
    const char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* result = new char[length+1];
    for (int i = 0; i < length; i++)
    {
        result[i] = charset[rand() % strlen(charset)];
    }
    result[length] = '\0';
    return result;
}

int main (int argc, char* argv[])
{
    if (argc == 5)
    {
        srand(time(NULL));      // the start of the generator
        int nmax = atoi(argv[1]);       // max shelf space
        int l = atoi(argv[2]);      // L books the user want to create
        int k1 = atoi(argv[3]);     // k1 times to place book
        int k2 = atoi(argv[4]);     // k2 times to take book

        // k1-k2 must be less or equal to l
        if ((k1 > l) || (k2 > l) || (k2 > k1))
        {
            cout << "You place or take more books than they are." << endl;
            return 0;
        }

        Bookcase bookcase(nmax);      // construction of the library
        // creation of all books
        Book** books;      // array of L books
        books = new Book*[l];
        for (int i = 0 ; i < l ; i++)
        {
            int isbn = rand() % 8999 + 1000;        // 4 digit isbn
            books[i] = new Book(rand_str(4), rand_str(8), isbn);
        }

        // k1 random book place
        for (int i = 0 ; i < k1 ; i++)
        {
            int pos = rand() % 5 + 1;     // spot to place book 
            bookcase.place_book(pos, *books[i]);
        }

        // k2 random take place
        for (int i = 0 ; i < k2 ; i++)
        {
            int pos = rand() % 5 + 1;     // spot to take book
            bookcase.take_book(pos);
        }

        //print the whole bookcase
        bookcase.print();

        // deletion of all books (book array)
        for (int i = 0 ; i < l ; i++)
        {
            delete books[i];
        }
        delete[] books;
    }
    else
    {
        cout << "Wrong given arguments." << endl;
    }
    return 0;
}