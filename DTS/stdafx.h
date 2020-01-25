// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdint.h>

#define DTS_MAX_CORE_SIZE      16384
#define DTS_MAX_EXTENSION_SIZE 32768

 typedef enum
 {
     DTS_SYNCWORD_CORE           = 0x7FFE8001,
     DTS_SYNCWORD_XCH            = 0x5A5A5A5A,
     DTS_SYNCWORD_XXCH           = 0x47004A03,
     DTS_SYNCWORD_X96K           = 0x1D95F262,
     DTS_SYNCWORD_XBR            = 0x655E315E,
     DTS_SYNCWORD_LBR            = 0x0A801921,
     DTS_SYNCWORD_XLL            = 0x41A29547,
     DTS_SYNCWORD_SUBSTREAM      = 0x64582025,
     DTS_SYNCWORD_SUBSTREAM_CORE = 0x02b09261,
 } dts_syncword;
 
 typedef enum
 {
     DTS_XXCH_LOUDSPEAKER_MASK_C    = 0x00000001,    /* Centre in front of listener */
     DTS_XXCH_LOUDSPEAKER_MASK_L    = 0x00000002,    /* Left in front */
     DTS_XXCH_LOUDSPEAKER_MASK_R    = 0x00000004,    /* Right in front */
     DTS_XXCH_LOUDSPEAKER_MASK_LS   = 0x00000008,    /* Left surround on side in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_RS   = 0x00000010,    /* Right surround on side in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_LFE1 = 0x00000020,    /* Low frequency effects subwoofer */
     DTS_XXCH_LOUDSPEAKER_MASK_CS   = 0x00000040,    /* Centre surround in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_LSR  = 0x00000080,    /* Left surround in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_RSR  = 0x00000100,    /* Right surround in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_LSS  = 0x00000200,    /* Left surround on side */
     DTS_XXCH_LOUDSPEAKER_MASK_RSS  = 0x00000400,    /* Right surround on side */
     DTS_XXCH_LOUDSPEAKER_MASK_LC   = 0x00000800,    /* Between left and centre in front */
     DTS_XXCH_LOUDSPEAKER_MASK_RC   = 0x00001000,    /* Between right and centre in front */
     DTS_XXCH_LOUDSPEAKER_MASK_LH   = 0x00002000,    /* Left height in front */
     DTS_XXCH_LOUDSPEAKER_MASK_CH   = 0x00004000,    /* Centre Height in front */
     DTS_XXCH_LOUDSPEAKER_MASK_RH   = 0x00008000,    /* Right Height in front */
     DTS_XXCH_LOUDSPEAKER_MASK_LFE2 = 0x00010000,    /* Second low frequency effects subwoofer */
     DTS_XXCH_LOUDSPEAKER_MASK_LW   = 0x00020000,    /* Left on side in front */
     DTS_XXCH_LOUDSPEAKER_MASK_RW   = 0x00040000,    /* Right on side in front */
     DTS_XXCH_LOUDSPEAKER_MASK_OH   = 0x00080000,    /* Over the listener's head */
     DTS_XXCH_LOUDSPEAKER_MASK_LHS  = 0x00100000,    /* Left height on side */
     DTS_XXCH_LOUDSPEAKER_MASK_RHS  = 0x00200000,    /* Right height on side */
     DTS_XXCH_LOUDSPEAKER_MASK_CHR  = 0x00400000,    /* Centre height in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_LHR  = 0x00800000,    /* Left height in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_RHR  = 0x01000000,    /* Right height in rear */
     DTS_XXCH_LOUDSPEAKER_MASK_CL   = 0x02000000,    /* Centre in the plane lower than listener's ears */
     DTS_XXCH_LOUDSPEAKER_MASK_LL   = 0x04000000,    /* Left in the plane lower than listener's ears */
     DTS_XXCH_LOUDSPEAKER_MASK_RL   = 0x08000000,    /* Right in the plane lower than listener's ears */
 } dts_loudspeaker_mask;
 
 typedef enum
 {
     DTS_CHANNEL_LAYOUT_C       = 0x0001,    /* Centre in front of listener */
     DTS_CHANNEL_LAYOUT_L_R     = 0x0002,    /* Left/Right in front */
     DTS_CHANNEL_LAYOUT_LS_RS   = 0x0004,    /* Left/Right surround on side in rear */
     DTS_CHANNEL_LAYOUT_LFE1    = 0x0008,    /* Low frequency effects subwoofer */
     DTS_CHANNEL_LAYOUT_CS      = 0x0010,    /* Centre surround in rear */
     DTS_CHANNEL_LAYOUT_LH_RH   = 0x0020,    /* Left/Right height in front */
     DTS_CHANNEL_LAYOUT_LSR_RSR = 0x0040,    /* Left/Right surround in rear */
     DTS_CHANNEL_LAYOUT_CH      = 0x0080,    /* Centre height in front */
     DTS_CHANNEL_LAYOUT_OH      = 0x0100,    /* Over the listener's head */
     DTS_CHANNEL_LAYOUT_LC_RC   = 0x0200,    /* Between left/right and centre in front */
     DTS_CHANNEL_LAYOUT_LW_RW   = 0x0400,    /* Left/Right on side in front */
     DTS_CHANNEL_LAYOUT_LSS_RSS = 0x0800,    /* Left/Right surround on side */
     DTS_CHANNEL_LAYOUT_LFE2    = 0x1000,    /* Second low frequency effects subwoofer */
     DTS_CHANNEL_LAYOUT_LHS_RHS = 0x2000,    /* Left/Right height on side */
     DTS_CHANNEL_LAYOUT_CHR     = 0x4000,    /* Centre height in rear */
     DTS_CHANNEL_LAYOUT_LHR_RHR = 0x8000,    /* Left/Right height in rear */
 } dts_channel_layout;
 

 typedef enum
 {
     DTS_SUBSTREAM_TYPE_NONE      = 0,
     DTS_SUBSTREAM_TYPE_CORE      = 1,
     DTS_SUBSTREAM_TYPE_EXTENSION = 2,
 } dts_substream_type;
 
 typedef struct
 {
     uint32_t sampling_frequency;
     uint32_t frame_duration;
     uint16_t frame_size;
     uint16_t channel_layout;
     uint8_t  channel_arrangement;
     uint8_t  xxch_lower_planes;
     uint8_t  extension_audio_descriptor;
     uint8_t  pcm_resolution;
 } dts_core_info_t;
 
 typedef struct
 {
     uint32_t sampling_frequency;
     uint32_t frame_duration;
     uint16_t channel_layout;
     uint8_t  xxch_lower_planes;
     uint8_t  bStaticFieldsPresent;
     uint8_t  bMixMetadataEnbl;
     uint8_t  bOne2OneMapChannels2Speakers;
     uint8_t  nuNumMixOutConfigs;
     uint8_t  nNumMixOutCh[4];
     uint8_t  number_of_assets;
     uint8_t  stereo_downmix;
     uint8_t  representation_type;
     uint8_t  bit_resolution;
 } dts_extension_info_t;
 
 typedef struct
 {
     uint32_t sampling_frequency;
     uint32_t frame_duration;
     uint16_t channel_layout;
     uint8_t  bit_width;
 } dts_lossless_info_t;
 
 typedef struct
 {
     uint32_t sampling_frequency;
     uint32_t frame_duration;
     uint16_t channel_layout;
     uint8_t  stereo_downmix;
     uint8_t  lfe_present;
     uint8_t  duration_modifier;
     uint8_t  sample_size;
 } dts_lbr_info_t;
 
 typedef enum
 {
     DTS_CORE_SUBSTREAM_CORE_FLAG = 0x00000001,
     DTS_CORE_SUBSTREAM_XXCH_FLAG = 0x00000002,
     DTS_CORE_SUBSTREAM_X96_FLAG  = 0x00000004,
     DTS_CORE_SUBSTREAM_XCH_FLAG  = 0x00000008,
     DTS_EXT_SUBSTREAM_CORE_FLAG  = 0x00000010,
     DTS_EXT_SUBSTREAM_XBR_FLAG   = 0x00000020,
     DTS_EXT_SUBSTREAM_XXCH_FLAG  = 0x00000040,
     DTS_EXT_SUBSTREAM_X96_FLAG   = 0x00000080,
     DTS_EXT_SUBSTREAM_LBR_FLAG   = 0x00000100,
     DTS_EXT_SUBSTREAM_XLL_FLAG   = 0x00000200,
 } lsmash_dts_construction_flag;


 typedef struct
 {
     uint32_t DTSSamplingFrequency;  /* the maximum sampling frequency stored in the compressed audio stream */
     uint32_t maxBitrate;            /* the peak bit rate, in bits per second, of the audio elementary stream for the duration of the track,
                                      * including the core substream (if present) and all extension substreams.
                                      * If the stream is a constant bit rate, this parameter shall have the same value as avgBitrate.
                                      * If the maximum bit rate is unknown, this parameter shall be set to 0. */
     uint32_t avgBitrate;            /* the average bit rate, in bits per second, of the audio elementary stream for the duration of the track,
                                      * including the core substream and any extension substream that may be present. */
     uint8_t  pcmSampleDepth;        /* the bit depth of the rendered audio
                                      * The value is 16 or 24 bits. */
     uint8_t  FrameDuration;         /* the number of audio samples decoded in a complete audio access unit at DTSSamplingFrequency
                                      *   0: 512, 1: 1024, 2: 2048, 3: 4096 */
     uint8_t  StreamConstruction;    /* complete information on the existence and of location of extensions in any synchronized frame */
     uint8_t  CoreLFEPresent;        /* the presence of an LFE channel in the core
                                      *   0: none
                                      *   1: LFE exists */
     uint8_t  CoreLayout;            /* the channel layout of the core within the core substream
                                      * If no core substream exists, this parameter shall be ignored and ChannelLayout or
                                      * RepresentationType shall be used to determine channel configuration. */
     uint16_t CoreSize;              /* The size of a core substream AU in bytes.
                                      * If no core substream exists, CoreSize = 0. */
     uint8_t  StereoDownmix;         /* the presence of an embedded stereo downmix in the stream
                                      *   0: none
                                      *   1: embedded downmix present */
     uint8_t  RepresentationType;    /* This indicates special properties of the audio presentation.
                                      *   0: Audio asset designated for mixing with another audio asset
                                      *   2: Lt/Rt Encoded for matrix surround decoding
                                      *   3: Audio processed for headphone playback
                                      *   otherwise: Reserved
                                      * If ChannelLayout != 0, this value shall be ignored. */
     uint16_t ChannelLayout;         /* complete information on channels coded in the audio stream including core and extensions */
     uint8_t  MultiAssetFlag;        /* This flag shall set if the stream contains more than one asset.
                                      *   0: single asset
                                      *   1: multiple asset
                                      * When multiple assets exist, the remaining parameters only reflect the coding parameters of the first asset. */
     uint8_t  LBRDurationMod;        /* This flag indicates a special case of the LBR coding bandwidth, resulting in 1/3 or 2/3 band limiting.
                                      * If set to 1, LBR frame duration is 50 % larger than indicated in FrameDuration */
 
 } lsmash_dts_specific_parameters_t;

 typedef struct
 {
     FILE *stream;     /* I/O stream */
     uint8_t error;
     uint8_t *data;    /* buffer for reading/writing */
     uint64_t store;   /* valid data size on buffer */
     uint64_t alloc;   /* total buffer size including invalid area */
     uint64_t pos;     /* data position on buffer to be read next */
     uint64_t written; /* data size written into "stream" already */
 } lsmash_bs_t;

 typedef struct {
     lsmash_bs_t* bs;
     uint8_t store;
     uint8_t cache;
 } lsmash_bits_t;

 typedef struct
 {
     uint32_t number_of_buffers;
     uint32_t buffer_size;
     void    *buffers;
 } lsmash_multiple_buffers_t;

 typedef struct
 {
     dts_substream_type               substream_type;
     //lsmash_dts_construction_flag     flags;
     int32_t     flags; // GYJ
     lsmash_dts_specific_parameters_t ddts_param;
     dts_core_info_t                  core;
     dts_extension_info_t             extension;
     dts_lossless_info_t              lossless;
     dts_lbr_info_t                   lbr;
     uint8_t  ddts_param_initialized;
     uint8_t  no_more_read;
     uint8_t  extension_index;
     uint8_t  extension_substream_count;
     uint32_t frame_duration;
     uint32_t frame_size;
     uint8_t  buffer[2 * DTS_MAX_EXTENSION_SIZE];
     uint8_t *buffer_pos;
     uint8_t *buffer_end;
     lsmash_bits_t *bits;
     lsmash_multiple_buffers_t *au_buffers;
     uint8_t *au;
     uint32_t au_length;
     uint8_t *incomplete_au;
     uint32_t incomplete_au_length;
     uint32_t au_number;
 } dts_info_t;

// TODO: reference additional headers your program requires here
