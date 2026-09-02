#ifndef P0_FINGERPRINT_H
#define P0_FINGERPRINT_H

// ========== P0 FINGERPRINT DEFINITIONS ==========
// This fingerprint is used to identify the correct kernel image
// during the KASLR brute-force phase.

#define P0_FINGERPRINT_WORDS 4

// Your fingerprint bytes from earlier: 08 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
#define P0_FINGERPRINT { 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

// Offsets for each word in the fingerprint
static const uint64_t p0_fingerprint_offsets[P0_FINGERPRINT_WORDS] = {
    0x0000,  // Word 0
    0x0008,  // Word 1
    0x0010,  // Word 2
    0x0018   // Word 3
};

// The actual fingerprint data structure
struct p0_fingerprint {
    uint64_t words[P0_FINGERPRINT_WORDS];
    uint64_t slide;
};

// Define the fingerprint(s) to search for
static const struct p0_fingerprint p0_fingerprints[] = {
    {
        .words = P0_FINGERPRINT,
        .slide = 0x00000000
    }
};

#endif // P0_FINGERPRINT_H
