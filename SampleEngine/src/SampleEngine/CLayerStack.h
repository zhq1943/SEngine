#pragma once

#include"SampleEngine/Core.h"
#include"CLayer.h"

#include<vector>

namespace SEngine {
	class SE_API CLayerStack
	{
	public:
		CLayerStack();
		~CLayerStack();

		void PushLayer(CLayer* layer);
		void PushOverLay(CLayer* layer);
		void PopLayer(CLayer* layer);
		void PopOverLayer(CLayer* layer);

		std::vector<CLayer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<CLayer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<CLayer*> m_Layers;
		std::vector<CLayer*>::iterator m_LayerInsert;
	};
}