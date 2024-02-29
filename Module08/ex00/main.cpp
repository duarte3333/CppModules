#include "easyfind.hpp"
#include <vector>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec(arr, arr + 10);
    try{
        std::vector<int>::iterator find = easyfind(vec, 9);
        std::cout << *find << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}