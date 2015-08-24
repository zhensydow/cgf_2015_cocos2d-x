#include "SceneMainMenu.hpp"
#include <iostream>

//--------------------------------------------------------------------
using namespace cocos2d;

//--------------------------------------------------------------------
Scene *
SceneMainMenu::createScene(){
    auto scene = Scene::create();

    auto root = SceneMainMenu::create();

    scene->addChild( root );

    return scene;
}

//--------------------------------------------------------------------
bool SceneMainMenu::init(){
    if( !Node::init() ){
        return false;
    }

    printf( "SceneMainMenu::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF( "Main Menu", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    return true;
}

//--------------------------------------------------------------------
void SceneMainMenu::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
