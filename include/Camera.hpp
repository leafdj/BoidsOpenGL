#ifndef INCLUDE_CAMERA_HPP
#define INCLUDE_CAMERA_HPP

#pragma once

#include "Entity.hpp"

class Camera : public Entity {	// Making this an entity allows us to use all of the movement infrastructure from there.
public:							// Thinking about it, a component system would probably be ideal.
	Camera();

	void Init(glm::vec3 initPos = { 0, 10, -10 });
	void SetLookTarget(glm::vec3 _lookTarget) { lookTarget = _lookTarget; }

	void RotateLeft(const glm::vec3 &_point, float angle);
	void RotateRight(const glm::vec3 &_point, float angle);
	void RotateUp(const glm::vec3 &_point, float angle);
	void RotateDown(const glm::vec3 &_point, float angle);
	void RotateAround(const glm::vec3 &_point, const glm::vec3 &_axis, float angle);

	glm::mat4 GetViewProjection();
private:
	glm::mat4 projection;
	glm::vec3 lookTarget;
};

#endif // !INCLUDE_CAMERA_HPP