#ifndef USER_H
#define USER_H

#include <string>

class User {

public:

    User(const std::string & nan,const std::string & name,const std::string & surname,const std::string & email);

    std::string nan() const;

    std::string name() const;

    std::string surname() const;

    std::string email() const;
    


private:

    std::string m_nan;

    std::string m_name;

    std::string m_surname;

    std::string m_email;   

};

#endif