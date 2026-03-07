#include <iostream>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {

bool Numbers::isEmpty() const {
   return m_numbers == nullptr;
}

void Numbers::setEmpty() {
   m_numbers = nullptr;
   m_filename = nullptr;
   m_numCount = 0;
}

void Numbers::setFilename(const char* filename) {
   delete[] m_filename;
   m_filename = new char[strlen(filename) + 1];
   strcpy(m_filename, filename);
}

void Numbers::sort() {

   for (size_t i = 0; i < m_numCount; i++)
      for (size_t j = i + 1; j < m_numCount; j++)
         if (m_numbers[i] > m_numbers[j]) {
            double temp = m_numbers[i];
            m_numbers[i] = m_numbers[j];
            m_numbers[j] = temp;
         }
}

double Numbers::max() const {

   double m = m_numbers[0];

   for (size_t i = 1; i < m_numCount; i++)
      if (m < m_numbers[i])
         m = m_numbers[i];

   return m;
}

double Numbers::min() const {

   double m = m_numbers[0];

   for (size_t i = 1; i < m_numCount; i++)
      if (m > m_numbers[i])
         m = m_numbers[i];

   return m;
}

double Numbers::average() const {

   double sum = 0;

   for (size_t i = 0; i < m_numCount; i++)
      sum += m_numbers[i];

   return sum / m_numCount;
}

Numbers::Numbers() {
   setEmpty();
   m_isOriginal = false;
}

Numbers::Numbers(const char* filename) {

   setEmpty();
   m_isOriginal = true;

   setFilename(filename);

   m_numCount = numberCount();

   if (m_numCount > 0) {

      if (load())
         sort();
      else {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false;
      }
   }
}

}
