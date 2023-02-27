#pragma once 
#include "Utilities.h"
#include "Mario.h"
#include "GameObject.h"
#include "Gift.h"
#include "Turtle.h"
#include "Goomba.h"
#include "Spiny.h"
#include "Boo.h"
#include "Coin.h"
#include "Star.h"
#include "Flag.h"
#include "Mashroom.h"
#include "World_Block.h"
#include "StaticBlock.h"
#include "SpecialBlock.h"
#include "ExtraAccesorios.h"
#include <typeinfo>
#include <map>
#include <string>
#include <typeindex>

//-------------------------------------------------------
//This is Collision class control all collisions in
//  the game between all the objects
//-----------------------------------------------------------------
namespace 
{
	void MarioGift(GameObject& m, GameObject& g) 
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Gift& gift = dynamic_cast<Gift&>(g);
		mario.handleCollision(gift);
		gift.handleCollision(mario);
	}
	void GiftMario(GameObject& g, GameObject& m)
	{
		MarioGift(m, g);
	} 

	void MarioStaticBlock(GameObject& m, GameObject& b)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		StaticBlock& block = dynamic_cast<StaticBlock&>(b);
		mario.handleCollision(block);
	}
	void StaticBlockMario(GameObject& b, GameObject& m)
	{
		MarioStaticBlock(m,b);
	}

	void spinyMario(GameObject& sp, GameObject& m)
	{
		Spiny& spiny = dynamic_cast<Spiny&>(sp);
		Mario& mario = dynamic_cast<Mario&>(m);
		spiny.handleCollision(mario);
	}
	void Mariospiny(GameObject& m, GameObject& sp)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Spiny& spiny = dynamic_cast<Spiny&>(sp);
		mario.handleCollision(spiny);
		spinyMario(sp, m);
	}

	void SpinyStaticBlock(GameObject& sp, GameObject& wb )
	{
		Spiny& spiny = dynamic_cast<Spiny&>(sp);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		spiny.handleCollision(block);
	}

	void  StaticBlockSpiny(GameObject& wb, GameObject& sp)
	{
		SpinyStaticBlock(sp, wb);
	}
	void TurtleMario(GameObject& tur,GameObject& m)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Turtle& turtle = dynamic_cast<Turtle&>(tur);
		turtle.handleCollision(mario);
	}
	void MarioTurtle(GameObject& m,GameObject& tur)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Turtle& turtle = dynamic_cast<Turtle&>(tur);
		mario.handleCollision(turtle);
		TurtleMario(tur, m);
	}
	void TurtleStaticBlock(GameObject& tur, GameObject& wb)
	{
		Turtle& turtle = dynamic_cast<Turtle&>(tur);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		turtle.handleCollision(block);
	}

	void StaticBlockTurtle(GameObject& wb, GameObject& tur)
	{
		TurtleStaticBlock(tur, wb);
	}

	void GoombaMario(GameObject& gm, GameObject& m)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Goomba& goomba = dynamic_cast<Goomba&>(gm);
		goomba.handleCollision(mario);
	}

	void MarioGoomba(GameObject& m, GameObject& gm)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		Goomba& goomba = dynamic_cast<Goomba&>(gm);
		mario.handleCollision(goomba);
		GoombaMario(gm,m);
	}
	void GoombaStaticBlock(GameObject& gm, GameObject& wb)
	{
		Goomba& goomba = dynamic_cast<Goomba&>(gm);
		StaticBlock& block = dynamic_cast<StaticBlock&>(wb);
		goomba.handleCollision(block);
	}

	void StaticBlockGoomba(GameObject& wb, GameObject& gm)
	{
		GoombaStaticBlock(gm,wb);
	}
	void MarioExtraAccesorios(GameObject& m, GameObject& ea)
	{
		Mario& mario = dynamic_cast<Mario&>(m);
		ExtraAccesorios& extraAccesorios = dynamic_cast<ExtraAccesorios&>(ea);
		mario.handleCollision(extraAccesorios);
	}

	void ExtraAccesoriosMario(GameObject& ea, GameObject& m)
	{
		MarioExtraAccesorios(m, ea);
	}
	void BooStaticBlock(GameObject& bo, GameObject& b)
	{
		Boo& boo = dynamic_cast<Boo&>(bo);
		StaticBlock& block = dynamic_cast<StaticBlock&>(b);
		boo.handleCollision(block);
	}
	void StaticBlockBoo(GameObject& b, GameObject& bo)
	{
		BooStaticBlock(bo, b);
	}

	void MarioBoo(GameObject& m, GameObject& bo)
	{
		Boo& boo = dynamic_cast<Boo&>(bo);
		Mario& mario = dynamic_cast<Mario&>(m);
		boo.handleCollision(mario);
		mario.handleCollision(boo);
	}
	void BooMario(GameObject& bo, GameObject& m)
	{
		MarioBoo(m, bo);
	}
	using HitFunctionPtr = void (*)(GameObject&, GameObject&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;
	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Mario), typeid(StaticBlock))] = &MarioStaticBlock;
		phm[Key(typeid(Mario), typeid(Goomba))] = &MarioGoomba;
		phm[Key(typeid(Mario), typeid(Turtle))] = &MarioTurtle;
		phm[Key(typeid(Mario), typeid(Gift))] = &MarioGift;
		phm[Key(typeid(Gift), typeid(Mario))] = &GiftMario;
		phm[Key(typeid(Goomba), typeid(StaticBlock))] = &GoombaStaticBlock;
		phm[Key(typeid(Goomba), typeid(Mario))] = &GoombaMario;
		phm[Key(typeid(StaticBlock), typeid(Goomba))] = &StaticBlockGoomba;
		phm[Key(typeid(StaticBlock), typeid(Mario))] = &StaticBlockMario;
		phm[Key(typeid(StaticBlock), typeid(Spiny))] = &StaticBlockSpiny;
		phm[Key(typeid(StaticBlock), typeid(Turtle))] = &StaticBlockTurtle;
		phm[Key(typeid(Spiny), typeid(StaticBlock))] = &SpinyStaticBlock;
		phm[Key(typeid(Mario), typeid(Spiny))] = &Mariospiny;
		phm[Key(typeid(Spiny), typeid(Mario))] = &spinyMario;
		phm[Key(typeid(Turtle), typeid(StaticBlock))] = &TurtleStaticBlock;
		phm[Key(typeid(Turtle), typeid(Mario))] = &TurtleMario;
		phm[Key(typeid(Mario), typeid(ExtraAccesorios))] = &MarioExtraAccesorios;
		phm[Key(typeid(ExtraAccesorios), typeid(Mario))] = &ExtraAccesoriosMario;
		phm[Key(typeid(Boo), typeid(StaticBlock))] = &BooStaticBlock;
		phm[Key(typeid(StaticBlock), typeid(Boo))] = &StaticBlockBoo;
		phm[Key(typeid(Mario), typeid(Boo))] = &MarioBoo;
		phm[Key(typeid(Boo), typeid(Mario))] = &BooMario;
		phm[Key(typeid(Mario), typeid(Mashroom))] = &MarioGift;
		phm[Key(typeid(Mashroom), typeid(Mario))] = &GiftMario;
		phm[Key(typeid(Mario), typeid(Flag))] = &MarioGift;
		phm[Key(typeid(Flag), typeid(Mario))] = &GiftMario;
		phm[Key(typeid(Mario), typeid(Coin))] = &MarioGift;
		phm[Key(typeid(Coin), typeid(Mario))] = &GiftMario;
		phm[Key(typeid(Mario), typeid(Star))] = &MarioGift;
		phm[Key(typeid(Star), typeid(Mario))] = &GiftMario;
		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();
    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    if (mapEntry == collisionMap.end())
    {
        return nullptr;
    }
    return mapEntry->second;
}
	void processCollision(GameObject& object1, GameObject& object2)
	{
		auto phf = lookup(typeid(object1), typeid(object2));
		if (!phf)
		{
			return;
		}
		phf(object1, object2);
	}
} 
// STL-algorithm to run of all pairs
template <typename FwdIt, typename Fn>
void for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
	for (; begin != end; ++begin)
		for (auto second = begin + 1; second != end; ++second)
			fn(*begin, *second);
}

