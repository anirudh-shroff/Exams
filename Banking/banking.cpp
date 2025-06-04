#include <iostream>
using namespace std;

class BankAccount
{
protected:
    double accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount()
    {
        this->accountHolderName = "";
        this->accountNumber = 0;
        this->balance = 0;
    }

    void createAccount()
    {
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, this->accountHolderName);

        cout << "Enter Account Number: ";
        cin >> this->accountNumber;

        cout << "\n---------------------------\n";
        cout << "Account Created Successfully\n";
        cout << "Account Holder: " << this->accountHolderName << endl;
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Current Balance: " << this->balance;
        cout << "\n---------------------------\n";
    }

    double getAccountNumber()
    {
        return this->accountNumber;
    }

    void deposit()
    {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        this->balance += amount;
        cout << "\n---------------------------\n";
        cout << "Amount Deposited Successfully.\n";
        cout << "\n---------------------------\n";
    }

    void withdraw()
    {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > this->balance)
        {
            cout << "\n---------------------------\n";
            cout << "Error: Insufficient Balance!\n";
            cout << "\n---------------------------\n";
        }
        else
        {
            this->balance -= amount;
            cout << "\n---------------------------\n";
            cout << "Amount Withdrawn Successfully.\n";
            cout << "\n---------------------------\n";
        }
    }

    void getAccountInfo()
    {
        cout << "\n---------------------------\n";
        cout << "Account Holder: " << this->accountHolderName << endl;
        cout << "Account Number: " << this->accountNumber << endl;
        cout << "Current Balance: " << this->balance;
        cout << "\n---------------------------\n";
    }
};

class SavingsAccount : public BankAccount
{
private:
    int interestRate = 5;

public:
    double calculateInterest()
    {
        double interestAmt;
        int time;
        cout << "Enter time period (years): ";
        cin >> time;

        interestAmt = ((this->balance * interestRate * time) / 100);

        return interestAmt;
    }
};

int main()
{
    int choice;
    SavingsAccount savingsAccount[3]; // Array to hold multiple savings accounts

    do
    {
        cout << "\nBank Management System\n";
        cout << "1. Create Savings Account\n";
        cout << "2. View Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Calculate Interest\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Create Savings Account
        {
            static int i = 0; // Static index for creating accounts
            if (i < 3)
            {
                savingsAccount[i].createAccount();
                i++;
            }
            else
            {
                cout << "Account Limit Reached! (Max 3 Accounts)\n";
            }
            break;
        }
        case 2: // View Account Details
        {
            double accountNumber;
            bool accountFound = false;

            cout << "Enter account number: ";
            cin >> accountNumber;

            for (int i = 0; i < 3; i++)
            {
                if (savingsAccount[i].getAccountNumber() == accountNumber)
                {
                    accountFound = true;
                    savingsAccount[i].getAccountInfo();
                    break;
                }
            }

            if (!accountFound)
            {
                cout << "\n---------------------------\n";
                cout << "Error: Account Not Found!\n";
                cout << "\n---------------------------\n";
            }
            break;
        }
        case 3: // Deposit Money
        {
            double accountNumber;
            bool accountFound = false;

            cout << "Enter account number: ";
            cin >> accountNumber;

            for (int i = 0; i < 3; i++)
            {
                if (savingsAccount[i].getAccountNumber() == accountNumber)
                {
                    accountFound = true;
                    savingsAccount[i].deposit();
                    break;
                }
            }

            if (!accountFound)
            {
                cout << "\n---------------------------\n";
                cout << "Error: Account Not Found!\n";
                cout << "\n---------------------------\n";
            }
            break;
        }
        case 4: // Withdraw Money
        {
            double accountNumber;
            bool accountFound = false;

            cout << "Enter account number: ";
            cin >> accountNumber;

            for (int i = 0; i < 3; i++)
            {
                if (savingsAccount[i].getAccountNumber() == accountNumber)
                {
                    accountFound = true;
                    savingsAccount[i].withdraw();
                    break;
                }
            }

            if (!accountFound)
            {
                cout << "\n---------------------------\n";
                cout << "Error: Account Not Found!\n";
                cout << "\n---------------------------\n";
            }
            break;
        }
        case 5: // Calculate Interest
        {
            double accountNumber;
            bool accountFound = false;

            cout << "Enter account number: ";
            cin >> accountNumber;

            for (int i = 0; i < 3; i++)
            {
                if (savingsAccount[i].getAccountNumber() == accountNumber)
                {
                    accountFound = true;
                    double interest = savingsAccount[i].calculateInterest();

                    cout << "\n---------------------------\n";
                    cout << "Interest Amount: " << interest;
                    cout << "\n---------------------------\n";
                    break;
                }
            }

            if (!accountFound)
            {
                cout << "\n---------------------------\n";
                cout << "Error: Account Not Found!\n";
                cout << "\n---------------------------\n";
            }
            break;
        }
        case 6: // Exit
            cout << "Thank you for using our Bank Management System!\n";
            break;
        default:
            cout << "Invalid choice. Please try again!\n";
        }

    } while (choice != 6);

    return 0;
}