#include <iostream>
#include <string>
using namespace std;

class publication
{

protected:
    string title;
    float price;

public:
    void getdata()
    {
        cout << "Enter Title of book: ";
        cin >> title;
        cout << "Enter price of book:";
        cin >> price;
    }
    void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    publication()
    {
        title = " ";
        price = 0;
    }
};

class book : public publication
{

private:
    int pagecount;

public:
    void get_book_data();
    void put_book_data();
    book()
    {
        pagecount = 0;
    }
};

class tape : public publication
{

private:
    float playtime;

public:
    void get_tape_data();
    void put_tape_data();
    tape()
    {
        playtime = 0;
    }
};

void book::get_book_data()
{

  
    cout << "Enter number of pages in book: ";
    try
    {
        cin >> pagecount;
        if(pagecount<0)
        {
            throw(2);
        }
    }
    catch(int x)
    {
        cout << "Pagecount is not valid\n";
        price = 0;
        title = " ";
        pagecount = 0;
    }
    
    // cin >> pagecount;
}

void book::put_book_data()
{
    putdata();
    cout << "Pagecount:" << pagecount << endl;
}

void tape::get_tape_data()
{
   
    cout << "Enter playtime:";
    cin >> playtime;
}

void tape::put_tape_data()
{
    putdata();
    cout << "Playtime: " << playtime << endl;
}

int main()
{
    publication p;
    book b;
    tape t;
    p.getdata();
    b.get_book_data();
    t.get_tape_data();
    b.put_book_data();
    t.put_tape_data();
    return 0;
}
