#ifndef REPOSITORYCREATOR_H
#define REPOSITORYCREATOR_H

#include <database/repositoryTypes.h>
#include <database/repositoryJSONFact.h>
#include <database/repositoryXMLFact.h>
#include <unordered_map>

class RepositoryCreator{

public:

    std::shared_ptr<RepositoryAbstractFact> get_repository(const RepositoryType & repositoryType) const;

private:

// NOTE unordered_map
std::unordered_map<RepositoryType, std::shared_ptr<RepositoryAbstractFact>> m_repositories {
    {RepositoryType::JSON, std::make_shared<RepositoryJSONFact>()},
    {RepositoryType::XML, std::make_shared<RepositoryXMLFact>()}
};

};

#endif