#pragma once
#include "Utilities.h"

class Animation
{
public:
  Animation(float switchTime):switchTime(switchTime),m_animation(animationType::standing) {}
  ~Animation() = default;
  void animation(sf::Sprite& sprite, float deltaTime, direction dir);
  void addAttackVector(std::vector<sf::IntRect>& vector) {m_attackVector = vector;}
  void addStandVector(std::vector<sf::IntRect>& vector) {m_standVector = vector;}
  void addMoveVector(std::vector<sf::IntRect>& vector) {m_moveVector = vector;}
  void addDefeatVector(std::vector<sf::IntRect>& vector) {m_defeatVector = vector;}
  void addRotateVector(std::vector<sf::IntRect>& vector) {m_rotateVector = vector;}
  void addJumpVector(std::vector<sf::IntRect>& vector) {m_jumpVector = vector;}
  void addInjuredVector(std::vector<sf::IntRect>& vector) {m_injuredVector = vector;}
  void addFlyVector(std::vector<sf::IntRect>& vector) {m_flyVector = vector;}
  void updateCurrentAnimation(animationType newAnimation);
  void setAnimationFlags(animationType &newAnimation);
  void resetAnimations();
  void setAnimation();
  void setAnimationType(animationType animation) { m_animation = animation; }
  void rotate() {inRotation = true;}
  void setMove(){inMove = true;}
  void setJump() {inJump = true;}
  void setAttack() {inAttack = true;}
  void setFly() {inFly = true;}
  void setDefeat() {inDefeat = true;}
  void setInjured() {inInjured = true;}
  void setStand() {inStand = true; inMove = false;}
  bool isRotate() {return inRotation ;}
  bool isMove(){return inMove;}
  bool isJump() {return inJump;}
  bool isAttack() {return inAttack;}
  bool isFly() {return inFly;}
  bool isDefeat() {return inDefeat;}
  bool isDead() {return m_defeated;}
  bool inrotation() { return inRotation;}
  void setRotation() { inRotation = true; }
  bool isInjured() { return inInjured && injuredIndex != 0; }
  void isNotInjured() { inInjured = false; injuredIndex = 0; }
  animationType getCurrentAnimation() { return m_animation; }

private:
	void manageAnimation(float& deltaTime, int& index, int& size, bool& in_animation);
	bool inRotation = false,
		 inJump = false,
		 inAttack = false,
		 inFly = false,
		 inDefeat = false,
		 inInjured = false,
		 inMove = false,
		 inStand = false;
	int standIndex = 0;
	int	moveIndex = 0;
	int	attackIndex = 0;
	int	defeatIndex = 0,
		rotateIndex = 0,
		jumpIndex = 0,
		flyIndex = 0,
		injuredIndex = 0,
		currIndex = 0;
	std::vector<sf::IntRect>
		m_standVector, m_moveVector,
		m_defeatVector, m_jumpVector,
		m_injuredVector, m_rotateVector,
		m_attackVector,m_flyVector;
	float switchTime;
	bool m_defeated = false;
	animationType m_animation;
};