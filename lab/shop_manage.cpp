#include <bits/stdc++.h>
using namespace std;
const int m = 50;
class items
{
    int itemcode[m];
    float itemprice[m];
    int quantity[m];
    int sellcode[m];
    float sellprice[m];
    int sellquantity[m];
    int count;
    int sellcount;
    int sum = 0;

public:
    void cnt()
    {
        count = 0;
        sellcount = 0;
    }
    void getitem(void);
    void displaysum(void);
    void sell(int);
    void displayitem(void);
    void deleteitem(void);
    void displayspacificitem();
    void printreceipt(void);
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
void items ::printreceipt(void)
{
    int given;
    if (sellcount != 0)
    {
        cout << endl
             << "      Total Bill = " << sum << " BDT" << endl;
        cout << "Enter given amount" << endl;
        cin >> given;
    }

    cout << "                     -----------------------------------------" << endl;
    if (sellcount == 0)
    {
        cout << "                     |           No sold items found             " << endl;
    }
    else
        cout << "                     | Item Code  Item price  Qua  Net price " << endl;
    if (sellcount != 0)
    {
        for (int i = 0; i < sellcount; i++)
        {
            cout << "                     |   " << sellcode[i] << "       " << sellprice[i] << " BDT"
                 << "      " << sellquantity[i] << "     " << (sellquantity[i] * sellprice[i]) << "     " << endl;
            // sum += (sellquantity[i] * sellprice[i]);
        }
    }

    if (sum != 0)
    {
        cout << "                     |                Total bill:   " << sum << " BDT " << endl;
        cout << "                     |              Given amount:   " << given << " BDT " << endl;
        cout << "                     |           Returned amount:   " << given - sum << " BDT " << endl;
    }
    cout << "                     -----------------------------------------" << endl;
    sellcount = 0;
    sum -= sum;
}
void items ::sell(int x)
{
    static int totalsell = 0;
    if (x == 3)
    {
        cout << endl
             << "Total sell: " << totalsell << " BDT" << endl;
        return;
    }
    if (x == 8) // return item
    {
        if (sellcount == 0)
        {
            cout << endl
                 << "      No sold item to remove!!" << endl;
            return;
        }
        int a, q;
        cout << "Enter sold item code" << endl;
        cin >> a;
        for (int i = 0; i < sellcount; i++)
        {
            if (a == sellcode[i])
            {
                cout << "Enter sold item quantity" << endl;
                cin >> q;
                if (sellquantity[i] < q)
                {
                    cout << endl
                         << "      Invalid sold item quantity.Only sold " << sellquantity[i] << endl;
                    return;
                }
            }
            else
            {
                cout << endl
                     << "      Invalid sold item code!!" << endl;
                return;
            }
            sellquantity[i] -= q;
            cout << "      Successfully returned item " << endl;
            totalsell -= (itemprice[i] * q);
            sum -= (itemprice[i] * q);
            if (sellquantity[i] == 0)
            {
                remove(sellcode, sellcode + 50, sellcode[i]);
                sellcount--;
            }
        }

        for (int j = 0; j < count; j++)
        {
            if (a == itemcode[j])
                quantity[j] += q;
        }
        return;
    } // return closed
    if (count == 0)
    {
        cout << endl
             << "      Sorry, No item is available at this moment." << endl;
        return;
    }

    int a, q;
    cout << "Enter sell item code" << endl;
    cin >> a;
    int notfound = 1;
    for (int i = 0; i < count; i++)
    {
        if (a == itemcode[i])
        {
            if (quantity[i] == 0)
            {
                cout << endl
                     << "      Sorry, The item is not available at this moment" << endl;
                return;
            }

            notfound = 0;
            break;
        }
    }
    if (notfound)
    {
        cout << endl
             << "      Invalid item code!!" << endl
             << endl;
        return;
    }

    cout << "Enter item quantity" << endl;
    cin >> q;

    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == a)
        {
            if (quantity[i] < q)
            {
                cout << endl
                     << "      Invalid Quantity.Only have " << quantity[i] << endl;
                return;
            }
            quantity[i] -= q;
            cout << "Succesfully sell " << (itemprice[i] * q) << " BDT" << endl;
            sum += (itemprice[i] * q);
            totalsell += (itemprice[i] * q);
            for (int i = 0; i < sellcount; i++)
            {
                if (a == sellcode[i])
                {
                    sellquantity[i] += q;
                    return;
                }
            }
            sellcode[sellcount] = itemcode[i];
            sellprice[sellcount] = itemprice[i];
            sellquantity[sellcount] = q;
            sellcount++;
            return;
        }
    }
}
void items ::displayitem(void)
{
    if (count == 0)
    {
        cout << endl
             << "No item data found" << endl;
        return;
    }
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
    if (count == 0)
    {
        cout << endl
             << "No item to delete" << endl;
        return;
    }
    int a;
    cout << "Enter item code" << endl;
    cin >> a;
    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == a)
        {
            remove(itemcode, itemcode + m, a);
            count--;
            cout << endl
                 << "Item deleted successfully" << endl;
            return;
        }
    }
    cout << endl
         << "Invalid itemcode" << endl;
}
void items ::displayspacificitem(void)
{
    if (count == 0)
    {
        cout << endl
             << "No items is available" << endl;
        return;
    }
    cout << "Enter search item code" << endl;
    int x, invalid = 1;
    cin >> x;

    for (int i = 0; i < count; i++)
    {
        if (itemcode[i] == x)
        {
            cout << "Code  Price  Quantity" << endl;
            cout << itemcode[i] << "   ";
            cout << itemprice[i] << " BDT    ";
            cout << quantity[i] << endl;
            if (quantity[i] == 0)
                cout << "Stock out" << endl;
            invalid = 0;
            break;
        }
    }
    if (invalid)
        cout << endl
             << "      No item matched for this code!!" << endl;
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
             << "What is your opinion?  ";
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
            order.printreceipt();
            break;
        case 10:
            break;
        default:
            cout << "Error in input; Try again" << endl;
        }
    } while (x != 10);
    return 0;
}
