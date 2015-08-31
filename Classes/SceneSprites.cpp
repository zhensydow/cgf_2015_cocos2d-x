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

    m_button2 = Sprite::create( "button01.png" );

    m_button2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 450.0f } );
    m_button2->setColor( {0,255,0} );
    this->addChild( m_button2, 2 );

    m_button3 = Sprite::create( "button01.png" );

    m_button3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 450.0f } );
    m_button3->setColor( {0,0,255} );
    this->addChild( m_button3, 2 );

    auto mario1 = Sprite::create( "mario01.png" );

    mario1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 300.0f } );

    this->addChild( mario1, 1 );

    auto mario2 = Sprite::create( "mario01.png" );

    mario2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 300.0f } );
    mario2->setScaleX( -1.0f );
    this->addChild( mario2, 1 );

    m_mario3 = Sprite::create( "mario01.png" );

    m_mario3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 300.0f } );
    m_mario3->setRotation( 50.0f );
    this->addChild( m_mario3, 1 );

    auto link1 = Sprite::create( "link01.png" );

    link1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 150.0f } );

    this->addChild( link1, 1 );

    m_link2 = Sprite::create( "link01.png" );

    m_link2->setPosition( { scr_origin.x + 250.0f,
                scr_origin.y + 150.0f } );
    m_link2->setScale( 2.0f );
    this->addChild( m_link2, 1 );

    m_link3 = Sprite::create( "link01.png" );

    m_link3->setPosition( { scr_origin.x + 400.0f,
                scr_origin.y + 150.0f } );
    m_link3->setScale( 4.0f );
    this->addChild( m_link3, 1 );

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
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    if( code == EventKeyboard::KeyCode::KEY_ESCAPE ){
        Director::getInstance()->popScene();
    }else if( code == EventKeyboard::KeyCode::KEY_1 ){

        auto move = MoveBy::create( 0.5, {0, 50} );
        m_link2->runAction( move );

    }else if( code == EventKeyboard::KeyCode::KEY_2 ){

        auto move1 = MoveBy::create( 0.5, {100, 0} );
        auto move2 = MoveBy::create( 0.4, {0, -50} );
        auto move3 = MoveBy::create( 0.3, {-100, 0} );
        auto move4 = MoveBy::create( 0.2, {0, 50} );

        auto seq = Sequence::create( move1, move2, move3, move4, nullptr );

        m_link3->runAction( seq );

    }else if( code == EventKeyboard::KeyCode::KEY_3 ){

        auto move = MoveTo::create( 0.5, { scr_origin.x + 250.0f,
                    scr_origin.y + 150.0f } );
        m_link2->runAction( move );

    }else if( code == EventKeyboard::KeyCode::KEY_4 ){

        auto move = MoveBy::create( 0.5f, {100, 0} );
        auto disp = FadeOut::create( 0.5f );

        m_mario3->runAction( move );
        m_mario3->runAction( disp );

    }else if( code == EventKeyboard::KeyCode::KEY_5 ){

        auto move_simple = MoveBy::create( 1.0f, {0,-300} );
        auto move_simple_rv = move_simple->reverse();
        auto move_ease = EaseInOut::create( move_simple->clone(), 2.0f );
        auto move_ease_rv = move_ease->reverse();

        auto seq1 = Sequence::create( move_simple, move_simple_rv, nullptr );
        auto seq2 = Sequence::create( move_ease, move_ease_rv, nullptr );

        m_button2->runAction( seq1 );
        m_button3->runAction( seq2 );

    }

}

//--------------------------------------------------------------------
