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
    _eventDispatcher->removeEventListener( m_keybd );
}

//--------------------------------------------------------------------
bool SceneSprites::init(){
    using namespace std::placeholders;

    if( !Node::init() ){
        return false;
    }

    printf( "SceneSprites::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    // create a debug name
    auto label = Label::createWithTTF( "Sprites", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    // setup input listeners
    m_keybd = EventListenerKeyboard::create();
    m_keybd->onKeyReleased = std::bind( &SceneSprites::onKeyReleased,
                                        this, _1, _2 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_keybd, this );

    return true;
}

//--------------------------------------------------------------------
void SceneSprites::onEnter(){
    Node::onEnter();

    printf( "SceneSprites::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneSprites::onKeyReleased( EventKeyboard::KeyCode code, Event* event ){
    if( code == EventKeyboard::KeyCode::KEY_ESCAPE ){
        Director::getInstance()->popScene();
    }
}

//--------------------------------------------------------------------
