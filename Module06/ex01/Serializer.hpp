#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer {
    Serializer();
    ~Serializer();
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &src);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif