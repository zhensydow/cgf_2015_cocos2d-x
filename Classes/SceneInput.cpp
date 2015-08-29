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

//--------------------------------------------------------------------------
SceneInput::~SceneInput(){
    _eventDispatcher->removeEventListener( m_keybd );
    _eventDispatcher->removeEventListener( m_touch );
    _eventDispatcher->removeEventListener( m_mouse );
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

    // create message labels
    m_key = Label::createWithTTF( "key", "fonts/gentium.ttf", 24 );
    m_key->setAnchorPoint( { 0.0f, 0.5f } );
    m_key->setPosition( {scr_origin.x + 100.0f, scr_origin.y + 400.0f } );

    this->addChild( m_key, 2 );

    m_button = Label::createWithTTF( "mouse button", "fonts/gentium.ttf", 24 );
    m_button->setAnchorPoint( { 0.0f, 0.5f } );
    m_button->setPosition( {scr_origin.x + 100.0f, scr_origin.y + 350.0f } );

    this->addChild( m_button, 2 );

    m_pos = Label::createWithTTF( "mouse button", "fonts/gentium.ttf", 24 );
    m_pos->setAnchorPoint( { 0.0f, 0.5f } );
    m_pos->setPosition( {scr_origin.x + 100.0f, scr_origin.y + 300.0f } );

    this->addChild( m_pos, 2 );

    // setup input listeners

    m_keybd = EventListenerKeyboard::create();
    m_keybd->onKeyPressed = std::bind( &SceneInput::onKeyPressed,
                                       this,
                                       std::placeholders::_1,
                                       std::placeholders::_2 );
    m_keybd->onKeyReleased = std::bind( &SceneInput::onKeyReleased,
                                        this,
                                        std::placeholders::_1,
                                        std::placeholders::_2 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_keybd, this );

    m_touch = EventListenerTouchOneByOne::create();
    m_touch->setSwallowTouches( true );
    m_touch->onTouchBegan = std::bind( &SceneInput::onTouchBegan,
                                       this,
                                       std::placeholders::_1,
                                       std::placeholders::_2 );
    m_touch->onTouchEnded = std::bind( &SceneInput::onTouchEnded,
                                       this,
                                       std::placeholders::_1,
                                       std::placeholders::_2 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_touch, this );

    m_mouse = EventListenerMouse::create();
    m_mouse->onMouseMove = std::bind( &SceneInput::onMouseMove,
                                      this,
                                      std::placeholders::_1 );
    m_mouse->onMouseUp = std::bind( &SceneInput::onMouseUp,
                                    this,
                                    std::placeholders::_1 );
    m_mouse->onMouseDown = std::bind( &SceneInput::onMouseDown,
                                      this,
                                      std::placeholders::_1 );
    m_mouse->onMouseScroll = std::bind( &SceneInput::onMouseScroll,
                                        this,
                                        std::placeholders::_1 );

    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_mouse, this );

    return true;
}

//--------------------------------------------------------------------
void SceneInput::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneInput::onKeyPressed( cocos2d::EventKeyboard::KeyCode code,
                               cocos2d::Event* event )
{
    m_key->setString( "Key Pressed: " + std::to_string((int)code) );
}

//--------------------------------------------------------------------
void SceneInput::onKeyReleased( cocos2d::EventKeyboard::KeyCode code,
                                cocos2d::Event* event )
{
    m_key->setString( "Key Released: " + std::to_string((int)code) );
}

//--------------------------------------------------------------------
bool SceneInput::onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event ){
    auto pos = touch->getLocation();
    m_key->setString( "Touch Began: " + std::to_string((int)pos.x) + ", " +
                      std::to_string((int)pos.y));
    return true;
}

//--------------------------------------------------------------------
void SceneInput::onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event ){
    auto pos = touch->getLocation();
    m_key->setString( "Touch Ended: " + std::to_string((int)pos.x) + ", " +
                      std::to_string((int)pos.y));
}

//--------------------------------------------------------------------
void SceneInput::onMouseDown( Event *event ){
    EventMouse* e = (EventMouse*)event;
    m_button->setString( "Mouse Down: " +
                         std::to_string(e->getMouseButton()));
}

//--------------------------------------------------------------------
void SceneInput::onMouseUp( Event *event ){
    EventMouse* e = (EventMouse*)event;
    m_button->setString( "Mouse Up: " +
                         std::to_string(e->getMouseButton()));
}

//--------------------------------------------------------------------
void SceneInput::onMouseMove( Event *event ){
    EventMouse* e = (EventMouse*)event;
    m_pos->setString( " " + std::to_string((int)e->getCursorX()) + ", " +
                      std::to_string((int)e->getCursorY()) );
}

//--------------------------------------------------------------------
void SceneInput::onMouseScroll( Event *event ){
    m_button->setString( "Mouse Scroll" );
}

//--------------------------------------------------------------------
