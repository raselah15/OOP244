#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;

namespace seneca {

   void Account::setEmpty() {
      m_name[0] = '\0';
      m_number = -1;
      m_balance = 0.0;
   }

   bool Account::validNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }

   bool Account::validName(const char* name) const {
      return name && name[0] != '\0';
   }

   Account::Account() {
      m_name[0] = '\0';
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(const char* name) {
      if (validName(name)) {
         strncpy(m_name, name, NameMaxLen);
         m_name[NameMaxLen] = '\0';
         m_number = 0;
         m_balance = 0.0;
      }
      else {
         setEmpty();
      }
   }

   Account::Account(const char* name, int number, double balance) {
      if (validName(name) && validNumber(number) && balance >= 0) {
         strncpy(m_name, name, NameMaxLen);
         m_name[NameMaxLen] = '\0';
         m_number = number;
         m_balance = balance;
      }
      else {
         setEmpty();
      }
   }

   ostream& Account::display() const {
      if (*this) {
         cout << m_name << " | " << m_number << " | ";
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << m_balance;
      }
      else if (~*this) {
         cout << "NEW | " << m_balance;
      }
      else {
         cout << "BAD DATA";
      }
      return cout;
   }

   Account::operator bool() const {
      return m_number >= 10000 && m_number <= 99999;
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   Account::operator const char*() const {
      return m_name;
   }

   Account::operator char*() {
      return m_name;
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account& Account::operator=(int number) {
      if (~*this && validNumber(number)) {
         m_number = number;
      }
      else if (~*this) {
         m_number = -1;
      }
      return *this;
   }

   Account& Account::operator+=(double amount) {
      if (*this && amount > 0) m_balance += amount;
      return *this;
   }

   Account& Account::operator-=(double amount) {
      if (*this && amount > 0 && m_balance >= amount) m_balance -= amount;
      return *this;
   }

   Account& Account::operator<<(Account& from) {
      if (*this && from && this != &from) {
         m_balance += from.m_balance;
         from.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& to) {
      if (*this && to && this != &to) {
         to.m_balance += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator++() {
      if (*this) m_balance++;
      return *this;
   }

   Account Account::operator++(int) {
      Account temp = *this;
      ++(*this);
      return temp;
   }

   Account& Account::operator--() {
      if (*this && m_balance > 0) m_balance--;
      return *this;
   }

   Account Account::operator--(int) {
      Account temp = *this;
      --(*this);
      return temp;
   }

   double operator+(const Account& A, const Account& B) {
      double sum = 0;
      if (A) sum += (double)A;
      if (B) sum += (double)B;
      return sum;
   }

   double operator+=(double& value, const Account& A) {
      if (A) value += (double)A;
      return value;
   }

}

