#ifndef GENERATEDATAS_H
#define GENERATEDATAS_H

#include <database/repositoryTypes.h>

class User;
class Lodging;
class Offer;

class GenerateDatas{

public:

    void generate(const RepositoryType & repoType);

private:

    void printUser(const User & user) const;
    
    void printLodging(const Lodging & lodging) const;
    
    void printOffer(const Offer & offer) const;

};

#endif