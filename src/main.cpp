#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "VideoPlayer.hpp"
#include "video_place.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("NYAN CAT!!");

		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::create("cat.png"_spr),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMyButton(CCObject*) {
		geode::createQuickPopup(
			"meow",            // title
			"are you sure you want to go in? if you do, you will have to restart to go out",   // content
			"yes", "no",      // buttons
			[](auto, bool btn1) {
				if (!btn1) {
					auto scenePrev = CCTransitionFade::create(0.5f, GPKofiLayer::scene());
        			CCDirector::sharedDirector()->replaceScene(scenePrev);			
				}
			}
		);
	}
};