#include <iostream>
#include <windows.h>
#include <ctime>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

// class bankCredit
// {
//     public:
//     double bankBalance;

//     bankCredit();
//     bankBalance = 5000000.00;

//     bankCredit(double BC)
//     bankBalance = BC;
// };

class node
{
public:
    int account_Number;
    int age;
    double balance;
    double loanRecieveBOX;
    double loanReturnBOX;
    double fixedDeposite;
    double goldInterest;
    unsigned int time;
    short int duration;
    string name;
    string phone_no;
    string email;
    string password;
    node *next;

    node()
    {
        account_Number = 0;
        age = 0;
        balance = 0.0;
        loanRecieveBOX = 0.0;
        loanReturnBOX - 0.0;
        fixedDeposite - 0.0;
        goldInterest = 0.0;
        time = 0;
        duration = 0;
        name = "NULL";
        phone_no = "NULL";
        email = "NULL";
        password = "NULL";
        next = NULL;
    }

    node(int acno, double bal, double LRcB, double LReB, double FD, double GI, unsigned int tm, short drtin, int year, string nam, string num, string eml, string pass)
    {
        account_Number = acno;
        balance = bal;
        loanRecieveBOX = LRcB;
        loanReturnBOX = LReB;
        fixedDeposite = FD;
        goldInterest = GI;
        time = tm;
        duration = drtin;
        age = year;
        name = nam;
        phone_no = num;
        email = eml;
        password = pass;
    }
};

class bank
{
public:
    node *head;

    bank()
    {

        head = NULL;
    }

    bank(node *n)
    {
        head = n;
    }

    //check if account exist or not//

