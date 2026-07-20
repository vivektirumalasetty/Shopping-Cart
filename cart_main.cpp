#include "datamodel.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(3, "mango", 16),
    Product(2, "guava", 36),
    Product(5, "banana", 56),
    Product(4, "strawberry", 29),
    Product(6, "pineapple", 20),
};

Product *chooseProducts()
{
    // display all the products
    string productlist;

    cout << "available products" << endl;

    for (auto product : allProducts)
    {
        productlist.append(product.getDisplayName());
    }

    cout << productlist << endl;
    cout << "-------------------------" << endl;

    string choice;
    cin >> choice;

    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getfirstletter() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "product not found!!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    bool result;
    if (cart.isempty())
    {
        cout << "Cart empty cannot checkout!" << endl;
        result = false;
    }

    int cash; // only cash payment is accepted
    cout << "enter inputting cash" << endl;
    cin >> cash;

    int total = cart.getTotal();

    if (cash >= total)
    {
        cout << "Change :" << cash - total << endl;
        cout << "THANK YOU FOR SHOPPING!" << endl;
        result = true;
    }
    else
    {
        cout << "NOT ENOUGH CASH!" << endl;
        result = false;
    }

    return result;
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "Select an action - (a)dd and item,(v)iew cart,(c)heckout" << endl;
        cin >> action;

        if (action == 'a')
        {
            // add to cart
            // this action requires viewing the products and then adding to cart
            Product *product = chooseProducts();

            if (product != NULL)
            {
                cout << "Added to the cart: " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'v')
        {
            // view the products in cart
            cout << "------------------------" << endl;
            cout << cart.viewcart() << endl;
            cout << "------------------------" << endl;
        }
        else
        {
            // checkout
            cout << "------------------------" << endl;
            cout << cart.viewcart() << endl;
            if (checkout(cart))
            {
                break;
            }
            cout << "------------------------" << endl;
        }
    }

    return 0;
}