#ifndef CREATEOFFERUC_H
#define CREATEOFFERUC_H

#include <string>
#include <memory>

class OfferRepository;

class CreateOfferUC{
    
public:

    CreateOfferUC(const std::shared_ptr<OfferRepository> offerRepository);

    void createOffer(size_t lodgingID, const std::string & startDate, const std::string & endDate, size_t price, const std::string & NanClientUser) const;

private:

    std::shared_ptr<OfferRepository> m_offerRepository;
};

#endif