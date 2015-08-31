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

    // create sprites
    auto button1 = Sprite::create( "button01.png" );

    button1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 450.0f } );

    this->addChild( button1, 1 );

    auto button2 = Sprite::create( "button01.png" );

    button2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 450.0f } );
    button2->setColor( {0,255,0} );
    this->addChild( button2, 1 );

    auto button3 = Sprite::create( "button01.png" );

    button3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 450.0f } );
    button3->setColor( {0,0,255} );
    this->addChild( button3, 1 );

    auto mario1 = Sprite::create( "mario01.png" );

    mario1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 300.0f } );

    this->addChild( mario1, 1 );

    auto mario2 = Sprite::create( "mario01.png" );

    mario2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 300.0f } );
    mario2->setScaleX( -1.0f );
    this->addChild( mario2, 1 );

    auto mario3 = Sprite::create( "mario01.png" );

    mario3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 300.0f } );
    mario3->setRotation( 50.0f );
    this->addChild( mario3, 1 );

    auto link1 = Sprite::create( "link01.png" );

    link1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 150.0f } );

    this->addChild( link1, 1 );

    auto link2 = Sprite::create( "link01.png" );

    link2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 150.0f } );
    link2->setScale( 2.0f );
    this->addChild( link2, 1 );

    auto link3 = Sprite::create( "link01.png" );

    link3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 150.0f } );
    link3->setScale( 4.0f );
    this->addChild( link3, 1 );

    auto link1b = Sprite::create( "anim_01_0.png",
                                  { 0.0f, 0.0f, 115.0f, 296.0f } );

    link1b->setPosition( { scr_origin.x + 650.0f,
                scr_origin.y + 300.0f } );

    this->addChild( link1b, 1 );

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
