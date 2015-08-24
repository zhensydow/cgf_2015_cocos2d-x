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

    auto label = Label::createWithTTF( "Main Menu", "fonts/gentium.ttf", 24 );

    label->setPosition( { 500, 500 } );

    this->addChild( label, 3 );

    return true;
}

//--------------------------------------------------------------------
void SceneMainMenu::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
