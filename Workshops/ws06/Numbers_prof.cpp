#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;

namespace seneca {

double Numbers::average() const {
   double avg = 0.0;
   for (size_t i = 0; i < m_numCount; i++) {
      avg += m_numbers[i];
   }
   return avg / m_numCount;
}

double Numbers::min() const {
   double minVal = m_numbers[0];
   for (size_t i = 1; i < m_numCount; i++) {
      if (m_numbers[i] < minVal)
         minVal = m_numbers[i];
   }
   return minVal;
}

double Numbers::max() const {
   double maxVal = m_numbers[0];
   for (size_t i = 1; i < m_numCount; i++) {
      if (m_numbers[i] > maxVal)
         maxVal = m_numbers[i];
   }
   return maxVal;
}

}
