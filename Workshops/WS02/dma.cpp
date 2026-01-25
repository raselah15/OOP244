#include "dma.h"
#include "cstr.h"

namespace seneca {

Samples* CreateSamples(const char* title) {
    Samples* s = new Samples;
    s->m_data = nullptr;
    s->m_size = 0;

    s->m_title = new char[strlen(title) + 1];
    strcpy(s->m_title, title);

    return s;
}

void append(int*& data, int size, const int appendedData[], int dataSize) {
    int* temp = new int[size + dataSize];

    for (int i = 0; i < size; i++)
        temp[i] = data[i];

    for (int i = 0; i < dataSize; i++)
        temp[size + i] = appendedData[i];

    delete[] data;
    data = temp;
}

void add(Samples& S, const int data[], int size) {
    if (S.m_data == nullptr) {
        S.m_data = new int[size];
        for (int i = 0; i < size; i++)
            S.m_data[i] = data[i];
        S.m_size = size;
    } else {
        append(S.m_data, S.m_size, data, size);
        S.m_size += size;
    }
}

void freemem(Samples*& s) {
    if (s) {
        delete[] s->m_title;
        delete[] s->m_data;
        delete s;
        s = nullptr;
    }
}

}


