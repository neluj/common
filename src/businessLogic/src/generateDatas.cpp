#include <businessLogic/generateDatas.h>
#include <database/repositoryCreator.h>
#include <database/offerRepositoryXML.h>
#include <database/offerRepositoryJSON.h>
#include <database/userRepositoryXML.h>
#include <database/userRepositoryJSON.h>
#include <database/lodgingRepositoryXML.h>
#include <database/lodgingRepositoryJSON.h>
#include <domain/user.h>
#include <domain/offer.h>
#include <domain/lodging.h>
#include <iostream>

void GenerateDatas::generate(const RepositoryType & repoType){

    RepositoryCreator repoCreator;

    std::shared_ptr<RepositoryAbstractFact> repositoryFact = repoCreator.get_repository(repoType);


    // USERS 

    std::shared_ptr<UserRepository> userRepositoryManager = repositoryFact->userRepository();
    
    User user0("000d","Julen","Gonzalez","jgonzalez");
    User user1("111a","Marina","rdg","marina_rdg");
    User user2("222d","Alex","Martinez","alex_martinez");
    User user3("333a","Eloy","Casagrande","eloy_casagrande");
    User user4("444d","Yoki","Sousa","yoki_sousa");
    User user5("555g","Jose","aldo","jose_aldo");

    std::cout << "\n" << "GENERATING USERS,..." << "\n";

    userRepositoryManager->createUser(user0);
    printUser(user0);

    userRepositoryManager->createUser(user1);
    printUser(user1);

    userRepositoryManager->createUser(user2);
    printUser(user2);

    userRepositoryManager->createUser(user3);
    printUser(user3);

    userRepositoryManager->createUser(user4);
    printUser(user4);

    userRepositoryManager->createUser(user5);
    printUser(user5);

    // LODGINGS

    std::shared_ptr<LodgingRepository> lodgingRepositoryManager = repositoryFact->lodgingRepository();

    Lodging lodging0(0,"000d","casa campo","Madrid","Calle 13");
    Lodging lodging1(1,"000d","casa Kontxa","SS","Kontxaldea");
    Lodging lodging2(2,"000d","Casa Peñon","Cadiz","Cerca del peñon");
    Lodging lodging3(3,"333a","Casa Malaga","MAL","Donde la feria");
    Lodging lodging4(4,"111a","Casa catalana","BCN","Ramplas");


    std::cout << "GENERATING LODGINGS,..." << "\n";

    lodgingRepositoryManager->createLodging(lodging0);
    printLodging(lodging0);

    lodgingRepositoryManager->createLodging(lodging1);
    printLodging(lodging1);

    lodgingRepositoryManager->createLodging(lodging2);
    printLodging(lodging2);

    lodgingRepositoryManager->createLodging(lodging3);
    printLodging(lodging3);

    lodgingRepositoryManager->createLodging(lodging4);
    printLodging(lodging4);

    // OFFERS

    std::shared_ptr<OfferRepository> offerRepositoryManager = repositoryFact->offerRepository();


    Offer offer0(0,2,"01/06/1993","04061993",3445 ,"111");
    Offer offer1(1,2,"01/06/1995","05061993",4539,"111");
    Offer offer2(2,1,"01/06/1997","06061993",134,"222");
    Offer offer3(3,0,"01/06/1997","060619933333",1333334,"222");

    std::cout << "GENERATING OFFERS,..." << "\n";

    offerRepositoryManager->createOffer(offer0);
    printOffer(offer0);

    offerRepositoryManager->createOffer(offer1);
    printOffer(offer1);
    
    offerRepositoryManager->createOffer(offer2);
    printOffer(offer2);

    offerRepositoryManager->createOffer(offer3);
    printOffer(offer3);


}


void GenerateDatas::printUser(const User & user) const
{
    std::cout << "\n";
    std::cout << "NAN: " << user.nan() << " -- ";
    std::cout << "Nombre: " << user.name() << " -- ";
    std::cout << "Surname: " << user.surname() << " -- ";
    std::cout << "Email : " << user.email() << " -- ";
    std::cout << "\n";
}
    
void GenerateDatas::printLodging(const Lodging & lodging) const
{
    std::cout << "\n";
    std::cout << "ID: " << lodging.id() << " -- ";
    std::cout << "Name: " << lodging.name() << " -- ";
    std::cout << "CityCode: " << lodging.cityCode() << " -- ";
    std::cout << "Ubication : " << lodging.ubication() << " -- ";
    std::cout << "\n";
}
    
void GenerateDatas::printOffer(const Offer & offer) const
{
    std::cout << "\n";
    std::cout << "ID: " << offer.id() << " -- ";
    std::cout << "lodgingId: " << offer.lodgingId() << " -- ";
    std::cout << "startDate: " << offer.startDate() << " -- ";
    std::cout << "endDate: " << offer.endDate() << " -- ";
    std::cout << "price: " << offer.price() << " -- ";
    std::cout << "NanClientUser: " << offer.NanClientUser() << " -- ";
    std::cout << "\n";
}
