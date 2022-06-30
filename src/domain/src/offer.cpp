#include <domain/offer.h>


Offer::Offer(size_t id, size_t lodgingID, const std::string & startDate, const std::string & endDate, size_t price, const std::string & NanClientUser):
    m_id(id),
    m_lodgingId(lodgingID),
    m_NanClientUser(NanClientUser),
    m_startDate(startDate),
    m_price(price),
    m_endDate(endDate)
{}

size_t Offer::id() const
{
    return m_id;
}

size_t Offer::lodgingId() const
{
 return m_lodgingId;
}

std::string Offer::startDate() const
{
    return m_startDate;
}

std::string Offer::endDate() const
{
    return m_endDate;
}

size_t Offer::price() const
{
    return m_price;
}

std::string Offer::NanClientUser() const
{
    return m_NanClientUser;
}

void Offer::setClient(const std::string & clientNan)
{
    m_NanClientUser = clientNan;
}
