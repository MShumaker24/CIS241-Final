#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *, int);

int main() {
	char *s;
	size_t maxn = 50;
	int ret = EOF + 1;

	s = (char *) malloc(sizeof(char)*maxn);
	while (ret != EOF) {
		ret = getline(&s, &maxn, stdin);
		if (ret != EOF) {
			reverse(s, ret);
		}
	}

	free(s);
	return 0;
}

void reverse(char *word, int length) {
	char newWord[length];
	char *topptr = newWord;

	//reverse the first half of the word
	if ((length - 1) % 2 == 0) {
		for (int i = length / 2 - 1; i >= 0; i--) {
			*topptr = *(word + i);
			topptr = topptr + 1;
		}

		//*topptr = char[length / 2]

		//reverse the second half
		for (int i = length - 2; i > length / 2 - 1; i--) {
			*topptr = *(word + i);
			topptr = topptr + 1;
		}
	}
	else {
		length = length - 1;
		for (int i = length / 2 - 1; i >= 0; i--) {
			*topptr = *(word + i);
			topptr = topptr + 1;
		}
		*(topptr) = *(word + length / 2);
		topptr = topptr + 1;
		for (int i = length - 1; i >= length / 2 + 1; i--) {
			*topptr = *(word + i);
			topptr = topptr + 1;
		}
	}

	*topptr = '\0';
	/*
	for (int i = 0; i < length; i++) {
		printf("%s", newWord[i]);
	}
	*/

	printf("%s", newWord);
	printf("\n");
}
