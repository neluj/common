#include <fstream>
#include <iostream>
#include <filesystem>
#include <database/userRepositoryJSON.h>
#include <domain/user.h>


UserRepositoryJSON::UserRepositoryJSON(const std::string & path) : 
    UserRepository( path )
{
    initRepository();
}

void UserRepositoryJSON::createUser (const User & user) const 
{

	std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();

    nlohmann::json jsonUser = {{"nan", user.nan()}, {"name", user.name()}, {"surname", user.surname()}, {"email", user.email()}};

    baseJsonObj->push_back(jsonUser);
    prettyPrint(*baseJsonObj);
        
    
}

std::unique_ptr<User> UserRepositoryJSON::getUser (std::string nan) const 
{

    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();

    for (auto& userJson : *baseJsonObj){

        if(userJson["nan"] == nan){  
            std::unique_ptr<User> user = std::make_unique<User>(userJson["nan"], userJson["name"], userJson["surname"], userJson["email"]);
            return user;
        }

    }

    return nullptr;
}

void UserRepositoryJSON::deleteUser (std::string nan) const
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    size_t counter{0};
    bool found{false};

    while(!found && counter<baseJsonObj->size()){
        auto& userJson = baseJsonObj->at(counter);

        if(userJson["nan"] == nan){
            found = true;
            baseJsonObj->erase(counter);
            prettyPrint(*baseJsonObj);
        }

        ++counter;
    }

}

void UserRepositoryJSON::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        createBaseElements();
    }
}


void UserRepositoryJSON::createBaseElements() const
{
    nlohmann::json baseJsonObj = {};
    prettyPrint(baseJsonObj);
}

void UserRepositoryJSON::prettyPrint(const nlohmann::json & jsonObj) const
{
    std::ofstream repositoryFile(m_path);
    repositoryFile << std::setw(4) << jsonObj << std::endl;
    repositoryFile.close();
}

std::unique_ptr<nlohmann::json> UserRepositoryJSON::getJsonBaseObj() const
{
        std::fstream  fileR(m_path);
	    std::unique_ptr<nlohmann::json> baseJsonObj = std::make_unique<nlohmann::json>(nlohmann::json::parse(fileR));
        fileR.close();

        return baseJsonObj;
}



