#pragma once

#include "FrameWork/RenderSystem.h"

namespace Cocos {
	class OpenglRender:public RenderSystem {
	public:
		void BeginScene();
		void EndScene();

		void BeginFrame();
		void EndFrame();

		void DrawPoint();
		void DrawLine();
		void DrawTriangle();

		void DrawGeometry();
		void DrawSkyBox();

		void DrawTerrain();

		void SetPipelineState(PipelineState*);

		void DrawBatch();

		bool setShaderParameter(const char* paramName,const uint32_t param);
		bool setShaderParameter(const char* paramName,const glm::mat4& mat) ;

	private:

		void InitGeometries();

		void initializeSkyBox();


		uint32_t m_CurrentShader;

		std::vector<GLuint> m_buffers;

		DrawBatchContext m_SkyBoxDrawBatchContext;
		DrawBatchContext m_TerrainDrawBatchContext;
	};

}