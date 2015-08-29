#include "SceneInput.hpp"
#include <cstdio>

//--------------------------------------------------------------------
using namespace cocos2d;

//--------------------------------------------------------------------
Scene *
SceneInput::createScene(){
    auto scene = Scene::create();

    auto root = SceneInput::create();

    scene->addChild( root );

    return scene;
}

//--------------------------------------------------------------------
bool SceneInput::init(){
    if( !Node::init() ){
        return false;
    }

    printf( "SceneInput::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    // create a debug name
    auto label = Label::createWithTTF( "Input", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    return true;
}

//--------------------------------------------------------------------
void SceneInput::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
