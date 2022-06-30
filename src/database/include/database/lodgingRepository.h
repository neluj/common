#ifndef LODGINGREPOSITORY_H
#define LODGINGREPOSITORY_H

#include <vector>
#include <memory>
#include <domain/lodging.h>

class LodgingRepository{

public:

    LodgingRepository(const std::string & path) : m_path(path){}

    virtual ~LodgingRepository() = default;

    virtual void createLodging(const Lodging & lodging) const = 0;

    virtual std::unique_ptr<Lodging> getLodging (size_t id) const = 0;

    virtual void deleteLodging(size_t id) const = 0;

    virtual std::vector<std::unique_ptr<Lodging>> getLodgingList() const = 0;

protected:

    std::string m_path;

};

#endif