#include "SceneMainMenu.hpp"
#include <cstdio>
#include "SceneInput.hpp"
#include "SceneSprites.hpp"
#include "SceneBall.hpp"
#include "SceneBreakout.hpp"

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
    using namespace std::placeholders;

    if( !Node::init() ){
        return false;
    }

    printf( "SceneMainMenu::init\n" );

    auto scr_size = Director::getInstance()->getVisibleSize();
    auto scr_origin = Director::getInstance()->getVisibleOrigin();

    // create a debug name
    auto label = Label::createWithTTF( "Main Menu", "fonts/gentium.ttf", 24 );
    auto label_size = label->getContentSize();

    label->setPosition( {
            scr_origin.x + label_size.width/2.0f + 10.0f,
                scr_origin.y + scr_size.height
                - label_size.height/2.0f - 10.0f} );

    this->addChild( label, 3 );

    // create a background
    auto bg = Sprite::create( "bg_menu.png" );

    bg->setPosition( { scr_origin.x + scr_size.width/2.0f,
                scr_origin.y + scr_size.height/2.0f } );

    this->addChild( bg, -1 );

    // create main menu

    auto menu = Menu::create();

    menu->setPosition( { scr_origin.x + scr_size.width/2.0f,
                scr_origin.y + scr_size.height/2.0f } );


    auto menu_label = Label::createWithTTF( "Input", "fonts/gentium.ttf", 48);
    auto menu_item = MenuItemLabel::create( menu_label,
                                            std::bind( &SceneMainMenu::menu1,
                                                       this, _1 ) );
    menu->addChild( menu_item );

    menu_label = Label::createWithTTF( "Sprites", "fonts/gentium.ttf", 48);
    menu_item = MenuItemLabel::create( menu_label,
                                       std::bind( &SceneMainMenu::menu2,
                                                  this, _1 ) );

    menu->addChild( menu_item );

    menu_label = Label::createWithTTF( "Ball", "fonts/gentium.ttf", 48);
    menu_item = MenuItemLabel::create( menu_label,
                                       std::bind( &SceneMainMenu::menu3,
                                                  this, _1 ) );

    menu->addChild( menu_item );

    menu_label = Label::createWithTTF( "Breakout", "fonts/gentium.ttf", 48);
    menu_item = MenuItemLabel::create( menu_label,
                                       std::bind( &SceneMainMenu::menu4,
                                                  this, _1 ) );

    menu->addChild( menu_item );

    menu->alignItemsVerticallyWithPadding( 20.0f );

    this->addChild( menu, 1 );

    return true;
}

//--------------------------------------------------------------------
void SceneMainMenu::onEnter(){
    Node::onEnter();

    printf( "SceneMainMenu::onEnter\n" );
}

//--------------------------------------------------------------------
void SceneMainMenu::menu1( Ref * sender ){
    printf( "SceneMainMenu::menu1\n" );

    auto scene = SceneInput::createScene();
    Director::getInstance()->pushScene( scene );
    //Director::getInstance()->replaceScene( scene );
}

//--------------------------------------------------------------------
void SceneMainMenu::menu2( Ref * sender ){
    printf( "SceneMainMenu::menu2\n" );

    auto scene = SceneSprites::createScene();
    Director::getInstance()->pushScene( scene );
}

//--------------------------------------------------------------------
void SceneMainMenu::menu3( Ref * sender ){
    printf( "SceneMainMenu::menu3\n" );

    auto scene = SceneBall::createScene();
    Director::getInstance()->pushScene( scene );
}

//--------------------------------------------------------------------
void SceneMainMenu::menu4( Ref * sender ){
    printf( "SceneMainMenu::menu4\n" );

    auto scene = SceneBreakout::createScene();
    Director::getInstance()->pushScene( scene );
}

//--------------------------------------------------------------------
