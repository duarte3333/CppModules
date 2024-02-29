#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _span;
        std::vector<int> values;
        bool sorted;
    public:
        Span();
        Span(unsigned i) { _span = i; sorted = false;}
        Span &operator=(const Span &src);
        Span(const Span &src) {*this = src;}
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        class SpanFullException: public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Span already full, cannot add any more numbers.";
            }
        };
        class NoSpanException: public std::exception {
        public:
            virtual const char *what() const throw() {
                return "Not enough numbers to determine a span";
            }
        };
       

};
//unsigned used alone without specifying a type, it implicitly refers to unsigned int.

#endif