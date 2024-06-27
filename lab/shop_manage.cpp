#include <bits/stdc++.h>
using namespace std;
const int m = 50;
class items
{
    int itemcode[m];
    float itemprice[m];
    int quantity[m];
    int count;

public:
    void cnt()
    {
        count = 0;
    }
    void getitem(void);
    void displaysum(void);
    void sell(int);
    void displayitem(void);
    void deleteitem(void);
    void displayspacificitem();
    void printreceipt(int, int,int);
    void removeitemfromsell();
};
void items ::getitem(void)
{
    cout << "Enter item code" << endl;
    int newitem;
    cin >> newitem;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == newitem)
        {
            cout << "Enter item quantity" << endl;
            int qua;
            cin >> qua;
            quantity[i] += qua;
            return;
        }
    }
    itemcode[count] = newitem;
    cout << "Enter item price" << endl;
    cin >> itemprice[count];
    cout << "Enter item quantity" << endl;
    cin >> quantity[count];
    count++;
}
void items ::displaysum(void)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = sum + (itemprice[i] * quantity[i]);
    }
    cout << endl
         << "Total value: " << sum << " BDT" << endl;
}
void items ::printreceipt(int i, int q, int returnitem)
{
    static map<int, int> mp;
    if (returnitem == -1)
    {
        for (auto &m : mp)
        {
            if (itemcode[m.first] == itemcode[i])
            {
                m.second -= q;
                return;
            }
        }
    }

    //
    if (i == -1 && q == -1)
    {
        int sum = 0;
        cout << "                     -----------------------------------------" << endl;
        if(mp.empty()==1)
        {
            cout<<"                     |           No sold items found             "<<endl;
        }
        else 
        cout << "                     | Item Code  Item price  Qua  Net price " << endl;
        for (auto m : mp)
        {
            if (itemcode[m.first] != 0)
            {
                cout << "                     |   " << itemcode[m.first] << "       " << itemprice[m.first] << " BDT"
                     << "      " << m.second << "     " << (itemprice[m.first] * m.second) << "     " << endl;
                sum += (itemprice[m.first] * m.second);
            }
        }
        if(sum!=0)
        cout << "                     |                Total bill:   " << sum << " BDT " << endl;
        cout << "                     -----------------------------------------" << endl;
        mp.clear();
        return;
    }
    if (mp.empty() == 0)
    {
        for (auto &m : mp)
        {
            if (itemcode[m.first] == itemcode[i])
            {
                m.second += q;
                return;
            }
        }
    }
    // for (auto m : mp)
    //     cout << m.first << " " << m.second << endl;
    mp[i] = q;
}
void items ::sell(int x)
{
    static int totalsell = 0;
    if (x == 3)
    {
        cout << "Total sell: " << totalsell << " BDT" << endl;
        return;
    }
    if (x == 8)
    {
        int a, q;
        cout << "Enter item code" << endl;
        cin >> a;
        cout << "Enter item quantity" << endl;
        cin >> q;
        for (int i = 0; i < count; i++)
        {
            if (itemcode[i] == a)
            {
                quantity[i] += q;
                cout << "Successfully returned " << endl;
                totalsell -= (itemprice[i] * q);
                printreceipt(i, q, -1);
                return;
            }
        }
    }
    int a, q;
    cout << "Enter item code" << endl;
    cin >> a;
    cout << "Enter item quantity" << endl;
    cin >> q;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == a)
        {
            if (quantity[i] == 0)
            {
                cout << "Sorry, The product is not available" << endl;
                break;
            }
            else if (quantity[i] < q)
            {
                cout << "Invalid Quantity.Only have " << quantity[i] << endl;
                break;
            }
            quantity[i] -= q;
            printreceipt(i, q, 5);
            cout << "Succesfully sell " << (itemprice[i] * q) << " BDT" << endl;
            totalsell += (itemprice[i] * q);
        }
    }
}
void items ::displayitem(void)
{
    cout << "Code   Price   Quantity" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << itemcode[i] << "    ";
        cout << itemprice[i] << " BDT     ";
        cout << quantity[i] << endl;
    }
}
void items ::deleteitem(void)
{
    int a;
    cout << "Enter item code" << endl;
    cin >> a;
    remove(itemcode, itemcode + m, a);
    count--;
}
void items ::displayspacificitem(void)
{
    cout << "Enter search item code" << endl;
    int x;
    cin >> x;
    cout << "Code  Price  Quantity" << endl;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == x)
        {
            cout << itemcode[i] << "   ";
            cout << itemprice[i] << " BDT    ";
            cout << quantity[i] << endl;
            break;
        }
    }
}


int main()
{
    items order;
    order.cnt();
    int x;
    do
    {
        cout << endl
             << "Seller services:" << endl;
        cout << "        1 Add an item" << endl;
        cout << "        2 Display all item" << endl;
        cout << "        3 Display total value" << endl;
        cout << "        4 Display total sell" << endl;
        cout << "        5 Search an item" << endl;
        cout << "        6 Delete an item" << endl;
        cout << "Customer services:" << endl;
        cout << "        7 Sell an item" << endl;
        cout << "        8 Remove item from sell" << endl;
        cout << "        9 Print receipt" << endl;
        cout << "       10 quit: " << endl;
        cout << endl
             << "What is your opinion?" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            order.getitem();
            break;
        case 2:
            order.displayitem();
            break;
        case 3:
            order.displaysum();
            break;
        case 4:
            order.sell(3);
            break;
        case 5:
            order.displayspacificitem();
            break;
        case 6:
            order.deleteitem();
            break;
        case 7:
            order.sell(4);
            break;
        case 8:
            order.sell(8);
            break;
        case 9:
            order.printreceipt(-1, -1,0);
            break;
        case 10:
            break;
        default:
            cout << "Error in input; Try again" << endl;
        }
    } while (x != 10);
    return 0;
}
