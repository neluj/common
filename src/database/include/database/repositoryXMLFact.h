#ifndef REPOSITORYXMLFACT_H
#define REPOSITORYXMLFACT_H

#include <database/repositoryAbstractFact.h>

class RepositoryXMLFact : public RepositoryAbstractFact{

public:

    virtual std::shared_ptr<UserRepository>     userRepository      () const override;

    virtual std::shared_ptr<LodgingRepository> lodgingRepository    () const override;

    virtual std::shared_ptr<OfferRepository>   offerRepository      () const override;

};

#endif