#include <iostream>
#include <cstring>
#include "Transcript.h"

using namespace std;

namespace seneca {

   Transcript::Transcript(const char* name, unsigned int studentNumber)
      : Marks() {

      m_studentNumber = studentNumber;

      if (name) {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
   }

   Transcript::Transcript(const Transcript& src)
      : Marks(src) {

      m_studentNumber = src.m_studentNumber;

      if (src.m_name) {
         m_name = new char[strlen(src.m_name) + 1];
         strcpy(m_name, src.m_name);
      }
   }

   Transcript& Transcript::operator=(const Transcript& src) {
      if (this != &src) {

         Marks::operator=(src);

         delete[] m_name;
         m_name = nullptr;

         m_studentNumber = src.m_studentNumber;

         if (src.m_name) {
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
         }
      }
      return *this;
   }

   Transcript::~Transcript() {
      delete[] m_name;
   }

   ostream& Transcript::display(ostream& os) const {
      os << (m_name ? m_name : "No Name")
         << " (" << m_studentNumber << ")" << endl;

      os << "--------------------------------------------------------------------------" << endl;

      Marks::display(os);

      return os;
   }

}
