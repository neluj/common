#include <database/repositoryXMLFact.h>
#include <database/userRepositoryXML.h>
#include <database/lodgingRepositoryXML.h>
#include <database/offerRepositoryXML.h>

std::shared_ptr<UserRepository>     RepositoryXMLFact::userRepository      () const
{
    return std::make_shared<UserRepositoryXML>();
}

std::shared_ptr<LodgingRepository> RepositoryXMLFact::lodgingRepository    () const
{
    return std::make_shared<LodgingRepositoryXML>();
}

std::shared_ptr<OfferRepository>    RepositoryXMLFact::offerRepository     () const
{
    return std::make_shared<OfferRepositoryXML>();
}
