#include <cstring>
#include "Utils.h"

namespace seneca {

   Utils ut;

   char* Utils::allocAndCopy(const char* src) const {
      char* str{};
      if (src) {
         str = new char[strlen(src) + 1];
         strcpy(str, src);
      }
      return str;
   }

}
