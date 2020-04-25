#if defined(_WIN32) || defined(__WIN32__)
#define WOE_IS_ME
#endif

char
pathsep(void)
{
#ifdef WOE_IS_ME
	return '\\';
#else
	return '/';
#endif
}
