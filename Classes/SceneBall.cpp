#include "SceneBall.hpp"
#include <cstdio>

//--------------------------------------------------------------------
using namespace cocos2d;

//--------------------------------------------------------------------
Scene *
SceneBall::createScene(){
    auto scene = Scene::create();

    auto root = SceneBall::create();

    scene->addChild( root );

    return scene;
}

//--------------------------------------------------------------------------
SceneBall::~SceneBall(){
    _eventDispatcher->removeEventListener( m_keybd );
}

//--------------------------------------------------------------------
bool SceneBall::init(){
    using namespace std::placeholders;

    if( !Node::init() ){
        return false;
    }

    printf( "SceneBall::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    // create a debug name
    auto label = Label::createWithTTF( "Ball", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    // setup input listeners
    m_keybd = EventListenerKeyboard::create();
    m_keybd->onKeyReleased = std::bind( &SceneBall::onKeyReleased,
                                        this, _1, _2 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_keybd, this );

    // create sprites
    m_ball = Sprite::create( "ball01.png" );
    m_ball->setPosition(  { scr_origin.x + scr_size.width/2.0f,
                scr_origin.y + scr_size.height/2.0f } );
    this->addChild( m_ball, 1 );

    auto rot = RotateBy::create( 1.0f, -120.0f );
    m_ball->runAction( RepeatForever::create( rot ) );

    m_shadow = Sprite::create( "ball02.png" );
    m_shadow->setPosition(  { scr_origin.x + scr_size.width/2.0f,
                scr_origin.y + scr_size.height/2.0f } );
    this->addChild( m_shadow, 1 );

    glClearColor( 1.0, 1.0, 1.0, 1.0 );

    return true;
}

//--------------------------------------------------------------------
void SceneBall::onEnter(){
    Node::onEnter();

    printf( "SceneBall::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneBall::onKeyReleased( EventKeyboard::KeyCode code, Event* event ){
    if( code == EventKeyboard::KeyCode::KEY_ESCAPE ){
        glClearColor( 0.0, 0.0, 0.0, 1.0 );
        Director::getInstance()->popScene();
    }else if( code == EventKeyboard::KeyCode::KEY_1 ){

        m_ball->setVisible( true );
        m_shadow->setVisible( false );

    }else if( code == EventKeyboard::KeyCode::KEY_2 ){

        m_ball->setVisible( false );
        m_shadow->setVisible( true );

    }else if( code == EventKeyboard::KeyCode::KEY_3 ){

        m_ball->setVisible( true );
        m_shadow->setVisible( true );

    }
}

//--------------------------------------------------------------------
