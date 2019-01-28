#pragma once

#define initialiseSingleton( type ) \
  template <> type * Singleton < type > :: m_singleton = 0

#define initialiseTemplateSingleton( temp, type ) \
  template <> temp< type > * Singleton < temp< type > > :: m_singleton = 0

#define createFileSingleton( type ) \
  initialiseSingleton( type ); \
  type the##type

template <typename type>
class Singleton
{
public:
	Singleton() {
		this->m_singleton = static_cast<type *>(this);
	}
	virtual ~Singleton() {
		this->m_singleton = 0;
	}

	inline static type &getSingleton() {
		return *m_singleton;
	}
	inline static type *getSingletonPtr() {
		return m_singleton;
	}
	static type &getInstance() {
		static type instance;
		m_singleton = &instance;
		return *m_singleton;
	}

private:
	static type *m_singleton;
};

