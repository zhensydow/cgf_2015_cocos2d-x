#include "SceneSprites.hpp"
#include <cstdio>

//--------------------------------------------------------------------
using namespace cocos2d;

//--------------------------------------------------------------------
Scene *
SceneSprites::createScene(){
    auto scene = Scene::create();

    auto root = SceneSprites::create();

    scene->addChild( root );

    return scene;
}

//--------------------------------------------------------------------------
SceneSprites::~SceneSprites(){
    // empty
}

//--------------------------------------------------------------------
bool SceneSprites::init(){
    if( !Node::init() ){
        return false;
    }

    printf( "SceneSprites::init\n" );

}

//--------------------------------------------------------------------
void SceneSprites::onEnter(){
    Node::onEnter();

    printf( "SceneSprites::onEnter\n" );
}

//--------------------------------------------------------------------
