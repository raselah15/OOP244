#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include <iostream>

namespace seneca {

   const int NameMaxLen = 40;

   class Account {
      char m_name[NameMaxLen + 1];
      int m_number;
      double m_balance;

      void setEmpty();
      bool validNumber(int number) const;
      bool validName(const char* name) const;

   public:
      Account();
      Account(const char* name);
      Account(const char* name, int number, double balance);

      std::ostream& display() const;

      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      operator char*();

      bool operator~() const;

      Account& operator=(int number);

      Account& operator+=(double amount);
      Account& operator-=(double amount);

      Account& operator<<(Account& from);
      Account& operator>>(Account& to);

      Account& operator++();
      Account operator++(int);
      Account& operator--();
      Account operator--(int);
   };

   double operator+(const Account& A, const Account& B);
   double operator+=(double& value, const Account& A);

}

#endif

