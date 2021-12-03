// header file

////////////////////////////////
class Base 
{
private:
public:
    Base();
    ~Base();
};

////////////////////////////////
class Book 
{
private:
    const char* title;
    const char* author;
    int isbn;
public:
    Book(const char*, const char*, int);
    ~Book();

    void show();       // shows book's informations
};


////////////////////////////////
class Shelf
{
private:
    Book** books;
    int sum;
    int nmax;
public:
    Shelf(int);     // nmax 
    ~Shelf();

    bool place_book(Book&);
    bool take_book();
    void print();
};


////////////////////////////////
class Closet
{
private:
    Shelf s1;
    Shelf s2;
    int sum;
    int nmax;
public:
    Closet(int);
    ~Closet();

    bool place_book(int, Book&);   // posotion, book
    bool take_book(int);
    void print();
};


///////////////////////////////
class Bookcase
{
private:
    Shelf s1;
    Shelf s2;
    Shelf s3;
    Closet c1;
    Base b;
    int nmax;
    int sum;
public:
    Bookcase(int);      //nmax
    ~Bookcase();

    bool place_book(int, Book&);
    bool take_book(int);
    void print();
};