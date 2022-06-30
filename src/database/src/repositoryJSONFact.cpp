#include <database/repositoryJSONFact.h>
#include <database/userRepositoryJSON.h>
#include <database/lodgingRepositoryJSON.h>
#include <database/offerRepositoryJSON.h>

std::shared_ptr<UserRepository> RepositoryJSONFact::userRepository() const
{
    return std::make_shared<UserRepositoryJSON>();
}

std::shared_ptr<LodgingRepository> RepositoryJSONFact::lodgingRepository() const
{
    return std::make_shared<LodgingRepositoryJSON>();
}

std::shared_ptr<OfferRepository> RepositoryJSONFact::offerRepository() const
{
    return std::make_shared<OfferRepositoryJSON>();
}
