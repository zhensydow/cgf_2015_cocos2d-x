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

    return true;
}

//--------------------------------------------------------------------
void SceneMainMenu::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
