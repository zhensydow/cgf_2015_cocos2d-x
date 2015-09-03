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
    m_keybd->onKeyPressed = std::bind( &SceneBreakout::onKeyPressed,
                                        this, _1, _2 );
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

    // setup an update function
    this->schedule( std::bind( &SceneBreakout::update, this, _1 ) , "update" );

    m_dirballx = 1.0f;
    m_dirbally = 0.5f;

    auto len = sqrt( m_dirballx*m_dirballx + m_dirbally*m_dirbally );
    m_dirbally /= len;
    m_dirbally /= len;

    return true;
}

//--------------------------------------------------------------------
void SceneBreakout::onEnter(){
    Node::onEnter();

    printf( "SceneBreakout::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneBreakout::onKeyPressed( EventKeyboard::KeyCode code, Event* event ){
    if( code == EventKeyboard::KeyCode::KEY_LEFT_ARROW ){
        m_bat_move += -1;
    }else if( code == EventKeyboard::KeyCode::KEY_RIGHT_ARROW ){
        m_bat_move += 1;
    }
}

//--------------------------------------------------------------------
void SceneBreakout::onKeyReleased( EventKeyboard::KeyCode code, Event* event ){
    if( code == EventKeyboard::KeyCode::KEY_ESCAPE ){
        Director::getInstance()->popScene();
    }else if( code == EventKeyboard::KeyCode::KEY_LEFT_ARROW ){
        m_bat_move += 1;
    }else if( code == EventKeyboard::KeyCode::KEY_RIGHT_ARROW ){
        m_bat_move += -1;
    }
}

//--------------------------------------------------------------------
void SceneBreakout::update( float delta ){
    constexpr float BAT_VELOCITY = 200.0f;
    constexpr float BALL_VELOCITY = 300.0f;

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    auto min_x = scr_origin.x + 200.0f;
    auto max_x = scr_origin.x + scr_size.width - 200.0f;

    auto min_y = scr_origin.y + 10.0f;
    auto max_y = scr_origin.y + scr_size.height - 10.0f;

    // update bat position
    auto batx = m_bat->getPositionX();

    batx += m_bat_move * BAT_VELOCITY * delta;

    if( batx < min_x ){
        batx = min_x;
    }

    if( batx > max_x ){
        batx = max_x;
    }

    m_bat->setPositionX( batx );

    // update ball position
    auto ballx = m_ball->getPositionX();
    auto bally = m_ball->getPositionY();
    ballx += m_dirballx * BALL_VELOCITY * delta;
    bally += m_dirbally * BALL_VELOCITY * delta;

    if( ballx < min_x ){
        ballx = min_x;
        m_dirballx *= -1;
    }

    if( ballx > max_x ){
        ballx = max_x;
        m_dirballx *= -1;
    }

    if( bally < min_y ){
        bally = min_y;
        m_dirbally *= -1;
    }

    if( bally > max_y ){
        bally = max_y;
        m_dirbally *= -1;
    }

    m_ball->setPosition( ballx, bally );

}

//--------------------------------------------------------------------
