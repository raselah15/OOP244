#include <iostream>
#include "CC.h"
#include "cstr.h"

using namespace std;

namespace seneca {

   void CC::freeMem() {
      delete[] m_name;
      m_name = nullptr;
   }

   void CC::aloCopy(const char* name) {
      freeMem();
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }

   bool CC::validate(const char* name,
                     unsigned long long cardNo,
                     short cvv,
                     short expMon,
                     short expYear) const {
      return name && strlen(name) > 2 &&
             cardNo >= 4000000000000000ull &&
             cardNo <= 4099999999999999ull &&
             cvv >= 100 && cvv <= 999 &&
             expMon >= 1 && expMon <= 12 &&
             expYear >= 24 && expYear <= 32;
   }

   void CC::prnNumber(unsigned long long ccnum) const {
      cout << ccnum / 1000000000000ull << " ";
      ccnum %= 1000000000000ull;
      cout << ccnum / 100000000ull << " ";
      ccnum %= 100000000ull;
      cout << ccnum / 10000ull << " ";
      cout << ccnum % 10000ull;
   }

   void CC::display(const char* name,
                    unsigned long long number,
                    short expYear,
                    short expMon,
                    short cvv) const {
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   CC::CC() {
      set();
   }

   CC::CC(const char* name,
          unsigned long long number,
          short cvv,
          short expMon,
          short expYear) {
      set();
      set(name, number, cvv, expMon, expYear);
   }

   CC::~CC() {
      freeMem();
   }

   void CC::set() {
      freeMem();
      m_number = 0;
      m_cvv = 0;
      m_expMonth = 0;
      m_expYear = 0;
   }

   void CC::set(const char* name,
                unsigned long long number,
                short cvv,
                short expMon,
                short expYear) {
      set();
      if (validate(name, number, cvv, expMon, expYear)) {
         aloCopy(name);
         m_number = number;
         m_cvv = cvv;
         m_expMonth = expMon;
         m_expYear = expYear;
      }
   }

   bool CC::isEmpty() const {
      return m_name == nullptr;
   }

   void CC::display() const {
      if (isEmpty()) {
         cout << "Invalid Credit Card Record" << endl;
      } else {
         display(m_name, m_number, m_expYear, m_expMonth, m_cvv);
      }
   }

}
o

