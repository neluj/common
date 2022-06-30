#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <businessLogic/session.h>

#include <string>
#include <memory>

class User;
class RepositoryAbstractFact;

class ConsoleUI{
public:

    ConsoleUI();

    void run();

private:

    void access();

    void login() ;

    void regist();

    void selectRepository();

    void selectMainOption();

    void createLodging();

    void createOffer();
        
    void hireOut();

    void generateDatas();

    std::string divideLine() const;

    void printOption(size_t optionNumber, const std::string & optionName) const;

    void printTitle(const std::string & title) const;

    void printInstruction(const std::string & title) const;

    Session m_session;

};

#endif