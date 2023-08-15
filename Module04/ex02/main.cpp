#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //const Animal* test = new Animal();
    const AbsAnimal* j = new Dog();
    const AbsAnimal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout << "-----------------" << std::endl;
    AbsAnimal* arrayAnimals[10];

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

    std::cout << "------IDEAS------" << std::endl;
    
    Dog* bonito = new Dog();
    Dog* tmp2 = new Dog(*bonito);

    bonito->showBrainIdea(5);
    tmp2->showBrainIdea(5);

    bonito->setBrainIdea("bonito thinks he is pretty", 5);
    bonito->showBrainIdea(5);
    tmp2->setBrainIdea("tmp2 thinks he is earth is flat", 5);
    tmp2->showBrainIdea(5);
    
    delete bonito;
    delete tmp2;

    std::cout << "------------" << std::endl;

    std::cout << "Dog Deep copy" << std::endl;
    std::cout << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "------------" << std::endl;

    std::cout << "Testing Deep copy" << std::endl;
    std::cout << std::endl;

    Cat test2;
    {
        Cat temp2 = test2;
    }

    std::cout << "----------------" << std::endl;

    return 0;
}