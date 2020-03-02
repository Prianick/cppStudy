#include <iostream>

using namespace std;

unsigned strlen1(const char *str)
{
	unsigned len = 0;

	while (str[len] != '\0') {
		++len;
	}

	return len;
}

int strstr2(const char *text, const char *pattern)
{
    for(int i = 0; *text != '\0' || *pattern == '\0'; i++, text++)
        for(int j = 0; *(text + j) == *(pattern + j) || *pattern == '\0'; j++)
            if(*(pattern + j + 1) == '\0' || *pattern == '\0')
                return i;
    return -1; 
}

int strstr1(const char *text, const char *pattern)
{
	if (strlen1(pattern) > strlen1(text)) {
		return -1;
	}
	if (!*pattern || pattern == text) {
		return 0;
	}
	int res = -1;
	int pointer = 0;
	const char * textPos = 0;
	const char * patternStart = 0;
	
	patternStart = pattern;

	while (*text) {
		textPos = text;

		while (*pattern) {
			// cout << "text " << *text << " ";
			// cout << "pattern " << *pattern << " ";

			if (*pattern == *text) {
				// cout << " ok ";
				++pattern;
				++text;
			} else {
				pattern = patternStart;
				// cout << " false ";
				text = textPos;
				res = -1;
				break;
			}

			if (!*pattern) {
				// cout << " end ";
				res = pointer;
				break;
			}
		}

		++pointer;
		++text;
	}
	return res;
}

void test1()
{
	struct test{
	    int ret_value;
	    const char *text;
	    const char *pattern;
	};
	test tests[] = {
	        {0, "", ""}, //0
	        {0, "a", ""}, //1
	        {0, "a", "a"}, //2
	        {-1, "a", "b"}, //3
	        {0, "aa", ""}, //4
	        {0, "aa", "a"}, //5
	        {0, "ab", "a"}, //6
	        {1, "ba", "a"}, //7
	        {-1, "bb", "a"}, //8
	        {0, "aaa", ""}, //9
	        {0, "aaa", "a"}, //10
	        {1, "abc", "b"}, //11
	        {2, "abc", "c"}, //12
	        {-1, "abc", "d"}, //13
	        {-1, "a", "aa"}, //14
	        {-1, "a", "ba"}, //15
	        {-1, "a", "ab"}, //16
	        {-1, "a", "bb"}, //17
	        {-1, "a", "aaa"}, //18
	        {-1, "aa", "aaa"}, //19
	        {0, "aaa", "aaa"}, //20
	        {0, "aaab", "aaa"}, //21
	        {1, "baaa", "aaa"}, //22
	        {1, "baaaa", "aaa"}, //23
	        {1, "baaab", "aaa"}, //24
	        {-1, "abd", "abc"}, //25
	        {2, "ababc", "abc"}, //26
	        {3, "abdabc", "abc"}, //27
	        {-1, "", "a"}, //28
	        {2, "asasaf", "asaf"}, //29
	        {2, "ababac", "abac"}, //30
	        {2, "a8abab", "ab"}, //31
	        {8, "hhhhhefrherhrh", "her"} //32
	};
	for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
	    int ret = strstr2(tests[i].text, tests[i].pattern);
	    (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
	     cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
	}
}

int main(int argc, char const *argv[])
{
	char str[] = "abc";
	char pattern[] = "abd";
	// char * p = 0;
	// int res = -1;

	// int arr[5] = {1,2,3};

	// p = &str[0];

	// cout << strstr1(str, pattern) ;

	// cout << strstr1(p, p) << endl;

	test1();
	
	// cout << strstr1(str, pattern) << endl;

	return 0;
}