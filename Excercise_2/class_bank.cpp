#include <iostream>
#include <cstring>
#include "classes.h"
using namespace std;

////////////////////////////////////////////
Bank::Bank(int k, int l)
{
    // creation of the cashiers
    Bank::cashiers = new Cashier*[5];
    for (int i = 0 ; i < 5 ; i++)
    {
        Bank::cashiers[i] = new Cashier(l, i);

    }
    Bank::open(0);      // opening the first cashier
    Bank::open_cashiers = 1;
    Bank::last_open = 0;
    Bank::last_customer = 1;
    Bank::curr_serving = 1;
    Bank::last_serve = -1;
    Bank::k = k;
}

bool Bank::enter()
{
    // no need for more cashiers
    if (Bank::check_to_open() == true)
    {
        Bank::last_customer++;
        return true;
    }
    // need to open one more cashier
    int i = Bank::last_open;
    int count = 0;
    bool flag = false;
    while ((count++ < 5) && (flag == false))
    {
        if (++i == 5)
        {
            i = 0;
        }
        if (Bank::cashiers[i]->is_open() == false)
        {
            Bank::open(i);  // opening the next closed cashier
            flag = true;
        }
    }
    if (flag == true)
    {
        Bank::last_customer++;
        return true;
    }
    // no more customers can be served
    cout << "Sorry you cannot enter until some customers are served!" << endl;
    return false;
}

void Bank::serve()
{
    int i = 0;
    if (Bank::open_cashiers == 0)
    {
        Bank::open(i);
    }
    else {
        i = Bank::last_serve;
        int count = 0;
        bool flag = false;
        while ((count++ < 5) && (flag == false))
        {
            if (++i == 5 )
            {
                i = 0;
            }
            if ((Bank::cashiers[i]->is_open() == true) && (Bank::cashiers[i])->is_free() == true) {
                flag = true;
            }
        }
    }
    int x = i + 1;
    cout << "Customer no: " << Bank::curr_serving << " by cashier no: " << x << endl;
    Bank::last_serve = i;
    Bank::cashiers[i]->serve();
    Bank::cashiers[i]->free();
    // need to check again for closed cashiers
    if (Bank::cashiers[i]->is_open() == false)
    {
        Bank::open_cashiers--;
    }
    Bank::exit();
}

void Bank::exit()
{
    Bank::curr_serving++;
    if (Bank::check_to_close() == false)
    {
        for (int i = 0 ; i < 5 ; i++) {
            if (Bank::cashiers[i]->is_open() == true)
            {
                Bank::close(i);
                break;
            }
        } 
    }
}

bool Bank::check_to_open()
{
    if ((Bank::waiting_customers()) >= (Bank::open_cashiers * Bank::k))
    {
        return false;
    }
    return true;
}

bool Bank::check_to_close()
{
    int x = Bank::open_cashiers;
    if ((Bank::waiting_customers()) <= (--x * Bank::k))
    {
        return false;
    }
    return true;
}

void Bank::open(int i)
{
    Bank::cashiers[i]->open();
    Bank::open_cashiers++;
    Bank::last_open = i;
    cout << "Cashier " << ++i << " opened." << endl;
}

void Bank::close(int i)
{
    Bank::cashiers[i]->close();
    Bank::open_cashiers--;
    cout << "Cashier " << ++i << " closed." << endl;
}

int Bank::waiting_customers()
{
    return (Bank::last_customer - Bank::curr_serving);
}

Bank::~Bank() {
    for (int i = 0 ; i < 5 ; i++)
    {
        delete Bank::cashiers[i];
    }
    delete[] Bank::cashiers;
}