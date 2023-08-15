#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "-----------------" << std::endl;
    Animal* arrayAnimals[10];

    for (int i = 0; i < 5; i++){
        arrayAnimals[i] = new Dog();
        std::cout << "-" << std::endl;

    }
    for (int i = 5; i < 10; i++){
        arrayAnimals[i] = new Cat();
        std::cout << "-" << std::endl;
    }

    for (int i = 9; i >= 0; i--){
        arrayAnimals[i]->makeSound();
        delete arrayAnimals[i];
    }

    std::cout << "-----------------" << std::endl;

    //Check deep copy
    const Dog* dog = new Dog();
    const Animal* dog2 = new Dog(*dog);

    dog->makeSound();
    dog2->makeSound();

    delete dog;
    delete dog2;

    return 0;
}