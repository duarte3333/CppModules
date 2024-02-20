#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(Serializer const &src) {
    *this = src;
}

Serializer &Serializer::operator=(Serializer const &src) {
    (void)src;
    return *this;
}

// This function is used to serialize the pointer to the Data object
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}