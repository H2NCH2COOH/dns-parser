#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#include "dns-classes.h"
#include "dns-rrtypes.h"
#include "dns-rcodes.h"
#include "dns-opcodes.h"

typedef struct
{
    uint8_t opaque;
} DNSName;

typedef struct
{
    uint8_t* raw;
    size_t   raw_len;

    DNSName* name;
    uint16_t type; //Local endianness
    uint16_t class; //Local endianness
    uint32_t ttl; //Local endianness

    uint16_t rdata_len; //Local endianness
    uint8_t* rdata;
} DNSRR;

typedef struct
{
    uint8_t* raw;       //The raw packet. Will be set to the buff supplyed to the parse function
    size_t   raw_len;

    uint16_t id; //Local endianness
    bool query;
    bool response;
    uint8_t op_code; //Only 4-bit wide
    struct
    {
        bool aa;
        bool tc;
        bool rd;
        bool ra;
        bool ad;
        bool cd;
    } flags;
    uint8_t rcode; //Only 4-bit wide

    uint16_t query_count; //Local endianness
    uint16_t answer_count; //Local endianness
    uint16_t auth_count; //Local endianness
    uint16_t add_count; //Local endianness
} DNSPacket;

static inline bool dns_parse(DNSPacket* dst, uint8_t* src, size_t src_len)
{
    assert(dst);
    assert(src);
    assert(src_len >= 12);

    memset(dst, 0, sizeof(DNSPacket));

    dst->raw = src;
    dst->raw_len = src_len;

    uint8_t* ptr = src;

    dst->id = (ptr[0] << 8) | ptr[1];
    ptr += 2;

    uint8_t b = *ptr;
    if(b & 0x80)
    {
        dst->query = true;
        dst->response = false;
    }
    else
    {
        dst->query = false;
        dst->response = true;
    }
    dst->op_code = (b & 0x78) >> 3;
    dst->flags.aa = b & 0x04;
    dst->flags.tc = b & 0x02;
    dst->flags.rd = b & 0x01;
    ++ptr;

    b = *ptr;
    dst->flags.ra = b & 0x80;
    dst->flags.ad = b & 0x20;
    dst->flags.cd = b & 0x10;
    dst->rcode = b & 0x0F;
    ++ptr;

    dst->query_count = (ptr[0] << 8) | ptr[1];
    ptr += 2;

    dst->answer_count = (ptr[0] << 8) | ptr[1];
    ptr += 2;

    dst->auth_count = (ptr[0] << 8) | ptr[1];
    ptr += 2;

    dst->add_count = (ptr[0] << 8) | ptr[1];
    ptr += 2;

    return true;
}

static inline bool dns_get_next_rr(DNSPacket* pkt, DNSRR* last, DNSRR* next)
{
    assert(pkt);
    assert(next);

    uint8_t* ptr;

    if(last)
    {
        ptr = last->raw + last->raw_len;
        if(ptr >= (pkt->raw + pkt->raw_len))
        {
            //Last RR
            return false;
        }
    }
    else
    {
        ptr = pkt->raw + 12;
    }

    next->raw = ptr;
    size_t len = 0;

    next->name = (DNSName*)ptr;
    uint8_t b = *ptr;
    while(b)
    {
        if((b & 0xC0) == 0xC0)
        {
            //Pointer
            ptr += 1;
            len += 1;
            break;
        }
        ptr += b + 1;
        len += b + 1;
        b = *ptr;
    }

    //Skip final zero or second byte of a pointer
    ptr += 1;
    len += 1;

    next->type = (ptr[0] << 8) | ptr[1];
    ptr += 2;
    len += 2;

    next->class = (ptr[0] << 8) | ptr[1];
    ptr += 2;
    len += 2;

    next->ttl = (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
    ptr += 4;
    len += 4;

    next->rdata_len = (ptr[0] << 8) | ptr[1];
    ptr += 2;
    len += 2;

    next->rdata = ptr;
    ptr += next->rdata_len;
    len += next->rdata_len;

    next->raw_len = len;

    return true;
}

static inline bool dns_get_first_rr(DNSPacket* pkt, DNSRR* rr)
{
    return dns_get_next_rr(pkt, NULL, rr);
}

//Return 0 if success
//Return total size needed (including the '\0') if buff is too small
static inline size_t dns_name_to_str(DNSPacket* pkt, DNSName* name, char* buff, size_t buff_size)
{
    assert(pkt);
    assert(name);

    size_t len = 0;
    uint8_t* start = (uint8_t*)name;
    uint8_t* ptr = start;
    uint8_t b;
    for(b = *ptr; b; b = *ptr)
    {
        if((b & 0xC0) == 0xC0)
        {
            //Pointer jump
            uint16_t offset = ((b & 0x3F) << 8) | ptr[1];
            ptr = pkt->raw + offset;
            if(ptr != start)
            {
                len += 1;
            }
            continue;
        }

        ptr += b + 1;
        len += b + 1;
    }
    len += 1;

    if(len > buff_size)
    {
        return len;
    }

    ptr = start;
    for(b = *ptr; b; b = *ptr)
    {
        if((b & 0xC0) == 0xC0)
        {
            //Pointer jump
            uint16_t offset = ((b & 0x3F) << 8) | ptr[1];
            ptr = pkt->raw + offset;
            if(ptr != start)
            {
                *buff++ = '.';
            }
            continue;
        }

        ptr += b + 1;
        memcpy(buff, ptr + 1, b);
        buff += b;
        *buff++ = '.';
    }
    *buff = '\0';

    return 0;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */
