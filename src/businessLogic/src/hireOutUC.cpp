#include <businessLogic/hireOutUC.h>
#include <database/offerRepository.h>

HireOutUC::HireOutUC(const std::shared_ptr<OfferRepository> offerRepository) :
    m_offerRepository(offerRepository)
{

}

void HireOutUC::hireOut(size_t offer_id,const std::string &  NanClientUser)
{
    std::unique_ptr<Offer> offer = m_offerRepository->getOffer(offer_id);

    m_offerRepository->deleteOffer(offer_id);

    offer->setClient(NanClientUser);

    m_offerRepository->createOffer(*offer.get());
}