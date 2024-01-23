#include <fstream>
#include <iostream>
#include <filesystem>
#include <lodgingRepositoryJSON.h>

LodgingRepositoryJSON::LodgingRepositoryJSON(const std::string & path) : 
    LodgingRepository( path )
{
    initRepository();
}

void LodgingRepositoryJSON::createLodging(const Lodging & lodging) const 
{

	std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj(); 
    nlohmann::json jsonLodging = {{"id", lodging.id()}, {"NanHostUser", lodging.NanHostUser()}, {"name", lodging.name()}, {"cityCode", lodging.cityCode()}, {"ubication", lodging.ubication()}};
    
    baseJsonObj->push_back(jsonLodging);
    prettyPrint(*baseJsonObj);
        
}

std::unique_ptr<Lodging> LodgingRepositoryJSON::getLodging (size_t id) const 
{
    
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();

    for (auto& londgingJson : *baseJsonObj){

        if(londgingJson["id"] == id){  
            std::unique_ptr<Lodging> lodging = std::make_unique<Lodging>(londgingJson["id"], londgingJson["NanHostUser"], londgingJson["name"], londgingJson["cityCode"], londgingJson["ubication"]);
            return lodging;
        }
    }

    return nullptr;
}

void LodgingRepositoryJSON::deleteLodging(size_t id) const 
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    size_t counter{0};
    bool found{false};

    while(!found && counter<baseJsonObj->size()){
        auto& lodgingJson = baseJsonObj->at(counter);

        if(lodgingJson["id"] == id){
            found = true;
            baseJsonObj->erase(counter);
            prettyPrint(*baseJsonObj);
        }

        ++counter;
    }
}


std::vector<std::unique_ptr<Lodging>> LodgingRepositoryJSON::getLodgingList() const 
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    std::vector<std::unique_ptr<Lodging>> lodgingList;

    for (auto& londgingJson : *baseJsonObj){
 
        std::unique_ptr<Lodging> lodging = std::make_unique<Lodging>(londgingJson["id"],londgingJson["NanHostUser"], londgingJson["name"], londgingJson["cityCode"], londgingJson["ubication"]);
        lodgingList.push_back(std::move(lodging));
    }

    return lodgingList;
}

void LodgingRepositoryJSON::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        createBaseElements();
    }
}


void LodgingRepositoryJSON::createBaseElements() const
{
    nlohmann::json baseJsonObj = {};
    prettyPrint(baseJsonObj);
}

void LodgingRepositoryJSON::prettyPrint(const nlohmann::json & jsonObj) const
{
    std::ofstream repositoryFile(m_path);
    repositoryFile << std::setw(4) << jsonObj << std::endl;
    repositoryFile.close();
}

std::unique_ptr<nlohmann::json> LodgingRepositoryJSON::getJsonBaseObj() const
{
        std::fstream  fileR(m_path);
	    std::unique_ptr<nlohmann::json> baseJsonObj = std::make_unique<nlohmann::json>(nlohmann::json::parse(fileR));
        fileR.close();

        return baseJsonObj;
}

