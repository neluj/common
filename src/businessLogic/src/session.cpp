#include <businessLogic/session.h>


Session::Session(const RepositoryType & repoType)
{
    setRepositoryType(repoType);
}

void Session::setRepositoryType(const RepositoryType & repoType)
{
    RepositoryCreator repoCreator;
    m_repository = repoCreator.get_repository(repoType);
}

bool Session::createOffer(const Offer & offer) const
{
    
}

void Session::createLodging(const Lodging & lodging) const
{}

std::unique_ptr<Offer> Session::getOffers()
{}