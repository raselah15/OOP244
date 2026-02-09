#include <iostream>
#include <cstring>
#include <iomanip>
#include "Account.h"

using namespace std;

namespace seneca {

   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
      m_holderName[0] = '\0';
   }

   Account::Account() {
      m_number = 0;
      m_balance = 0.0;
      m_holderName[0] = '\0';
   }

   Account::Account(const char* holderName) {
      if (holderName && holderName[0]) {
         strncpy(m_holderName, holderName, NameMaxLen);
         m_holderName[NameMaxLen] = '\0';
         m_number = 0;
         m_balance = 0.0;
      }
      else setEmpty();
   }

   Account::Account(const char* holderName, int number, double balance) {
      if (holderName && holderName[0] && number >= 10000 && number <= 99999 && balance >= 0) {
         strncpy(m_holderName, holderName, NameMaxLen);
         m_holderName[NameMaxLen] = '\0';
         m_number = number;
         m_balance = balance;
      }
      else setEmpty();
   }

   ostream& Account::display() const {
      if (m_number == -1) {
         cout << "| Bad Account                    | ----- | ------------ |";
      }
      else {
         cout << "| " << setw(30) << left << m_holderName << " | ";
         if (m_number == 0)
            cout << " NEW  | ";
         else
            cout << setw(5) << right << m_number << " | ";

         cout << setw(12) << fixed << setprecision(2) << right << m_balance << " |";
      }
      return cout;
   }

   Account::operator bool() const {
      return m_number >= 10000 && m_number <= 99999 && m_balance >= 0 && m_holderName[0];
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   Account::operator const char*() const {
      return m_holderName;
   }

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
         setEmpty();
      return *this;
   }

   Account& Account::operator=(double balance) {
      if (*this && balance >= 0)
         m_balance = balance;
      else if (balance < 0)
         setEmpty();
      return *this;
   }

   Account& Account::operator+=(double value) {
      if (*this && value > 0)
         m_balance += value;
      return *this;
   }

   Account& Account::operator-=(double value) {
      if (*this && value > 0 && m_balance >= value)
         m_balance -= value;
      return *this;
   }

   Account& Account::operator<<(Account& right) {
      if (this != &right && *this && right) {
         m_balance += right.m_balance;
         right.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& right) {
      if (this != &right && *this && right) {
         right.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account& Account::operator++() {
      if (*this) m_balance += 1;
      return *this;
   }

   Account Account::operator++(int) {
      Account temp = *this;
      if (*this) m_balance += 1;
      return temp;
   }

   Account& Account::operator--() {
      if (*this && m_balance >= 1) m_balance -= 1;
      return *this;
   }

   Account Account::operator--(int) {
      Account temp = *this;
      if (*this && m_balance >= 1) m_balance -= 1;
      return temp;
   }

}

