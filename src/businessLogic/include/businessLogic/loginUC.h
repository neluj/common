#ifndef LOGINUC_H
#define LOGINUC_H

#include <string>
#include <memory>

class UserRepository;
class User;

class LoginUC{
    
public:

    LoginUC(const std::shared_ptr<UserRepository> userRepository);

    std::unique_ptr<User> login(const std::string & nan) const;

private:

    std::shared_ptr<UserRepository> m_userRepository;
};

#endif