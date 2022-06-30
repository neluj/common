#ifndef FINDLODGINGBYOFFERIDUC_H
#define FINDLODGINGBYOFFERIDUC_H

#include <memory>
#include <string>

class LodgingRepository;
class Lodging;

class FindLodgingByOfferIDUC{

public:

    FindLodgingByOfferIDUC(const std::shared_ptr<LodgingRepository> lodginRepository);

    std::unique_ptr<Lodging> find(size_t lodgingID) const;

private:

    std::shared_ptr<LodgingRepository> m_lodgingRepository;

};

#endif