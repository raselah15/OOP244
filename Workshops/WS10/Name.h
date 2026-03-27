#ifndef SENECA_NAME_H
#define SENECA_NAME_H

#include <iostream>

namespace seneca {

   class Name {
      char* m_value{};
   public:
      Name();
      Name(const char* name);
      Name(const Name& src);
      Name& operator=(const Name& src);
      ~Name();

      std::ostream& display(std::ostream& os) const;
   };

   std::ostream& operator<<(std::ostream& os, const Name& N);

}

#endif