    node *accExist(int acno1)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->account_Number == acno1)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }
        return temp;
    }

    //2. branch node with current(append)//

    void createAccount(node *n)
    {
        system("CLS");
        time_t t = time(NULL);
        tm *const pTInfo = localtime(&t);
        int b = 1900 + pTInfo->tm_year;
        // cout << "Current year: " << b << '\n';

        int a, age;

        age = abs(n->age - b);

        if (accExist(n->account_Number) != NULL)
        {
            MessageBox(0, "ERROR:( Account number already exists \n Please Enter a UNIQUE account number ", "ALERT", MB_OK);
            cout << "ERROR :( Cant open account with"
                 << " " << n->account_Number << " "
                 << ". Please create account using a UNIQUE account number ";
        }
        else if (age < 18)
        {
            // char age1 =  age ;
            cout << endl;

            // sprintf_s( "age is : %d",age);
            MessageBox(0, "ERROR :( The minimum age to open a bank account is 18 years ", "ALERT", MB_OK);
            cout << "ERROR :( your age is " << age << " the minimum age to open a bank account is 18 " << endl;
        }

        else
        {
            if (head == NULL)
            {
                head = n;
                MessageBox(0, "Your account has been created", "CONGRATULATIONS", MB_OK);
                cout << "ACCOUNT CREATED" << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }

                ptr->next = n;
                MessageBox(0, "Your account has been created", "CONGRATULATIONS", MB_OK);
                cout << "Account Created";
            }
        }
    }

    //3. Widrawl / deposit amount from remaining balance;

    void Add_sub_balance(int bal_update, int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {

            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            cout << "Wrong password";
        }
        else if (temp->account_Number != acno)
        {
            cout << "Wrong account number";
        }
        else
        {
            temp->balance = temp->balance + bal_update;

            cout << "Total balance =" << temp->balance << endl;

            if (bal_update >= 0)
            {
                cout << bal_update << " Amount added to " << temp->account_Number << "of " << temp->name << endl;
                cout << " Total amount of balance left = " << temp->balance;
            }
            else
            {
                cout << bal_update << "Amount widthrawl from " << temp->account_Number << "of " << temp->name << endl;
                cout << "Total amount of balance left =" << temp->balance;
            }
        }
    }

    //4.Show full detail of user from accno and password//

    void showAcc(int acno)

    {
        system("CLS");

        if (head == NULL)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << "Info for thisn account are" << endl;
            node *temp = head;
            node *temp1 = NULL;
            while (temp != NULL)
            {
                if (temp->account_Number == acno)
                {
                    temp1 = temp;
                }
                temp = temp->next;
            }

            cout << "Account Number :-"
                 << " " << temp1->account_Number << endl;
            cout << "Remaining balance:-"
                 << " " << temp1->balance << endl;
            cout << "User Name:-"
                 << " " << temp1->name << endl;
            cout << "Phone Number :-"
                 << " " << temp1->phone_no << endl;
            cout << "Email Id :-"
                 << " " << temp1->email << endl;
            cout << "Fixed Deposit Balance :-"
                 << " " << temp1->fixedDeposite << endl;
            cout << "Loan recieved :-"
                 << " " << temp1->loanRecieveBOX << endl;
            cout << "Loan Returned :-"
                 << " " << temp1->loanReturnBOX << endl;
        }
    }

    //5. Delete an Accounnt//

    void deleteAccount(int acno, string pass)

    {
        system("CLS");
        if (head == NULL)
        {
            cout << "No Account registered in your bank branch LMFAO" << endl;
        }
        else if (head != NULL)
        {
            if (head->account_Number == acno)
            {
                head = head->next;
                cout << "Bank account UNLINKED with GLOBAL BANK  " << acno << endl;
            }

            else
            {
                node *temp = NULL;
                node *currentprt = head->next;
                node *prevptr = head;

                while (currentprt != NULL)
                {
                    if (currentprt->account_Number == acno)
                    {
                        temp = currentprt;
                        currentprt = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentprt = currentprt->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Account deleted  :" << acno << endl;
                }
                else
                {
                    cout << "Bank Account  Doesnt exist with the account number" << acno << endl;
                }
            }
        }
    }

    void totalUser()
    {
        system("CLS");
        int count = 1;
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }

        cout << "Total active user from our branch = " << count << endl;
    }

    void totalAmount()
    {
        node *temp = head;
        int count = temp->balance;

        while (temp->next != NULL)
        {
            count = count + temp->balance;
            temp = temp->next;
        }
        cout << "Total amount of money in BANK left =" << count;
    }

    // ----------------------------------------------------------------------------------------LOAN SECTION LOGIC----------------------------------------------------------------------------------------------

    //    -------------------------------------------------------------------------------------------HOME LOAN------------------------------------------------------------------------------------------------

    void homeLoan(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            cout << "Wrong password";
        }
        else if (temp->account_Number != acno)
        {
            cout << "Wrong account number";
        }
        else
        {
            system("CLS");
            int interest = 6;
            char yn;
            double totalAmount;
            double SI;
            int year;
            double monthly;
            cout << "\nSet your time period to pay your LOAN " << endl;
            cin >> year;
            cout << "year=" << year << endl;
            cout << "\nThe maximum amount of HOME LOAN can be given on the basis of your savings in your account is =" << temp->balance * 8 << "Rupees" << endl;
            double principal;
            cout << "Enter the requirment of loan equal or below " << temp->balance * 8 << endl;
            cin >> principal;

            cout << "\nInterest yearly = 6% " << endl;
            SI = (principal * year * interest) / 100;

            totalAmount = principal + SI;

            monthly = totalAmount / (year * 12);

            cout << "\nMonthly installment till for the next " << year * 12 << " Months = " << monthly << endl;
            cout << "\nAre you sure you are ready to CREDIT " << principal << " Rupees LOAN with 6% in your account?    [y/n]   " << endl;
            cin >> yn;
            if (yn == 'y')
            {
                temp->balance = temp->balance + principal;
                temp->loanRecieveBOX = temp->loanRecieveBOX + principal;
                cout << "CONGRATULATIONS " << temp->name << "HOME LOAN has been CREDIT into your account :)";
                MessageBox(0, "Loan has been approved and added into your credit", "CONGRATULATIONS", MB_OK);
            }
            else
            {
                cout << "huhu" << endl;
            }
        }
    }

    //    --------------------------------------------------------------------------------------GOLD LOAN------------------------------------------------------------------------------------------------

    void goldLoan(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }
        else
        {
            double gold;
            int years;
            double rate = 4766.00;
            int interest = 10;
            double SI;
            double returningMoney;
            char yn;

            cout << "\nENTER THE AMOUNT OF GOLD IN GRAMS[gms] = ";
            cin >> gold;

            cout << "\nENTER TIME PERIOD [YEARS] =";
            cin >> years;
            SI = ((gold * rate) * years * interest) / 100;
            returningMoney = ((gold * rate) + SI);
            cout << "According to current gold rates and weight of your gold the maximum about of GOLD LOAN can be given = " << ((gold * rate) * 75) / 100 << " RUPEES " << endl;
            cout << "Total amount of money to be deposit before  " << years << " from now with 10% LOAN INTEREST = " << returningMoney << " RUPEES" << endl;
            cout << "Are you sure you want to take GOLD LOAN?? [y/n]" << endl;

            cin >> yn;
            if (yn == 'y')
            {
                temp->balance = temp->balance + (gold * rate);
                temp->loanRecieveBOX = temp->loanRecieveBOX + (gold * rate);
                temp->goldInterest = returningMoney;
                cout << "CONGRATULATIONS " << temp->name << "GOLD LOAN has been CREDIT into your account :)";
                MessageBox(0, "Money has been credited into your account", "CONGRATULATIONS", MB_OK);
            }
            else
            {
                cout << "huhu" << endl;
            }
        }
    }
    // ------------------------------------------------------------------------------LOAN AGAINST FIXED DEPOSIT---------------------------------------------------------------------

    void checkFixedDepo(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }
        else
        {
            int check = time(NULL);
            long int breaK;
            long double difference, years;
            char yn;
            breaK = (temp->duration) * 31536000;
            int initial = temp->time;
            difference = abs(initial - check);
            cout << initial << " " << check << endl;
            years = difference / 31536000;
            cout << fixed << setprecision(10) << years << endl;
            double principal = temp->fixedDeposite, I = 10;

            double a;
            double internal;
            internal = pow((1 + (I / 100)), years);
            cout << internal;
            cout << endl;
            a = principal * internal;
            cout << a;
            temp->fixedDeposite = a;

            cout << "Total value of fixed deposite with interest till now " << endl;
            cout << "\nDo you want to BREAK your FIXED DEPOSITE?[y/n]" << endl;
            cin >> yn;
            if (yn == 'y')
            {
                if (difference < breaK)
                {
                    int withd;
                    cout.width(140);
                    cout << "\n\n !!!!!!!!!WARNING !!!!!!!!" << endl;
                    cout << "\n You will be fined upto 2% and all your money will be transfered to SAVINGS account" << endl;
                    cout << "\n Are you sure you want to break before MATURITY?? [y/n]" << endl;
                    cin >> yn;
                    if (yn == 'y')
                    {
                        int tempVar;
                        tempVar = (temp->fixedDeposite * 2) / 100;
                        temp->fixedDeposite = temp->fixedDeposite - tempVar;
                        cout << "\nTotal amount in your FIXED DEPOSIT account =" << temp->fixedDeposite << endl;
                        cout << "\n Enter the amount you want to widhrawl =" << endl;
                        cin >> withd;
                        temp->balance = temp->balance + temp->fixedDeposite;
                        temp->fixedDeposite = 0;
                        cout << "\n Total amout in your SAVINGS ACCOUNT = " << temp->balance << endl;
                    }
                    else
                    {
                        cout << "Thanks for wasting out time :)" << endl;
                    }
                }
            }
        }
    }
    // -----------------------------------------------------------------------------PERSONAL LOAN---------------------------------------------------------------------

    void personalLoan(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }
        else
        {
        }
    }

    // ------------------------------------------------------------------------------STUDENT LOAN---------------------------------------------------------------------

    void studentLoan(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }
        else
        {
            int age, roll_no, confirm_roll_no, income, total, total_given, sem;

            char yn;
            cout << "\nEnter Age according to GOVT documentation/s" << endl;
            cin >> age;
            cout << "\nAdmission confirmed?? [y/n]" << endl;
            cin >> yn;
            if (yn = 'y')
            {
                cout << "\n Does the lender " << temp->name << " have any source of income? [y/n]" << endl;
                cin >> yn;
                if (yn == 'y')
                {
                    cout << "\nEnter income according to income certificate" << endl;
                    cin >> income;
                    cout << "\nTotal semister in course" << endl;
                    cin >> sem;
                    cout << "\n Total fee of course :" << endl;
                    cin >> total;

                    total_given = (total * 80) / 100;

                    cout << "\nTotal amount of loan bank can lend to " << temp->name << total_given << " RUPEES ";
                    cout << "\nAre you sure you want to avail loan?? [y/n]" << endl;
                    cin >> yn;
                    if (yn == 'y')
                    {
                        cout << "Enter your UNIVERSITY roll no" << endl;
                        cin >> roll_no;

                        int i = 3;
                        while (i > 0)
                        {
                            cout << "\nRe-write your university roll number" << endl;
                            cin >> confirm_roll_no;
                            if (roll_no == confirm_roll_no)
                            {
                                ofstream out("UniversityAccount1.txt");
                                int sem;
                                // cout << "\nEnter total number of semisters " << endl;
                                out << total_given << "\n";
                                out << roll_no;

                                i = 0;
                            }
                            else
                            {
                                i--;
                                cout << "\nRoll No not matched TRY AGAIN!!!" << endl;
                                cout << "Chances Left"
                                     << "=" << i;
                            }
                        }
                    }
                    else
                    {
                        cout << "\nok:)" << endl;
                    }
                }
                else
                {
                    cout << temp->name << " could get 50% of its total tuition fees = " << total / 50 << endl;

                    total_given = ((total / 50) * 50) / 100;

                    cout << "\nTotal amount of loan bank can lend to " << temp->name << total / 50 << " RUPEES ";
                    cout << "\nAre you sure you want to avail loan?? [y/n]" << endl;
                    cin >> yn;
                    if (yn == 'y')
                    {
                        cout << "Enter your UNIVERSITY roll no" << endl;
                        cin >> roll_no;
                        cout << "Confirm and re-write your university roll number" << endl;

                        cin >> confirm_roll_no;
                        int i = 3;
                        while (i > 0)
                        {
                            if (roll_no == confirm_roll_no)
                            {
                                ofstream out("UniversityAccount1.txt");
                                int sem;
                                cout << "\nEnter total number of semisters " << endl;
                                cin >> sem;
                                out << total_given << "\n";
                                out << roll_no;

                                i = 0;
                            }
                            else
                            {
                                i--;
                                cout << "\nRoll No not matched TRY AGAIN!!!" << endl;
                                cout << "Chances Left"
                                     << "=" << i;
                            }
                        }
                    }
                    else
                    {
                        cout << "\nok:)" << endl;
                    }
                }
            }
            else
            {
                cout << "\nCant avail loan to " << temp->name << " because no confirmation of admistion from his/her UNIVERSITY/INSTITUTE" << endl;
            }
        }
    }

    // ---------------------------------------------------------------------------------FIXED DEPOSIT----------------------------------------------------------------------------

    void fixedDeposit(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }

        else
        {
            int duration, money, initial;
            char yn;
            cout << "Total amount of money in your savings account = " << temp->balance << " RUPEES" << endl;
            cout << "\n Enter the amount of money " << endl;
            cin >> money;
            cout << "\n Enter Time Period Between 1 to 10" << endl;
            cin >> duration;
            temp->duration = duration;

            cout << "Compound Interest on FIXED DEPOSIT is 10% p.a " << endl;
            cout << "\n Are you sure you want to transfer " << temp->balance << " RUPEES to FIXED DEPOSIT account? [y/n]" << endl;
            cin >> yn;
            if (yn == 'y')
            {
                temp->fixedDeposite = money;
                temp->balance = temp->balance - money;
                initial = time(NULL);
                temp->time = initial;
            }
            else
            {
                cout << "\nThanks for wasting my time :)" << endl;
            }
        }
    }
    //---------------------------------------------------------------------------------------------------FIXED LOAN BALANCE------------------------------------------------------------------------------------------

    void fixedDepositBalance(int acno, string pass)

    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {

            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            cout << "Wrong password";
        }
        else if (temp->account_Number != acno)
        {
            cout << "Wrong account number";
        }
        else
        {
            int timeA, timeB;
            long double difference;
            char yn;

            timeA = time(NULL);
            cout << "Checking time difference [y/n]" << endl;
            cin >> yn;
            if (yn == 'y')
            {
                timeB = time(NULL);
                difference = abs(timeA - timeB);
                cout << difference;
            }
            // long double difference;

            long double years;
            // if (difference < 604800)
            // {
            //     cout << "Sorry ! YOU WILL NOT GET ANY INTEREST BEFORE 7 DAYS OF DEPOSIT . \n DO YOU WANT TO BREAK YOUR FIXED DEPOSITED MONEY? [y/n]" << endl;
            // }
            // else
            {

                years = difference / 31536000;
                cout << fixed << setprecision(10) << years << endl;
            }

            double principal, I = 10;
            principal = temp->fixedDeposite;

            double a;
            double internal;
            internal = pow((1 + (I / 100)), years);
            // cout << "INTERNAL=";
            // cout << internal;
            // cout << endl;
            a = principal * internal;
            cout << "Current amount : " << a;
        }
    }

    // -------------------------------------------------------------------------------------------------LOAN DEPOSIT SECTION-----------------------------------------------------------------------------------------
    void depositeGoldLoan(int acno, string pass)
    {
        system("CLS");
        node *ptr = head;
        node *temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->account_Number == acno)
            {
                temp = ptr;
            }

            ptr = ptr->next;
        }

        if (temp->password != pass)
        {
            MessageBox(0, "WRONG PASSWORD", "X", MB_OK);
        }
        else if (temp->account_Number != acno)
        {
            MessageBox(0, "WRONG ACCOUNT NUMBER", "X", MB_OK);
        }

        else
        {
            double pay;
            cout << "\n Total amount to be paid :"
                 << " " << temp->goldInterest << " Rupees\n"
                 << endl;
            cout << "\n Enter the amount of money you want to return :"
                 << " " << endl;
            cin >> pay;
            int option4;

            cout << "\n Mode of payment" << endl;
            cout << "\n 1. Cash" << endl;
            cout << "\n 2. checque" << endl;
            cout << "\n 3. Directly from savings" << endl;
            cout << "\n Choose an option" << endl;
            cin >> option4;

            switch (option4)
            {
            case 1:
                char yn1;
                cout << "\nPayment confirmed?[y/n]" << endl;
                cin >> yn1;
                if (yn1 == 'y')
                {
                    break;
                }

                break;
            case 2:
                char yn;
                cout << "\nPayment confirmed?[y/n]" << endl;
                cin >> yn;
                if (yn == 'y')
                {
                    break;
                }
                break;
            case 3:
                if (temp->balance < pay)
                {
                    // cout << "\nInsufficent bank balance :(" << endl;
                    MessageBox(0, "INSUFFICENT BANK BALANCE", "X", MB_OK);
                }
                else
                {
                    temp->balance = temp->balance - pay;
                    temp->goldInterest = temp->goldInterest - pay;
                }

                break;

            default:
                break;
            }
        }
    }
};
// global value for containing vurrent time value//
int main()
{

    system("color 0B");
    bank b;
    int option;
    int acno, bal_update, year;
    string pass, name, email, numb;

    do
    {

        {
            cout << endl;
            cout.width(120);
            cout << "Welcome To  Global Bank     " << endl;
            cout.width(120);
            cout << "==========================\n\n\n"
                 << endl;
            cout << "What operation you want to perform?" << endl;
            cout << "\n1. Create a new account" << endl;
            cout << "\n2. Show full details of account" << endl;
            cout << "\n3. Deposite / Widthrawl " << endl;
            cout << "\n4. Count number of customers in this branch" << endl;
            cout << "\n5. Count total amount of money does this branch hold" << endl;
            cout << "\n6. Delete an account" << endl;
            cout << "\n7. LOAN SECTION" << endl;
            cout << "\n8. Open a FIXED DEPOSITE account " << endl;
            cout << "\n9. Check Current balance in FIXED ACCOUNT" << endl;
            cout << "\nEnter an option" << endl;
            cin >> option;
            node *n1 = new node();

            switch (option)
            {
            case 0:
                break;

            case 1:
                system("CLS");
                srand(time(NULL));
                acno = rand() % 9000 + 1000;
                cout << "Account is : " << acno << endl;
                cout << "Enter a unique password" << endl;
                cin >> pass;
                cout << "Enter Account holders name" << endl;
                cin >> name;
                cout << "Enter email id " << endl;
                cin >> email;
                cout << "Enter phone number" << endl;
                cin >> numb;
                cout << "Enter your year of birth" << endl;
                cin >> year;
                n1->account_Number = acno;
                n1->name = name;
                n1->password = pass;
                n1->phone_no = numb;
                n1->email = email;
                n1->balance = 500;
                n1->age = year;

                b.createAccount(n1);
                break;
            case 2:
                system("CLS");
                cout << "Enter your unique account number" << endl;
                cin >> acno;
                // cout << "Enter password of your account" << endl;
                // cin >> pass;

                b.showAcc(acno);
                break;

            case 4:
                system("CLS");
                b.totalUser();
                break;
            case 3:
                system("CLS");
                cout << "Enter your account number" << endl;
                cin >> acno;
                cout << "Enter your password" << endl;
                cin >> pass;
                cout << "Enter the amount you want to add/sub from the account" << endl;
                cin >> bal_update;
                b.Add_sub_balance(bal_update, acno, pass);
                break;

            case 5:
                system("CLS");

                b.totalAmount();

                break;
            case 6:
                system("CLS");
                cout << "Enter your account number" << endl;
                cin >> acno;
                cout << "Enter your password" << endl;
                cin >> pass;
                b.deleteAccount(acno, pass);
                break;

                cout << endl;
                cout << endl;

            case 7:
                system("CLS");

                cout << "---------------------LOAN SECTION---------------------" << endl;
                cout << "\n1. SECURED LOAN" << endl;
                cout << "\n --->  Home Loan " << endl;
                cout << "\n --->  Gold Loan " << endl;
                cout << "\n --->  Loan against FD \n"
                     << endl;
                cout << "\n2. UNSECURED LOAN" << endl;
                cout << "\n --->  Personal Loan " << endl;
                cout << "\n --->  Marriage Loan " << endl;
                cout << "\n --->  Student Loan " << endl;
                cout << "\n --->  Loan for COVID paitents\n"
                     << endl;
                cout << "\n3. FLEXI LAON" << endl;
                cout << "\n --->  Home Loan " << endl;
                cout << "\n --->  Gold Loan " << endl;
                cout << "\n --->  Loan against FD \n"
                     << endl;
                cout << "\n4. DEPOSITE LOAM\n"
                     << endl;
                cout << "\n---> Gold loan " << endl;
                cout << "\n ---> Home loan" << endl;
                cout << "\n ---> Loan against  FD" << endl;
                cout << "\n ---> Marriage loan" << endl;
                cout << "Choose an OPTION  " << endl;
                cin >> option;
                switch (option)
                {

                case 1:

                    cout << "\n-------------------SECURED LOAN--------------------\n"
                         << endl;

                    int option;
                    cout << "\n1. HOME LOAN" << endl;
                    cout << "\n2. GOLD LOAN" << endl;
                    cout << "\n3. LOAN AGAINST FIXED DEPOSITE" << endl;

                    cout << "Choose an option" << endl;

                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        cout << "----------------------HOME LOAN-------------------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enteryour Password" << endl;
                        cin >> pass;
                        b.homeLoan(acno, pass);
                        break;
                    case 2:
                        cout << "-----------------------GOLD LOAN----------------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enteryour Password" << endl;
                        cin >> pass;
                        b.goldLoan(acno, pass);

                        break;
                    case 3:
                        cout << "--------------- LOAN AGAINST FIXED DEPOSITE----------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enteryour Password" << endl;
                        cin >> pass;
                        b.checkFixedDepo(acno, pass);
                        break;

                    default:
                        break;
                    }

                    break;

                case 2:

                    cout
                        << "\n-------------------UNSECURED LOAN-------------------\n"
                        << endl;
                    int option2;
                    cout << "\n1. PERSONAL LOAN" << endl;
                    cout << "\n2. MARRIAGE LOAN" << endl;
                    cout << "\n3. STUDENT LOAN" << endl;
                    cout << "\n4. LOAN FOR COVID PATIENTS" << endl;
                    cout << "Choose an option" << endl;
                    cin >> option2;

                    switch (option2)
                    {
                    case 1:
                        cout << "----------------------PERSONAL LOAN------------------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;

                        break;
                    case 2:
                        cout << "----------------------MARRIAGE LOAN-----------------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;

                        break;
                    case 3:
                        cout << "-------------------- LOAN FOR STUDENTS---------------------" << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;
                        b.studentLoan(acno, pass);

                        break;
                    case 4:
                        cout << "---------------------LOAN FOR COVID------------------------\n"
                             << endl;
                        break;

                    default:
                        break;
                    }

                    break;

                case 3:

                    cout << "\n--------------------FLEXI LOAN----------------------\n"
                         << endl;

                    break;
                case 4:
                    cout << "-----------------------RETURN LOAN---------------------\n"
                         << endl;
                    int option3;
                    cout << "\n 1. GOLD LOAN" << endl;
                    cout << "\n 2. HOME LOAN " << endl;
                    cout << "\n 3.LOAN AGAINST FD" << endl;
                    cout << "\n 4. MARRIAGE LOAN" << endl;
                    cout << "choose an option" << endl;
                    cin >> option3;
                    switch (option3)
                    {
                    case 1:
                        cout << "-------------------GOLD LOAN-------------------\n"
                             << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;
                        b.depositeGoldLoan(acno, pass);
                        break;
                    case 2:
                        cout << "-------------------HOME LOAN-------------------\n"
                             << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;

                        break;
                    case 3:
                        cout << "---------------LOAN AGAINST FD------------------\n"
                             << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;

                        break;
                    case 4:
                        cout << "-------------------MARRIAGE LOAN-------------------\n"
                             << endl;
                        cout << "Enter your account number" << endl;
                        cin >> acno;
                        cout << "Enter your Password" << endl;
                        cin >> pass;

                        break;

                    default:
                        break;
                    }
                    break;
                default:
                    break;

                    system("CLS");
                }
                break;

            case 8:
                system("CLS");
                cout << "\n--------------------------FIXED DEPOSITE----------------------------";
                cout << "Enter your account number" << endl;
                cin >> acno;
                cout << "Enter your password" << endl;
                cin >> pass;
                b.fixedDeposit(acno, pass);
                break;

            case 9:
                system("CLS");
                cout << "\n--------------------------FIXED DEPOSITE BALANCE----------------------------";
                cout << "Enter your account number" << endl;
                cin >> acno;
                cout << "Enter your password" << endl;
                cin >> pass;
                b.fixedDepositBalance(acno, pass);
                break;
            }
        }
    } while (option != 0);
    return 0;
}
