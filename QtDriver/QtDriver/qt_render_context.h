#pragma once
#include "base_render2d_context.h"

class QtRenderContext : public Render2D::BaseRender2DContext
{
public:
	QtRenderContext();
	~QtRenderContext();

	void bind_context();
	void unbind_context();

	void swap_buffers();
};

