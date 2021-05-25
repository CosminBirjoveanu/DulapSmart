//
// Created by gionson on 4/4/21.
//

#ifndef SMARTDROBE_NOTIFICATIONMANAGER_H
#define SMARTDROBE_NOTIFICATIONMANAGER_H

#include "../Entities/Haina.h"
#include <ctime>

class NotificationManager {
public:
    bool verificareInterval(time_t ultimaScoatere);
    void trimitereNotificare(Haina h);
};


#endif //SMARTDROBE_NOTIFICATIONMANAGER_H
