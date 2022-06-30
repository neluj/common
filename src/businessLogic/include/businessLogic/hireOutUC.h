#ifndef HIREOUT_H
#define HIREOUT_H

#include <string>
#include <memory>

class OfferRepository;

class HireOutUC{
    
public:

    HireOutUC(const std::shared_ptr<OfferRepository> offerRepository);

    void hireOut(size_t offer_id,const std::string &  NanClientUser);

private:

    std::shared_ptr<OfferRepository> m_offerRepository;
};

#endif