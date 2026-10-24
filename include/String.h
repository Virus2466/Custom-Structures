#pragma once

#include<iostream>
#include<cstddef>


class mstring {
public:
	mstring();
	explicit mstring(const char* str);
	~mstring();


	// copy
	mstring(const mstring& rhs);
	mstring& operator=(const mstring& rhs);

	size_t size() const noexcept;
	size_t capacity() const noexcept;
	const char* c_str() const noexcept;

private:
	char* m_data;
	std::size_t m_size;
	std::size_t m_capacity;

};
