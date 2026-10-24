#include "String.h"
#include<cstring>


// default constructor.
mstring::mstring() 
	: m_data(new char[1]{'\0'}), 
	  m_size(0), 
	  m_capacity(0){}


// c-string constructor
mstring::mstring(const char* str) 
	: m_data(nullptr),
	  m_size(0),
	  m_capacity(0) {
			if (str == nullptr) {
				m_data = new char[1] {'\0'};
				return;
			}
			
			const size_t len = std::strlen(str);
			char* buffer = new char[len + 1];

			std::memcpy(buffer, str, len + 1);
			m_data = buffer;
			m_size = len;
			m_capacity = len;

	  }


mstring::mstring(const mstring& rhs) 
	: m_data(new char[rhs.m_size + 1]),
	  m_size(rhs.m_size),
	  m_capacity(rhs.m_capacity){
		std::memcpy(m_data, rhs.m_data, m_size + 1);

	}


mstring& mstring::operator=(const mstring& rhs) {
	if (this == &rhs) {
		return *this;
	}

	char* buffer = new char[rhs.m_size + 1];
	std::memcpy(buffer, rhs.m_data, rhs.m_size);

	delete[] m_data;

	m_data = buffer;
	m_size = rhs.m_size;
	m_capacity = rhs.m_size;

	return *this;
}

size_t mstring::size() const noexcept {
	return m_size;
}

size_t mstring::capacity() const noexcept {
	return m_capacity;
}

const char* mstring::c_str() const noexcept{
	return m_data;
}



mstring::~mstring() {
	delete[] m_data;
}