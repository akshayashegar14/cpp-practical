
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Base Custom Exception Class
class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// Insufficient Balance Exception
class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException()
        : BankException("Error: Insufficient balance!")
    {
    }
};

// Invalid Amount Exception
class InvalidAmountException : public BankException
{
public:
    InvalidAmountException()
        : BankException("Error: Enter a valid amount!")
    {
    }
};

// Bank Account Class
class BankAccount
{
private:
    string name;
    int accountNo;
    double balance;

public:
    BankAccount(string n, int a, double b)
    {
        name = n;
        accountNo = a;
        balance = b;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        balance += amount;
        cout << "Deposit Successful!" << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException();

        if (amount > balance)
            throw InsufficientFundsException();

        balance -= amount;
        cout << "Withdrawal Successful!" << endl;
    }

    void display()
    {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accountNo << endl;
        cout << "Available Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account("Priya", 1025, 8000);

    cout << "===== BANK MANAGEMENT SYSTEM =====" << endl;

    cout << "\nInitial Account Details:";
    account.display();

    try
    {
        cout << "\nDepositing Rs. 2000..." << endl;
        account.deposit(2000);

        cout << "\nWithdrawing Rs. 3000..." << endl;
        account.withdraw(3000);

        cout << "\nWithdrawing Rs. 15000..." << endl;
        account.withdraw(15000);
    }
    catch (const InsufficientFundsException &e)
    {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException &e)
    {
        cout << e.what() << endl;
    }
    catch (const BankException &e)
    {
        cout << "Bank Error: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cout << "General Error: " << e.what() << endl;
    }

    cout << "\n===== FINAL ACCOUNT DETAILS =====";
    account.display();

    cout << "\nThank you for banking with us!" << endl;

    return 0;
}
