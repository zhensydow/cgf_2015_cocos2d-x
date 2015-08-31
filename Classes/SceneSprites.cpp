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
    _eventDispatcher->removeEventListener( m_mouse );
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

    m_mouse = EventListenerMouse::create();
    m_mouse->onMouseUp = std::bind( &SceneSprites::onMouseUp,
                                    this, _1 );
    m_mouse->onMouseMove = std::bind( &SceneSprites::onMouseMove,
                                      this, _1 );
    _eventDispatcher->addEventListenerWithSceneGraphPriority( m_mouse, this );

    // create sprites
    m_button1 = Sprite::create( "button01.png" );

    m_button1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 450.0f } );

    this->addChild( m_button1, 1 );

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

    auto coin1 = Sprite::create( "coin01.png" );
    m_mario3->addChild( coin1 );
    coin1->setPosition( {0.0f ,50.0f} );
    this->addChild( m_mario3, 1 );

    m_link1 = Sprite::create( "link01.png" );

    m_link1->setPosition( { scr_origin.x + 100.0f,
                scr_origin.y + 150.0f } );

    this->addChild( m_link1, 1 );

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

    Vector<SpriteFrame*> link_frames;
    link_frames.reserve( 5*5 );
    for( int j = 0 ; j < 5 ; ++j ){
        for( int i = 0 ; i < 5 ; ++i ){
            auto frame = SpriteFrame::create( "anim_01_0.png",
                                              { i*115.0f, j*296.0f,
                                                      115.0f, 296.0f } );
            link_frames.pushBack( frame );
        }
    }

    auto link1b = Sprite::create( "anim_01_0.png",
                                  { 0.0f, 0.0f, 115.0f, 296.0f } );

    auto link_animation = Animation::createWithSpriteFrames( link_frames,
                                                             1.0f / 25.0f );

    link1b->setPosition( { scr_origin.x + 650.0f,
                scr_origin.y + 300.0f } );

    auto action = Animate::create( link_animation );
    link1b->runAction( RepeatForever::create( action ) );

    this->addChild( link1b, 1 );

    // setup random
    std::random_device rd;
    m_gen.seed( rd() );

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
        glClearColor( 0.0, 0.0, 0.0, 1.0 );
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

    }else if( code == EventKeyboard::KeyCode::KEY_B ){
        glClearColor( 1.0, 1.0, 1.0, 1.0 );
    }

}

//--------------------------------------------------------------------
void SceneSprites::onMouseUp( Event *event ){
    std::uniform_real_distribution<> dis( 0.0, 600.0 );

    EventMouse* e = (EventMouse*)event;

    auto bb = m_button1->getBoundingBox();

    if( bb.containsPoint( e->getLocationInView() ) ){
        auto move = MoveTo::create( 0.2f, { dis(m_gen) + 100.0f, dis(m_gen) } );

        m_button1->stopAllActions();
        m_button1->runAction( EaseOut::create( move, 2.0f ) );
    }
}

//--------------------------------------------------------------------
void SceneSprites::onMouseMove( Event *event ){
    EventMouse* e = (EventMouse*)event;

    auto pos = e->getLocationInView();
    auto move = MoveTo::create( 1.0f, pos );

    m_link1->stopAllActions();
    m_link1->runAction( EaseOut::create( move, 2.0f ) );

}

//--------------------------------------------------------------------
