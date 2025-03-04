#include "main.hpp"

#include <zore/devices/Window.hpp>
#include <zore/devices/KeyCodes.hpp>
#include <zore/graphics/RenderEngine.hpp>
#include <zore/ui/Editor.hpp>
#include <zore/ui/Console.hpp>
#include <zore/Debug.hpp>

using namespace zore;

DemoApplication::DemoApplication(LaunchOptions options) : Application(options), m_camera(Window::GetAspectRatio(), 5) {
	m_handler.Register(&DemoApplication::OnKeyPress, this);

	m_shader.SetSource("example.glsl").Compile().Bind();
	m_shader.SetFloat4("camera", { m_camera.GetPosition(), m_camera.GetScale() });

	RenderEngine::SetClearColour(1.0, 0.0, 0.0, 1.0);
	RenderEngine::SetTopology(MeshTopology::TRIANGLE_STRIP);
	RenderEngine::SetVSync(false);
	RenderEngine::SetDepthTest(false);
	RenderEngine::SetFaceCulling(false);
}

void DemoApplication::Run() {
	VertexLayout layout(m_shader, {});

	while (!Window::ShouldClose()) {
		RenderEngine::Clear();
		RenderEngine::DrawLinear(4);

		if (m_enable_console) {
			Editor::BeginFrame();
			Console::Draw();
			Editor::EndFrame();
		}
		Window::Update();
	}
}

bool DemoApplication::OnKeyPress(const KeyPressedEvent& e) {
	if (e.key == KEY_ESCAPE)
		m_enable_console = !m_enable_console;
	return false;
}

Application* Application::Create() {
	return new DemoApplication({
		.enable_audio = false
		});
}