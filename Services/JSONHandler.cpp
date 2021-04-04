//
// Created by gionson on 4/4/21.
//

#include "JSONHandler.h"

string JSONHandler::parseJSONFromFile(ifstream& InputFile) {
    string JSONToString = json::parse(InputFile).dump(4);
    return JSONToString;
}
