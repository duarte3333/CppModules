#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria* inventory[4];
    public:
        MateriaSource();
        MateriaSource(std::string nameInput);
        ~MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(const MateriaSource &other);

        void learnMateria(AMateria* NewMateria);
        AMateria* createMateria(std::string const & type);
};
