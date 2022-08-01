#pragma once

#define DNS_RCODE_NoError   0  /* No Error [RFC1035] */
#define DNS_RCODE_FormErr   1  /* Format Error [RFC1035] */
#define DNS_RCODE_ServFail  2  /* Server Failure [RFC1035] */
#define DNS_RCODE_NXDomain  3  /* Non-Existent Domain [RFC1035] */
#define DNS_RCODE_NotImp    4  /* Not Implemented [RFC1035] */
#define DNS_RCODE_Refused   5  /* Query Refused [RFC1035] */
#define DNS_RCODE_YXDomain  6  /* Name Exists when it should not [RFC2136][RFC6672] */
#define DNS_RCODE_YXRRSet   7  /* RR Set Exists when it should not [RFC2136] */
#define DNS_RCODE_NXRRSet   8  /* RR Set that should exist does not [RFC2136] */
#define DNS_RCODE_NotAuth   9  /* Server Not Authoritative for zone [RFC2136] */
#define DNS_RCODE_NotAuth   9  /* Not Authorized [RFC2845] */
#define DNS_RCODE_NotZone   10 /* Name not contained in zone [RFC2136] */
#define DNS_RCODE_DSOTYPENI 11 /* DSO-TYPE Not Implemented [RFC8490] */
#define DNS_RCODE_BADVERS   16 /* Bad OPT Version [RFC6891] */
#define DNS_RCODE_BADSIG    16 /* TSIG Signature Failure [RFC2845] */
#define DNS_RCODE_BADKEY    17 /* Key not recognized [RFC2845] */
#define DNS_RCODE_BADTIME   18 /* Signature out of time window [RFC2845] */
#define DNS_RCODE_BADMODE   19 /* Bad TKEY Mode [RFC2930] */
#define DNS_RCODE_BADNAME   20 /* Duplicate key name [RFC2930] */
#define DNS_RCODE_BADALG    21 /* Algorithm not supported [RFC2930] */
#define DNS_RCODE_BADTRUNC  22 /* Bad Truncation [RFC4635] */
#define DNS_RCODE_BADCOOKIE 23 /* Bad/missing Server Cookie [RFC7873] */
