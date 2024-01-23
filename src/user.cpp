#include <user.h>

User::User(const std::string & nan,const std::string & name,const std::string & surname,const std::string & email) :
    m_nan(nan),
    m_name(name),
    m_surname(surname),
    m_email(email)
    {
    }

std::string User::nan() const
{
    return m_nan;
}

std::string User::name() const
{
    return m_name;
}

std::string User::surname() const
{
    return m_surname;
}

std::string User::email() const
{
    return m_email;
}

    