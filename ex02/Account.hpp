#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class Account {

	private:

		static int	_nbAccounts;
		static int	_totalAmount;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		static void	_displayTimestamp( void ){
			std::time_t now = std::time(NULL);
			std::tm*    t   = std::localtime(&now);
			std::cout
			<< "["
			<< t->tm_year + 1900
			<< std::setw(2) << std::setfill('0') << t->tm_mon + 1
			<< std::setw(2) << std::setfill('0') << t->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << t->tm_hour
			<< std::setw(2) << std::setfill('0') << t->tm_min
			<< std::setw(2) << std::setfill('0') << t->tm_sec
			<< "] ";
		}

		int				_accountIndex;
		int				_amount;
		int				_nbDeposits;
		int				_nbWithdrawals;

		Account( void );

	public:

		typedef Account		t;
		
		static int	getNbAccounts( void );
		static int	getTotalAmount( void );
		static int	getNbDeposits( void );
		static int	getNbWithdrawals( void );
		static void	displayAccountsInfos( void );
		Account( int initial_deposit );
		~Account( void );
		void	makeDeposit( int deposit );
		bool	makeWithdrawal( int withdrawal );
		int		checkAmount( void ) const;
		void	displayStatus( void ) const;


};

#endif
