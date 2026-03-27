#include <iostream>
#include <cstring>
#include "Marks.h"
#include "Utils.h"

using namespace std;

namespace seneca {

   // -------- Mark --------
   Mark::Mark() {}

   Mark::Mark(const char* title, int mark) {
      m_title = ut.allocAndCopy(title);
      m_mark = mark;
   }

   Mark::Mark(const Mark& src) {
      m_title = ut.allocAndCopy(src.m_title);
      m_mark = src.m_mark;
   }

   Mark& Mark::operator=(const Mark& src) {
      if (this != &src) {
         delete[] m_title;
         m_title = ut.allocAndCopy(src.m_title);
         m_mark = src.m_mark;
      }
      return *this;
   }

   Mark::~Mark() {
      delete[] m_title;
   }

   const char* Mark::title() const {
      return m_title;
   }

   int Mark::mark() const {
      return m_mark;
   }

   // -------- Marks --------
   Marks::Marks() {}

   Marks::Marks(const Marks& src) {
      m_count = src.m_count;
      if (m_count > 0) {
         m_marks = new Mark[m_count];
         for (int i = 0; i < m_count; i++) {
            m_marks[i] = src.m_marks[i];
         }
      }
   }

   Marks& Marks::operator=(const Marks& src) {
      if (this != &src) {
         delete[] m_marks;

         m_count = src.m_count;
         if (m_count > 0) {
            m_marks = new Mark[m_count];
            for (int i = 0; i < m_count; i++) {
               m_marks[i] = src.m_marks[i];
            }
         } else {
            m_marks = nullptr;
         }
      }
      return *this;
   }

   Marks::~Marks() {
      delete[] m_marks;
   }

   Marks& Marks::addMark(const char* title, int mark) {
      Mark* temp = new Mark[m_count + 1];

      for (int i = 0; i < m_count; i++) {
         temp[i] = m_marks[i];
      }

      temp[m_count] = Mark(title, mark);

      delete[] m_marks;
      m_marks = temp;
      m_count++;

      return *this;
   }

   Mark& Marks::operator[](int index) const {
      return m_marks[index];
   }

   ostream& Marks::display(ostream& os) const {
      for (int i = 0; i < m_count; i++) {
         os.width(70);
         os.setf(ios::left);
         os << m_marks[i].title();
         os.unsetf(ios::left);
         os << m_marks[i].mark() << endl;
      }
      return os;
   }

   ostream& operator<<(ostream& os, const Marks& M) {
      return M.display(os);
   }

}
