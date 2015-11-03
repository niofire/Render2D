#pragma once
#include "render_context.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void attach_to_context(RenderContext& context);
};

