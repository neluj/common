#include <database/repositoryCreator.h>

std::shared_ptr<RepositoryAbstractFact> RepositoryCreator::get_repository(const RepositoryType & repositoryType) const
{
    return m_repositories.at(repositoryType);   
}
