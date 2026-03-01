#include <iostream>
#include <iomanip>
#include "Mark.h"

using namespace std;

namespace seneca {

   Mark::Mark(double value, char type) {
      if (value >= 0 && value <= 100)
         m_value = value;
      else
         m_value = -1;

      m_type = type;
   }

   bool Mark::isValid() const {
      return m_value >= 0 && m_value <= 100;
   }

   // RAW integer
   Mark::operator int() const {
      return int(m_value + 0.5);
   }

   // RAW double (NOT GPA)
   Mark::operator double() const {
      return m_value;
   }

   Mark::operator const char*() const {
      if (!isValid()) return "";

      if (m_value < 50) return "F";
      if (m_value < 55) return "D";
      if (m_value < 60) return "D+";
      if (m_value < 65) return "C";
      if (m_value < 70) return "C+";
      if (m_value < 75) return "B";
      if (m_value < 80) return "B+";
      if (m_value < 90) return "A";
      return "A+";
   }

   Mark::operator bool() const {
      return isValid();
   }

   Mark& Mark::operator+=(double value) {
      if (isValid()) {
         m_value += value;
         if (m_value > 100)
            m_value = -1;
      }
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = type;
      return *this;
   }

   ostream& Mark::display(ostream& os) const {

      if (!isValid()) {
         if (m_type == GRADE)
            os << "**";
         else
            os << "***";
      }
      else if (m_type == GPA) {
         os << fixed << setprecision(1)
            << setw(3) << (m_value / 25.0);
      }
      else if (m_type == MARK) {
         os << right << setfill('_')
            << setw(3) << int(*this);
      }
      else if (m_type == GRADE) {
         os << left << setw(3)
            << (const char*)(*this);
      }

      os << setfill(' ');
      return os;
   }

   ostream& display(const Mark& M, char type, ostream& os) {

      Mark temp = M;
      temp = MARK;
      temp.display(os);

      if (type != MARK) {
         os << ": ";
         temp = type;
         temp.display(os);
      }

      return os;
   }

   ostream& operator<<(ostream& os, const Mark& M) {
      return M.display(os);
   }

   istream& operator>>(istream& is, Mark& M) {

      int value;
      char ch;

      while (true) {

         if (!(is >> value)) {
            cout << "Invalid integer, try again.\n> ";
            is.clear();
            is.ignore(1000, '\n');
         }
         else {
            ch = is.get();

            if (ch != '\n') {
               cout << "Invalid trailing characters. Please enter only an integer.\n> ";
               is.ignore(1000, '\n');
            }
            else if (value < 0 || value > 100) {
               cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            }
            else {
               M = Mark(value);
               break;
            }
         }
      }

      return is;
   }

   ifstream& operator>>(ifstream& ifs, Mark& M) {
      int value;
      char comma, type;

      ifs >> value >> comma >> type;

      if (ifs) {
         if (type == 'M')
            M = Mark(value, MARK);
         else if (type == 'G')
            M = Mark(value, GPA);
         else if (type == 'R')
            M = Mark(value, GRADE);
      }

      return ifs;
   }

   double operator+(double left, const Mark& right) {
      return left + double(right);
   }

   int operator+(int left, const Mark& right) {
      return left + int(right);
   }

   double operator-(double left, const Mark& right) {
      return left - double(right);
   }

   int operator-(int left, const Mark& right) {
      return left - int(right);
   }

   double operator/(double left, const Mark& right) {
      return left / right.m_value;
   }

   int operator/(int left, const Mark& right) {
      return left / int(right.m_value + 0.5);
   }

}
