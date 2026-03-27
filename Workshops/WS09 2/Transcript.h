#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H

#include "Marks.h"

namespace seneca {

   class Transcript : public Marks {
      char* m_name{};
      unsigned int m_studentNumber{};

   public:
      Transcript(const char* name = nullptr, unsigned int studentNumber = 0);
      Transcript(const Transcript& src);
      Transcript& operator=(const Transcript& src);
      ~Transcript();

      std::ostream& display(std::ostream& os) const override;
   };

}

#endif
