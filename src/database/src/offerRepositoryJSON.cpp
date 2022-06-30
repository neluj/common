#include <fstream>
#include <iostream>
#include <filesystem>
#include <database/offerRepositoryJSON.h>



OfferRepositoryJSON::OfferRepositoryJSON(const std::string & path) : 
    OfferRepository( path )
{
    initRepository();
}


void OfferRepositoryJSON::createOffer(const Offer & offer) const
{

	std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    nlohmann::json jsonOffer= {{"id", offer.id()}, {"lodgingId", offer.lodgingId()}, {"startDate", offer.startDate()},{"endDate", offer.endDate()}, {"price", offer.price()}, {"NanClientUser", offer.NanClientUser()}};
    baseJsonObj->push_back(jsonOffer);
    prettyPrint(*baseJsonObj);            
}

std::unique_ptr<Offer> OfferRepositoryJSON::getOffer(size_t id) const
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();

    for (auto& offerJson : *baseJsonObj){

        if(offerJson["id"] == id){  
            std::unique_ptr<Offer> offer = std::make_unique<Offer>(id, offerJson["lodgingId"], offerJson["startDate"], offerJson["endDate"], offerJson["price"], offerJson["NanClientUser"]);
            return offer;
        }

    }

    return nullptr;    
}

void OfferRepositoryJSON::deleteOffer(size_t id) const
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    size_t counter{0};
    bool found{false};

    while(!found && counter<baseJsonObj->size()){
        auto& offerJson = baseJsonObj->at(counter);

        if(offerJson["id"] == id){
            found = true;
            baseJsonObj->erase(counter);
            prettyPrint(*baseJsonObj);
        }

        ++counter;
    }
}

std::vector<std::unique_ptr<Offer>> OfferRepositoryJSON::getOfferList() const
{
    std::unique_ptr<nlohmann::json> baseJsonObj = getJsonBaseObj();
    std::vector<std::unique_ptr<Offer>> offerList;

    for (auto& offerJson : *baseJsonObj){
 
        std::unique_ptr<Offer> offer = std::make_unique<Offer>(offerJson["id"], offerJson["lodgingId"], offerJson["startDate"], 
                                                                offerJson["endDate"], offerJson["price"],offerJson["NanClientUser"]);
        offerList.push_back(std::move(offer));
    }

    return offerList;
}

void OfferRepositoryJSON::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        createBaseElements();
    }
}


void OfferRepositoryJSON::createBaseElements() const
{
    nlohmann::json baseJsonObj = {};
    prettyPrint(baseJsonObj);
}

void OfferRepositoryJSON::prettyPrint(const nlohmann::json & jsonObj) const
{
    std::ofstream repositoryFile(m_path);
    repositoryFile << std::setw(4) << jsonObj << std::endl;
    repositoryFile.close();
}

std::unique_ptr<nlohmann::json> OfferRepositoryJSON::getJsonBaseObj() const
{
        std::fstream  fileR(m_path);
	    std::unique_ptr<nlohmann::json> baseJsonObj = std::make_unique<nlohmann::json>(nlohmann::json::parse(fileR));
        fileR.close();

        return baseJsonObj;
}
