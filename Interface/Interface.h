#ifndef SMARTDROBE_INTERFACE_H
#define SMARTDROBE_INTERFACE_H

enum language {en, ro};

class Interface {

protected:
    language lang;
public:
    virtual void mainMenu() = 0;
    virtual void checkRecommendations() = 0;
    virtual void checkWeather() = 0;
    virtual void checkEvents() = 0;
    virtual void checkConsumables() = 0;
    virtual void showFreeHangers() = 0;
    virtual void showControlsAndSettings() = 0;
};

class CLI: Interface {

};


#endif //SMARTDROBE_INTERFACE_H
