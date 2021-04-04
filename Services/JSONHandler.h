//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_JSONHANDLER_H
#define SMARTDROBE_JSONHANDLER_H

#include "../Services/Libraries.h"

class JSONHandler {
public:
    static string parseJSONFromFile(ifstream&);
};


#endif //SMARTDROBE_JSONHANDLER_H
