#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include <iostream>

namespace seneca {

   const int NameMaxLen = 30;

   class Account {
      char m_holderName[NameMaxLen + 1];
      int m_number;
      double m_balance;

   public:
      Account();   // default constructor

      Account(const char* holderName);
      Account(const char* holderName, int number, double balance);

      std::ostream& display() const;

      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;

      char& operator[](int index);
      const char operator[](int index) const;

      Account& operator=(int number);
      Account& operator=(double balance);

      Account& operator+=(double value);
      Account& operator-=(double value);

      Account& operator<<(Account& from);
      Account& operator>>(Account& to);

      bool operator~() const;

      Account& operator++();
      Account operator++(int);
      Account& operator--();
      Account operator--(int);
   };

}

#endif

