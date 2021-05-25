//
// Created by gionson on 4/4/21.
//

#include "NotificationManager.h"
bool NotificationManager::verificareInterval(time_t ultimaScoatere){
    time_t now = time(0);
    return (difftime(ultimaScoatere, now)/(60*60^24))>=4;
}
void NotificationManager::trimitereNotificare(Haina h){
    if(verificareInterval(h.getUltimaScoatere())){
        std::string mesaj=h.getDenumire()+" lipseste din dulap de mai mult de 4 zile!";
    }
}