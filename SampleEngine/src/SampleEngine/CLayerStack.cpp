#include"sepch.h"
#include"CLayerStack.h"

namespace SEngine {
	CLayerStack::CLayerStack()
	{

	}

	CLayerStack::~CLayerStack()
	{
		for (CLayer* layer:m_Layers)
		{
			delete layer;
		}
	}

	void CLayerStack::PushLayer(CLayer* layer)
	{
		 m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
	}

	void CLayerStack::PushOverLay(CLayer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	void CLayerStack::PopLayer(CLayer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void CLayerStack::PopOverLayer(CLayer* overLayer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overLayer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}