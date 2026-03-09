#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
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

size_t Numbers::numberCount() const {
   ifstream file(m_filename);
   size_t count = 0;
   double temp;

   while (file >> temp) {
      count++;
   }

   return count;
}

void Numbers::sort() {
   for (size_t i = 0; i < m_numCount; i++) {
      for (size_t j = i + 1; j < m_numCount; j++) {
         if (m_numbers[i] > m_numbers[j]) {
            double temp = m_numbers[i];
            m_numbers[i] = m_numbers[j];
            m_numbers[j] = temp;
         }
      }
   }
}

bool Numbers::load() {
   ifstream file(m_filename);
   if (!file) return false;

   m_numbers = new double[m_numCount];

   for (size_t i = 0; i < m_numCount; i++) {
      file >> m_numbers[i];
   }

   return true;
}

void Numbers::save() const {
   if (isEmpty() || !m_isOriginal) return;

   ofstream file(m_filename);

   for (size_t i = 0; i < m_numCount; i++) {
      file << m_numbers[i] << endl;
   }
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

Numbers::Numbers(const Numbers& src) {
   setEmpty();
   *this = src;
}

Numbers::~Numbers() {
   save();
   delete[] m_numbers;
   delete[] m_filename;
}

Numbers& Numbers::operator=(const Numbers& src) {
   if (this != &src) {

      delete[] m_numbers;
      delete[] m_filename;

      m_numCount = src.m_numCount;
      m_isOriginal = false;

      if (src.m_filename) {
         m_filename = new char[strlen(src.m_filename) + 1];
         strcpy(m_filename, src.m_filename);
      }

      if (src.m_numbers) {
         m_numbers = new double[m_numCount];
         for (size_t i = 0; i < m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
         }
      }
   }

   return *this;
}

Numbers& Numbers::operator+=(double value) {

   double* temp = new double[m_numCount + 1];

   for (size_t i = 0; i < m_numCount; i++) {
      temp[i] = m_numbers[i];
   }

   temp[m_numCount] = value;

   delete[] m_numbers;
   m_numbers = temp;

   m_numCount++;

   sort();

   return *this;
}

ostream& Numbers::display(ostream& os) const {

   if (isEmpty()) {
      os << "Empty list";
   }
   else {

      os << "=========================" << endl;

      for (size_t i = 0; i < m_numCount; i++) {
         os << m_numbers[i] << endl;
      }

      os << "-------------------------" << endl;
      os << "Total numbers: " << m_numCount << endl;
      os << "Average: " << average() << endl;
      os << "Minimum: " << min() << endl;
      os << "Maximum: " << max() << endl;
      os << "=========================" << endl;
   }

   return os;
}

ostream& operator<<(ostream& os, const Numbers& N) {
   return N.display(os);
}

istream& operator>>(istream& is, Numbers& N) {
   double value;
   is >> value;
   N += value;
   return is;
}

}
