#include <businessLogic/createOfferUC.h>
#include <database/offerRepository.h>
#include <vector>

CreateOfferUC::CreateOfferUC(const std::shared_ptr<OfferRepository> offerRepository):
    m_offerRepository(offerRepository)
{}

void CreateOfferUC::createOffer(size_t lodgingID, const std::string & startDate, const std::string & endDate, size_t price, const std::string & NanClientUser) const
{   
    size_t max_id{0};
    std::vector<std::unique_ptr<Offer>> offers = m_offerRepository->getOfferList();
    for(auto && offerI : offers){
        if(offerI->id() > max_id){
            max_id = offerI->id();
            max_id++;
        }
    }
    Offer offer(max_id, lodgingID, startDate, endDate, price, NanClientUser);
    m_offerRepository->createOffer(offer);
}
