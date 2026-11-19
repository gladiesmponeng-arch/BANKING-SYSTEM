#include <iostream>
using namespace std;

// ================= DECLARATION =================

char names[3][30] = {"Thabo", "Lerato", "Sipho"};

int accountNumbers[3] = {1234, 5678, 9012};

int pins[3] = {2190, 3333, 1088};

double balances[3] = {1500, 2500, 3500};

int currentUser = -1;

void deposit();
void withdraw();
void sendCash();
void checkBalance();
void Exit();
void menu();


// ================= VOID DEPOSIT =================

void deposit()
{
    double amount;

    cout << "\n===== DEPOSIT =====" << endl;
    cout << "Enter amount to deposit: R";
    cin >> amount;

    if (amount > 0)
    {
        balances[currentUser] = balances[currentUser] + amount;

        cout << "Deposit successful!" << endl;
        cout << "Amount deposited: R" << amount << endl;
        cout << "New balance: R" << balances[currentUser] << endl;
    }
    else
    {
        cout << "Invalid amount!" << endl;
    }
}


// ================= VOID WITHDRAW =================

void withdraw()
{
    double amount;

    cout << "\n===== WITHDRAW =====" << endl;
    cout << "Enter amount to withdraw: R";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount!" << endl;
    }
    else if (amount > balances[currentUser])
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        balances[currentUser] = balances[currentUser] - amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Amount withdrawn: R" << amount << endl;
        cout << "Remaining balance: R" << balances[currentUser] << endl;
    }
}


// ================= VOID SEND CASH =================

void sendCash()
{
    int recipient;
    int recipientIndex = -1;
    double amount;

    cout << "\n===== SEND CASH =====" << endl;
    cout << "Enter recipient account number: ";
    cin >> recipient;

    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == recipient)
        {
            recipientIndex = i;
        }
    }

    if (recipientIndex == -1)
    {
        cout << "Account number does not exist!" << endl;
    }
    else if (recipientIndex == currentUser)
    {
        cout << "You cannot send money to your own account!" << endl;
    }
    else
    {
        cout << "Recipient name: " << names[recipientIndex] << endl;

        cout << "Enter amount to send: R";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
        }
        else if (amount > balances[currentUser])
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            balances[currentUser] = balances[currentUser] - amount;

            balances[recipientIndex] = balances[recipientIndex] + amount;

            cout << "Cash sent successfully!" << endl;
            cout << "Amount sent: R" << amount << endl;
            cout << "Remaining balance: R" << balances[currentUser] << endl;
        }
    }
}


// ================= VOID CHECK BALANCE =================

void checkBalance()
{
    cout << "\n===== CHECK BALANCE =====" << endl;

    cout << "Account holder: " << names[currentUser] << endl;

    cout << "Account number: " << accountNumbers[currentUser] << endl;

    cout << "Available balance: R" << balances[currentUser] << endl;
}


// ================= VOID EXIT =================

void Exit()
{
    cout << "\nThank you for banking with GCC BANK!" << endl;

    cout << "Have a nice day!" << endl;
}


// ================= VOID MENU =================

void menu()
{
    int choice;

    do
    {
        cout << "\n========== GCC BANK ==========" << endl;
        cout << "Welcome, " << names[currentUser] << endl;

        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Send Cash" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;

        cout << "==============================" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                sendCash();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                Exit();
                break;

            default:
                cout << "Invalid choice! Please select between 1 and 5." << endl;
        }

    } while (choice != 5);
}


// ================= INT MAIN =================

int main()
{
    int account;
    int pin;
    bool login = false;

    cout << "================================" << endl;
    cout << "       WELCOME TO GCC BANK      " << endl;
    cout << "================================" << endl;

    cout << "Enter account number: ";
    cin >> account;

    cout << "Enter PIN: ";
    cin >> pin;

    for (int i = 0; i < 3; i++)
    {
        if (accountNumbers[i] == account && pins[i] == pin)
        {
            currentUser = i;
            login = true;
        }
    }

    if (login == true)
    {
        cout << "\nLogin successful!" << endl;
        cout << "Welcome " << names[currentUser] << endl;

        menu();
    }
    else
    {
        cout << "\nIncorrect account number or PIN!" << endl;
    }

    return 0;
}
