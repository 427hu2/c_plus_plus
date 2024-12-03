#include <iostream>
#include <ostream>

#include "lib/greet.h"
#include "pugixml/src/pugixml.hpp"


#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    Greet();

    json ex1 = json::parse(R"(
        {
            "pi": 3.141,
            "happy": true
        }
    )");

    std::cout << ex1.at("pi") << std::endl;


    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("tree.xml");
    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;

}
