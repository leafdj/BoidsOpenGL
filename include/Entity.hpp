#ifndef INCLUDE_ENTITY_HPP
#define INCLUDE_ENTITY_HPP

#pragma once

#include "Model.hpp"

#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

class Entity {
public:
	Entity();

	void Init(glm::vec3 initialPosition = { 0,0,0 }, Model *initialModel = NULL);
	void Update(float deltaTime);
	void Render(glm::mat4 viewProjection);

	void SetForce(const glm::vec3 &_force) { mForce = _force; }
	void AddVelocity(const glm::vec3 &_vel) { SetVelocity(GetVelocity() + _vel); }
	glm::vec3 GetVelocity() { return mVelocity; }
	void SetVelocity(const glm::vec3 &_vel);
	void SetModel(Model *model) { mModel = model; }
	glm::vec3 GetPosition() { return mPosition; }
	void SetPosition(const glm::vec3 &position, bool reset = false);
	void Translate(const glm::vec3 &movement) { 
		mPosition += movement; }

protected:
	glm::vec3 mPosition;
	glm::vec3 mVelocity;
	GLfloat maxVelocity;
	glm::vec3 mForce;
private:
	Model *mModel;
	GLfloat mMass;
	glm::vec3 prevPosition;
};

#endif // !INCLUDE_ENTITY_HPP