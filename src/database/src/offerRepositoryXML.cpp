#include <filesystem>
#include <database/offerRepositoryXML.h>

using namespace tinyxml2;

const char * ROOTOFFERS = "offers";

OfferRepositoryXML::OfferRepositoryXML(const std::string & path) : 
    OfferRepository( path )
{
    initRepository();
}

void OfferRepositoryXML::createOffer(const Offer & offer) const 
{

    XMLDocument doc;
    doc.LoadFile(m_path.c_str());

    XMLElement* rootXML = doc.FirstChildElement(ROOTOFFERS);

    XMLElement * offerXML = doc.NewElement("offer");

    offerXML->SetAttribute("id", offer.id());
    offerXML->SetAttribute("lodgingId", offer.lodgingId());
    offerXML->SetAttribute("startDate", offer.startDate().c_str());
    offerXML->SetAttribute("endDate", offer.endDate().c_str());
    offerXML->SetAttribute("price", offer.price());
    offerXML->SetAttribute("NanClientUser", offer.NanClientUser().c_str());

    rootXML->InsertEndChild(offerXML);
        
    doc.LinkEndChild(rootXML);
    doc.SaveFile(m_path.c_str());
   
}

std::unique_ptr<Offer> OfferRepositoryXML::getOffer(size_t id) const
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(!doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" ))
        return nullptr;

    XMLElement* offerXML = doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" )->ToElement();
   

    for( offerXML; offerXML; offerXML=offerXML->NextSiblingElement() ){

        size_t actualId = atoi(offerXML->Attribute("id"));

        if(actualId == id){

            return std::make_unique<Offer>(actualId, atoi(offerXML->Attribute("lodgingId")), offerXML->Attribute("startDate"), offerXML->Attribute("endDate"), atoi(offerXML->Attribute("price")), offerXML->Attribute("NanClientUser"));
        }

    }

    return nullptr;    
}

void OfferRepositoryXML::deleteOffer(size_t id) const 
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" )){

        XMLNode* rootXML = doc.FirstChildElement(ROOTOFFERS)->ToElement();
        XMLElement* offerXML = doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" )->ToElement();

        for( offerXML; offerXML; offerXML=offerXML->NextSiblingElement() ){

            size_t actualId = atoi(offerXML->Attribute("id"));
            if(actualId == id){

                rootXML->DeleteChild(offerXML);

            }

        }

        doc.LinkEndChild(rootXML);

        doc.SaveFile(m_path.c_str());
    }
}

std::vector<std::unique_ptr<Offer>> OfferRepositoryXML::getOfferList() const 
{
    std::vector<std::unique_ptr<Offer>> offerList;

    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(!doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" ))
        return offerList;

    XMLElement* offerXML = doc.FirstChildElement(ROOTOFFERS)->FirstChildElement( "offer" )->ToElement();
   

    for( offerXML; offerXML; offerXML=offerXML->NextSiblingElement() ){

        std::unique_ptr<Offer> offer = std::make_unique<Offer>(atoi(offerXML->Attribute("id")), atoi(offerXML->Attribute("lodgingId")), offerXML->Attribute("startDate"),
                                                             offerXML->Attribute("endDate"), atoi(offerXML->Attribute("price")),offerXML->Attribute("NanClientUser"));

        offerList.push_back(std::move(offer));
    }

    return offerList;

}

void OfferRepositoryXML::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        XMLDocument doc;
        XMLElement *rootXML = doc.NewElement(ROOTOFFERS);   
        doc.LinkEndChild(rootXML);        
        doc.SaveFile(m_path.c_str());
    }

}

