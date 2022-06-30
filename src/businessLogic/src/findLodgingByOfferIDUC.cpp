#include <businessLogic/findLodgingByOfferIDUC.h>
#include <database/lodgingRepository.h>
  
FindLodgingByOfferIDUC::FindLodgingByOfferIDUC(const std::shared_ptr<LodgingRepository> lodgingRepository) :
    m_lodgingRepository(lodgingRepository)
{}

std::unique_ptr<Lodging> FindLodgingByOfferIDUC::find(size_t lodgingID) const
{
    return m_lodgingRepository->getLodging(lodgingID);        
}