#include <iostream>
#include "io.h"
#include "cstr.h"

using namespace std;

namespace seneca {

   void read(char* name) {
      cout << "Name\n> ";
      cin.getline(name, 256);
   }

   bool read(PhoneRec& rec, FILE* fptr) {
      return fscanf(fptr, "%s %s %lld",
         rec.m_name,
         rec.m_lastName,
         &rec.m_phoneNumber) == 3;
   }

   void print(long long phoneNumber) {
      cout << "(" << phoneNumber / 10000000 << ") "
           << (phoneNumber / 10000) % 1000 << "-"
           << phoneNumber % 10000;
   }

   void print(const PhoneRec& rec, size_t& row, const char* filter) {
      bool match = true;

      if (filter && filter[0]) {
         match = strstr(rec.m_name, filter) ||
                 strstr(rec.m_lastName, filter);
      }

      if (match) {
         cout << row++ << ": "
              << rec.m_name << " "
              << rec.m_lastName << " ";
         print(rec.m_phoneNumber);
         cout << endl;
      }
   }

   void print(PhoneRec* recs[], size_t size, const char* filter) {
      size_t row = 1;
      for (size_t i = 0; i < size; i++) {
         print(*recs[i], row, filter);
      }
   }

   void setPointers(PhoneRec* recPtrs[], PhoneRec recs[], size_t size) {
      for (size_t i = 0; i < size; i++) {
         recPtrs[i] = &recs[i];
      }
   }

   void sort(PhoneRec* recPtrs[], size_t size, bool byLastName) {
      for (size_t i = 0; i < size - 1; i++) {
         for (size_t j = i + 1; j < size; j++) {
            if (byLastName) {
               if (strcmp(recPtrs[i]->m_lastName,
                          recPtrs[j]->m_lastName) > 0) {
                  PhoneRec* temp = recPtrs[i];
                  recPtrs[i] = recPtrs[j];
                  recPtrs[j] = temp;
               }
            } else {
               if (strcmp(recPtrs[i]->m_name,
                          recPtrs[j]->m_name) > 0) {
                  PhoneRec* temp = recPtrs[i];
                  recPtrs[i] = recPtrs[j];
                  recPtrs[j] = temp;
               }
            }
         }
      }
   }

}

