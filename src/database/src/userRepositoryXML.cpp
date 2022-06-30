#include <filesystem>
#include <database/userRepositoryXML.h>
#include <domain/user.h>

const char * ROOTUSER = "users";

using namespace tinyxml2;

UserRepositoryXML::UserRepositoryXML(const std::string & path) : 
    UserRepository( path )
{
    initRepository();
}

void UserRepositoryXML::createUser (const User & user) const 
{


    XMLDocument doc;
    doc.LoadFile(m_path.c_str());

    XMLElement* rootXML = doc.FirstChildElement(ROOTUSER);

    XMLElement * userXML = doc.NewElement("user");

    userXML->SetAttribute("nan", user.nan().c_str());
    userXML->SetAttribute("name", user.name().c_str());
    userXML->SetAttribute("surname", user.surname().c_str());
    userXML->SetAttribute("email", user.email().c_str());

    rootXML->InsertEndChild(userXML);
        
    doc.LinkEndChild(rootXML);

    doc.SaveFile(m_path.c_str());

    
}

std::unique_ptr<User> UserRepositoryXML::getUser (std::string nan) const 
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(!doc.FirstChildElement(ROOTUSER)->FirstChildElement( "user" ))
        return nullptr;

    XMLElement* userXML = doc.FirstChildElement(ROOTUSER)->FirstChildElement( "user" )->ToElement();
   

    for( userXML; userXML; userXML=userXML->NextSiblingElement() ){

        std::string actualNan = userXML->Attribute("nan");

        if(actualNan == nan){

            std::unique_ptr<User> user = std::make_unique<User>(actualNan, userXML->Attribute("name"), userXML->Attribute("surname"), userXML->Attribute("email"));
            return user;
        }

    }

    return nullptr;
    
}

void UserRepositoryXML::deleteUser (std::string nan) const
{
    XMLDocument doc;
    doc.LoadFile(m_path.c_str());
    
    if(doc.FirstChildElement(ROOTUSER)->FirstChildElement( "user" )){

        XMLNode* rootXML = doc.FirstChildElement(ROOTUSER)->ToElement();
        XMLElement* userXML = doc.FirstChildElement(ROOTUSER)->FirstChildElement( "user" )->ToElement();

        for( userXML; userXML; userXML=userXML->NextSiblingElement() ){

            std::string actualNan = userXML->Attribute("nan");
            if(actualNan == nan){

                rootXML->DeleteChild(userXML);

            }

        }

        doc.LinkEndChild(rootXML);

        doc.SaveFile(m_path.c_str());
    }
            
}

void UserRepositoryXML::initRepository() const
{
    if(!std::filesystem::exists(m_path))
    {
        XMLDocument doc;
        XMLElement *rootXML = doc.NewElement(ROOTUSER);   
        doc.LinkEndChild(rootXML);        
        doc.SaveFile(m_path.c_str());
    }

}

