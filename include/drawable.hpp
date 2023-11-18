#ifndef VOXELCRAFT_DRAWABLE_HPP
#define VOXELCRAFT_DRAWABLE_HPP

#include "material.hpp"
#include "transform.hpp"

class Drawable {
public:
	virtual ~Drawable() = default;

	virtual Material getMaterial() const = 0;
	virtual Transform getTransform() const = 0;
};

#endif
