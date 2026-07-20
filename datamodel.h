#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// forward declaration
class Item;
class Cart;

class Product
{
    int id;
    string name;
    int price;

public:
    Product() = default;
    Product(int u_id, string name, int price)
    {
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName()
    {
        return name + "  rs: " + to_string(price) + "\n";
    }

    string getfirstletter()
    {
        return name.substr(0, 1);
    }

    friend class Item;
    friend class Cart;
};

class Item
{
    Product product;
    int quantity;

public:
    Item() = default;
    Item(Product p, int q) : product(p), quantity(q) {}

    int getItemprice()
    {
        return quantity * product.price;
    }

    string getIteminfo()
    {
        return to_string(quantity) + " x " + product.name + "  rs: " + to_string(quantity * product.price) + "\n";
    }
    friend class Cart;
};

class Cart
{
    unordered_map<int, Item> items;

public:
    void addProduct(Product product)
    {
        if (items.count(product.id) == 0)
        {
            Item new_Item(product, 1);
            items[product.id] = new_Item;
        }
        else
        {
            items[product.id].quantity += 1;
        }
    }

    int getTotal()
    {
        int total = 0;

        for (auto Itempair : items)
        {
            auto temp = Itempair.second;
            total += temp.getItemprice();
        }

        return total;
    }

    string viewcart()
    {
        if (items.empty())
        {
            return "cart is empty";
        }

        string itemizedlist;
        int cart_total = getTotal();

        for (auto Itempair : items)
        {
            auto temp = Itempair.second;
            itemizedlist.append(temp.getIteminfo());
        }

        return itemizedlist + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool isempty()
    {
        return items.empty();
    }
};