#include <filesystem>
#include <database/lodgingRepositoryXML.h>

const char * ROOTLODGIN = "lodgins";

using namespace tinyxml2;

LodgingRepositoryXML::LodgingRepositoryXML(const std::string & path) : 
    LodgingRepository( path )
{
    initRepository();
}

void LodgingRepositoryXML::createLodging(const Lodging & lodging) const 
{


    XMLDocument doc;
    doc.LoadFile(m_path.c_str());

    XMLElement* rootXML = doc.FirstChildElement(ROOTLODGIN);


    XMLElement * lodgingXML = doc.NewElement("lodging");

    lodgingXML->SetAttribute("id", lodging.id());
    lodgingXML->SetAttribute("NanHostUser", lodging.NanHostUser().c_str());
    lodgingXML->SetAttribute("name", lodging.name().c_str());
    lodgingXML->SetAttribute("cityCode", lodging.cityCode().c_str());
    lodgingXML->SetAttribute("ubication", lodging.ubication().c_str());

    rootXML->InsertEndChild(lodgingXML);
        
    doc.LinkEndChild(rootXML);

    doc.SaveFile(m_path.c_str());

    
}

std::unique_ptr<Lodging> LodgingRepositoryXML::getLodging (size_t id) const
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(!doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" ))
        return nullptr;

    XMLElement* lodgingXML = doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" )->ToElement();
   

    for( lodgingXML; lodgingXML; lodgingXML=lodgingXML->NextSiblingElement() ){

        size_t actualId = atoi(lodgingXML->Attribute("id"));

        if(actualId == id){

            std::unique_ptr<Lodging> lodging = std::make_unique<Lodging>(actualId, lodgingXML->Attribute("NanHostUser"),lodgingXML->Attribute("name"), lodgingXML->Attribute("cityCode"), lodgingXML->Attribute("ubication"));
            return lodging;
        }

    }

    return nullptr;
}

void LodgingRepositoryXML::deleteLodging(size_t id) const
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" )){

        XMLNode* rootXML = doc.FirstChildElement(ROOTLODGIN)->ToElement();
        XMLElement* lodgingXML = doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" )->ToElement();

        for( lodgingXML; lodgingXML; lodgingXML=lodgingXML->NextSiblingElement() ){

            size_t actualId = atoi(lodgingXML->Attribute("id"));
            if(actualId == id){

                rootXML->DeleteChild(lodgingXML);

            }

        }

        doc.LinkEndChild(rootXML);

        doc.SaveFile(m_path.c_str());
    }
}

std::vector<std::unique_ptr<Lodging>> LodgingRepositoryXML::getLodgingList() const 
{
    std::vector<std::unique_ptr<Lodging>> lodgingList;

    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(!doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" ))
        return lodgingList;

    XMLElement* lodgingXML = doc.FirstChildElement(ROOTLODGIN)->FirstChildElement( "lodging" )->ToElement();
   

    for( lodgingXML; lodgingXML; lodgingXML=lodgingXML->NextSiblingElement() ){

        std::unique_ptr<Lodging> lodging = std::make_unique<Lodging>(atoi(lodgingXML->Attribute("id")), lodgingXML->Attribute("NanHostUser"), lodgingXML->Attribute("name"), lodgingXML->Attribute("cityCode"),lodgingXML->Attribute("ubication"));

        lodgingList.push_back(std::move(lodging));
    }

    return lodgingList;
}


void LodgingRepositoryXML::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        XMLDocument doc;
        XMLElement *rootXML = doc.NewElement(ROOTLODGIN);   
        doc.LinkEndChild(rootXML);        
        doc.SaveFile(m_path.c_str());
    }

}