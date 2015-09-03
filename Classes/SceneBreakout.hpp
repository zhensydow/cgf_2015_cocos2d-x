//------------------------------------------------------------------------------
#ifndef SCENEBREAKOUT_HPP_
#define SCENEBREAKOUT_HPP_

#include "cocos2d.h"

class SceneBreakout : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual ~SceneBreakout();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneBreakout);

    void onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                        cocos2d::Event* event );

private:
    cocos2d::EventListenerKeyboard* m_keybd;

    cocos2d::Sprite * m_bat;
    cocos2d::Sprite * m_ball;
};


//------------------------------------------------------------------------------
#endif//SCENEBREAKOUT_HPP_

//------------------------------------------------------------------------------
