//------------------------------------------------------------------------------
#ifndef SCENEBREAKOUT_HPP_
#define SCENEBREAKOUT_HPP_

#include <vector>
#include "cocos2d.h"

class SceneBreakout : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual ~SceneBreakout();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneBreakout);

    void onKeyPressed( cocos2d::EventKeyboard::KeyCode code,
                       cocos2d::Event* event );
    void onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                        cocos2d::Event* event );

    void update( float delta );

private:
    cocos2d::EventListenerKeyboard* m_keybd;

    cocos2d::Sprite * m_bat;
    cocos2d::Sprite * m_ball;

    std::vector<cocos2d::Sprite*> m_bricks;

    int m_bat_move = 0;

    float m_dirballx = 0;
    float m_dirbally = 0;
};


//------------------------------------------------------------------------------
#endif//SCENEBREAKOUT_HPP_

//------------------------------------------------------------------------------
