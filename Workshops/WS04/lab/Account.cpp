#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

namespace seneca {

   bool Account::isValid() const {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0 && m_holderName[0];
   }

   Account::Account(const char* name) {
      if (name && name[0]) {
         strcpy(m_holderName, name);
         m_number = 0;
         m_balance = 0.0;
      }
      else {
         m_number = -1;
         m_balance = 0.0;
         m_holderName[0] = 0;
      }
   }

   Account::Account(const char* name, int num, double bal) {
      if (name && name[0] && num >= 10000 && num <= 99999 && bal >= 0) {
         strcpy(m_holderName, name);
         m_number = num;
         m_balance = bal;
      }
      else {
         m_number = -1;
         m_balance = 0.0;
         m_holderName[0] = 0;
      }
   }

   ostream& Account::display() const {
      if (m_number == -1)
         cout << "Bad Account";
      else if (m_number == 0)
         cout << "New | " << m_holderName << " | " << m_balance;
      else
         cout << m_number << " | " << m_holderName << " | " << m_balance;
      return cout;
   }

   Account::operator bool() const { return isValid(); }
   Account::operator int() const { return m_number; }
   Account::operator double() const { return m_balance; }
   Account::operator const char*() const { return m_holderName; }

   char& Account::operator[](int index) {
      index %= NameMaxLen;
      return m_holderName[index];
   }

   const char Account::operator[](int index) const {
      index %= NameMaxLen;
      return m_holderName[index];
   }

   Account& Account::operator=(int number) {
      if (m_number == 0 && number >= 10000 && number <= 99999)
         m_number = number;
      else if (number < 10000 || number > 99999)
         m_number = -1;
      return *this;
   }

   Account& Account::operator=(double bal) {
      if (isValid() && bal >= 0)
         m_balance = bal;
      else if (bal < 0)
         m_number = -1;
      return *this;
   }

   Account& Account::operator+=(double val) {
      if (isValid() && val >= 0) m_balance += val;
      return *this;
   }

   Account& Account::operator-=(double val) {
      if (isValid() && val >= 0 && m_balance >= val) m_balance -= val;
      return *this;
   }

   Account& Account::operator<<(Account& other) {
      if (this != &other && isValid() && other.isValid()) {
         m_balance += other.m_balance;
         other.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& other) {
      if (this != &other && isValid() && other.isValid()) {
         other.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   bool Account::operator~() const { return m_number == 0; }

   Account& Account::operator++() { if (isValid()) m_balance++; return *this; }
   Account Account::operator++(int) { Account temp = *this; ++(*this); return temp; }

   Account& Account::operator--() { if (isValid() && m_balance >= 1) m_balance--; return *this; }
   Account Account::operator--(int) { Account temp = *this; --(*this); return temp; }

}

