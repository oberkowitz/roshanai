// WAV file format

#ifndef __WAV_H__
#define __WAV_H__

#endif // __WAV_H__

// Chunk headers
typedef struct {
    uint32_t ckID;
    uint32_t cksize;
    uint16_t wFormatTag;
    uint16_t nChannels;
    uint32_t nSamplesPerSec;
    uint32_t nAvgBytesPerSec;
    uint16_t nBlockAlign;
    uint16_t wBitsPerSample;
    uint16_t cbSize;
    uint16_t wValidBitsPerSample;
    uint32_t dwChannelMask;
    uint32_t SubFormat[4];
} FmtChunk;

typedef struct {
    uint32_t RIFF_ID;
    uint32_t cksize;
    uint32_t WAVEID;
    FmtChunk fmtChunk;
} WAV_Header;


#define WAV_FORMAT_PCM 0x0001

