//------------------------------------------------------------------------------
#ifndef SCENEINPUT_HPP_
#define SCENEINPUT_HPP_

#include "cocos2d.h"

class SceneInput : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual ~SceneInput();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneInput);

    void onKeyPressed( cocos2d::EventKeyboard::KeyCode code,
                       cocos2d::Event* event );
    void onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                        cocos2d::Event* event );
    bool onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event );
    void onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event );
    void onMouseDown( cocos2d::Event *event );
    void onMouseUp( cocos2d::Event *event );
    void onMouseMove( cocos2d::Event *event );
    void onMouseScroll( cocos2d::Event *event );

private:
    cocos2d::Label * m_key;
    cocos2d::Label * m_button;
    cocos2d::Label * m_pos;

    cocos2d::EventListenerKeyboard* m_keybd;
    cocos2d::EventListenerTouchOneByOne* m_touch;
    cocos2d::EventListenerMouse* m_mouse;

};



//------------------------------------------------------------------------------
#endif//SCENEINPUT_HPP_

//------------------------------------------------------------------------------
