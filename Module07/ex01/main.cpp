#include "iter.hpp"

class Awesome
{
    public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
    private:
    int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >

void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];
    iter( tab, 5, print );
    iter( tab2, 5, print );
    return 0;
}

// template <class T>
// void	increase(T *i)
// {
//     *i += 1;
// }

// template <class T>
// void	print_array(T *array, unsigned int lenght)
// {
//     for (unsigned int i = 0; i < lenght; i++)
//         std::cout << array[i] << " ";
//     std::cout << std::endl;
// }

// int	main()
// {
//     int	int_array[10];

//     for (unsigned int i = 0; i < 10; i++)
//         int_array[i] = i;

//     print_array(int_array, 10);
//     iter(int_array, 10, increase);
//     print_array(int_array, 10);

//     std::cout << std::endl << "----------------" << std::endl << std::endl;

//     char char_array[26];

//     for (unsigned int i = 0; i < 26; i++)
//         char_array[i] = i + 'a';

//     print_array(char_array, 26);
//     iter(char_array, 26, increase);
//     print_array(char_array, 26);
// }