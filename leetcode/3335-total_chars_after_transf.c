#include <stdio.h>

void print_array(int *a, int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        if (i != len-1) {
            printf("%d, ", a[i]);
        }
        else {
            printf("%d ]\n", a[i]);
        }
    }
}

/*****************************************************************/

#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

unsigned int mod(long long x) {
    return (x >= 0) ? (x % MOD) : (MOD - (-x) % MOD) % MOD;
}

int lengthAfterTransformations(char* s, int t) {
    long long *freq = (long long *) calloc(26, sizeof(long long));
    long long *nfreq = (long long *) calloc(26, sizeof(long long));

    // Initialize frequencies
    for (; *s != '\0'; s++) {
        freq[*s - 'a']++;
    }

    for (int i = 0; i < t; i++) {
        // Reset nfreq to current freq at the start of each iteration
        memcpy(nfreq, freq, 26 * sizeof(long long));
        
        for (int c = 0; c < 26; c++) {
            if (freq[c] == 0) continue;
            
            if (c == 25) {
                // Handle 'z' case
                nfreq[0] = mod((long long)nfreq[0] + freq[25]);
                nfreq[1] = mod((long long)nfreq[1] + freq[25]);
                nfreq[25] = mod(nfreq[25] - freq[25]);
            } else {
                // Handle other letters
                nfreq[c+1] = mod((long long)nfreq[c+1] + freq[c]);
                nfreq[c] = mod(nfreq[c] - freq[c]);
            }
        }
        
        // Update freq for next iteration
        memcpy(freq, nfreq, 26 * sizeof(long long));
    }
    
    // Calculate total
    long long total = 0;
    for (int c = 0; c < 26; c++) {
        total = mod(total + freq[c]);
    }
    
    free(freq);
    free(nfreq);
    
    return (unsigned int)total;
}

/*****************************************************************/

int main() {
    printf("result = %d\n", lengthAfterTransformations("abcyy", 2));
    return 0;
}
