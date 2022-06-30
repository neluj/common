#ifndef OFERREPOSITORYJSON_H
#define OFERREPOSITORYJSON_H

#include <vector>
#include <memory>
#include <domain/offer.h>


class OfferRepository{

public:

    OfferRepository(const std::string & path) : m_path(path){}

    virtual ~OfferRepository() = default;

    virtual void createOffer(const Offer & offer) const = 0;

    virtual std::unique_ptr<Offer> getOffer(size_t id) const = 0;

    virtual void deleteOffer(size_t id) const = 0;

    virtual std::vector<std::unique_ptr<Offer>> getOfferList() const = 0;

protected:

    std::string m_path;

};

#endif