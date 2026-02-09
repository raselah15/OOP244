#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

namespace seneca {

   Account::Account() {
      m_holderName[0] = '\0';
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(const char* name) {
      if (name && name[0]) {
         strncpy(m_holderName, name, NameMaxLen);
         m_holderName[NameMaxLen] = '\0';
         m_number = 0;
         m_balance = 0.0;
      }
      else {
         m_holderName[0] = '\0';
         m_number = -1;
         m_balance = 0.0;
      }
   }

   Account::Account(const char* name, int number, double balance) {
      if (name && name[0] && number >= 10000 && number <= 99999 && balance >= 0) {
         strncpy(m_holderName, name, NameMaxLen);
         m_holderName[NameMaxLen] = '\0';
         m_number = number;
         m_balance = balance;
      }
      else {
         m_holderName[0] = '\0';
         m_number = -1;
         m_balance = 0.0;
      }
   }

   ostream& Account::display() const {
      if (m_number == -1) {
         cout << "Bad Account";
      }
      else {
         cout << m_holderName << " | " << m_number << " | " << m_balance;
      }
      return cout;
   }

   Account::operator bool() const { return m_number >= 10000 && m_number <= 99999; }
   Account::operator int() const { return m_number; }
   Account::operator double() const { return m_balance; }
   Account::operator const char*() const { return m_holderName; }

   char& Account::operator[](int i) { return m_holderName[i % NameMaxLen]; }
   const char Account::operator[](int i) const { return m_holderName[i % NameMaxLen]; }

   Account& Account::operator=(int num) {
      if (m_number == 0 && num >= 10000 && num <= 99999) m_number = num;
      else if (num < 10000 || num > 99999) m_number = -1;
      return *this;
   }

   Account& Account::operator=(double bal) {
      if (bal >= 0) m_balance = bal;
      else m_number = -1;
      return *this;
   }

   Account& Account::operator+=(double v) {
      if (*this && v >= 0) m_balance += v;
      return *this;
   }

   Account& Account::operator-=(double v) {
      if (*this && v >= 0 && m_balance >= v) m_balance -= v;
      return *this;
   }

   Account& Account::operator<<(Account& from) {
      if (this != &from && *this && from) {
         m_balance += from.m_balance;
         from.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& to) {
      if (this != &to && *this && to) {
         to.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   bool Account::operator~() const { return m_number == 0; }

   Account& Account::operator++() { if (*this) m_balance += 1; return *this; }
   Account Account::operator++(int) { Account temp = *this; if (*this) m_balance += 1; return temp; }
   Account& Account::operator--() { if (*this && m_balance >= 1) m_balance -= 1; return *this; }
   Account Account::operator--(int) { Account temp = *this; if (*this && m_balance >= 1) m_balance -= 1; return temp; }

}

