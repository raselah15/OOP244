#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {

Numbers::~Numbers() {
   save();
   delete[] m_numbers;
   delete[] m_filename;
}

Numbers::Numbers(const Numbers& other) {
   setEmpty();
   m_isOriginal = false;

   if (!other.isEmpty()) {
      m_numCount = other.m_numCount;
      m_numbers = new double[m_numCount];

      for (size_t i = 0; i < m_numCount; i++)
         m_numbers[i] = other.m_numbers[i];
   }
}

Numbers& Numbers::operator=(const Numbers& other) {

   if (this != &other) {

      delete[] m_numbers;

      m_numCount = other.m_numCount;

      if (other.m_numbers) {
         m_numbers = new double[m_numCount];

         for (size_t i = 0; i < m_numCount; i++)
            m_numbers[i] = other.m_numbers[i];
      }
      else
         m_numbers = nullptr;
   }

   return *this;
}

size_t Numbers::numberCount() const {

   size_t count = 0;

   ifstream file(m_filename);
   char ch;

   while (file.get(ch))
      if (ch == '\n')
         count++;

   return count;
}

bool Numbers::load() {

   bool success = false;

   if (m_numCount > 0) {

      m_numbers = new double[m_numCount];

      ifstream file(m_filename);

      size_t i = 0;

      while (file && i < m_numCount) {

         file >> m_numbers[i];

         if (file)
            i++;
      }

      if (i == m_numCount)
         success = true;
      else {
         delete[] m_numbers;
         setEmpty();
      }
   }

   return success;
}

void Numbers::save() const {

   if (m_isOriginal && !isEmpty()) {

      ofstream file(m_filename);

      for (size_t i = 0; i < m_numCount; i++)
         file << m_numbers[i] << endl;
   }
}

Numbers& Numbers::operator+=(double value) {

   if (!isEmpty()) {

      double* temp = new double[m_numCount + 1];

      for (size_t i = 0; i < m_numCount; i++)
         temp[i] = m_numbers[i];

      m_numCount++;

      temp[m_numCount - 1] = value;

      delete[] m_numbers;

      m_numbers = temp;

      sort();
   }

   return *this;
}

ostream& Numbers::display(ostream& ostr) const {

   if (isEmpty()) {

      ostr << "Empty list";

   }
   else {

      ostr << fixed << setprecision(2);

      ostr << "=========================" << endl;

      if (m_isOriginal)
         ostr << m_filename << endl;
      else
         ostr << "*** COPY ***" << endl;

      for (size_t i = 0; i < m_numCount; i++) {

         ostr << m_numbers[i];

         if (i != m_numCount - 1)
            ostr << ", ";
      }

      ostr << endl;

      ostr << "-------------------------" << endl;

      ostr << "Total of " << m_numCount << " number(s)" << endl;

      ostr << "Largest number:  " << max() << endl;

      ostr << "Smallest number: " << min() << endl;

      ostr << "Average:         " << average() << endl;

      ostr << "=========================";
   }

   return ostr;
}

ostream& operator<<(ostream& os, const Numbers& N) {
   return N.display(os);
}

istream& operator>>(istream& istr, Numbers& N) {

   double value;

   istr >> value;

   if (istr)
      N += value;

   return istr;
}

}
