#ifndef CREATELODGINUC_H
#define CREATELODGINUC_H

#include <string>
#include <memory>

class LodgingRepository;

class CreateLodgingUC{
    
public:

    CreateLodgingUC(const std::shared_ptr<LodgingRepository> lodgingRepository);

    void createLodging(const Lodging & lodging) const;

private:

    size_t findNewID() const;

    std::shared_ptr<LodgingRepository> m_lodgingRepository;
};

#endif