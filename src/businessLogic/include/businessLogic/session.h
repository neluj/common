#ifndef SESSION_H
#define SESSION_H

#include <domain/user.h>
#include <domain/lodging.h>
#include <domain/offer.h>
#include <database/repositoryTypes.h>
#include <businessLogic/findLodgingByOfferIDUC.h>
#include <businessLogic/findOffersByStartDateUC.h>
#include <businessLogic/hireOutUC.h>
#include <businessLogic/loginUC.h>
#include <businessLogic/createLodgingUC.h>
#include <businessLogic/createOfferUC.h>
#include <businessLogic/registerUC.h>
#include <database/repositoryCreator.h>

#include <memory>


class Session{ 
    
public:

    Session(const RepositoryType & repoType);

    void setRepositoryType(const RepositoryType & repoType);

    bool login(const User & user);

    std::unique_ptr<Offer> getOffers();


private:

    std::shared_ptr<User> m_sessionUser;

    std::shared_ptr<RepositoryAbstractFact> m_repository;

};

#endif