#ifndef LODGINGREPOSITORYXML_H
#define LODGINGREPOSITORYXML_H

#include <lodgingRepository.h>
#include "tinyxml2.h"

class LodgingRepositoryXML : public LodgingRepository{

public:

    LodgingRepositoryXML(const std::string & path = "lodgings.xml");

    virtual void createLodging(const Lodging & lodging) const override;

    virtual std::unique_ptr<Lodging> getLodging (size_t id) const override;

    virtual void deleteLodging(size_t id) const override;

    virtual std::vector<std::unique_ptr<Lodging>> getLodgingList() const override;

private:

    void initRepository() const;

};

#endif