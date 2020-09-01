#include "Framework/RenderSystem.h"

namespace Cocos {
	RenderSystem *g_RenderSystem = new RenderSystem();


	int RenderSystem::Initialize() {

		ShadowPass *shadow = new ShadowPass();
		m_passes.push_back(shadow);

		ForwardPass *forward = new ForwardPass();
		forward->Init();
		m_passes.push_back(forward);

		//g_openglRender->BeginScene();

		return 0;
	}

	void RenderSystem::Tick() {
		g_openglRender->BeginFrame();
		auto iter = m_passes.begin();
		while (iter != m_passes.end())
		{
			(*iter)->Draw();
			++iter;
		}
		g_openglRender->EndFrame();
	}

	void RenderSystem::Finalize() {
		auto iter = m_passes.begin();
		while (iter != m_passes.end())
		{
			delete (*iter);
			++iter;
		}
		g_openglRender->EndScene();
	}

}
