
#ifndef CPP_LANG_HPP
#define CPP_LANG_HPP

// must be C++11 or later

#if __cplusplus < 201103
#	error "C++ is too old"
#endif

// [[deprecated]]
#if __cplusplus >= 201402
#	define CPP_DEPRECATED [[depreacted]]
#else
#	define CPP_DEPRECATED [[gnu::depreacted]]
#endif

// static_assert
#if __cpp_static_assert >= 201411
#	define STATIC_ASSERT(x) static_assert(x)
#else
#	define STATIC_ASSERT(x) static_assert(x, #x)
#endif


#endif // !CPP_LANG_HPP

