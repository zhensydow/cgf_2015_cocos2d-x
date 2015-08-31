//------------------------------------------------------------------------------
#ifndef SCENEBALL_HPP_
#define SCENEBALL_HPP_

#include "cocos2d.h"

class SceneBall : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual ~SceneBall();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneBall);

    void onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                        cocos2d::Event* event );

private:
    cocos2d::EventListenerKeyboard* m_keybd;

    cocos2d::Sprite * m_ball;
    cocos2d::Sprite * m_shadow;
};

//------------------------------------------------------------------------------
#endif//SCENEBALL_HPP_

//------------------------------------------------------------------------------
