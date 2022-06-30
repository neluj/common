#ifndef REPOSITORYFACT_H
#define REPOSITORYFACT_H

#include <database/userRepository.h>
#include <database/lodgingRepository.h>
#include <database/offerRepository.h>
#include <string>
#include <memory>


class RepositoryAbstractFact{

public:

    virtual ~RepositoryAbstractFact() = default;

    virtual std::shared_ptr<UserRepository>     userRepository      () const = 0;

    virtual std::shared_ptr<LodgingRepository> lodgingRepository    () const = 0;

    virtual std::shared_ptr<OfferRepository>    offerRepository     () const = 0;

};
#endif