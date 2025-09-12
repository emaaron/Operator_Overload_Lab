/*
*	Name: Aaron Vasquez
*	Date: September 11, 2025
*	Program Purpose: Simple banking system meant for adding different bank accounts and classes having control while saving through vectors
*	Assignment: Lab Activities: Objects and Classes I
*/

// Imported libraries
#include <iostream> // Imported standard library for input/output
#include <string> // Imported for conversions and getting full name
#include <vector> // Imported to store each BankAccount class
#include <limits> // Imported for helping with input
/*#include <stdlib.h> Optional: "Was going to use system("cls"); for clearing the console because of messy console after a while"*/

// BankAccount Class
class BankAccount
{
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
		// Store Parameters to according class private variable
		accountNumber = AccountNumber;
		accountHolderName = AccountHolderName;
		balance = Balance;
	}
	// Setter for [accountHolderName]
	void SetAccountHolderName(std::string AccountHolderName)
	{
		// Stores the Name to BankAccount private varaible accountHolderName
		accountHolderName = AccountHolderName;
		return;
	}
	// Function for adding funds to Account's
	void Deposit(double amount)
	{
		// Check values of amount before assigning the new results
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
	}
	// Function for removing funds to Account's
	void Withdraw(double amount)
	{
		// Check values of amount before assigning the new results
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
	}
	// Public Accessors (getters)
	std::string GetAccountNumber() { return accountNumber; } // Return value of Account Number
	std::string GetAccountHolderName() { return accountHolderName; } // Return value of Account Holder Name
	double GetBalance() { return balance; } // Return Account Balance
private:
	// Declared private variables (helping for each Account data)
	std::string accountNumber;
	std::string accountHolderName;
	double balance;
};

int main()
{
	// Main program variables
	BankAccount bank_Account;
	std::vector<BankAccount> bank;
	bool found;
	int option, accountNum;
	std::string accountName;
	double amount;

	// Main program loop (Loops until 5 is entered)
	do {
		std::cout << "[Choose a option!]"
			<< "\n1. Open Account"
			<< "\n2. Check Account"
			<< "\n3. Deposit"
			<< "\n4. Withdraw"
			<< "\n5. Quit" << std::endl;

		// Input [option] with input checking for only numbers
		std::cout << "> ";
		while (!(std::cin >> option))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "> ";
		}
		std::cout << std::endl;

		switch (option)
		{
		case 1: // Option = 1 (Option 1)

			// Generated message for entering a account number
			std::cout << "Define a account number for the Bank Account." << std::endl;

			// Input [accountNum] (Checking for numbers firstly before converting into a string for class)
			std::cout << "> ";
			while (!(std::cin >> accountNum))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "> ";
			}
			std::cout << std::endl;

			// Generate message for entering a account name
			std::cout << "Define a account name for the Bank Account." << std::endl;

			// Input [accountName] (getline is used to use either just first name or a full person's name)
			std::cout << "> ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, accountName);
			std::cout << std::endl;

			// Import results into the BankAccount classes
			bank_Account.SetAccountHolderName(accountName); // Use the class setter SetAccountHolderName() for defining the Bank Account Holder Name
			bank_Account = BankAccount(std::to_string(accountNum), bank_Account.GetAccountHolderName(), bank_Account.GetBalance()); // std::to_string(accountNum) converts accountNum into a string because class purposes uses Bank Account Number in string
			bank.push_back(bank_Account); // Store results into bank vector
			break;
		case 2: // Option = 2 (Option 2)
			if (bank.empty()) // Check beforehand if the program just started and there is no info in the bank vector
			{
				// Generated message
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				// Generated message
				std::cout << "Please enter in your account number" << std::endl;

				// Input [accountNum] (Verification/Get the specific user info from Bank Account Number)
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				// Loop to find the specific user from their Bank Account Number
				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true; // if found it'll now be true

						// Generated message of users info
						std::cout << "Bank Info:"
							<< "\nAccount Name: " << bank.at(i).GetAccountHolderName()
							<< "\nAccount Number: " << bank.at(i).GetAccountNumber()
							<< "\nCurrent Balance: $" << bank.at(i).GetBalance() << std::endl;
					}
				}
				// Return message if users bank account was not found
				if (found != true) { std::cout << "Account was not found!" << std::endl; }
			}
			std::cout << std::endl;
			break;
		case 3: // Option = 3 (Option 3)
			if (bank.empty()) // Check beforehand if the program just started and there is no info in the bank vector
			{
				// Generated message
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				// Generated message
				std::cout << "Please enter in your account number." << std::endl;

				// Input [accountNum] (Verification/Get the specific user info from Bank Account Number)
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				// Loop to find the specific user from their Bank Account Number
				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true; // if found it'll now be true

						// Prompts the user to enter the amount to deposit
						std::cout << "How much would you like to deposit?" << std::endl;

						// Input [amount]
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;

						// Store the amount to the users BankAccount balance
						bank.at(i).Deposit(amount); // Added funds through the class
					}
				}
				// Return message if users bank account was not found
				if (found != true) { std::cout << "Account was not found!" << std::endl; }
			}
			std::cout << std::endl;
			break;
		case 4: // Option = 4 (Option 4)
			if (bank.empty()) // Check beforehand if the program just started and there is no info in the bank vector
			{
				// Generated message
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				// Generated message
				std::cout << "Please enter in your account number." << std::endl;

				// Input [accountNum] (Verification/Get the specific user info from Bank Account Number)
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;

				// Loop to find the specific user from their Bank Account Number
				found = false;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						found = true; // if found it'll now be true

						// Prompts the user to enter the amount to withdraw
						std::cout << "How much would you like to withdraw?" << std::endl;

						// Input [amount]
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;

						// Subtract the amount to the users BankAccount balance
						bank.at(i).Withdraw(amount);
					}
				}
				// Return message if users bank account was not found
				if (found != true) { std::cout << "Account was not found!" << std::endl; }
			}
			std::cout << std::endl;
			break;
		default:
			continue; // Continue through input if option is not define as one of the cases
		}
	} while (option != 5); // Main program loop
	return 0;
}