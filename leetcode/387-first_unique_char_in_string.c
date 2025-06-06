#define INFINITY 1000000

typedef struct {
    int first_index;
    int count;
} Repeat;

int firstUniqChar(char* s) {
    Repeat repeat[26];

    for (int c = 0; c < 26; c++) {
        repeat[c].first_index = INFINITY;
        repeat[c].count = 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (repeat[s[i] - 'a'].first_index == INFINITY) {
            repeat[s[i] - 'a'].first_index = i;
        }
        repeat[s[i] - 'a'].count++;
    }

    int first_uniq = INFINITY;
    for (int c = 0; c < 26; c++) {
        if (repeat[c].count == 1 && repeat[c].first_index < first_uniq) {
            first_uniq = repeat[c].first_index;
        }
    }

    return first_uniq == INFINITY ? -1 : first_uniq;
}
