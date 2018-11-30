#!/bin/sh

curl https://www.iana.org/assignments/dns-parameters/dns-parameters-4.csv -o rrtypes.csv || exit 1

echo '#pragma once' > dns-rrtypes.h
echo >> dns-rrtypes.h

echo "/* Build from IANA online data at $(date '+%Y-%m-%d %H:%M:%S %z') */" >> dns-rrtypes.h
echo >> dns-rrtypes.h

tr -d '\n' < rrtypes.csv | tr '\r' '\n' | sed 's/        //' | \
sed -En 's/^([^,]+),([0-9]+),([^,]*),([^,]*),.*$/#define DNS_RRTYPE_\1 \2 \/* \3 \4 *\//p' | \
sed 's/DNS_RRTYPE_\*/DNS_RRTYPE_ANY/' | \
sed -E '/^#define DNS_RRTYPE_([a-zA-Z0-9]*-)+[a-zA-Z0-9]+ / s/-/_/' \
>> dns-rrtypes.h

rm -f rrtypes.csv
