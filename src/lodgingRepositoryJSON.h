#ifndef LODGINGREPOSITORYJSON_H
#define LODGINGREPOSITORYJSON_H

#include <lodgingRepository.h>
#include <nlohmann/json.hpp>


class LodgingRepositoryJSON : public LodgingRepository{

public:

    LodgingRepositoryJSON(const std::string & path = "lodgings.json");

    virtual void createLodging(const Lodging & lodging) const override;

    virtual std::unique_ptr<Lodging> getLodging (size_t id) const override;

    virtual void deleteLodging(size_t id) const override;

    virtual std::vector<std::unique_ptr<Lodging>> getLodgingList() const override;

private:

    void initRepository() const;

    void createBaseElements() const;

    void prettyPrint(const nlohmann::json & jsonObj) const;

    std::unique_ptr<nlohmann::json> getJsonBaseObj() const;

};

#endif