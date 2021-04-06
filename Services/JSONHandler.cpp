//
// Created by gionson on 4/4/21.
//

#include "JSONHandler.h"

string JSONHandler::parseJSONFromFile(ifstream& InputFile) {
    string JSONToString = json::parse(InputFile).dump(4);
    return JSONToString;
}

string JSONHandler::parseJSON(json InputJSON) {
    string JSONToString = InputJSON.dump(4);
    return JSONToString;
}

json JSONHandler::getJSONFromString(string InputString) {
    json StringToJSON = json::parse(InputString);
    return StringToJSON;
}

json JSONHandler::getJSONFromFile(ifstream& InputFile) {
    json JSONFromFile = json::parse(InputFile);
    return JSONFromFile;
}


