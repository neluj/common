#ifndef OFFER_H
#define OFFER_H

#include <string>

class Offer{

public:

    Offer(size_t id, size_t lodgingID, const std::string & startDate, const std::string & endDate, size_t price, const std::string & NanClientUser = "" );

    size_t id() const;

    size_t lodgingId() const;

    std::string startDate() const;

    std::string endDate() const;

    size_t price() const;

    std::string NanClientUser() const;

    void setClient(const std::string & clientNan);


private:

    size_t m_id;

    size_t m_lodgingId;

    std::string m_startDate;

    std::string m_endDate;

    size_t m_price;

    std::string m_NanClientUser;

};

#endif