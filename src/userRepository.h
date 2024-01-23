#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <string>
#include <memory>

class User;

class UserRepository{

public:

    UserRepository(const std::string & path) : m_path(path){}

    virtual ~UserRepository() = default;

    virtual void createUser (const User & user) const = 0;

    virtual std::unique_ptr<User> getUser (std::string nan) const = 0;

    virtual void deleteUser (std::string nan) const = 0;

protected:

    std::string m_path;

};

#endif
