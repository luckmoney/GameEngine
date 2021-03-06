#pragma once
namespace Cocos {

	enum class IndexType {
		kIndexDataTypeInt8, kIndexDataTypeInt16, kIndexDataTypeInt32
	};

	class SceneIndexArrary {
	public:
		SceneIndexArrary(uint32_t* data,uint32_t size, IndexType type,const char *index)
		:m_data(data)
		,m_type(type)
		,m_size(size)
		, m_nMaterialIndex(index){

		}

		SceneIndexArrary()
		:m_data(0)
		,m_size(0)
		,m_nMaterialIndex(""){
		}

		const uint32_t* GetData() {
			return m_data;
		}
		const size_t& GetSize() {
			return m_size;
		}

		IndexType& GetType() {
			return m_type;
		}

		const uint32_t GetCount() {
			return m_size / sizeof(unsigned int);
		}

		const std::string GetMaterialIndex() const {
			return m_nMaterialIndex;
		}

	private:
		const uint32_t* m_data;
		const size_t m_size;
		IndexType m_type;
		const std::string m_nMaterialIndex;
	};
}