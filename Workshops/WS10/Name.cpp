#include <iostream>
#include <cstring>
#include "Name.h"
#include "Utils.h"

using namespace std;

namespace seneca {

   Name::Name() {}

   Name::Name(const char* name) {
      m_value = ut.allocAndCopy(name);
   }

   Name::Name(const Name& src) {
      m_value = ut.allocAndCopy(src.m_value);
   }

   Name& Name::operator=(const Name& src) {
      if (this != &src) {
         delete[] m_value;
         m_value = ut.allocAndCopy(src.m_value);
      }
      return *this;
   }

   Name::~Name() {
      delete[] m_value;
   }

   ostream& Name::display(ostream& os) const {
      if (m_value) os << m_value;
      return os;
   }

   ostream& operator<<(ostream& os, const Name& N) {
      return N.display(os);
   }

}
