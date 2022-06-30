#ifndef OFFERREPOSITORYJSON_H
#define OFFERREPOSITORYJSON_H

#include <database/offerRepository.h>
#include <nlohmann/json.hpp>


class OfferRepositoryJSON : public OfferRepository{

public:

    OfferRepositoryJSON(const std::string & path = "offers.json");

    virtual void createOffer(const Offer & offer) const override;

    virtual std::unique_ptr<Offer> getOffer(size_t id) const override;

    virtual void deleteOffer(size_t id) const override;

    virtual std::vector<std::unique_ptr<Offer>> getOfferList() const override;
    
private:

    void initRepository() const;

    void createBaseElements() const;

    void prettyPrint(const nlohmann::json & jsonObj) const;

    std::unique_ptr<nlohmann::json> getJsonBaseObj() const;

};

#endif