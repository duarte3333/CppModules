#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const AbsAnimal* j = new Dog();
    const AbsAnimal* i = new Cat();
    //const AbsAnimal* s = new AbsAnimal(); Para testar classe abstrata 

    //const AbsAnimal* 
    delete j;//should not create a leak
    delete i;

    std::cout << "-----------------" << std::endl;
    AbsAnimal* arrayAbsAnimals[10];
    //AbsAnimal.makeSound();

    for (int i = 0; i < 5; i++){
        arrayAbsAnimals[i] = new Dog();
        std::cout << "-" << std::endl;

    }
    for (int i = 5; i < 10; i++){
        arrayAbsAnimals[i] = new Cat();
        std::cout << "-" << std::endl;
    }

    for (int i = 9; i >= 0; i--){
        arrayAbsAnimals[i]->makeSound();
        delete arrayAbsAnimals[i];
    }

    std::cout << "-----------------" << std::endl;

    Dog cao1;
    //AbsAnimal cao2;
    //cao2 = cao1;

    cao1.makeSound(); 
    //cao2.makeSound();

    std::cout << "-----------------" << std::endl;

    //Check deep copy
    const Dog* dog = new Dog();
    //const AbsAnimal* dog2 = new Dog(*dog);

    //dog->makeSound();
    //dog2->makeSound();

    delete dog;
    //delete dog2;

    return 0;
}