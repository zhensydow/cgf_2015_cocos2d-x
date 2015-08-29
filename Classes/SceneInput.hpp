//------------------------------------------------------------------------------
#ifndef SCENEINPUT_HPP_
#define SCENEINPUT_HPP_

#include "cocos2d.h"

class SceneInput : public cocos2d::Node {
public:
    static cocos2d::Scene* createScene();

    virtual bool init() override;
    void onEnter() override;

    CREATE_FUNC(SceneInput);

private:
    cocos2d::Label * m_key;
    cocos2d::Label * m_button;
    cocos2d::Label * m_pos;

};



//------------------------------------------------------------------------------
#endif//SCENEINPUT_HPP_

//------------------------------------------------------------------------------
