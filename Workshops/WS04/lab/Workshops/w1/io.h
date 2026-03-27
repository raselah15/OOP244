#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstddef>
#include <cstdio>

namespace seneca {

   struct PhoneRec {
      char m_name[16];
      char m_lastName[26];
      long long m_phoneNumber;
   };

   void read(char* name);
   bool read(PhoneRec& rec, FILE* fptr);

   void print(long long phoneNumber);
   void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);
   void print(PhoneRec* recs[], size_t size, const char* filter = nullptr);

   void setPointers(PhoneRec* recPtrs[], PhoneRec recs[], size_t size);
   void sort(PhoneRec* recPtrs[], size_t size, bool byLastName);

}

#endif // !SENECA_IO_H

