#include <domain/lodging.h>

Lodging::Lodging(size_t id, const std::string & NanHostUser, const std::string & name, const std::string & cityCode, const std::string & ubication):
    m_id(id),
    m_NanHostUser(NanHostUser),
    m_name(name),
    m_cityCode(cityCode),
    m_ubication(ubication)
{}

size_t Lodging::id() const
{
    return m_id;
}

std::string Lodging::NanHostUser() const 
{
    return m_NanHostUser;
}

std::string Lodging::name() const
{
    return m_name;
}

std::string Lodging::cityCode() const
{
    return m_cityCode;
}

std::string Lodging::ubication() const
{
    return m_ubication;
}
