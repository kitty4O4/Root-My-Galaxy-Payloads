#ifndef P0_FINGERPRINT_H
#define P0_FINGERPRINT_H

#define P0_FINGERPRINT_WORDS 4
#define P0_FINGERPRINT { 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }

static const uint64_t p0_fingerprint_offsets[P0_FINGERPRINT_WORDS] = {
    0x0000, 0x0008, 0x0010, 0x0018
};

struct p0_fingerprint {
    uint64_t words[P0_FINGERPRINT_WORDS];
    uint64_t slide;
};

static const struct p0_fingerprint p0_fingerprints[] = {
    { .words = P0_FINGERPRINT, .slide = 0x00000000 }
};

#endif
