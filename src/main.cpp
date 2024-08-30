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
		auto scenePrev = CCTransitionFade::create(0.5f, GPKofiLayer::scene());
        CCDirector::sharedDirector()->replaceScene(scenePrev);
	}
};