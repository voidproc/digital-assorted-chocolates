# include <Siv3D.hpp> // OpenSiv3D v0.6.6

enum class Scenes
{
	Title,
	Main,
};

void Main()
{
	constexpr Size sceneSize{ 128, 128 };
	Window::Resize(sceneSize);

	Scene::SetResizeMode(ResizeMode::Keep);

	int scale = 4;
	Window::Resize(sceneSize * scale);

	Scene::SetTextureFilter(TextureFilter::Nearest);
	const ScopedRenderStates2D renderState{ SamplerState::ClampNearest };

	const Texture texture_title{ U"images/title.png" };


	// Titleシーンから始まる

	Scenes scene = Scenes::Title;


	while (System::Update())
	{
		if (scene == Scenes::Title)
		{
			// Titleシーン

			Scene::SetBackground(Palette::Hotpink);

			texture_title.drawAt(Scene::CenterF());

			if (MouseL.down())
			{
				scene = Scenes::Main;
			}
		}
		else if (scene == Scenes::Main)
		{
			// Main シーン

			Scene::SetBackground(Palette::Hotpink);

		}
	}
}
