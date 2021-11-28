// header file

///////////////////////////////
class Cashier {
private:
    bool open_flag;
    bool serving_flag;
    int customers_served;
    int l;
    int cashier_no;
public:
    Cashier(int, int);       // l, cashier_no
    ~Cashier();
    void open();
    void close();
    void serve();
    void free();
    bool is_open();
    bool is_free();
};

///////////////////////////////
class Bank {
private:
    int last_customer;
    int curr_serving;
    int open_cashiers;
    int k;
    int last_open;
    int last_serve;
    Cashier** cashiers;
public:
    Bank(int, int);     // k, l
    ~Bank();
    bool enter();
    void serve();
    void exit();
    bool check_to_open();
    bool check_to_close();
    void open(int);
    void close(int);
};