#pragma once

namespace Render2D{
	class BaseRender2DContext
	{
	public:
		virtual void bind_context() = 0;
		virtual void unbind_context() = 0;
		virtual void swap_buffers() = 0;
	};


}