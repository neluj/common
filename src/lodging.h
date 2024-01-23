#ifndef LODGING_H
#define LODGING_H

#include <string>

class Lodging {

public:

    Lodging(size_t id, const std::string & NanHostUser, const std::string & name, const std::string & cityCode, const std::string & ubication);

    size_t id() const;

    std::string NanHostUser() const;

    std::string name() const;

    std::string cityCode() const;

    std::string ubication() const;

private:

    size_t m_id;

    std::string m_NanHostUser;

    std::string m_name;

    std::string m_cityCode;

    std::string m_ubication;

};
#endif