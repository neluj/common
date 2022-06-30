#ifndef USERREPOSITORYJSON_H
#define USERREPOSITORYJSON_H

#include <database/userRepository.h>
#include <nlohmann/json.hpp>

class UserRepositoryJSON : public UserRepository{

    public:

    UserRepositoryJSON(const std::string & path = "users.json");
    
    virtual void createUser (const User & user) const override;

    virtual std::unique_ptr<User> getUser (std::string nan) const override;

    virtual void deleteUser (std::string nan) const override;


private:

    void initRepository() const;

    void createBaseElements() const;

    void prettyPrint(const nlohmann::json & jsonObj) const;

    std::unique_ptr<nlohmann::json> getJsonBaseObj() const;

    

};

#endif