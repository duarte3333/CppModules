#ifndef ICE_HPP
#define ICE_HPP

class Ice
{
    protected:
        std::string materiaType;
    public:
        Ice();
        Ice(const Ice &other); 
        Ice& operator=(const Ice &other);
        ~Ice();
        Ice(std::string const & type);

        Ice* clone() const;
        void use(ICharacter& target);
};

#endif
