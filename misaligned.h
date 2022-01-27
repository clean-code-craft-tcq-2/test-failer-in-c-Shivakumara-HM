ColorPair GetColorFromPairNumber(int pairNumber);
void testNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor);
int printColorMap() ;

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

