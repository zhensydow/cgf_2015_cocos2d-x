//------------------------------------------------------------------------------
#ifndef SCENEMAINMENU_HPP_
#define SCENEMAINMENU_HPP_

#include "cocos2d.h"

class SceneMainMenu : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneMainMenu);

    void menu1( Ref* sender );
    void menu2( Ref* sender );
    void menu3( Ref* sender );
    void menu4( Ref* sender );
    void menu5( Ref* sender );

private:
};

//------------------------------------------------------------------------------
#endif//SCENEMAINMENU_HPP_

//------------------------------------------------------------------------------
