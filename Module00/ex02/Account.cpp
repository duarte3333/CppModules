#include "Account.hpp"
#include "iostream"
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Constructor */
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    std::cout << "index:" << this->_accountIndex \
            << ";amount:" << this->_amount \
            << ";created\n";
}

/* Destructor */
Account::~Account()
{
	_displayTimestamp();
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex \
			<< ";amount:" << this->_amount \
			<< ";closed\n";
}

/* Indica as informacoes de todas as contas */
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts \
                << ";total:" << _totalAmount \
                << ";deposits:" << _totalNbDeposits \
                << ";withdrawals:" << _totalNbWithdrawals \
                << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex \
                << ";amount:" << _amount \
                << ";deposits:" << _nbDeposits \
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/* Indica o timestamp */
void Account::_displayTimestamp() {
    std::time_t now = time(0);
    tm *gmtm = gmtime(&now);
    std::cout << "[" << gmtm->tm_year + 1900 \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mon \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_mday << "_" \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_hour \
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_min
    << std::setfill('0') <<  std::setw(2) << gmtm->tm_sec << "] ";
}

/* Faz um deposito */
void Account::makeDeposit( int deposit )
{
	int inicial;
	
	_displayTimestamp();
	inicial = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << inicial \
		<< ";deposit:" << deposit \
		<< ";amount:" << this->_amount \
		<< ";nb_deposits:" << this->_nbDeposits \
		<< "\n";
}

/* Executa um withdrawal */
bool Account::makeWithdrawal( int withdrawal )
{	
	int inicial;

	_displayTimestamp();
	inicial = this->_amount;
	std::cout << "index:" << this->_accountIndex \
		<< ";p_amount:" << inicial;
	if (withdrawal <= this->_amount)
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
			this->_nbWithdrawals += 1;
		this->_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal \
		<< ";amount:" << this->_amount \
		<< ";nb_withdrawals:" << this->_nbWithdrawals \
		<< "\n";
		return (true);
	}
	std::cout << ";withdrawal:" << "refused" \
	<< "\n";
	return (false);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}