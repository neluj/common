#include <businessLogic/createLodgingUC.h>
#include <database/lodgingRepository.h>

CreateLodgingUC::CreateLodgingUC(const std::shared_ptr<LodgingRepository> lodgingRepository):
    m_lodgingRepository(lodgingRepository)
{}

void CreateLodgingUC::createLodging(const Lodging & lodging) const
{
    size_t max_id = findNewID();

    m_lodgingRepository->createLodging(lodging);
}


size_t CreateLodgingUC::findNewID() const 
{
    size_t max_id{0};
    std::vector<std::unique_ptr<Lodging>> lodgings = m_lodgingRepository->getLodgingList();
    for(auto && lodgingI : lodgings){
        if(lodgingI->id() > max_id){
            max_id = lodgingI->id();
            max_id++;
        }
    }

    return max_id;

}