/*
*	Name: Aaron Vasquez
*	Date: September 20, 2025
*	Program Purpose: Simple banking system meant for adding different bank accounts and classes having control while saving through vectors
*	Assignment: Lab Activities: Advanced Objects and Classes II
*/

// Imported libraries
#include <iostream>
#include <string>
#include <vector>
#include <limits>

// BankAccount Class
class BankAccount {
public:
	// Default Constructor
	BankAccount()
	{
		accountNumber = "";
		accountHolderName = "";
		balance = 0.00;
	}

	// Parameterized Constructor
	BankAccount(std::string AccountNumber, std::string AccountHolderName, double Balance)
	{
		accountNumber = AccountNumber;
		accountHolderName = AccountHolderName;
		balance = Balance;
	}

	// Constructor
	BankAccount(const BankAccount& other) {
		accountNumber = other.accountNumber;
		accountHolderName = other.accountHolderName;
		balance = other.balance;
	}

	// Assignment Operator
	BankAccount& operator=(const BankAccount& other)
	{
		if (this != &other)
		{
			accountNumber = other.accountNumber;
			accountHolderName = other.accountHolderName;
			balance = other.balance;
		}
		return *this;
	}

	// Destructor
	~BankAccount() {}

	// Arithmetic Operator (+=)
	BankAccount& operator+=(double amount)
	{
		if (amount == 0)
		{
			std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
		}
		else if (amount < 0)
		{
			std::cout << "Invalid amount of money to deposit." << std::endl;
		}
		else {
			balance += amount;
			std::cout << "New account balance: $" << balance << std::endl;
		}
		return *this;
	}

	// Arithmetic Operator (-=)
	BankAccount& operator-=(double amount)
	{
		if (amount == 0)
		{
			std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
		}
		else if (amount < 0)
		{
			std::cout << "Invalid amount of money to withdraw." << std::endl;
		}
		else if (amount > balance)
		{
			std::cout << "Not enough funds." << std::endl;
		}
		else {
			balance -= amount;
			std::cout << "New account balance: $" << balance << std::endl;
		}
		return *this;
	}

	// Comparison Operator (==)
	bool operator==(const BankAccount& other) const {
		return (accountNumber == other.accountNumber &&
			accountHolderName == other.accountHolderName &&
			balance == other.balance);
	}

	// Comparison Operator (<)
	bool operator<(const BankAccount& other) const {
		return (balance < other.balance);
	}

	// Comparison Operator (>)
	bool operator>(const BankAccount& other) const {
		return (balance > other.balance);
	}

	// Static function (Printing account)
	static void printAccount(const BankAccount& account) {
		std::cout << "Bank Info:"
			<< "\nAccount Name: " << account.accountHolderName
			<< "\nAccount Number: " << account.accountNumber
			<< "\nCurrent Balance: $" << account.balance
			<< std::endl;
		return;
	}

	// Static function (Creating account)
	static BankAccount createAccountFromInput() {
		BankAccount createAccount;
		int accountNum;
		std::string accountName;

		std::cout << "Define a account number for the Bank Account." << std::endl;

		std::cout << "> ";

		while (!(std::cin >> accountNum))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> ";
		}
		std::cout << std::endl;

		std::cout << "Define a account name for the Bank Account." << std::endl;
		std::cout << "> ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, accountName);
		std::cout << std::endl;

		createAccount.SetAccountHolderName(accountName);
		createAccount = BankAccount(std::to_string(accountNum), createAccount.GetAccountHolderName(), createAccount.GetBalance());
		return createAccount;
	}

	void SetAccountHolderName(std::string AccountHolderName)
	{
		accountHolderName = AccountHolderName;
		return;
	}

	// Getters
	std::string GetAccountNumber() { return accountNumber; }
	std::string GetAccountHolderName() { return accountHolderName; }
	double GetBalance() { return balance; }

private:
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
};

int main()
{
	// Main variables
	BankAccount account;
	std::vector<BankAccount> bank;
	int option, accountNum;
	std::string accountName;
	bool found = false;
	double amount;

	// Main program loop (stops if 5 is entered)
	do {
		std::cout << "[Choose a option!]"
			<< "\n1. Open Account"
			<< "\n2. See Account"
			<< "\n3. Deposit"
			<< "\n4. Withdraw"
			<< "\n5. Quit"
			<< std::endl;

		std::cout << "> ";

		// Input option
		while (!(std::cin >> option))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> ";
		}
		std::cout << std::endl;

		switch (option)
		{
		case 1: // option = 1 (Option 1)
			account = BankAccount::createAccountFromInput();

			found = false;

			for (int i = 0; i < bank.size(); i++)
			{
				if (bank.at(i).GetAccountNumber() == account.GetAccountNumber() == true)
				{
					found = true;
				}
			}
			if (found == false) { bank.push_back(account); }
			else { std::cout << "Account number already exists to someone." << std::endl; }
			std::cout << std::endl;
			break;
		case 2: // option = 2 (Option 2)
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else {
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						BankAccount::printAccount(bank.at(i));
					}
				}
				if (found != true)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 3: // option = 3 (Option 3)
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;
						std::cout << "How much would you like to deposit?" << std::endl;
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						bank.at(i) += amount;
					}
				}
				if (found != true)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		case 4: // option = 4 (Option 4)
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number." << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true;

						std::cout << "How much would you like to withdraw?" << std::endl;


						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;

						bank.at(i) -= amount;
					}
				}
				if (found != true)
				{
					std::cout << "Account was not found!" << std::endl;
				}
			}
			std::cout << std::endl;
			break;
		default:
			continue; // Continue through input if option is not define as one of the cases
		}

	} while (option != 5); // Main program end loop (If 5 entered it'll end program)

	return 0;
}