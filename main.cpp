#include <iostream>
#include <string>
#include <vector>
#include <limits>

class BankAccount
{
public:
	BankAccount()
	{
		accountNumber = "";
		accountHolderName = "";
		balance = 0.00;
	}
	BankAccount(std::string AccountNumber, std::string AccountHolderName, double Balance)
	{
		accountNumber = AccountNumber;
		accountHolderName = AccountHolderName;
		balance = Balance;
	}
	void SetAccountHolderName(std::string AccountHolderName)
	{
		accountHolderName = AccountHolderName;
		return;
	}
	void Deposit(double amount)
	{
		if (amount == 0)
		{
			std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
		}
		else if (amount > balance)
		{
			std::cout << "Invalid amount of money to deposit." << std::endl;
		}
		else {
			balance += amount;
			std::cout << "New account balance: $" << balance << std::endl;
		}
	}
	void Withdraw(double amount)
	{
		if (amount == 0)
		{
			std::cout << "Your balance did not change cause of invalid amount of 0." << std::endl;
		}
		else if (amount < 0)
		{
			std::cout << "Invalid amount of money to withdraw" << std::endl;
		}
		else {
			balance -= amount;
			std::cout << "New account balance: $" << balance << std::endl;
		}
	}
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
	std::vector<BankAccount> bank;
	int option, accountNum;
	std::string accountName;
	double amount;

	do {
		std::cout << "[Choose a option!]"
			<< "\n1. Open Account"
			<< "\n2. Check Account"
			<< "\n3. Deposit"
			<< "\n4. Withdraw"
			<< "\n5. Quit" << std::endl;

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
		case 1:
			std::cout << "Enter in a account number" << std::endl;
			std::cout << "> ";

			while (!(std::cin >> accountNum))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "> ";
			}

			std::cout << std::endl;

			std::cout << "Enter in a account name" << std::endl;
			std::cout << "> ";
			std::cin >> accountName;
			std::cout << std::endl;

			bank.push_back(BankAccount(std::to_string(accountNum), accountName, 0.00));
			break;
		case 2:
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number" << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}

				std::cout << std::endl;

				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						std::cout << "Bank Info:"
							<< "\nAccount Name: " << bank.at(i).GetAccountHolderName()
							<< "\nAccount Number: " << bank.at(i).GetAccountNumber()
							<< "\nCurrent Balance: $" << bank.at(i).GetBalance() << std::endl;
					}
					else {
						std::cout << "Account was not found!" << std::endl;
					}
				}
			}
			std::cout << std::endl;
			break;
		case 3:
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number" << std::endl;
				std::cout << "> ";
				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}
				std::cout << std::endl;
				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						std::cout << "How much would you like to deposit?" << std::endl;
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						bank.at(i).Deposit(amount);
					}
					else
					{
						std::cout << "Sorry, did not find your account!" << std::endl;
					}
				}
			}
			std::cout << std::endl;
			break;
		case 4:
			if (bank.empty())
			{
				std::cout << "Sorry but there are no accounts registered." << std::endl;
			}
			else
			{
				std::cout << "Please enter in your account number" << std::endl;
				std::cout << "> ";

				while (!(std::cin >> accountNum))
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "> ";
				}

				std::cout << std::endl;

				for (int i = 0; i < bank.size(); i++)
				{
					if (bank.at(i).GetAccountNumber() == std::to_string(accountNum))
					{
						std::cout << "How much would you like to withdraw?" << std::endl;
						std::cout << "$ ";
						while (!(std::cin >> amount))
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cout << "$ ";
						}
						std::cout << std::endl;
						bank.at(i).Withdraw(amount);
					}
					else {
						std::cout << "Sorry, did not find your account!" << std::endl;
					}
				}
			}
			std::cout << std::endl;
			break;
		default:
			continue;
		}
	} while (option != 5);
	return 0;
}