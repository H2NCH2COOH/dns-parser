#pragma once

/* Built from IANA online data at 2019-09-14 14:59:45 +0800 */

#define DNS_RRTYPE_A 1 /* a host address [RFC1035] */
#define DNS_RRTYPE_NS 2 /* an authoritative name server [RFC1035] */
#define DNS_RRTYPE_MD 3 /* a mail destination (OBSOLETE - use MX) [RFC1035] */
#define DNS_RRTYPE_MF 4 /* a mail forwarder (OBSOLETE - use MX) [RFC1035] */
#define DNS_RRTYPE_CNAME 5 /* the canonical name for an alias [RFC1035] */
#define DNS_RRTYPE_SOA 6 /* marks the start of a zone of authority [RFC1035] */
#define DNS_RRTYPE_MB 7 /* a mailbox domain name (EXPERIMENTAL) [RFC1035] */
#define DNS_RRTYPE_MG 8 /* a mail group member (EXPERIMENTAL) [RFC1035] */
#define DNS_RRTYPE_MR 9 /* a mail rename domain name (EXPERIMENTAL) [RFC1035] */
#define DNS_RRTYPE_NULL 10 /* a null RR (EXPERIMENTAL) [RFC1035] */
#define DNS_RRTYPE_WKS 11 /* a well known service description [RFC1035] */
#define DNS_RRTYPE_PTR 12 /* a domain name pointer [RFC1035] */
#define DNS_RRTYPE_HINFO 13 /* host information [RFC1035] */
#define DNS_RRTYPE_MINFO 14 /* mailbox or mail list information [RFC1035] */
#define DNS_RRTYPE_MX 15 /* mail exchange [RFC1035] */
#define DNS_RRTYPE_TXT 16 /* text strings [RFC1035] */
#define DNS_RRTYPE_RP 17 /* for Responsible Person [RFC1183] */
#define DNS_RRTYPE_AFSDB 18 /* for AFS Data Base location [RFC1183][RFC5864] */
#define DNS_RRTYPE_X25 19 /* for X.25 PSDN address [RFC1183] */
#define DNS_RRTYPE_ISDN 20 /* for ISDN address [RFC1183] */
#define DNS_RRTYPE_RT 21 /* for Route Through [RFC1183] */
#define DNS_RRTYPE_NSAP 22 /* "for NSAP address  NSAP style A record" */
#define DNS_RRTYPE_NSAP_PTR 23 /* "for domain name pointer  NSAP style" */
#define DNS_RRTYPE_SIG 24 /* for security signature [RFC4034][RFC3755][RFC2535][RFC2536][RFC2537][RFC2931][RFC3110][RFC3008] */
#define DNS_RRTYPE_KEY 25 /* for security key [RFC4034][RFC3755][RFC2535][RFC2536][RFC2537][RFC2539][RFC3008][RFC3110] */
#define DNS_RRTYPE_PX 26 /* X.400 mail mapping information [RFC2163] */
#define DNS_RRTYPE_GPOS 27 /* Geographical Position [RFC1712] */
#define DNS_RRTYPE_AAAA 28 /* IP6 Address [RFC3596] */
#define DNS_RRTYPE_LOC 29 /* Location Information [RFC1876] */
#define DNS_RRTYPE_NXT 30 /* Next Domain (OBSOLETE) [RFC3755][RFC2535] */
#define DNS_RRTYPE_EID 31 /* Endpoint Identifier [Michael_Patton][http://ana-3.lcs.mit.edu/~jnc/nimrod/dns.txt] */
#define DNS_RRTYPE_NIMLOC 32 /* Nimrod Locator [1][Michael_Patton][http://ana-3.lcs.mit.edu/~jnc/nimrod/dns.txt] */
#define DNS_RRTYPE_SRV 33 /* Server Selection [1][RFC2782] */
#define DNS_RRTYPE_ATMA 34 /* ATM Address "[ATM Forum Technical Committee */
#define DNS_RRTYPE_NAPTR 35 /* Naming Authority Pointer [RFC2915][RFC2168][RFC3403] */
#define DNS_RRTYPE_KX 36 /* Key Exchanger [RFC2230] */
#define DNS_RRTYPE_CERT 37 /* CERT [RFC4398] */
#define DNS_RRTYPE_A6 38 /* A6 (OBSOLETE - use AAAA) [RFC3226][RFC2874][RFC6563] */
#define DNS_RRTYPE_DNAME 39 /* DNAME [RFC6672] */
#define DNS_RRTYPE_SINK 40 /* SINK [Donald_E_Eastlake][http://tools.ietf.org/html/draft-eastlake-kitchen-sink] */
#define DNS_RRTYPE_OPT 41 /* OPT [RFC6891][RFC3225] */
#define DNS_RRTYPE_APL 42 /* APL [RFC3123] */
#define DNS_RRTYPE_DS 43 /* Delegation Signer [RFC4034][RFC3658] */
#define DNS_RRTYPE_SSHFP 44 /* SSH Key Fingerprint [RFC4255] */
#define DNS_RRTYPE_IPSECKEY 45 /* IPSECKEY [RFC4025] */
#define DNS_RRTYPE_RRSIG 46 /* RRSIG [RFC4034][RFC3755] */
#define DNS_RRTYPE_NSEC 47 /* NSEC [RFC4034][RFC3755] */
#define DNS_RRTYPE_DNSKEY 48 /* DNSKEY [RFC4034][RFC3755] */
#define DNS_RRTYPE_DHCID 49 /* DHCID [RFC4701] */
#define DNS_RRTYPE_NSEC3 50 /* NSEC3 [RFC5155] */
#define DNS_RRTYPE_NSEC3PARAM 51 /* NSEC3PARAM [RFC5155] */
#define DNS_RRTYPE_TLSA 52 /* TLSA [RFC6698] */
#define DNS_RRTYPE_SMIMEA 53 /* S/MIME cert association [RFC8162] */
#define DNS_RRTYPE_Unassigned 54 /*   */
#define DNS_RRTYPE_HIP 55 /* Host Identity Protocol [RFC8005] */
#define DNS_RRTYPE_NINFO 56 /* NINFO [Jim_Reid] */
#define DNS_RRTYPE_RKEY 57 /* RKEY [Jim_Reid] */
#define DNS_RRTYPE_TALINK 58 /* Trust Anchor LINK [Wouter_Wijngaards] */
#define DNS_RRTYPE_CDS 59 /* Child DS [RFC7344] */
#define DNS_RRTYPE_CDNSKEY 60 /* DNSKEY(s) the Child wants reflected in DS [RFC7344] */
#define DNS_RRTYPE_OPENPGPKEY 61 /* OpenPGP Key [RFC7929] */
#define DNS_RRTYPE_CSYNC 62 /* Child-To-Parent Synchronization [RFC7477] */
#define DNS_RRTYPE_ZONEMD 63 /* message digest for DNS zone [draft-wessels-dns-zone-digest] */
#define DNS_RRTYPE_SPF 99 /*  [RFC7208] */
#define DNS_RRTYPE_UINFO 100 /*  [IANA-Reserved] */
#define DNS_RRTYPE_UID 101 /*  [IANA-Reserved] */
#define DNS_RRTYPE_GID 102 /*  [IANA-Reserved] */
#define DNS_RRTYPE_UNSPEC 103 /*  [IANA-Reserved] */
#define DNS_RRTYPE_NID 104 /*  [RFC6742] */
#define DNS_RRTYPE_L32 105 /*  [RFC6742] */
#define DNS_RRTYPE_L64 106 /*  [RFC6742] */
#define DNS_RRTYPE_LP 107 /*  [RFC6742] */
#define DNS_RRTYPE_EUI48 108 /* an EUI-48 address [RFC7043] */
#define DNS_RRTYPE_EUI64 109 /* an EUI-64 address [RFC7043] */
#define DNS_RRTYPE_TKEY 249 /* Transaction Key [RFC2930] */
#define DNS_RRTYPE_TSIG 250 /* Transaction Signature [RFC2845] */
#define DNS_RRTYPE_IXFR 251 /* incremental transfer [RFC1995] */
#define DNS_RRTYPE_AXFR 252 /* transfer of an entire zone [RFC1035][RFC5936] */
#define DNS_RRTYPE_MAILB 253 /* "mailbox-related RRs (MB  MG or MR)" */
#define DNS_RRTYPE_MAILA 254 /* mail agent RRs (OBSOLETE - see MX) [RFC1035] */
#define DNS_RRTYPE_ANY 255 /* A request for some or all records the server has available [RFC1035][RFC6895][RFC8482] */
#define DNS_RRTYPE_URI 256 /* URI [RFC7553] */
#define DNS_RRTYPE_CAA 257 /* Certification Authority Restriction [RFC-ietf-lamps-rfc6844bis-07] */
#define DNS_RRTYPE_AVC 258 /* Application Visibility and Control [Wolfgang_Riedel] */
#define DNS_RRTYPE_DOA 259 /* Digital Object Architecture [draft-durand-doa-over-dns] */
#define DNS_RRTYPE_AMTRELAY 260 /* Automatic Multicast Tunneling Relay [draft-ietf-mboned-driad-amt-discovery] */
#define DNS_RRTYPE_TA 32768 /* DNSSEC Trust Authorities "[Sam_Weiler][http://cameo.library.cmu.edu/][Deploying DNSSEC Without a Signed Root.  Technical Report 1999-19 */
#define DNS_RRTYPE_DLV 32769 /* DNSSEC Lookaside Validation [RFC4431] */
#define DNS_RRTYPE_Reserved 65535 /*   */
