//------------------------------------------------------------------------------
#ifndef SCENESPRITES_HPP_
#define SCENESPRITES_HPP_

#include "cocos2d.h"

class SceneSprites : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual ~SceneSprites();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneSprites);

    void onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                        cocos2d::Event* event );
    void onMouseMove( cocos2d::Event *event );

private:
    cocos2d::EventListenerKeyboard* m_keybd;
    cocos2d::EventListenerMouse* m_mouse;

    cocos2d::Sprite * m_button2;
    cocos2d::Sprite * m_button3;
    cocos2d::Sprite * m_link1;
    cocos2d::Sprite * m_link2;
    cocos2d::Sprite * m_link3;
    cocos2d::Sprite * m_mario3;
};

//------------------------------------------------------------------------------
#endif//SCENESPRITES_HPP_

//------------------------------------------------------------------------------
