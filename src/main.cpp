#include <zore/core/Application.hpp>
#include <zore/devices/Window.hpp>
#include <zore/graphics/RenderEngine.hpp>
#include <zore/ui/Editor.hpp>
#include <zore/ui/Console.hpp>

#include <zore/Debug.hpp>
#include <zore/utils/Time.hpp>

namespace zore {

	class DemoApplication : public Application {
	public:
		DemoApplication(LaunchOptions options) : Application(options) {
			RenderEngine::SetVSync(false);
		}

		void Run() {
			RenderEngine::SetClearColour(1.0, 0.0, 0.0, 1.0);

			while (!Window::ShouldClose()) {
				RenderEngine::Clear();
				Editor::BeginFrame();
				Console::Draw();
				Editor::EndFrame();
				Window::Update();
			}
		}

	private:

	};

	Application* Application::Create() {
		return new DemoApplication({
			.enable_audio = false
			});
	}
}