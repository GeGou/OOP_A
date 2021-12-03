#include <iostream>
#include <cstring>
#include "classes.h"
using namespace std;

/////////////////////////////////////////////
Cashier::Cashier(int l, int i)
{
    Cashier::open_flag = false;
    Cashier::serving_flag = false;
    Cashier::l = l;
    Cashier::cashier_no = ++i;
}

void Cashier::open()
{
    Cashier::open_flag = true;
    Cashier::customers_served = 0;
}

void Cashier::close()
{
    Cashier::open_flag = false;
}

void Cashier::serve()
{
    Cashier::serving_flag = true;
}

void Cashier::free()
{
    Cashier::serving_flag = false;
    Cashier::customers_served++;
    if (Cashier::customers_served == Cashier::l)
    {
        Cashier::close();
        cout << "Cashier no: " << Cashier::cashier_no << " closes cause overworked." << endl;
    }
}

bool Cashier::is_open()
{
    return Cashier::open_flag;
}

bool Cashier::is_free()
{
    return !Cashier::serving_flag;
}

Cashier::~Cashier() {}