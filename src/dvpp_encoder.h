#ifndef __DVPP_ENCODER_H__
#define __DVPP_ENCODER_H__

#include "acl/acl.h"
#include "acl/ops/acl_dvpp.h"
#include "acl_cb_thread.h"

#include "util.h"

class RtmpContext;

class DvppEncoder {
public:
    DvppEncoder();
    ~DvppEncoder();
    void Destory();
    aclError Init(const pthread_t thread_id, int h, int w, RtmpContext* ctx);
    aclError SendFrame(uint8_t* data);
private:
    int height;
    int width;
    int size;
    aclvencChannelDesc* channel_desc;
    aclvencFrameConfig* frame_config;
    RtmpContext* rtmp_ctx;
};

#endif//__DVPP_ENCODER_H__