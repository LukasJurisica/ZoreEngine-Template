#pragma once

#include <zore/core/Application.hpp>
#include <zore/Graphics.hpp>
#include <zore/Events.hpp>
#include <zore/core/Camera.hpp>

namespace zore {

	class DemoApplication : public Application {
	public:
		DemoApplication(LaunchOptions options);
		~DemoApplication() = default;

		void Run() override;

	private:
		bool OnKeyPress(const KeyPressedEvent& e);

	private:
		Shader m_shader;
		Event::MultiHandler m_handler;
		Camera2D m_camera;
		bool m_enable_console = false;
	};
}