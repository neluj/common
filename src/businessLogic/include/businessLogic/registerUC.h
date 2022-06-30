#ifndef REGISTERUC_H
#define REGISTERUC_H

#include <memory>
#include <domain/user.h>

class UserRepository;

class RegisterUC{
    
public:

    RegisterUC(const std::shared_ptr<UserRepository> userRepository);

    void regist(const User & user);

private:

    std::shared_ptr<UserRepository> m_userRepository;
    
};

#endif