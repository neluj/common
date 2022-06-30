#include <businessLogic/findOffersByStartDateUC.h>
#include <database/offerRepository.h>
#include <algorithm>
  
FindOffersByStartDateUC::FindOffersByStartDateUC(const std::shared_ptr<OfferRepository> offerRepository) :
    m_offerRepository(offerRepository)
{}

std::vector<std::unique_ptr<Offer>> FindOffersByStartDateUC::find(const std::string & startDate)
{
    std::vector<std::unique_ptr<Offer>> offers = std::move(m_offerRepository->getOfferList());

    /* NOTE expresion lambda y algoritmo de STL. Esta clase se ha implementado solo para mostrar el uso de
        las expresiones lambda y el uso de algoritmos de STL. En un caso real no es la más apropiada de implementar esta 
        funcionalidad.
    */

    
    offers.erase(
        std::remove_if(offers.begin(), offers.end(), 
        [&](const auto& o)
            {return startDate != o->startDate();}
        ), offers.end()
    );
    
    return offers;
        
}
