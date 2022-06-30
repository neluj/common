#ifndef OFFERREPOSITORYXML_H
#define OFFERREPOSITORYXML_H

#include <database/offerRepository.h>
#include "tinyxml2.h"

class OfferRepositoryXML : public OfferRepository{

public:

    OfferRepositoryXML(const std::string & path = "offers.xml");

    virtual void createOffer(const Offer & offer) const override;

    virtual std::unique_ptr<Offer> getOffer(size_t id) const override;

    virtual void deleteOffer(size_t id) const override;

    virtual std::vector<std::unique_ptr<Offer>> getOfferList() const override;

private:

    void initRepository() const;

};


#endif