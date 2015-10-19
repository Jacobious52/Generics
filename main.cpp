#include "GConfig.h"

int main()
{
    // example of loading in a json file to Generic Objects
    GConfig config = GConfig::read("test.json");
    // print it
    std::cout << config.getDict() << std::endl;

    // get the biomes dict
    // biomes is in the top level so we pas config.getDict()
    GDict *biomes = GDictFromDict(config.getDict(), "biomes");

    // forest is in the biomes dictionary
    // as forest is also a dictionary, get it like this
    GDict *forest = GDictFromDict(biomes, "forest");

    // freq is a number in forest dict
    // so get the number like so
    GNumber *freq = GNumberFromDict(forest, "freq");

    // print it
    std::cout << "freq " << freq << std::endl;

    // get the array door in one go which it in the tiles dict, which is on the first level
    GArray *door = GArrayFromDict(GDictFromDict(config.getDict(), "tiles"), "door");

    // print it
    std::cout << door << std::endl;

    // Get the 3rd String from the array door
    std::cout << GStringFromArray(door, 2) << std::endl;

    return 0;
}
