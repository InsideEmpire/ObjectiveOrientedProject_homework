#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Goods
{
private:
    string itemCode;
    string name;
    string color;
    string size;
    double unitPrice;
    int quantity;

public:
    Goods() {}
    Goods(string code, string n, string c, string s, double price, int q)
        : itemCode(code), name(n), color(c), size(s), unitPrice(price), quantity(q) {}

    double getTotalPrice()
    {
        return unitPrice * quantity;
    }

    void printInfo()
    {
        cout << name << "," << color << "," << size << ","
             << fixed << setprecision(2) << unitPrice << ","
             << quantity << ","
             << fixed << setprecision(2) << getTotalPrice() << endl;
    }

    string getItemCode()
    {
        return itemCode;
    }

    void increaseQuantity()
    {
        quantity++;
    }

    void decreaseQuantity()
    {
        if (quantity > 1)
            quantity--;
    }

    int getNumbers()
    {
        return quantity;
    }
};

class ShoppingCart
{
private:
    Goods cart[101];
    int totalItems;
    double totalPrice;

public:
    ShoppingCart() : totalItems(0), totalPrice(0) {}

    void addItem(Goods &item)
    {
        bool found = false;
        for (int i = 0; i < totalItems; ++i)
        {
            if (cart[i].getItemCode() == item.getItemCode())
            {
                cart[i].increaseQuantity();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cart[totalItems++] = item;
        }

        updateTotal();
    }

    void deleteItem(const string &itemCode)
    {
        for (int i = 0; i < totalItems; ++i)
        {
            if (cart[i].getItemCode() == itemCode)
            {
                for (int j = i; j < totalItems - 1; ++j)
                {
                    cart[j] = cart[j + 1];
                }
                totalItems--;
                break;
            }
        }

        updateTotal();
    }

    void increaseItemQuantity(const string &itemCode)
    {
        for (int i = 0; i < totalItems; ++i)
        {
            if (cart[i].getItemCode() == itemCode)
            {
                cart[i].increaseQuantity();
                break;
            }
        }

        updateTotal();
    }

    void decreaseItemQuantity(const string &itemCode)
    {
        for (int i = 0; i < totalItems; ++i)
        {
            if (cart[i].getItemCode() == itemCode)
            {
                cart[i].decreaseQuantity();
                break;
            }
        }

        updateTotal();
    }

    void updateTotal()
    {
        totalPrice = 0;
        for (int i = 0; i < totalItems; ++i)
        {
            totalPrice += cart[i].getTotalPrice();
        }
    }

    void printCart()
    {
        cout << "商品清单:" << endl;
        cout << "商品,颜色,尺码,单价,数量,小计" << endl;
        for (int i = totalItems - 1; i >= 0; i--)
        {
            cart[i].printInfo();
        }
        cout << "----------" << endl;
        int numberOfItems = 0;
        for (int i = 0; i < totalItems; i++)
        {
            numberOfItems += cart[i].getNumbers();
        }
        
        cout << numberOfItems << "件商品,总商品金额" << fixed << setprecision(2) << totalPrice << endl;
        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        ShoppingCart cart;

        for (int i = 0; i < n; ++i)
        {
            string op;
            cin >> op;

            if (op == "ADD")
            {
                string code, name, color, size;
                double price;
                int quantity;
                cin >> code >> name >> color >> size >> price >> quantity;
                Goods item(code, name, color, size, price, quantity);
                cart.addItem(item);
            }
            else if (op == "DELETE")
            {
                string code;
                cin >> code;
                cart.deleteItem(code);
            }
            else if (op == "UP")
            {
                string code;
                cin >> code;
                cart.increaseItemQuantity(code);
            }
            else if (op == "DOWN")
            {
                string code;
                cin >> code;
                cart.decreaseItemQuantity(code);
            }
        }

        cart.printCart();
    }

    return 0;
}
