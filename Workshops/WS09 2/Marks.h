#ifndef SENECA_MARKS_H
#define SENECA_MARKS_H

#include <iostream>

namespace seneca {

   class Mark {
      char* m_title{};
      int m_mark{};

   public:
      Mark();
      Mark(const char* title, int mark);
      Mark(const Mark& src);
      Mark& operator=(const Mark& src);
      ~Mark();

      const char* title() const;
      int mark() const;
   };

   class Marks {
      Mark* m_marks{};
      int m_count{};

   public:
      Marks();
      Marks(const Marks& src);
      Marks& operator=(const Marks& src);
      virtual ~Marks();

      Marks& addMark(const char* title, int mark);
      Mark& operator[](int index) const;

      virtual std::ostream& display(std::ostream& os) const;
   };

   std::ostream& operator<<(std::ostream& os, const Marks& M);

}

#endif

