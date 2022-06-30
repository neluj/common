#ifndef USERREPOSITORYXML_H
#define USERREPOSITORYXML_H

#include <database/userRepository.h>
#include "tinyxml2.h"

class UserRepositoryXML : public UserRepository{

public:

    UserRepositoryXML(const std::string & path = "users.xml");
    
    virtual void createUser (const User & user) const override;

    virtual std::unique_ptr<User> getUser (std::string nan) const override;

    virtual void deleteUser (std::string nan) const override;

private:

    void initRepository() const;

};

#endif