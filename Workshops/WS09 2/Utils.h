#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {

   class Utils {
   public:
      char* allocAndCopy(const char* src) const;
   };

   extern Utils ut;

}

#endif
