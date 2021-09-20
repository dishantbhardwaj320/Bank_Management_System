#include <iostream>
#include <fstream>
using namespace std;

class node
{
public:
    int amount;
    int rollno;
    

    node()
    {
        amount = 0;
        rollno = 0;
       
    }
    node(int amt , int rln)
    {
        amount = amt;
        rollno = rln;
        
    }
};

int main()
{
    int b , c;
    ifstream in("UniversityAccount1.txt");
    in >> b;
    in >> c;
    node* n1 = new node();
    n1->amount = b;
    n1->rollno = c;
    system("CLS");
    cout<<"ROLL NO    AMOUNT"<<endl;
    cout<<"  "<< n1->rollno<<" ----> "<<n1->amount;

    return 0;
}