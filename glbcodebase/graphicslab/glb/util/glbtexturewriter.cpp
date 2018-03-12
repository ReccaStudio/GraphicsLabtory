//----------------------------------------------------------------------------
// Declaration: Copyright (c), i_dovelemon, 2017. All right reserved.
// Author: i_dovelemon[1322600812@qq.com]
// Date: 2017/08/08
// Brief: Write texture data to file
// Add: DDS R8B8G8
//----------------------------------------------------------------------------
#include "glbtexturewriter.h"

#include <stdio.h>
#include <memory.h>

#include "glbddsformat.h"
#include "glbmacro.h"

namespace glb {

namespace util {

//--------------------------------------------------------------------------------
// CONSTANT
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// DECLARATION
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

class TextureWriterBase {
public:
    TextureWriterBase();
    virtual ~TextureWriterBase();

public:
    virtual bool Write(const char* file_name, int8_t* data, int32_t width, int32_t height, int32_t pixel_format, int32_t bit_count) = 0;
};

//--------------------------------------------------------------------------------

class DDSWriter : public TextureWriterBase {
public:
    DDSWriter();
    virtual ~DDSWriter();

public:
    virtual bool Write(const char* file_name, int8_t* data, int32_t width, int32_t height, int32_t pixel_format, int32_t bit_count);

protected:
    void SetRGBAMask(DDSPixelFormat& pf, int32_t pixel_format);
    void ReorganizeRGBData(int8_t* data, TEXTURE_PIXEL_FORMAT_TYPE type);
};

//--------------------------------------------------------------------------------
// DEFINITION
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

TextureWriterBase::TextureWriterBase() {
}

TextureWriterBase::~TextureWriterBase() {
}

//--------------------------------------------------------------------------------

DDSWriter::DDSWriter() {
}

DDSWriter::~DDSWriter() {
}

bool DDSWriter::Write(const char* file_name, int8_t* data, int32_t width, int32_t height, int32_t pixel_format, int32_t bit_count) {
    bool result = false;

    FILE* file = fopen(file_name, "wb");

    if (file) {
        // Build dds file
        DDSFile dds;
        memset(&dds, 0, sizeof(dds));

        dds.magic_num = 0x20534444; // "DDS"

        dds.desc.size = 124;
        dds.desc.flag = DDS_SD_CAPS | DDS_SD_HEIGHT | DDS_SD_WIDTH | DDS_SD_PIXELFORMAT;
        dds.desc.height = height;
        dds.desc.width = width;
        
        dds.desc.format.size = 32;
        dds.desc.format.flag = DDS_PF_RGB;
        dds.desc.format.rgb_bit_count = bit_count;
        SetRGBAMask(dds.desc.format, pixel_format);

        dds.desc.caps.caps_1 = DDS_CAPS_TEXTURE;

        dds.main_data = new int8_t[width * height * bit_count / 8];

        // Flip data
        for (int32_t i = 0; i < height; i++) {
            memcpy(dds.main_data + i * width * bit_count / 8, data + (height - 1 - i) * width * bit_count / 8, width * bit_count / 8);
        }

        // Reorganize data to ABGR
        for (int32_t i = 0; i < height; i++) {
            for (int32_t j = 0; j < width; j++) {
                ReorganizeRGBData(dds.main_data + i * width * bit_count / 8 + j * bit_count / 8, static_cast<TEXTURE_PIXEL_FORMAT_TYPE>(pixel_format));
            }
        }

        // Write to file
        fwrite(&dds, sizeof(dds.magic_num) + sizeof(dds.desc), 1, file);
        fwrite(dds.main_data, sizeof(int8_t), width * height * bit_count / 8, file);

        delete[] dds.main_data;
        dds.main_data = NULL;
        memset(&dds, 0, sizeof(dds));

        result = true;
    }

    fclose(file);

    return result;
}

void DDSWriter::SetRGBAMask(DDSPixelFormat& pf, int32_t pixel_format) {
    if (pixel_format == TPFT_R16G16) {
        // In DDS, R16G16 is store as G16R16
        pf.red_bit_mask = 0x0000ffff;
        pf.green_bit_mask = 0xffff0000;
    } else {
        // TODO: do not support now
        GLB_SAFE_ASSERT(false);
    }
}

void DDSWriter::ReorganizeRGBData(int8_t* data, TEXTURE_PIXEL_FORMAT_TYPE type) {
    if (data != NULL) {
        if (type == TPFT_R16G16) {
            unsigned short * data16 = reinterpret_cast<unsigned short*>(data);
            unsigned int data32 = *reinterpret_cast<unsigned int*>(data);

            data16[0] = data32 & 0x0000ffff;  // G
            data16[1] = (data32 & 0xffff0000) >> 16;  // R
        } else {
            // TODO: do not support now
            GLB_SAFE_ASSERT(false);
        }
    } else {
        GLB_SAFE_ASSERT(false);
    }
}

//--------------------------------------------------------------------------------

bool TextureWriter::Write(const char* file_name, int8_t* data, int32_t width, int32_t height, int32_t pixel_format, int32_t bit_count, int32_t format) {
    bool result = false;

    if (format == TFT_DDS) {
        DDSWriter writer;
        result = writer.Write(file_name, data, width, height, pixel_format, bit_count);
    } else {
        // TODO: Only support dds file now
        GLB_SAFE_ASSERT(false);
    }

    return result;
}

};  // namespace util

};  // namespace glb