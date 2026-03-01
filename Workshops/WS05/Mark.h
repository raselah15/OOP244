#ifndef SENECA_MARK_H
#define SENECA_MARK_H

#include <iostream>
#include <fstream>

namespace seneca {

   const char MARK  = 'M';
   const char GRADE = 'G';
   const char GPA   = 'R';

   class Mark {
      double m_value{};
      char   m_type{ MARK };

   public:
      Mark(double value = 0, char type = MARK);

      bool isValid() const;

      operator int() const;
      operator double() const;
      operator const char*() const;
      operator bool() const;

      Mark& operator+=(double value);
      Mark& operator=(char type);

      std::ostream& display(std::ostream& os = std::cout) const;

      friend double operator/(double left, const Mark& right);
      friend int operator/(int left, const Mark& right);
   };

   std::ostream& display(const Mark& M, char type, std::ostream& os = std::cout);

   std::ostream& operator<<(std::ostream& os, const Mark& M);
   std::istream& operator>>(std::istream& is, Mark& M);
   std::ifstream& operator>>(std::ifstream& ifs, Mark& M);

   double operator+(double left, const Mark& right);
   int operator+(int left, const Mark& right);

   double operator-(double left, const Mark& right);
   int operator-(int left, const Mark& right);

}

#endif
