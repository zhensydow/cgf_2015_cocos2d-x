#include "SceneBreakout.hpp"
#include <cstdio>

//--------------------------------------------------------------------
using namespace cocos2d;

//--------------------------------------------------------------------
Scene *
SceneBreakout::createScene(){
    auto scene = Scene::create();

    auto root = SceneBreakout::create();

    scene->addChild( root );

    return scene;
}

//--------------------------------------------------------------------------
SceneBreakout::~SceneBreakout(){
    _eventDispatcher->removeEventListener( m_keybd );
}

//--------------------------------------------------------------------
bool SceneBreakout::init(){
    using namespace std::placeholders;

    if( !Node::init() ){
        return false;
    }

    printf( "SceneBreakout::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    // create a debug name
    auto label = Label::createWithTTF( "Breakout", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    // setup input listeners
    m_keybd = EventListenerKeyboard::create();
    m_keybd->onKeyReleased = std::bind( &SceneBreakout::onKeyReleased,
                                        this, _1, _2 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_keybd, this );

    // create sprites
    m_bat = Sprite::create( "bat01.png" );

    m_bat->setPosition( { scr_origin.x + scr_size.width / 2.0f,
                scr_origin.y + 100.0f } );

    this->addChild( m_bat, 1 );

    m_ball = Sprite::create( "miniball01.png" );

    m_ball->setPosition( { scr_origin.x + scr_size.width / 2.0f,
                scr_origin.y + scr_size.height / 2.0f } );

    this->addChild( m_ball, 1 );

    return true;
}

//--------------------------------------------------------------------
void SceneBreakout::onEnter(){
    Node::onEnter();

    printf( "SceneBreakout::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneBreakout::onKeyReleased( EventKeyboard::KeyCode code, Event* event ){
    if( code == EventKeyboard::KeyCode::KEY_ESCAPE ){
        Director::getInstance()->popScene();
    }
}

//--------------------------------------------------------------------