#ifndef SENECA_CC_H
#define SENECA_CC_H

#include <iostream>
#include "cstr.h"

namespace seneca {

class CC {
    char* m_name{};
    unsigned long long m_number{};
    short m_cvv{};
    short m_expMonth{};
    short m_expYear{};

    void aloCopy(const char* name);
    void deallocate();
    bool validate(const char* name,
                  unsigned long long number,
                  short cvv,
                  short expMon,
                  short expYear) const;
    void prnNumber(unsigned long long ccnum) const;
    void display(const char* name,
                 unsigned long long number,
                 short expYear,
                 short expMon,
                 short cvv) const;

public:
    CC();
    CC(const char* name,
       unsigned long long number,
       short cvv,
       short expMon = 12,
       short expYear = 26);
    ~CC();

    void set();
    void set(const char* name,
             unsigned long long number,
             short cvv,
             short expMon,
             short expYear);
    bool isEmpty() const;
    void display() const;
};

}

#endif

