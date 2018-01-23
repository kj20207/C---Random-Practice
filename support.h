#define LABEL_SIZE 6

// Re-used as extern variable in test.c
int variable = 10;

struct test_struct{
	int i;
	float f;
	char label[LABEL_SIZE];
};

union test_union{
	int i;
	float f;
	char label[LABEL_SIZE];
};