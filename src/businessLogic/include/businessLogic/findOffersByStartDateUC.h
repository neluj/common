#ifndef FINDOFFERSBYSTARTDATEUC_H
#define FINDOFFERSBYSTARTDATEUC_H

#include <memory>
#include <string>
#include <vector>

class OfferRepository;
class Offer;

class FindOffersByStartDateUC{

public:

    // NOTE inyeccion e inversión de dependencias
    FindOffersByStartDateUC(const std::shared_ptr<OfferRepository> offerRepository);

    std::vector<std::unique_ptr<Offer>> find(const std::string & startDate);

private:

    std::shared_ptr<OfferRepository> m_offerRepository;
};

#endif