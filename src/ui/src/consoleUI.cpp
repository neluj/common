#include <ui/consoleUI.h>
#include <domain/cities.h>
#include <iostream>

ConsoleUI::ConsoleUI() :
    m_session(RepositoryType::JSON)
{}

void ConsoleUI::run() 
{
    access();
}

void ConsoleUI::access()  
{
    std::cout << divideLine();
    printTitle("Panel de acceso");
    std::cout << divideLine();
    printOption(1,"Login");
    printOption(2,"Register");
    printOption(3,"Cambiar repositorio");
    printOption(4,"Generar Datos");
    printOption(5,"Salir");
    std::cout << divideLine();
    std::cout << "\n";

    size_t option;
    std::cin >> option;
    
    switch(option){
        case 1:
            login();
        break;
        case 2:
            regist();
        break;
        case 3:
            selectRepository();
        break;
        case 4:
            generateDatas();
        break;
    }
}

void ConsoleUI::login()
{
    std::cout << divideLine();
    printTitle("Login");
    std::cout << divideLine();
    printInstruction("Introduce tu DNI");
    std::string dni;
    std::cin >> dni;
    std::cout << divideLine();
    std::cout << "\n";
    access();
}

void ConsoleUI::regist()
{
    std::cout << divideLine();
    printTitle("Nuevo Usuario");
    std::cout << divideLine();
    printInstruction("Introduce tu DNI");
    std::string dni;
    std::cin >> dni;
    printInstruction("Introduce tu nombre");
    std::string nombre;
    std::cin >> nombre;
    printInstruction("Introduce tu apellido");
    std::string apellido;
    std::cin >> apellido;
    printInstruction("Introduce tu email");
    std::string email;
    std::cin >> email;
    std::cout << divideLine();
    std::cout << "\n";
    access();
}

void ConsoleUI::selectRepository()
{
    std::cout << divideLine();
    printTitle("Selecciona el tipo de repositorio");
    std::cout << divideLine();
    printOption(1,"Repositorio JSON (Default)");
    printOption(2,"Repositorio XML");
    printOption(3,"Salir");
    std::cout << divideLine();
    std::cout << "\n";
    
    RepositoryType repoType = RepositoryType::JSON;
    size_t option;
    std::cin >> option;
    
    if(option == 2)
        repoType =  RepositoryType::XML;

    m_session.setRepositoryType(repoType);
    
    //RepositoryCreator repoCreator;
//
    //m_repositoriFact = repoCreator.get_repository(repoType);

    access();
}

void ConsoleUI::selectMainOption()
{
    std::cout << divideLine();
    printTitle("Panel principal");
    std::cout << divideLine();
    printOption(1,"Registrar nuevo alojamiento");
    printOption(2,"Crear nueva oferta");
    printOption(3,"Alquilar alojamiento");
    printOption(4,"Salir");
    std::cout << divideLine();
    std::cout << "\n";

    size_t option;
    std::cin >> option;

        switch(option){
        case 1:
            createLodging();
        break;
        case 2:
            createOffer();
        break;
        case 3:
            hireOut();
        break;
    }
}


void ConsoleUI::hireOut()
{
    std::cout << divideLine();
    printTitle("Alquilar alojamiento");
    std::cout << divideLine();
    printInstruction("Selecciona una fecha de inicio (dd/mm/aaaa)");
    std::string sDate;
    std::cin >> sDate;
    std::cout << divideLine();
    printInstruction("Ofertas disponibles");

    // BORRATU
    //std::shared_ptr<OfferRepository> offerRepo = m_repositoriFact->offerRepository();
    //FindStartDateOffersUC fSDateOffers(offerRepo, sDate);
//
    //std::vector<std::unique_ptr<Offer>> offersDate = fSDateOffers.find();
    //std::for_each (offersDate.begin(), offersDate.end(), [](const std::unique_ptr<Offer> & offer){std::cout << "\nOffer price: " <<offer->price();});
    std::cout << divideLine();
    std::cout << "\n";
    selectMainOption();
}


void ConsoleUI::createLodging()
{
    std::cout << divideLine();
    printTitle("Nuevo alojamiento");
    std::cout << divideLine();
    printInstruction("Introduce el nombre del alojamiento");
    printInstruction("Introduce el código de la ciudad de la siguiente lista:");
    printInstruction("Introduce la ubicación");

    for(auto x : CITIES::m_CodeToCity){
        std::cout << "\n" << x.first << " - ";
        std::cout << x.second;
    }

    std::cout << divideLine();
    std::cout << "\n";
    selectMainOption();
}

void ConsoleUI::createOffer()
{   
    std::cout << divideLine();
    printTitle("Nueva oferta");
    std::cout << divideLine();
    printInstruction("Selecciona tu alojamiento");
    printInstruction("Indica la fecha de inicio");
    printInstruction("Indica la fecha de fin");
    printInstruction("Indica el precio");
    std::cout << divideLine();
    std::cout << "\n";
    selectMainOption();
}

void ConsoleUI::generateDatas()
{
    GenerateDatas genData;
    genData.generate(m_repoType);

    access();
}

void ConsoleUI::printOption(size_t optionNumber, const std::string & optionName) const
{
    std::cout << "\n" << optionNumber << ". " << optionName;
}

void ConsoleUI::printTitle(const std::string & title) const
{
    std::cout << "\n* " << title << " *";
}

void ConsoleUI::printInstruction(const std::string & title) const
{
     std::cout << "\n " << title;   
}

std::string ConsoleUI::divideLine() const
{
    std::string line{"\n"};
    for(int i = 0; i < 25; ++i)
        line += "-";
    return line;
}