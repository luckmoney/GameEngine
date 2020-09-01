#include "GeometrySubPass.h"
#include "Framework/Render/OpenglRender.h"

namespace Cocos {
	void GeometrySubPass::Draw() {
		
		auto pipelineState = g_PipelineManager->GetPipelineState("Basic");
		g_openglRender->SetPipelineState(&pipelineState);

		g_openglRender->DrawBatch();
	}
}