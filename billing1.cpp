#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};
void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t\t                            \n";
    cout << "\t\t\t\t          Super market main menu       /n";
    cout << "\t\t\t\t                            \n";
    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t\t                            \n";
    cout << "\t\t\t | 1) Administrator    |\n";
    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t | 2) buyer          |\n";
    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t | 3) exit          |\n";
    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t\t please select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t please login first \n";
        cout << "\t\t\t enter the email: ";
        cin >> email;
        cout << "\t\t\t password: \n";
        cin >> password;
        if (email == "roby@email.com" && password == "roby@123")
        {
            administrator();
        }
        else
        {
            cout << " invalid email/password";
        }
    case 2:
        buyer();
    case 3:
        exit(0);

    default:
        cout << " please select from the giben options  ";
        goto m;
    }
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t administrator menu ";
    cout << "\n\n\n\t\t\t__________1) add the product___|";
    cout << "\n\n\t\t\t                                |";
    cout << "\n\n\n\t\t\t__________2) modify the product___|";
    cout << "\n\n\t\t\t                                |";
    cout << "\n\n\n\t\t\t__________3) delete the product___|";
    cout << "\n\n\t\t\t                                |";
    cout << "\n\n\n\t\t\t__________3) back tp main menu___|";

    cout << "\n\n\t please enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << " invalid choice!  ";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t      buyer       \n";
    cout << "______________________\n";
    cout << "                        \n";
    cout << "\t\t\t 1) buy product \n";
    cout << "                      \n";
    cout << "\t\t\t 2) go back     \n";
    cout << "\t\t\t enter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "invalid choice !";
    }
    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token{0};
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t\t  add new product";
    cout << "\n\n\n\t\t\t product code of the product ";
    cin >> pcode;
    cout << "\n\n\n  name the product: ";
    cin >> pname;
    cout << "\n\n\n\t price of the product";
    cin >> price;
    cout << "\n\n\n\t discount on the product";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    cout << "\n\n\t\t record inserted !";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token{0};
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\n\t\t modify the record:";
    cout << "\n\t\t                       ";
    cout << "\n\n\n\t\t enter the product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n file does not exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t product new code:";
                cin >> c;
                cout << "\n\t\t name of the product:";
                cin >> n;
                cout << "\n\t\t price of the product:";
                cin >> p;
                cout << "\n\t\t discount on the product:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d;
                cout << "\n\n\t\t record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t record not found!";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token{0};
    cout << "\n\n\t\t delete product";
    cout << "\n\n\t\t product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t file do not exists";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\n\t\t product deleted successfuly";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t record not found!";
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n\n|______________________________________\n";
    cout << "prono\t\tname\t\tprice\n";
    cout << "\n\n\n|______________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t\t" << pname << "\t\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping ::reciept()
{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount{0};
    float dis{0};
    float total{0};

    cout << "\n\n\t\t RECIEPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\n\t\t empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n\n___________________________________\n";
        cout << "\n                                      \n";
        cout << "\n           please place the order      \n";
        cout << "\n                                      \n";
        cout << "\n\n___________________________________\n";

        do
        {
            cout << "\n\n enter the product code:";
            cin >> arrc[c];
            cout << "\n\n\n enter the quantity";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n\n duplicate product code please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n do you want o buy another product? if yes press y else press n for  no";
            cin >> choice;
        } while (choice == 'y');
        cout << "\n\n\t\t\t_______________reciept__________\n";
        cout << "\nproduct no\t product name\t product quantity\t price\t amount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total = total+dis;
                    cout << "\n"<< pcode << " " << pname << " " << arrq[i] << " " << price << " " << amount << " " << dis;

                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n\n\t\t\t ___________________________________";
    cout<<"\n\n total amount : "<<total;
}

int main(int argc, char const *argv[])
{
    shopping s;
    s.menu();
    return 0;
}

