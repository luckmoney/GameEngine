#pragma once

#include "FrameWork/RenderSystem.h"

namespace Cocos {

	class OpenglRender:public RenderSystem {
	public:
		void BeginScene();
		void EndScene();

		void BeginFrame(const Frame&);
		void EndFrame();

		void SetPerFrameConstants(const DrawFrameContext&);
		void SetLightInfo(const LightInfo&);

		virtual int32_t GenerateShadowMapArray(const uint32_t width, const uint32_t height, const uint32_t count);

		virtual void BeginShadowMap(const int32_t, const int32_t, const uint32_t, const uint32_t, const int32_t, const Frame&);
		virtual void EndShadowMap(const int32_t, const int32_t);
		virtual void SetShadowMaps(const Frame&);



		void DrawPoint();
		void DrawLine();
		void DrawTriangle();

		void DrawGeometry();
		void DrawSkyBox();

		void DrawTerrain();

		void BeginRenderToTexture(uint32_t texture_id,uint32_t,uint32_t,uint32_t);
		void EndRenderToTexture();

		void SetPipelineState(PipelineState*,const Frame&);

		void DrawBatch(Frame&);

		bool setShaderParameter(const char* paramName,const uint32_t param);
		bool setShaderParameter(const char* paramName,const glm::mat4& mat) ;

	private:

		void InitGeometries();

		void initializeSkyBox();


		uint32_t m_CurrentShader;

		std::vector<GLuint> m_buffers;

		DrawBatchContext m_SkyBoxDrawBatchContext;
		DrawBatchContext m_TerrainDrawBatchContext;

		uint32_t m_uboDrawFrameConstant[2] = {0};
		uint32_t m_uboShadowMatricesConstant[2] = { 0 };

		uint32_t m_uboLightInfo[2] = { 0 };

		uint32_t m_ShadowMapFramebufferName;
	};

}